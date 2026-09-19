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
