//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

// A scribe's quill to count the words
void count_words(const char* text, int* word_count, int* line_count) {
    char* current_position = text;
    int in_word = 0;
    *word_count = 0;
    *line_count = 0;

    while (*current_position) {
        if (*current_position == '\n') {
            (*line_count)++;
        }
        
        if ((*current_position == ' ' || *current_position == '\n' || *current_position == '\t') && in_word) {
            (*word_count)++;
            in_word = 0;
        } else if (!(*current_position == ' ' || *current_position == '\n' || *current_position == '\t')) {
            in_word = 1;
        }

        current_position++;
    }

    // In case the text does not end with space
    if (in_word) {
        (*word_count)++;
    }
}

// A function to present the royal scroll
void print_count(int word_count, int line_count) {
    printf("Hear ye, hear ye!\n");
    printf("The count of words inscribed upon this noble scroll is: %d\n", word_count);
    printf("The count of lines traversed in this manuscript is: %d\n", line_count);
    printf("May this knowledge serve thy kingdom well!\n");
}

int main() {
    FILE* scroll;
    char* scroll_text = (char*)malloc(MAX_SIZE);
    int word_count = 0;
    int line_count = 0;

    printf("Enter the name of thy parchment (file) to be inscribed: ");
    char filename[100];
    scanf("%s", filename);

    scroll = fopen(filename, "r");
    if (scroll == NULL) {
        printf("Alas! The scroll could not be found. Check thy parchment name.\n");
        free(scroll_text);
        return 1;
    }

    size_t read_size = fread(scroll_text, 1, MAX_SIZE, scroll);
    scroll_text[read_size] = '\0'; // Make it a string

    fclose(scroll);

    count_words(scroll_text, &word_count, &line_count);
    print_count(word_count, line_count);

    free(scroll_text);
    return 0;
}