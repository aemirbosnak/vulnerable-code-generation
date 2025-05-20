//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of words to count
#define MAX_WORDS 1000

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Define the structure of a word
typedef struct word {
    char *word;
    int count;
} word_t;

// Define the structure of the word count tool
typedef struct word_count_tool {
    word_t words[MAX_WORDS];
    int num_words;
} word_count_tool_t;

// Create a new word count tool
word_count_tool_t *word_count_tool_create() {
    word_count_tool_t *tool = malloc(sizeof(word_count_tool_t));
    if (tool == NULL) {
        return NULL;
    }

    tool->num_words = 0;

    return tool;
}

// Destroy a word count tool
void word_count_tool_destroy(word_count_tool_t *tool) {
    for (int i = 0; i < tool->num_words; i++) {
        free(tool->words[i].word);
    }

    free(tool);
}

// Add a word to the word count tool
int word_count_tool_add_word(word_count_tool_t *tool, char *word) {
    // Check if the word is already in the tool
    for (int i = 0; i < tool->num_words; i++) {
        if (strcmp(tool->words[i].word, word) == 0) {
            tool->words[i].count++;
            return 0;
        }
    }

    // Check if the tool is full
    if (tool->num_words == MAX_WORDS) {
        return -1;
    }

    // Add the word to the tool
    tool->words[tool->num_words].word = strdup(word);
    tool->words[tool->num_words].count = 1;
    tool->num_words++;

    return 0;
}

// Print the word count tool
void word_count_tool_print(word_count_tool_t *tool) {
    for (int i = 0; i < tool->num_words; i++) {
        printf("%s: %d\n", tool->words[i].word, tool->words[i].count);
    }
}

// Main function
int main(int argc, char **argv) {
    // Create a new word count tool
    word_count_tool_t *tool = word_count_tool_create();
    if (tool == NULL) {
        fprintf(stderr, "Error: Could not create word count tool\n");
        return EXIT_FAILURE;
    }

    // Add the words from the command line arguments to the tool
    for (int i = 1; i < argc; i++) {
        if (word_count_tool_add_word(tool, argv[i]) != 0) {
            fprintf(stderr, "Error: Could not add word to tool\n");
            word_count_tool_destroy(tool);
            return EXIT_FAILURE;
        }
    }

    // Print the word count tool
    word_count_tool_print(tool);

    // Destroy the word count tool
    word_count_tool_destroy(tool);

    return EXIT_SUCCESS;
}