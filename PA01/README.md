
Please read the ***ENTIRE*** readme. Please do not ask for help until ***AFTER***
reading this document, and the relevant sections from the course
notes. Do not be surprised if you are asked to do some reading before
receiving help. Failing to read is an extremely common problem that we
encounter when we help students. When you work at a job, nobody will
be there to read for you. Be patient, slow down, and read everything
before starting this assignment. This is very important, and
distinguishes good managers and employees from everyone else.

In this assignment, you will implement five different array processing
functions. Your solution should be short: between 50 and 150 lines of
code, including lines used for spacing.

# ~ Learning Goals ~

The main learning goals are five-fold, and all of them equally
important. You must learn:
(1) How to compile, run, and test your code.
(2) How to run your code under valgrind, in order to find memory
errors.
(3) How to run your code under gdb.
(4) How to "iterate" over arrays in C.
(5) How to use Version Control.

# ~ Getting Started ~

The PA01 folder contains five files:
(1) answer01.c: this is the file that you hand in. It has the skeleton
of five functions in it, and you must "fill in the blanks".
(2) answer01.h: this is a "header" file and it contains a complete
explanation of the functions you will be writing for this assignment.
(3) pa01.c: in computer science, you cannot know if a function is
correct without running it. You can use this file to write code that
runs the functions in answer01.c, in order to ensure their
correctness. pa01.c comes with some example testing code to help you
get started. You can modify or delete this code: it is yours to do
with what you will.
(4) README: this file.
(5) tester: see the discussion below on testing your assignment.

To get started, browse through the answer01.h file, to see what code
needs to be written. You will be writing code in the answer01.c
file. You can write code in the pa01.c file to test code written in
the answer01.c file.

Follow the discussions below on how to compile and run your code, as
well as test and submit it.

# ~ Submitting Your Assignment ~

You must submit one zip file to blackboard. This zip file must contain
precisely three files:
(1) answer01.c, your solution
(2) memcheck.log, a Valgrind log that you produced running your
program.
(3) gdb.txt, a logfile produced through running gdb.

Notes on creating each of these files are included in this readme.
You create the zip file using the following command.

 > ***zip pa01.zip answer01.c memcheck.log gdb.txt***

If your zip file does not meet the above specification, then you may
get zero for the assignment. In particular, right-clicking and
"archiving" the file in a window manager such as Windows, OSX, or KDE,
may produce the wrong directory structure, resulting in a zero
mark. YOU HAVE BEEN WARNED.  Following the instructions is *part* of
getting the assignment correct. So please follow the instructions.

Submit "pa01.zip" to blackboard.

# ~ Determining Your Mark ~

This assignment is pass or fail. You pass if everything works, and
fail if there is one or more things wrong. You can determine your mark
before submitting your assignment. To test your program, you must run
the "tester" program. You run the tester program as follows:

 > ***./tester answer01.c***

You can write your assignments on any computer, using any development
tools; however, they will be marked on the lab computers, and so you
should ensure that your program works on these computer before
submitting your assignment. This applies to *all* assignments in this
course.

Getting a passing grade from the tester only ensures a passing grade
for the assignment when you submit the assignment correctly, including
all auxiliary files listed above.

# ~ (1a) Compiling Your Program# ~

The remainder of this document is to help you figure out how to meet
the learning goals of this assignment. Firstly, you must compile, run
and test your program.

In this course we use the compiler "gcc", which is one of the world's
best and most important C compilers. You can compile your program by
typing the following into the terminal (make sure you are in your PA01
directory):

 > ***gcc -Wall -Wshadow -g pa01.c answer01.c -o pa01***

Gcc takes a wide variety of arguments, and these are the most
important arguments that we will use, and re-use in this course. The
arguments mean:
(1) -Wall, turn on all *common* compilation warnings. You will fail
the assignment if your solution has 1 or more compilation warnings.
(2) -Wshadow, in addition to common warnings, warn if a variable
declaration "shadows" the declaration of another variable.
(3) -g, turn on debugging symbols. This produces a larger executable
program; however, you can use this program in a debugger. You will
need to learn how to use the debugger "gdb" in order to pass this
course.
(4) pa01.c answer01.c. These are the files that you are compiling and
linking into a computer program. You only ever compile ".c" files. You
never compile ".h" files. Each ".c" file is compiled separately (gcc
does this internally), and multiple ".c" files are linked together
into a single computer program. Compiling and linking are two
different steps, but here we are doing both steps with a single
instruction. The "int main(...)" function must appear in precisely one
of those ".c" files (pa01.c). It cannot appear in answer01.c. If you
put "int main(...)" in answer01.c, then the tester will fail and you
will fail the assignment. (Aside: there are tricks that allow you to
maintain multiple main functions, using conditions; however, only one
main is present in an executable.)
(5) -o pa01, create an "output file" pa01. By default gcc will produce
a file called "a.out", and we are just telling gcc to name that file
"pa01" instead.

