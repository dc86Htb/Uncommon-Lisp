cmake_minimum_required(VERSION 3.22)
project(unlisp C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(mpc)
include_directories(mpc/examples)
include_directories(mpc/tests)

add_executable(unlisp
        mpc/examples/doge.c
        mpc/examples/foobar.c
        mpc/examples/line_reader.c
        mpc/examples/lispy.c
        mpc/examples/maths.c
        mpc/examples/smallc.c
        mpc/examples/tree_traversal.c
        mpc/tests/combinators.c
        mpc/tests/core.c
        mpc/tests/grammar.c
        mpc/tests/ptest.c
        mpc/tests/ptest.h
        mpc/tests/regex.c
        mpc/tests/test.c
        mpc.c
        mpc.h
        parsing.c
        test.c)
