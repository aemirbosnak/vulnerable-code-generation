//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

bool is_palindrome(const char* word);
void remove_whitespace(char* line);
int count_words(const char* line);

int main() {
    char line[MAX_LINE_LENGTH];
    printf("Enter a line of text:\n");
    fgets(line, MAX_LINE_LENGTH, stdin);
    remove_whitespace(line);
    int num_words = count_words(line);
    printf("Line contains %d words.\n", num_words);
    for (int i = 0; i < num_words; i++) {
        char word[MAX_WORD_LENGTH];
        char* token = strtok(line, " ");
        strcpy(word, token);
        if (is_palindrome(word)) {
            printf("Word %d is a palindrome.\n", i + 1);
        } else {
            printf("Word %d is not a palindrome.\n", i + 1);
        }
    }
    return 0;
}

bool is_palindrome(const char* word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i])!= tolower(word[length - i - 1])) {
            return false;
        }
    }
    return true;
}

void remove_whitespace(char* line) {
    int length = strlen(line);
    int new_length = 0;
    for (int i = 0; i < length; i++) {
        if (!isspace(line[i])) {
            line[new_length] = line[i];
            new_length++;
        }
    }
    line[new_length] = '\0';
}

int count_words(const char* line) {
    int count = 0;
    int length = strlen(line);
    for (int i = 0; i < length; i++) {
        if (isspace(line[i])) {
            count++;
        }
    }
    return count + 1;
}