## ~ (1b) Running Your Program ~

To run your program, simply type into the terminal:

 > ***./pa01***

Note that this should print:

   Welcome to ECE264, we are working on PA01.

This statement is printed by a "printf" statement in pa01.c. You can
(and should) modify pa01.c, and edit its behavior, in order to test
the behavior of the functions you are writing in "answer01.c".

The file (technically: compilation unit) pa01.c "knows" about the
functions in answer01.c, because it "includes" the declarations for
those functions, which are written in the file "answer01.h".
Declarations and are not compiled into code, but instead, they merely
describe the existence of some compilable function in some compilation
unit somewhere. In this case, the functions declared in answer01.h are
defined in the compilation unit "answer01.c".

In future assignments, you will only be provided with an "answerXY.h"
header file, with declarations. You will need to write your answerXY.c
file from scratch, and write your own test-cases and main function in
a separate compilation unit.

## ~ (1c) Testing Your Program ~

It is your responsibility to test your program and ensure that it
works. A program that is 99% correct is still 100% wrong. Many
students seem to have trouble with this concept, but it is extremely
important, and straight-forward.

Engineers are people who get things right. If an engineer builds a
wheel, it is round. If an engineer makes a door, it is not missing a
hinge or a handle. Same goes for computer programs. It is right or
wrong. Computer programs are very difficult to write correctly, and
large programs almost always involve subtle bugs. For this reason,
software engineers need to adopt a zero-tolerance policy for software
defects. If you know a bug exists in your code, and you do not fix it,
then you will receive a fail.

A "tester" program exists, which will tell you the mark you will
receive when you submit your assignment. (Assuming you submit it
correctly with all auxiliary files.) Receiving a pass does not mean
your assignment is perfect, but it does mean that your assignment
passes the tests we thought to put it through.

This tester program is provided as a courtesy -- it is up to you to
think about your program, and test it. This is a fundamental skill for
any computer programming task. If you can't get it right, then no-one
else will get it right for you. For this reason, the tester program is
unrealistically slow for repeated use. Please do not run the tester
program until *after* you are *sure* you have your assignment 100%
correct.

So how do you write and test your code?

The most important thing to understand is that you should test your
code as you go. Because you are just starting, pa01.c includes a
little bit of testing code to start you off. However, in future
assignments, you will have to generate all of the testing code
yourself.

To generate testing code, you have to *think* about the function your
developing, and then you have to write code that *demonstrates* that
it *always* works. This is a core skill to develop if you are
interested in being a competent computer programmer.

# ~ (2a) Running ./pa01 Under Valgrind ~

Valgrind is an extremely useful tool for finding problems in C
programs. It is free-software, and (for C) as good as any software
commercially available. Comparable commercial software is usually
worth a few thousand dollars per user. (!).

It is a core goal of this course that you learn how to use Valgrind in
order to ensure that your assignments do not have memory errors. If
you do not learn how to use Valgrind, and you pass the course, then we
have failed as educators. Valgrind is an invaluable tool in an
engineers toolbox to do what most people in society don't know how to
do: ensure that something is correct.

Valgrind has many functions; however, in this course, we will concern
ourselves with the "memcheck" function. The memcheck function runs
your code in an emulated environment, and checks whether you access
any bits of memory that you shouldn't. Memcheck also tests to see if
you have allocated (asked for) memory that you never freed (gave
back). Together, these two types of memory problems are some of the
most pernicious programming problems in the world, and cost literally
billions of dollars each year. Valgrind will help you find these
problems.

To run your code under Valgrind, you must first compile your code, and
then type the following into the terminal:

 > ***valgrind --tool=memcheck --leak-check=full --verbose --log-file=memcheck.log ./pa01***

This *runs* your program, but to check for errors, you must check the
log file that you just generated: "memcheck.log". This file
contains a lot of information. If your solution has no memory errors,
then you will see at the end of the file something like:

   ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)

