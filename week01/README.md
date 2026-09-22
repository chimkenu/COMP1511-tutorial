# COMP1511 Tutorial - Week 01

## Admin stuff

- Course structure
    - Lectures (2 hrs, 2 per week)
    - Tutorials (1 hr, 1 per week)
    - Labs (2 hrs, 1 per week)
- Assessment tasks
    - Exam (40% of final grade)
    - Assignment 1 (20%)
    - Assignment 2 (25%)
    - Problem Sets (Labs) (1 set per week worth 2% each, up to 15%)
- Where to go for help with course work
    - General help: course forum / tut-labs
    - Specific help: help sessions, drop-in sessions, revision sessions (starting around week 3)
    - Special/Others didn't help: email course account [cs1511@unsw.edu.au](mailto:cs1511@unsw.edu.au)
    - Course page: [https://cgi.cse.unsw.edu.au/~cs1511/current/](https://cgi.cse.unsw.edu.au/~cs1511/current/) (or search `comp1511` on google)
- TigerVNC (VLAB) Alternatives:
    - SSH FS (recommended) [https://abiram.me/cse-setup](https://abiram.me/cse-setup)
    - just SSH (NOT recommended) [https://taggi.cse.unsw.edu.au/FAQ/Logging_In_With_SSH/](https://taggi.cse.unsw.edu.au/FAQ/Logging_In_With_SSH/)

## Linux

In COMP1511, you will be working a Linux environment.
To put it very simply, [Linux](https://en.wikipedia.org/wiki/Linux) is a family of operating systems.
Maybe you've heard it's a kernel, but for the purposes of COMP1511, what you will actually be interacting
with that is 'different' from what you are normally used to in your own personal computers
is the [POSIX](https://en.wikipedia.org/wiki/POSIX)-compliant [shell](https://en.wikipedia.org/wiki/Shell_(computing)),
or **terminal**. This is where you will be compiling and running your code.

You can imagine the terminal like a text-based version of your file explorer with a little more functionality.

### Commands

| Command       | Purpose                                       |
| ------------- | --------------------------------------------- |
| `ls`          | List the contents of a directory              |
| `mkdir`       | Make (create) a new directory                 |
| `cd`          | Open/Move to a directory                      |
| `cd ..`       | Go back to the parent directory               |
| `code`        | Open/create a file                            |
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

## Additional Material

I recommend at this stage to get familiar with the environment you will be working in.

Here are some things that might be useful to you before you continue on.

### Organisation

I recommend you create a new directory specifically for your COMP1511/1911 work.
It usually looks like this:
```
$ mkdir 1511
$ cd 1511
$ mkdir week01
$ cd week01
```
After running these commands, you now have a 1511 directory in your home directory.
Personally, I have my files stored in the `~/Documents` directory.

When you do this, remember to `cd ~/1511/week01` (or wherever you made it) to access your work.

### Useful commands and shortcuts

If you have finished the problem set for this week, you may have realised that you
used a few new commands that weren't discussed in the tutorial (i.e. `give` and `1511`)

A few useful commands to know going forward are:
- `1511 style <file>` checks the [style](https://cgi.cse.unsw.edu.au/~cs1511/current/resources/style_guide.html) of your code.
- `1511 autotest-help` or just `autotest-help` provides some helpful feedback on your most recent autotest (if something failed).

