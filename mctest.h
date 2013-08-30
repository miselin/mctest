/*
 * Copyright (c) 2013 Matthew Iselin
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef MCTEST_H
#define MCTEST_H

#ifdef __cplusplus
extern "C" {
#endif

struct __mct_test {
    int (*routine)();
    const char *name;
} PACKED;

#define MCT_SECTION(x)           __attribute__((__section__(x)))
#define MCT_UNUSED               __attribute__((unused))

#define MCT_TEST_INIT_VAR(type, name, ...) type name = __VA_ARGS__

/**
 * Defines a new test to be performed. Name must be unique, and valid in a C
 * function name. C code that can be passed in as the LHS of operator == is
 * passed as a variable length parameter list, using the ',' operator.
 */
#define MCT_DEFINE_TEST(name, expected, init, /* croutine */ ...) \
    int __test_##name() { \
        init; \
        if((__VA_ARGS__) == (expected)) \
        return 0; \
        else \
        return 1; \
    } \
    struct __mct_test __test_dat_##name MCT_SECTION("__mctest") MCT_UNUSED = {__test_##name, #name};

/**
 * Run all defined tests.
 *
 * \param continue_on_error Set to one to continue running tests if one fails.
 * \return zero if all tests were successful.
 */
extern int mct_perform_tests(int continue_on_error);

#ifdef __cplusplus
}; // extern "C"
#endif

#endif // MCTEST_H

