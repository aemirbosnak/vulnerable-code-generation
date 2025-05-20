//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if a character is alphabetic
bool is_alpha(char c) {
    return (isalpha(c) || isalpha(tolower(c)));
}

// Function to count words in a string
int count_words(const char *str, const char *word) {
    int count = 0;
    bool in_word = false;

    for (const char *p = str; *p; ++p) {
        if (is_alpha(*p)) {
            if (!in_word) {
                if (strcmp(p, word) == 0) {
                    ++count;
                    in_word = true;
                } else {
                    in_word = false;
                }
            }
        }
    }

    if (in_word && strrchr(str, ' ') != str) {
        ++count;
    }

    return count;
}

// Function to read a file and count occurrences of a word
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    size_t nread;
    int count = 0;

    while ((nread = fread(buffer, sizeof(char), sizeof(buffer), fp))) {
        if (nread > 0) {
            for (size_t i = 0; i < nread; ++i) {
                buffer[i] = tolower(buffer[i]);
            }
            count += count_words(buffer, argv[2]);
            fseek(fp, -nread, SEEK_CUR);
        }
    }

    if (ferror(fp)) {
        perror("Error reading file");
        fclose(fp);
        return 1;
    }

    fclose(fp);

    printf("Thank you for using this word count tool!\n");
    printf("The word '%s' occurs %d times in the file '%s'.\n", argv[2], count, argv[1]);

    return 0;
}