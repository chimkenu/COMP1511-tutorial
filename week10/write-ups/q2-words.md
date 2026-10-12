# Q2 - Counting Words

> Count the number of words in a given string.

A word is defined to be a (non-empty) sequence of non-whitespace characters separated strictly by a whitespace.
Whitespace characters are space `' '` and newline `'\n'`.

This question uses a string, or a 1d array of characters.

Below is the function prototype to implement:

```c
int count_words(char *string);
```

## Example Usage

Assuming you name the file `q2.c`, you should expect to see:

```
$ dcc q2.c -o q2
$ ./q2
Enter string: Hello, World!
Word count: 2
Enter string: There  are    many    spaces between  these              words.
Word count: 7
Enter string:    g(s@"#w %_QITva~?\25   `uZPWqt|4Y$n E!A   + i918   K6d SRyDxG&k:[ljFrBcV> Opf}0MN])   /X*eb7 3 m;  ',UChH- L=<z.oJ^{   
Word count: 13
Enter string: <ctrl-d>
```

The first string `Hello, World!` contains 2 words. Note that the comma is included in the word `Hello,`,
and the exclamation mark is included in the word `World!`.

The next example, `There  are    many    spaces between  these              words.`, contains 7 words.
Here we wish to account for cases when there are multiple whitespace characters between 'words'.

The final example just includes all printable characters and has leading whitespace.

## Starter Code

```c
#include <stdio.h>

#define MAX_SIZE 2048

int count_words(char *string);

int main(void) {
    char buffer[MAX_SIZE];

    printf("Enter string: ");
    while (fgets(buffer, MAX_SIZE, stdin) != NULL) {
        printf("Word count: %d\nEnter string: ", count_words(buffer));
    }

    return 0;
}

int count_words(char *string) {
    // TODO: Write your solution here!
    return -1;
}
```

## Variations

To test your understanding, see if you can modify your existing code to do the following:

1. Find the length of the longest word.
2. Of the words that you've found, count the number of palindromes
   (words that read the same forwards and backwards).

The second one is annoying.

> Email me if you have any questions about these!

## Solution

[*click me for the full solution*](../sols/q2-words.c)

There are two solutions in the file above. I will explain the first one.
I first wrote a small helper function `is_whitespace` to tell if a given character
is considered a whitespace character. Since the condition is small enough you can
choose to omit this.

```c
int is_whitespace(char c) {
    return c == ' ' || c == '\n';
}
```

It's possible to include tab characters `'\t'` but for the purposes of the problem,
space and newline is enough. Now consider that a word is 'terminated' by spaces,
That is, if we have a sequence of (non-whitespace) characters followed by a whitespace,
that sequence makes up exactly 1 word.

We traverse the string using a counting loop, keeping track of (1) if we are in a word,
and (2) how many words we have encountered thus far. When we encounter a whitespace,
we can use (1) to know if a word has been terminated (that is, we are accounting for double spaces)
and thus add 1 to the count of words.

```c
int words = 0;
int current_word_length = 0;
for (int i = 0; string[i] != '\0'; i++) {
    if (is_whitespace(string[i])) {
        if (current_word_length > 0) {
            words++;
        }
        current_word_length = 0;
    } else {
        current_word_length++;
    }
}
```

Note that at the end of the string you might still be in a word, so you need to account for this.

```c
// ...after the for loop
if (current_word_length > 0) {
    words++;
}
return words;
```

This completes the solution.

Alternatively, the second solution is much shorter (but not as useful for the variations),
as it takes advantage of the fact that you only really need to look out for the 'boundary' between
words. That is, if you encounter a pair consisting of a non-whitespace character followed by a whitespace,
then you have seen exactly one word.

