// Code generated by re2c, DO NOT EDIT.
//line "golang/002_fill_eof_rule.--lang(go).re":1
package main

import "fmt"
import "os"

var SIZE int = 11

type YYCTYPE byte
type Input struct {
	file   *os.File
	data   []byte
	cursor int
	marker int
	token  int
	limit  int
	eof    bool
}

func fill(in *Input) int {
	// If nothing can be read, fail.
	if in.eof {
		return 1
	}

	// Check if at least some space can be freed.
	if in.token == 0 {
		// In real life can reallocate a larger buffer.
		panic("fill error: lexeme too long")
	}

	// Discard everything up to the start of the current lexeme,
	// shift buffer contents and adjust offsets.
	copy(in.data[0:], in.data[in.token:in.limit])
	in.cursor -= in.token
	in.marker -= in.token
	in.limit -= in.token
	in.token = 0

	// Read new data (as much as possible to fill the buffer).
	n, _ := in.file.Read(in.data[in.limit:SIZE])
	in.limit += n
	in.data[in.limit] = 0
	fmt.Printf("fill: %v '%s'\n", in.data[:in.limit+1],
		string(in.data[:in.limit]))

	// If read less than expected, this is the end of input.
	in.eof = in.limit < SIZE

	// If nothing has been read, fail.
	if n == 0 {
		return 1
	}

	return 0
}

func Lex(in *Input) int {
	in.token = in.cursor

	
//line "golang/002_fill_eof_rule.--lang(go).go":64
{
	var yych YYCTYPE
yyFillLabel0:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case ' ':
		goto yy4
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy6
	default:
		if (in.limit-in.cursor < 1) {
			if (fill(in) == 0) {
				goto yyFillLabel0
			}
			goto yyeof1
		}
		goto yy2
	}
yy2:
	in.cursor += 1
//line "golang/002_fill_eof_rule.--lang(go).re":69
	{
		fmt.Println("error")
		return -1
	}
//line "golang/002_fill_eof_rule.--lang(go).go":108
yy4:
	in.cursor += 1
//line "golang/002_fill_eof_rule.--lang(go).re":89
	{
		return 3
	}
//line "golang/002_fill_eof_rule.--lang(go).go":115
yy6:
	in.cursor += 1
	in.marker = in.cursor
yyFillLabel1:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case '-':
		goto yy9
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy6
	default:
		if (in.limit-in.cursor < 1) {
			if (fill(in) == 0) {
				goto yyFillLabel1
			}
		}
		goto yy8
	}
yy8:
//line "golang/002_fill_eof_rule.--lang(go).re":79
	{
		fmt.Printf("number-1: %v\n", string(in.data[in.token:in.cursor]))
		return 1
	}
//line "golang/002_fill_eof_rule.--lang(go).go":158
yy9:
	in.cursor += 1
yyFillLabel2:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy11
	default:
		if (in.limit-in.cursor < 1) {
			if (fill(in) == 0) {
				goto yyFillLabel2
			}
		}
		goto yy10
	}
yy10:
	in.cursor = in.marker
	goto yy8
yy11:
	in.cursor += 1
yyFillLabel3:
	yych = YYCTYPE(in.data[in.cursor])
	switch (yych) {
	case '0':
		fallthrough
	case '1':
		fallthrough
	case '2':
		fallthrough
	case '3':
		fallthrough
	case '4':
		fallthrough
	case '5':
		fallthrough
	case '6':
		fallthrough
	case '7':
		fallthrough
	case '8':
		fallthrough
	case '9':
		goto yy11
	default:
		if (in.limit-in.cursor < 1) {
			if (fill(in) == 0) {
				goto yyFillLabel3
			}
		}
		goto yy13
	}
yy13:
//line "golang/002_fill_eof_rule.--lang(go).re":84
	{
		fmt.Printf("number-2: %v\n", string(in.data[in.token:in.cursor]))
		return 2
	}
//line "golang/002_fill_eof_rule.--lang(go).go":234
yyeof1:
//line "golang/002_fill_eof_rule.--lang(go).re":74
	{
		fmt.Println("end")
		return 0
	}
//line "golang/002_fill_eof_rule.--lang(go).go":241
}
//line "golang/002_fill_eof_rule.--lang(go).re":92

}

func test(data string) (result int) {
	tmpfile := "input.txt"

	f, _ := os.Create(tmpfile)
	f.WriteString(data)
	f.Seek(0, 0)

	defer func() {
		if r := recover(); r != nil {
			fmt.Println(r)
			result = -2
		}
		f.Close()
		os.Remove(tmpfile)
	}()

	in := &Input{
		file:   f,
		data:   make([]byte, SIZE+1),
		cursor: SIZE,
		marker: SIZE,
		token:  SIZE,
		limit:  SIZE,
		eof:    false,
	}

	result = 9999
	for result > 0 {
		result = Lex(in)
	}

	return
}

func main() {
	var s string

	// Succeeds, the lexer needs 1 character ahead.
	s = "     1234567890     "
	if test(s) != 0 {
		panic("expected 'number: 1234567890'")
	}

	// Fails, the lexer needs 1 character ahead, but there is no space.
	s = "     12345678901    "
	if test(s) != -2 {
		panic("expected 'fill error: lexeme too long'")
	}

	// Succeeds, the lexer needs 1 character ahead.
	s = "     12345-6789     "
	if test(s) != 0 {
		panic("expected 'number: 12345-6789'")
	}

	// Fails, the lexer needs 1 character ahead, but there is no space.
	s = "     12345-67890     "
	if test(s) != -2 {
		panic("expected 'fill error: lexeme too long'")
	}

	// Fails, invalid input.
	s = "?#!*"
	if test(s) != -1 {
		panic("expected 'error'")
	}

	fmt.Println("OK")
}
