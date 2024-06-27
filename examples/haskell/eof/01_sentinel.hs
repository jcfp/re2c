-- Generated by re2c
{-# LANGUAGE RecordWildCards #-}
#1 "haskell/eof/01_sentinel.re"
-- re2hs $INPUT -o $OUTPUT
{-# OPTIONS_GHC -Wno-unused-record-wildcards #-}
{-# LANGUAGE OverloadedStrings #-}

import Control.Monad (when)
import Data.ByteString (ByteString, index)

data State = State {
    _yyinput :: ByteString,
    _yycursor :: Int,
    _count :: Int
}

-- expect a null-terminated string

#20 "haskell/eof/01_sentinel.hs"
yy0 :: State -> Int
yy0 State{..} =
    let yych = index _yyinput _yycursor in
    let __ = _yycursor + 1 in let _yycursor = __ in
    case yych of
        _c | 0x00 == _c ->
            yy1 State{..}
        _c | 0x20 == _c ->
            yy3 State{..}
        _c | 0x61 <= _c && _c <= 0x7A ->
            yy5 State{..}
        _c | True ->
            yy2 State{..}

yy1 :: State -> Int
yy1 State{..} =
#20 "haskell/eof/01_sentinel.re"
    _count
#39 "haskell/eof/01_sentinel.hs"

yy2 :: State -> Int
yy2 State{..} =
#19 "haskell/eof/01_sentinel.re"
    (-1)
#45 "haskell/eof/01_sentinel.hs"

yy3 :: State -> Int
yy3 State{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x20 == _c ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy3 State{..}
        _c | True ->
            yy4 State{..}

yy4 :: State -> Int
yy4 State{..} =
#22 "haskell/eof/01_sentinel.re"
    lexer State{..}
#61 "haskell/eof/01_sentinel.hs"

yy5 :: State -> Int
yy5 State{..} =
    let yych = index _yyinput _yycursor in
    case yych of
        _c | 0x61 <= _c && _c <= 0x7A ->
            let __ = _yycursor + 1 in let _yycursor = __ in
            yy5 State{..}
        _c | True ->
            yy6 State{..}

yy6 :: State -> Int
yy6 State{..} =
#21 "haskell/eof/01_sentinel.re"
    lexer State{_count = _count + 1, ..}
#77 "haskell/eof/01_sentinel.hs"

lexer :: State -> Int
lexer State{..} =
    yy0 State{..}

#23 "haskell/eof/01_sentinel.re"


main :: IO ()
main = do
    let test s n = when (lexer st  /= n) $ error "failed"
                   where st = State{_yyinput = s, _yycursor = 0, _count = 0}
    test "\0" 0
    test "one two three\0" 3
    test "f0ur\0" (-1)