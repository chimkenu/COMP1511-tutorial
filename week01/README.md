# COMP1511 Tutorial - Week 01

## Admin stuff

- Course structure
    - Lectures (2 hrs, 2 per week)
    - Tutorials (1 hr, 1 per week)
    - Labs (2 hrs, 1 per week)
- Assessment tasks
    - Exam (50% of final grade)
    - Assignments (2 worth 15% each)
    - Problem Sets (Labs) (1 set per week worth 2% each)
- Where to go for help with course work
    - General help: discourse / tut-labs
    - Specific help: help sessions (starting week 3)
    - Special/Others didn't help: email course account [cs1511@unsw.edu.au](mailto:cs1511@unsw.edu.au)
    - Course page: [https://cgi.cse.unsw.edu.au/~cs1511/current/](https://cgi.cse.unsw.edu.au/~cs1511/current/) (or search `comp1511` on google)
- TigerVNC (VLAB) Alternatives:
    - SSH FS (recommended) [https://abiram.me/cse-setup](https://abiram.me/cse-setup)
    - just SSH (NOT recommended) [https://taggi.cse.unsw.edu.au/FAQ/Logging_In_With_SSH/](https://taggi.cse.unsw.edu.au/FAQ/Logging_In_With_SSH/)

## Linux

### Commands

| Command       | Purpose                                       |
| ------------- | --------------------------------------------- |
| `ls`          | List the contents of a directory              |
| `mkdir`       | Make (create) a new directory                 |
| `cd`          | Open a directory                              |
| `cd ..`       | Go back to the parent directory               |
| `code <file>` | Open/create a file                            |
| `rm`          | Remove a file                                 |
| `rmdir`       | Remove a directory                            |
| `mv`          | Move a file/directory (can be used to rename) |
| `cp`          | Copy a file                                   |
| `touch`       | Create an empty file                          |
| `pwd`         | Print working directory (your current folder) |
| `cat`         | Print contents of a file                      |
| `clear`       | Clears the terminal                           |

### Terminal shortcuts

| Shortcut          | Purpose                                   |
| ----------------- | ----------------------------------------- |
| `up/down key`     | Look through history of commands          |
| `ctrl+shift+v`    | Paste from clipboard                      |
| `ctrl+c`          | Terminate program                         |
| `ctrl+d`          | Send end of file (EOF) to input           |

## C code features

### Comments

- Two ways of commenting:
  - Anything after `//` is treated as a comment
  - Can start a multiline comment with `/*` and end it with `*/`
- Comments are ignored by the compiler
- Generally used to explain a piece of code

```c
// This is a single line comment

/* This is also a single line comment */

/*
This
Is
A
Multiline
Comment
*/
```

### Escape sequences

- `\` followed by a single character forms an "escape sequence"
- These have special meanings when printing
- Some common examples are:
  - `\n` - newline
  - `\\` - literal `\` character
  - `\t` - tab (differs from machine to machine)

### Main function

- Required for the program to compile and run
- For now every program you write should follow this structure

```c
// Header comment
// This should include your name, zid, date
// as well as a short description of the program

int main(void) {
    // Code here
    return 0;
}
```
