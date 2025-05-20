//LLAMA2-13B DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT_MAX 100000

// Declare a magic wand to count words
struct WordWand {
    int word_count;
    char* buffer;
};

// Function to cast a spell and count words
void cast_spell(struct WordWand* wand) {
    char line[100];
    int i, j;

    // Read a line from the user
    printf("Speak a line, my dear wizard:\n");
    fgets(line, 100, stdin);

    // Remove trailing newline and whitespace
    for (i = strcspn(line, "\n\r"); i < strlen(line); i++) {
        if (isspace(line[i])) {
            line[i] = '\0';
        }
    }

    // Count the words in the line
    for (j = 0; j < strcspn(line, " \t\r\n"); j++) {
        if (!isspace(line[j])) {
            wand->word_count++;
        }
    }

    // Add the word count to the wand
    wand->word_count += j;

    // Print the wand's magic message
    printf("Your word count is %d, my dear wizard!\n", wand->word_count);
}

int main() {
    struct WordWand wand;

    // Initialize the wand with a magic message
    wand.word_count = 0;
    wand.buffer = malloc(100);
    strcpy(wand.buffer, "May the words be with you!");

    // Cast spells until the user says "stop"
    while (1) {
        cast_spell(&wand);
        printf("Continue? (y/n): ");
        char c = getchar();
        if (c == 'n') {
            break;
        }
    }

    // Free the wand's memory
    free(wand.buffer);

    return 0;
}