//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILENAME_LENGTH 255

void display_usage() {
    printf("Usage: wordcount <filename>\n");
}

bool is_whitespace(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

void count_words_in_file(FILE *file, const char *filename) {
    char c;
    int word_count = 0;
    bool in_word = false;

    while ((c = fgetc(file)) != EOF) {
        if (is_whitespace(c)) {
            if (in_word) {
                word_count++;
                in_word = false;
            }
        } else {
            in_word = true;
        }
    }
    
    // If the last character read was a part of a word, count it
    if (in_word) {
        word_count++;
    }

    printf("File: %s\nWord Count: %d\n", filename, word_count);
}

bool valid_filename(const char *filename) {
    if (filename == NULL || strlen(filename) == 0) {
        return false;
    }
    
    for (int i = 0; i < strlen(filename); i++) {
        if (filename[i] == '/' || filename[i] == '\\') {
            return false; // Invalid characters for filename
        }
    }
    
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage();
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    
    if (!valid_filename(filename)) {
        printf("Invalid filename: %s\n", filename);
        return EXIT_FAILURE;
    }
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    count_words_in_file(file, filename);
    
    fclose(file);
    return EXIT_SUCCESS;
}