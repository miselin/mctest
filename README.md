MCTest
======

Matt's lightweight and concise C unit test framework is a basic, concise, and
trivial framework for adding basic unit tests to a C program.

License
-----

Licensed under the 2-clause BSD license. Please read the LICENSE file in the
repository for more information.

Usage
-----

Have a read of the provided example, `example.c`, to identify how to integrate
MCTest with your program.

You will need to:
1. Compile mctest.c as a part of your program.
2. Define a set of tests by using the preprocessor macro `MCT_DEFINE_TEST` in
   `mctest.h`.
3. In your testing build, call `mct_perform_tests`; this will run all tests.

Example
-----

An example test is as follows:

    MCT_DEFINE_TEST(trie_deep, (void *) 0xbeef, void *t = create_trie(),
    			trie_insert(t, "h", (void*) 0),
    			trie_insert(t, "he", (void*) 0),
    			trie_insert(t, "hel", (void*) 0),
    			trie_insert(t, "hell", (void*) 0),
    			trie_insert(t, "hello", (void*) 0),
    			trie_insert(t, "helloworld", (void*) 0xbeef),
    			trie_search(t, "helloworld"))

The test is called 'trie_deep', the expected result from the test is a `void`
pointer to memory address `0xbeef`, a single variable `t` is defined and
initialised before the test begins, and then the C code is introduced to
actually run the test.

Note that the result of the rightmost statement will be used in the comparison
with the expected value.

TODO
-----

In no particular order...

* Dedicated test setup and teardown
* Compiler portability
* More flexible testing
* Concurrently running tests
* Test timing

Reporting Bugs
-----

Please report bugs and issues at https://github.com/pcmattman/mctest.
