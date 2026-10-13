# COMP1511 Tutorial - Week 10
---

> [!Warning]
> This is still a work in progress! I am hoping to finish writing this by the start of week 10.
> Since this is very new, there *might* be some typos or mistakes in the write-ups or solutions.
> Please [email me](mailto:z5559853@ad.unsw.edu.au) if you catch any errors or have any suggestions!!!
> Thanks for reading :D

## Congratulations

...for making it this far!

At this point, you should be familiar with most if not all of the
content this course has to offer, as you have been (hopefully) applying
what you have learned in the two assignments.

This week has no new content to go over, so this week we will be
going over some practice questions to prepare for upcoming final exam.

Here, I will be going over some final exam problems you may encounter
(in some form), and how to approach *unseen* or new problems.

## Overview

The COMP1511 final exam has 11 questions, typically divided into:

1. [Hurdle questions](#Hurdles) (questions 1-4, worth 48 marks total),
2. [Debugging questions](#Debugging) (questions 5-8, worth 20 marks total), and
3. [Open-ended questions](#Open-ended) (questions 9-11, worth 32 marks total),

for a total of 100 marks.

From the mark distribution, it is clear that the hurdle questions
are the most important ones to get. It is also drilled into you
that you **must** pass at least one of each kind of hurdle question.
Thus, most of this document will be dedicated to solving these kinds of questions.

The next most valuable type of question (in terms of marks) are the open-ended ones,
though these are kind of a mixed bag to solve (we'll get into it later).

Finally we have the debugging questions, surprisingly only worth 5 marks each
(I did not know that before typing this up). These are *generally* easier to
solve than the hurdle questions though are easy to get tripped up on.

## Solving Questions

After reading a question, I advise you *categorise* it
and *filter* the important information.

- Is it about `array`s or `linked list`s? (or `string`s, but you can group that into arrays I suppose)
- What is it asking for? What is the expected return type (if applicable)?
- Are there any libraries/features that are explicitly not allowed to be used?

Once you have a general idea on what the question is asking for,
one way to see how far along you are to a solution is to check:

0. Have I seen this question (or one suspiciously similar to this) before?
1. Do I have a solution I can do by hand?
2. If not, can I verify a solution/output is correct?
3. Otherwise, can I solve a trivial/simple input case by hand?

### Hurdles

Hurdle questions are categorised by the data structure that they require you to use.
Despite this, I actually think it is more useful to categorise the question by the operation that you will use,
as there are operations that are common between these data structures.

#### Searching

A search operation involves looking for (the existence or non-existence of) an element.
Whenever a question is asking you to check if a list contains or does not contain
a particular element (or group of), you will definitely implement a search operation.

What makes searching operations difficult may be implementing the condition for finding
the relevant element.

> **Q1.** Given a list of (strictly positive) integers, return the first prime number. If the list does not contain any primes, return -1.

[*click me for the full question 1*](write-ups/q1-primes.md)

The above question can appear as a 1D array or linked list hurdle. 

```c
// 1D ARRAY VERSION
int find_prime_array(int arr[], int size);

// LINKED LIST VERSION
int find_prime_list(struct node *head);
```

I **highly** suggest you make an attempt to solve these problems.
Most of the learning comes from doing, and not reading the solution.

Searching algorithms usually use a loop and a condition. Like:

```c
for (int i = 0; i < size; i++) {
    if (some_condition(arr[i])) {
        return 1; // found it!
        // you usually exit the loop here since youve found it already
    }
}
return 0; // i did not find it :(
```

Where `some_condition(arr[i])` returns true or false (1 or 0) given the *i*th element of an array.
It's sometimes helpful to make a helper function as conditions are sometimes more complicated than just
a single comparison.

#### Counting

Some problems may ask you to count, sum, or otherwise find an aggregate of a given list.

Simple examples include finding the sum of all elements of an integer array/linked list, or
[counting the number of prime numbers in a list](write-ups/q1-primes.md#Variations).

I suggest you attempt the above variation before moving on.

Solutions to counting problems usually involve looping over the data structure
and keeping track of the aggregate (sum, count, etc.) in a separate variable.

```c
// example over 2d array
int count = 0; // start with reasonable initial value.
               // sums and counts start at 0 but products should start at 1
// 2d loop over array
for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
        // at this point we are looking at the element arr[row][col]
        if (some_condition(arr[row][col])) {
            count++; // increase count if the current element (arr[row][col])
                     // matches a certain condition
        }
    }
}
return count; // after the 2d loop, we would have checked all elements,
              // and thus the count variable must match the true count (of whatever we are counting)
```

Sometimes you might have to keep track of what you've seen before.
In this case, you might have to either store a [flag](https://www.geeksforgeeks.org/dsa/use-of-flag-in-programming/)
in a variable or do some computation with the previous elements.

> **Q2.** Count the number of words in a given string.

[*click me for the full question 2*](write-ups/q2-words.md)

> **Q3.** Find the number of unique numbers in a given list.

[*click me for the full question 3*](write-ups/q3-unique.md)

Finally, the condition might involve more than a single element.
That is, you may need to consider surrounding data/elements in your list.

> **Q4.** Given a 2D array of doubles, find the number of *critical points*.

[*click me for the full question 4*](write-ups/q4-crit.md)

#### Insertion or Deletion

This problem is unique to linked list hurdles (though it is possible to do them in arrays).
You might be asked to insert or delete an element at a particular position or between two elements
with a certain property. 



### Debugging

Debugging questions are worth the least marks but should take less time
than hurdle questions. This is because you are given starter code that
is close to the true solution, with only a handful of errors.

#### Syntax Errors

This kind of error is caught by the compiler, and the easiest to resolve.
You usually start with these errors. I would always try to compile the
solution first, and resolve any errors the compiler raises. For example:

```c
int a
scan("%c", a);
```

The code above has 4 syntax errors, all of which a compiler will complain about.
Eventually, despite resolving all the syntax errors in the starter code,
the program may still be incorrect because of:

#### Logical Errors

This kind of error occurs when the algorithm or program itself does not
arrive at the correct output. This is caused usually by:
1. Incorrect order of operations
2. Rounding errors
3. Overflow or underflow
Note that this list is not exhaustive.

To resolve these, you need to know what the program is trying to do.

#### Last Resort

If you can't seem to appease the compiler or see what the logical error might be,
nobody is stopping you from writing the entire program yourself.

Since the problem is also given, you can treat this like an hurdle/open-ended
question, and just write code from scratch. Though, this kind of defeats the
spirit of the problem.

### Open-ended

Now I don't actually know what they're called (or if these type of questions even have a name), but I call
them open-ended questions because they *sometimes* (1) do not give you any starter code, and (2) let you decide
which of the two data structures to use to solve the problem instead of imposing one on you. I have seen q10s and 11s
that do not meet this criteria so `¯\_(ツ)_/¯`.

