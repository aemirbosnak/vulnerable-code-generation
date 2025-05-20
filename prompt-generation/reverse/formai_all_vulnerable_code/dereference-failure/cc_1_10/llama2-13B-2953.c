//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

void remove_punctuation(char *text) {
    char *p = strtok(text, "!@#$%^&*()_-+\|;:,./");
    char *q;
    while (p != NULL) {
        q = strtok(NULL, "!@#$%^&*()_-+\|;:,./");
        if (q == NULL) {
            break;
        }
        strcpy(p, q);
        p = q;
    }
}

void capitalize_words(char *text) {
    char *p = strtok(text, " ");
    char *q;
    while (p != NULL) {
        q = strtok(NULL, " ");
        if (q == NULL) {
            break;
        }
        *p = toupper(*p);
        p = q;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *text = malloc(MAX_LINE_LENGTH * sizeof(char));
    int line_number = 0;

    // Open input file and read lines
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        perror("Error opening input file");
        return 2;
    }

    while (fgets(text, MAX_LINE_LENGTH, file) != NULL) {
        line_number++;
        remove_punctuation(text);
        capitalize_words(text);
        printf("%d: %s\n", line_number, text);
    }

    // Free memory
    free(text);

    return 0;
}