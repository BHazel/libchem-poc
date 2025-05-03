# LibChem (Proof of Concept)

This is a proof of concept for a chemistry library in C, inspired by the content of _Elements of Physical Chemistry_ by Peter Atkins and Julio de Paula.

I wrote this in 2009-2010 while undertaking my PhD in chemistry and to practise C which I had recently started learning.

## Building & Running

I have made some minor edits to the original code from 2010 so it can easily compile and run, including the Makefile and declaring the `libError()` function in library source files.

Simply run `make` in the root of the repository and it will create a static library, `libchem.a`, which is then used to build and run the `test.c` file.