//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Linus Torvalds
/*
 *	C Word Frequency Counter 9000
 *	Version 1.0
 *	Author: Linus Torvalds Jr.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define WORD_SIZE 256

// Function prototypes
void print_title();
void print_instructions();
void count_words(char* filename, char* word);

int main(int argc, char* argv[]) {
    char* word;

    // set default word
    word = "hello";

    // Check for valid arguments
    if (argc < 2) {
        printf("Usage: %s filename [word]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check if word argument was provided
    if (argc == 3) {
        word = argv[2];
    }

    // Print title
    print_title();

    // Print instructions
    print_instructions();

    // Print word being counted
    printf("Counting occurances of the word '%s' in %s\n\n", word, argv[1]);

    // Count words
    count_words(argv[1], word);

    return EXIT_SUCCESS;
}

/*
 *  Prints the program title
 */
void print_title() {
    printf("\n=============================================\n");
    printf("C Word Frequency Counter 9000\n");
    printf("=============================================\n\n");
}

/*
 *  Prints program instructions
 */
void print_instructions() {
    printf("Instructions:\n");
    printf("  * Enter a word to count occurances of\n");
    printf("  * The program will count the number of times the word appears in a file\n");
    printf("  * Word is optional, if not provided the word 'hello' will be used\n\n");
}

/*
 *  Counts the occurances of a given word in a file
 *  filename: The file to search for the word
 *  word: The word to count occurances of
 */
void count_words(char* filename, char* word) {
    FILE* file;
    char buffer[BUFFER_SIZE];
    char* p;
    char c;
    int i, j, k;
    int count = 0;
    int word_len = strlen(word);

    // Open file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Read file character by character
    i = 0;
    while ((c = fgetc(file)) != EOF) {
        buffer[i++] = (char) c;

        // Check buffer length
        if (i >= BUFFER_SIZE) {
            printf("ERROR: Buffer overflow\n");
            exit(EXIT_FAILURE);
        }

        // Check if buffer contains word
        if (isspace(c) || c == '-') {
            buffer[i-1] = '\0'; // replace whitespace with null terminiator
            p = buffer;

            while (*p != '\0') {
                // Check if word is found
                if (strncmp(p, word, word_len) == 0) {
                    count++;
                }

                // Move to next word in buffer
                while (*p != '\0' && !isspace(*p) && *p != '-') {
                    p++;
                }

                // Move to next non-whitespace character
                while (*p != '\0' && (isspace(*p) || *p == '-')) {
                    p++;
                }

                if (*p == '\0') {
                    break;
                }
            }

            // Reset buffer
            i = 0;
        }
    }

    // Check if buffer contains last word
    if (i > 0) {
        buffer[i] = '\0'; // add null terminator to end of buffer
        p = buffer;

        while (*p != '\0') {
            // Check if word is found
            if (strncmp(p, word, word_len) == 0) {
                count++;
            }

            // Move to next word in buffer
            while (*p != '\0' && !isspace(*p) && *p != '-') {
                p++;
            }

            // Move to next non-whitespace character
            while (*p != '\0' && (isspace(*p) || *p == '-')) {
                p++;
            }

            if (*p == '\0') {
                break;
            }
        }
    }

    // Close file
    fclose(file);

    // Print results
    printf("'%s' appears %d times in %s\n", word, count, filename);
}