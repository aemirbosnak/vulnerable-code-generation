//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverse(char *str) {
    int len = strlen(str);
    char *rev = (char *)malloc(len + 1);
    int i = 0;
    for (int j = len - 1; j >= 0; j--) {
        rev[i++] = tolower(str[j]);
    }
    rev[i] = '\0';
    printf("Reversed string: %s\n", rev);
    free(rev);
}

void remove_vowels(char *str) {
    int len = strlen(str);
    char *new_str = (char *)malloc(len + 1);
    int i = 0;
    for (int j = 0; j < len; j++) {
        if (!isalpha(str[j])) {
            new_str[i++] = str[j];
        }
    }
    new_str[i] = '\0';
    printf("String with vowels removed: %s\n", new_str);
    free(new_str);
}

void count_words(char *str) {
    int len = strlen(str);
    int word_count = 0;
    int space_count = 0;
    int in_word = 0;
    for (int i = 0; i < len; i++) {
        if (isspace(str[i])) {
            space_count++;
            in_word = 0;
        } else {
            in_word = 1;
        }
        if (in_word && space_count > 0) {
            word_count++;
            space_count = 0;
        }
    }
    if (in_word) {
        word_count++;
    }
    printf("Number of words: %d\n", word_count);
}

void main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverse(str);
    remove_vowels(str);
    count_words(str);
}