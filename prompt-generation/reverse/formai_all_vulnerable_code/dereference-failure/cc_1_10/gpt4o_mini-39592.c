//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define DEFAULT_FILE "input.txt"

typedef struct {
    int word_count;
    int line_count;
    int char_count;
} CountResult;

void initialize_counts(CountResult *counts) {
    counts->word_count = 0;
    counts->line_count = 0;
    counts->char_count = 0;
}

int is_word_boundary(char current, char previous) {
    return (isspace(current) && !isspace(previous)) || (!isspace(current) && isspace(previous));
}

void process_file(FILE *file, CountResult *counts) {
    char buffer[MAX_BUFFER];
    int previous_char_is_space = 1; // Start as if previous character is space

    while (fgets(buffer, MAX_BUFFER, file)) {
        counts->line_count++;
        counts->char_count += strlen(buffer); // Adding the length of current line to character count

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (isspace(buffer[i])) {
                previous_char_is_space = 1;
            } else {
                if (previous_char_is_space) {
                    counts->word_count++;
                }
                previous_char_is_space = 0;
            }
        }
    }
}

void print_counts(CountResult counts, const char *filename) {
    printf("File: %s\n", filename);
    printf("Lines: %d\n", counts.line_count);
    printf("Words: %d\n", counts.word_count);
    printf("Characters: %d\n", counts.char_count);
}

char *get_filename_from_user() {
    char *filename = (char *)malloc(MAX_BUFFER);
    printf("Enter filename (or press Enter for default 'input.txt'): ");
    fgets(filename, MAX_BUFFER, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    if (strlen(filename) == 0) {
        strcpy(filename, DEFAULT_FILE);
    }
    return filename;
}

int main(int argc, char *argv[]) {
    FILE *file;
    CountResult counts;

    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file %s\n", argv[1]);
            return EXIT_FAILURE;
        }
    } else {
        char *filename = get_filename_from_user();
        file = fopen(filename, "r");
        free(filename);
        if (!file) {
            fprintf(stderr, "Could not open default file %s\n", DEFAULT_FILE);
            return EXIT_FAILURE;
        }
    }

    initialize_counts(&counts);
    process_file(file, &counts);
    fclose(file);

    print_counts(counts, argv[1]);

    return EXIT_SUCCESS;
}