//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void love_from_words(const char *filename);
void embrace_strlen(const char *str, int *word_count, int *char_count);
int is_delimiter(char ch);

int main() {
    const char *filename = "love_letters.txt"; // A note filled with words of affection
    love_from_words(filename);
    return 0;
}

void love_from_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (!file) {
        printf("Oh! My heart aches, for I cannot find the love letter...\n");
        return;
    }

    int word_count = 0, char_count = 0;
    char *line = NULL;
    size_t len = 0;

    printf("Gathering every sweet phrase from the pages of affection...\n");

    while (getline(&line, &len, file) != -1) {
        embrace_strlen(line, &word_count, &char_count);
    }
    
    printf("In the realm of ink, it seems that there were %d enchanting words...\n", word_count);
    printf("And in those words, I have counted %d delicate letters whispered...\n", char_count);

    // Cleanup
    free(line);
    fclose(file);
}

void embrace_strlen(const char *str, int *word_count, int *char_count) {
    int in_word = 0;
    const char *ptr = str;

    while (*ptr) {
        if (is_delimiter(*ptr)) {
            if (in_word) {
                in_word = 0;
                (*word_count)++;
            }
        } else {
            in_word = 1;
            (*char_count)++;
        }
        ptr++;
    }

    // If still inside a word at end of line
    if (in_word) {
        (*word_count)++;
    }
}

int is_delimiter(char ch) {
    return isspace(ch) || ispunct(ch);
}