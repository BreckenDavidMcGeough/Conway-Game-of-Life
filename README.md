Conway's Game of Life
===

This project is an implementation of John Horton Conway's Game of Life.
You should have received a detailed handout with requirements, guidance,
and grading criteria.

Repository Layout
---

The source code for your implementation (including the given code)
should be in the `src/` directory.  Your implementation should start in
`main.c`.

There are several sample input files in `inputs/`, mostly containing
well-known Life constructions.  You can parse them using the function
`parse_life()` in the given code (defined in `src/parser.c`, with usage
comments at its definition) and use them as starting states for your
implementation.

There are additionally expected outputs for particular generations of
several of the given inputs in `outputs/`, which you may find useful in
developing and testing your program.

Running Tests
---

You can test your implementation against a few of the expected outputs
by running `make test`.

Adding Source Files
---

If you would like to add source files to your implementation, create the
files in the `src/` directory and add the filenames to the `SOURCEFILES`
variable in the Makefile.  You must follow this approach for your files
to be properly submitted and used by the Autograder.

Succeeding at This Project
---

Start early.  Read all of the documentation.  Write things down on paper.
