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

1. Hurdle questions (questions 1-4, worth 48 marks total),
2. Debugging questions (questions 5-8, worth 20 marks total), and
3. Open-ended questions (questions 9-11, worth 32 marks total),

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

#### Counting

### Debugging

#### Compilation Errors

#### Logical Errors

#### Last Resort

### Open-ended
