# OS Assignment 01 - Report
**Name:** Shahab | **Roll No:** BSDSF24A032

## Feature 2: Multi-file Build

### Q1. Explain the linking rule `$(TARGET): $(OBJECTS)`. How is it different from linking against a library?
This rule means: the program (`client`) depends on all the object files (`main.o`,
`mystrfunctions.o`, `myfilefunctions.o`). If any `.o` file is newer than `client`,
make runs the command to link them together again.

Here we give gcc every `.o` file directly. When linking against a library, we give gcc
only `main.o` plus the library, using `-L` (the folder where the library is) and
`-l` (the library name, e.g. `-lmyutils` for `libmyutils.a`). The linker then takes
only the functions it needs from the library.

### Q2. What is a git tag and why is it useful? Simple tag vs annotated tag?
A tag is a permanent name for one specific commit, such as `v0.1.1-multifile`.
It marks important points like releases, so we can always go back to that exact version.

- **Simple (lightweight) tag:** just a name pointing to a commit. No extra information.
- **Annotated tag (`git tag -a`):** a full git object that stores the tagger's name,
  email, date and a message. It is recommended for releases.

### Q3. What is the purpose of a GitHub Release? Why attach binaries?
A Release is an official, downloadable version of the project, built on a tag.
It shows users which version is stable and what changed.

Attaching binaries (like `client`) lets people download and run the program directly,
without needing a compiler or building it from the source code themselves.

## Feature 3: Static Library

### Q1. Compare the Makefiles of Part 2 and Part 3. What changed to create a static library?
- A new macro `LIB = ../lib` was added for the library folder.
- A new rule builds `libmyutils.a` from `mystrfunctions.o` and `myfilefunctions.o`
  using `ar rc`, followed by `ranlib`.
- The link rule changed. In Part 2 all `.o` files were linked directly:
  `gcc main.o mystrfunctions.o myfilefunctions.o -o client`.
  In Part 3 only `main.o` is linked with the library:
  `gcc main.o -L../lib -lmyutils -o client_static`.
- The target now depends on `main.o` and `libmyutils.a` instead of all `.o` files.

### Q2. What is the purpose of `ar`? Why is `ranlib` used after it?
`ar` (archiver) packs many `.o` files into one archive file (`.a`), which is a
static library. `r` adds/replaces files and `c` creates the archive.

`ranlib` adds an index (symbol table) to the archive that lists which function is
in which `.o` file. The linker uses this index to find functions quickly.
(Modern `ar rcs` can create the index itself, but `ranlib` is the traditional way.)

### Q3. Does `nm client_static` show symbols like `mystrlen`? What does this tell you?
Yes. `nm bin/client_static` shows `mystrlen`, `mystrcpy`, `mygrep`, `wordCount` etc.
with the letter `T`, meaning their code is defined inside the executable.

This shows that static linking copies the code of the needed functions from the
library into the final program at build time. The program no longer needs
`libmyutils.a` to run.

## Feature 4: Dynamic Library

### Q1. What is Position-Independent Code (-fPIC) and why is it needed for shared libraries?
PIC is machine code that works correctly no matter which memory address it is loaded at.
Instead of using fixed (absolute) addresses, it uses addresses relative to the current
position.

A shared library is loaded at a different address in each program that uses it, and
one copy in memory is shared by many programs. So its code cannot depend on a fixed
address. `-fPIC` tells gcc to generate such code. Without it, `gcc -shared` fails.

### Q2. Explain the difference in file size between the static and dynamic clients.
- `client_static`: 807K
- `client_dynamic`: 17K

`client_static` was linked with `-static`, so the code of our library AND the whole
C library (printf, fopen, malloc...) was copied into the executable.

`client_dynamic` contains only `main()` and a note saying which libraries it needs
(`libmyutils.so`, `libc.so.6`). The actual code is loaded from those `.so` files at
run time, so the file is much smaller. `nm` confirms this: in `client_dynamic`,
`mystrlen` is `U` (undefined, comes from outside), while in `client_static` it is `T`
(defined inside).

### Q3. What is LD_LIBRARY_PATH? Why was it needed, and what does it tell us about the dynamic loader?
`LD_LIBRARY_PATH` is an environment variable with a list of extra folders where the
dynamic loader searches for `.so` files, before the standard system folders.

When `client_dynamic` starts, the dynamic loader (`ld-linux-x86-64.so.2`) must find
`libmyutils.so` and load it into memory. By default it only searches system folders
like `/lib` and `/usr/lib`, so it failed with "cannot open shared object file".
Setting `export LD_LIBRARY_PATH=$PWD/lib` told it to also search our `lib/` folder.

This shows that the dynamic loader is responsible, at run time, for finding every
required shared library, loading it into memory, and connecting (resolving) the
program's function calls to it. `ldd` shows the result of this search.
