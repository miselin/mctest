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

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include <mctest.h>

extern int __start___mctest;
extern int __stop___mctest;

int mct_perform_tests(int continue_on_error) {
    uintptr_t begin = (uintptr_t) &__start___mctest;
    uintptr_t end = (uintptr_t) &__stop___mctest;
    size_t testcount = (end - begin) / sizeof(struct __mct_test), n = 0;

    printf("==== MCTest Running Tests ====\n");

    printf("Tests begin at %" PRIxPTR ", end at %" PRIxPTR " [%zd tests]\n", begin, end, testcount);

    while(begin < end) {
        struct __mct_test *test = (struct __mct_test *) begin;
        printf("Test %zd of %zd: %s ", n++, testcount, test->name);
        if(!test->routine())
            printf("PASS\n");
        else {
            printf("FAIL\n");
            if(!continue_on_error)
                return 1;
        }
        begin += sizeof(struct __mct_test);
    }

    return 0;
}

