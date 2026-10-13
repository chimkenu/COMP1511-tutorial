#include <stdio.h>

#define MAX_SIZE 2048

int count_words(char *string);

// helper function
int is_whitespace(char c);

int main(void) {
    char buffer[MAX_SIZE];

    printf("Enter string: ");
    while (fgets(buffer, MAX_SIZE, stdin) != NULL) {
        printf("Word count: %d\nEnter string: ", count_words(buffer));
    }

    return 0;
}

int count_words(char *string) {
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

    if (current_word_length > 0) {
        current_word_length++;
    }

    return words;
}

// THIS ONE ALSO WORKS!!
// int count_words(char *string) {
//     int words = 0;
//     for (int i = 1; string[i] != '\0'; i++) {
//         if (!is_whitespace(string[i - 1]) && is_whitespace(string[i])) {
//             words++;
//         }
//     }
//     return words;
// }

int is_whitespace(char c) {
    return c == ' ' || c == '\n';
}

