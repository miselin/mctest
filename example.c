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

#include <string.h>

#include "mctest.h"

int main(int argc, char *argv[])
{
    return mct_perform_tests(1);
}

MCT_DEFINE_TEST(nulls, 0, void, memcmp(0, 0, 0))
MCT_DEFINE_TEST(same, 0, void, memcmp("foo", "foo", 4))
MCT_DEFINE_TEST(different, 1, void, memcmp("foo", "bar", 4))
MCT_DEFINE_TEST(same_longer, 0, void, memcmp("foobar", "foo", 3))
MCT_DEFINE_TEST(diff_longer, -1, void, memcmp("foobar", "foobaz", 7))

