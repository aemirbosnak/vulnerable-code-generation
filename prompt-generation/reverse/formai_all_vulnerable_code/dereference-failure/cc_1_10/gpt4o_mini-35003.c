//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

void to_uppercase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void process_text(FILE *file) {
    char *lines[MAX_LINES];
    char buffer[MAX_LENGTH];
    int count = 0;

    while (fgets(buffer, MAX_LENGTH, file) && count < MAX_LINES) {
        lines[count] = malloc(strlen(buffer) + 1);
        if (lines[count] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        strcpy(lines[count], buffer);
        count++;
    }

    printf("Original Text:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }

    printf("\nConverted to Uppercase:\n");
    for (int i = 0; i < count; i++) {
        to_uppercase(lines[i]);
        printf("%d: %s", i + 1, lines[i]);
    }

    printf("\nConverted to Lowercase:\n");
    for (int i = 0; i < count; i++) {
        to_lowercase(lines[i]);
        printf("%d: %s", i + 1, lines[i]);
    }

    printf("\nReversed Lines:\n");
    for (int i = 0; i < count; i++) {
        reverse_string(lines[i]);
        printf("%d: %s", i + 1, lines[i]);
    }

    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    process_text(file);
    fclose(file);
    return EXIT_SUCCESS;
}