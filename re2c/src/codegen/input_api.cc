#include <assert.h>
#include <sstream>

#include "src/codegen/emit.h"
#include "src/codegen/input_api.h"
#include "src/codegen/indent.h"
#include "src/conf/opt.h"
#include "src/globals.h"

namespace re2c
{

template<typename T>
static std::string to_string(const T &v)
{
	std::ostringstream s;
	s << v;
	return s.str();
}

InputAPI::InputAPI ()
	: type_ (DEFAULT)
{}

InputAPI::type_t InputAPI::type () const
{
	return type_;
}

void InputAPI::set (type_t t)
{
	type_ = t;
}

std::string InputAPI::expr_peek () const
{
	std::string s;
	switch (type_)
	{
		case DEFAULT:
			s = "*" + opts->yycursor;
			break;
		case CUSTOM:
			s = opts->yypeek + " ()";
			break;
	}
	return s;
}

std::string InputAPI::expr_peek_save () const
{
	return opts->yych + " = " + opts.yychConversion () + expr_peek ();
}

std::string InputAPI::stmt_peek (uint32_t ind) const
{
	return indent (ind) + expr_peek_save () + ";\n";
}

std::string InputAPI::stmt_skip (uint32_t ind) const
{
	std::string s;
	switch (type_)
	{
		case DEFAULT:
			s = "++" + opts->yycursor;
			break;
		case CUSTOM:
			s = opts->yyskip + " ()";
			break;
	}
	return indent (ind) + s + ";\n";
}

std::string InputAPI::stmt_backup (uint32_t ind) const
{
	std::string s;
	switch (type_)
	{
		case DEFAULT:
			s = opts->yymarker + " = " + opts->yycursor;
			break;
		case CUSTOM:
			s = opts->yybackup + " ()";
			break;
	}
	return indent (ind) + s + ";\n";
}

std::string InputAPI::stmt_backupctx (uint32_t ind) const
{
	std::string s;
	switch (type_)
	{
		case DEFAULT:
			s = opts->yyctxmarker + " = " + opts->yycursor;
			break;
		case CUSTOM:
			s = opts->yybackupctx + " ()";
			break;
	}
	return indent(ind) + s + ";\n";
}

std::string InputAPI::expr_dist () const
{
	std::string s;
	switch (type_) {
		case DEFAULT:
			s = "(" + opts->yycursor + " - " + opts->yyctxmarker + ")";
			break;
		case CUSTOM:
			s = opts->tags_yydist + "()";
			break;
	}
	return s;
}

std::string InputAPI::stmt_dist (uint32_t ind, const bool *mask,
	const std::valarray<Tag> &tags) const
{
	std::string s = indent(ind);
	for (size_t i = 0; i < tags.size(); ++i) {
		if (mask[i]) {
			const Tag &t = tags[tags[i].var.orig];
			s += vartag_expr(t.name, t.rule) + " = ";
		}
	}
	return s + expr_dist() + ";\n";
}

std::string InputAPI::expr_tag(const std::valarray<Tag> &tags, const Tag &tag) const
{
	std::string expr;

	if (tag.type == Tag::VAR) {
		const Tag &orig = tags[tag.var.orig];
		expr = vartag_expr(orig.name, orig.rule);
	} else {
		const std::string dist = to_string(tag.fix.dist);
		if (tag.fix.base == Tag::NONE) {
			if (type_ == DEFAULT) {
				// optimize '(YYCTXMARKER + ((YYCURSOR - YCTXMARKER) - yyctx))'
				// to       '(YYCURSOR - yytag)'
				return "(" + opts->yycursor + " - " + dist + ")";
			}
			expr = opts->tags_yydist + "() - " + dist;
		} else {
			const Tag &orig = tags[tags[tag.fix.base].var.orig];
			expr = "(" + vartag_expr(orig.name, orig.rule) + " - " + dist + ")";
		}
	}

	return (type_ == DEFAULT)
		? "(" + opts->yyctxmarker + " + " + expr + ")"
		: opts->tags_yytag + "(" + expr + ")";
}

std::string InputAPI::stmt_restore (uint32_t ind) const
{
	std::string s;
	switch (type_)
	{
		case DEFAULT:
			s = opts->yycursor + " = " + opts->yymarker;
			break;
		case CUSTOM:
			s = opts->yyrestore + " ()";
			break;
	}
	return indent (ind) + s + ";\n";
}

std::string InputAPI::stmt_restorectx(uint32_t ind,
	const std::valarray<Tag> &tags, const Tag &tag, bool basetag) const
{
	std::string s;

	if (tag.type == Tag::FIX) {
		const std::string dist = to_string(tag.fix.dist);
		s = (type_ == DEFAULT)
			? opts->yycursor + " -= " + dist
			: opts->yyrestorectx + " (" + opts->tags_yydist + "() - " + dist + ")";
	} else if (basetag) {
		const Tag &orig = tags[tag.var.orig];
		const std::string expr = vartag_expr(orig.name, orig.rule);
		s = (type_ == DEFAULT)
			? opts->yycursor + " = " + opts->yyctxmarker + " + " + expr
			: opts->yyrestorectx + " (" + expr + ")";
	} else {
		s = (type_ == DEFAULT)
			? opts->yycursor + " = " + opts->yyctxmarker
			: opts->yyrestorectx + " ()";
	}

	return indent(ind) + s + ";\n";
}

std::string InputAPI::stmt_skip_peek (uint32_t ind) const
{
	return type_ == DEFAULT
		? indent (ind) + opts->yych + " = " + opts.yychConversion () + "*++" + opts->yycursor + ";\n"
		: stmt_skip (ind) + stmt_peek (ind);
}

std::string InputAPI::stmt_skip_backup (uint32_t ind) const
{
	return type_ == DEFAULT
		? indent (ind) + opts->yymarker + " = ++" + opts->yycursor + ";\n"
		: stmt_skip (ind) + stmt_backup (ind);
}

std::string InputAPI::stmt_backup_peek (uint32_t ind) const
{
	return type_ == DEFAULT
		? indent (ind) + opts->yych + " = " + opts.yychConversion () + "*(" + opts->yymarker + " = " + opts->yycursor + ");\n"
		: stmt_backup (ind) + stmt_peek (ind);
}

std::string InputAPI::stmt_skip_backup_peek (uint32_t ind) const
{
	return type_ == DEFAULT
		? indent (ind) + opts->yych + " = " + opts.yychConversion () + "*(" + opts->yymarker + " = ++" + opts->yycursor + ");\n"
		: stmt_skip (ind) + stmt_backup (ind) + stmt_peek (ind);
}

std::string InputAPI::expr_lessthan_one () const
{
	return type_ == DEFAULT
		? opts->yylimit + " <= " + opts->yycursor
		: expr_lessthan (1);
}

std::string InputAPI::expr_lessthan (size_t n) const
{
	std::ostringstream s;
	switch (type_)
	{
		case DEFAULT:
			s << "(" << opts->yylimit << " - " << opts->yycursor << ") < " << n;
			break;
		case CUSTOM:
			s << opts->yylessthan << " (" << n << ")";
			break;
	}
	return s.str ();
}

} // end namespace re2c
