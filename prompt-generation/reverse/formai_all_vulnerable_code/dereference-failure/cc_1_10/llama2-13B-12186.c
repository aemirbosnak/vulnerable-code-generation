//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

void sort_words(char *text);
void remove_duplicates(char *text);
void print_unique_words(char *text);

int main() {
    char *text = "This is an example text for testing the program.";
    sort_words(text);
    remove_duplicates(text);
    print_unique_words(text);
    return 0;
}

void sort_words(char *text) {
    char *word = strtok(text, " ");
    while (word != NULL) {
        char *temp = word;
        while (*temp != ' ' && *temp != '\0') {
            temp++;
        }
        word = temp + 1;
        strtok(NULL, " ");
    }
}

void remove_duplicates(char *text) {
    char *word = strtok(text, " ");
    char *previous = NULL;
    while (word != NULL) {
        if (previous == NULL || strcmp(word, previous) != 0) {
            if (previous != NULL) {
                strcpy(previous, word);
            } else {
                previous = word;
            }
        }
        word = strtok(NULL, " ");
    }
}

void print_unique_words(char *text) {
    char *word = strtok(text, " ");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
}