Don't worry about suppressed errors: they are not errors. When your
program runs, the C runtime (almost always) performs a few memory
tricks in order to execute more efficiently. Memcheck picks up these
advanced programming tricks, and then they are suppressed because it
is well-known that these tricks are not errors. Valgrind offers these
error suppression facilities because they are required by advanced
developers who work on important "glue" code that holds modern
operating systems together. In short: don't worry about suppressed
errors. Google is your friend if you are interested in more
information; however, it will not be tested in this course.

# ~ (2b) Debugging Valgrind Errors ~

Look for the *first* error, and debug that error. Sometimes you will
get hundreds (or even hundreds of thousands) or errors; however, they
may all caused by the same line of code. So just debug the first
problem you encounter in the "memcheck.log" file.

Most memory errors fall into one of four categories:
(2b.i) "Invalid read of size X", where X is a number. This means that
you are reading X bytes of memory that you do not have access to.
(2b.ii) "Invalid write of size X", as above, except that you are
*writing* memory. Writing means, that the memory access is on the
left-hand side of an "=" sign. (ie., assignment operation, eg. x = 5.)
(2b.iii) "X bytes in 1 blocks definitely lost in loss record U of V",
which means that you have asked for X bytes of memory, but never freed
them.
(2b.iv) "Conditional jump or move depends on uninitialised value(s)" A
conditional jump or move is what happens in an if statement or a for
loop, where some condition (e.g., if(x > 5) {...}) determines the next
line of code that is executed. If the memory is uninitialized (e.g.,
"x" has not been set), then the program behavior is random. When you
see this error, look at the involved statement and ask yourself how
any involved variables could be uninitialized.

These memory errors can be difficult to solve, but it is much easier
if you think precisely about your code. This is necessary skill, and
expect to spend much time over this semester learning to do just that.

# ~ (2c) Submitting a Valgrind Log ~

In order to pass this assignment, you must submit a log file produced
by valgrind. See the section on submitting your assignment (above) for
information on how to do that.

# ~ (3) Using Gdb ~

Gdb is easily one of the world's most important debuggers. A debugger
is a virtual environment that you run your code within. This
environment allows you to control the execution of the code, and watch
what happens to the variables. Make sure that you *read* the course
notes on using gdb. Using gdb is a course requirement. If you ask for
help, you may in turn be asked to run your code under gdb.

To pass this assignment, you must submit a gdb log file. To produce a
logfile you must turn logging on. My preferred way of doing this is to
use command-line switches to tell gdb to set logging on. The command
looks as follows:

 > ***gdb -ex "set logging overwrite on" -ex "set logging on" ./pa01***
 ...

You must then set a breakpoint (read the documentation to learn how to
do this), step through your code, print the values of some variables,
and then quit gdb. You submit the file "gdb.txt". See the submission
guidelines for more information.

# ~ (4) Iterating Over Arrays in C ~

In computer science, iterating means visiting every element of a
"collection" once, and only once. An array is the most fundamental
type of collection, having a fixed size, and storing the elements
sequentially. The easiest way to iterate over an array is to use an
"index" variable in a for-loop:

```C
// Assume we have an array "array", with length "len"
   int ind; // the index variable
   for(ind = 0; ind < len; ++ind) {
      // do something with array[ind]
   }
```

You should already be familiar with this programming motif from
earlier courses. Please refer to the class notes and course materials
in order to understand how to iterate over arrays in C.

# ~ Summary ~

## Compile
 > ***gcc -Wall -Wshadow -g pa01.c answer01.c -o pa01***

## Run -- you must write your own tests
 > ***./pa01***

## Run under valgrind
 > ***valgrind --tool=memcheck --leak-check=full --verbose --log-file=memcheck.log ./pa01***

## ***Don't forget to *LOOK* at the log-file "memcheck.log"***

## Run under gdb -- this is an *example*. You will need to adjust these
## commands to your situation.
 > ***gdb -ex "set logging overwrite on" -ex "set logging on" ./pa01***

```gdb
(gdb) b pa01.c:59
(gdb) run
(gdb) p argc
(gdb) n
(gdb) n
(gdb) c
(gdb) quit
```

## See what your grade should be (providing you submit everything correctly):
 > ***./tester answer01.c***

## Create a zip file of your solution:
 > ***zip pa01.zip answer01.c memcheck.log gdb.txt***

## Upload pa01.zip to blackboard.

## Please read all instructions before asking for help.
