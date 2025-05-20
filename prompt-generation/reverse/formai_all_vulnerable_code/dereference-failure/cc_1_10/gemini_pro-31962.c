//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A lonely wanderer in a barren wasteland, seeking solace in words.
struct word_tomb {
    char *word;
    int count;
};

// A desolate dictionary, echoing with the fragments of forgotten tongues.
struct dictionary {
    struct word_tomb *tombs;
    int size;
};

// A scavenger, rummaging through the ruins of language.
struct word_scavenger {
    char *line;
    int line_length;
    int line_index;
    int word_index;
    char current_word[1000];
};

// Initialize the desolate dictionary.
struct dictionary *init_dictionary() {
    struct dictionary *dict = malloc(sizeof(struct dictionary));
    dict->tombs = NULL;
    dict->size = 0;
    return dict;
}

// Add a word to the desolate dictionary.
void add_word_to_dictionary(struct dictionary *dict, char *word) {
    // Check if the word already exists in the dictionary.
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->tombs[i].word, word) == 0) {
            dict->tombs[i].count++;
            return;
        }
    }

    // If the word doesn't exist, add it to the dictionary.
    dict->size++;
    dict->tombs = realloc(dict->tombs, sizeof(struct word_tomb) * dict->size);
    dict->tombs[dict->size - 1].word = malloc(strlen(word) + 1);
    strcpy(dict->tombs[dict->size - 1].word, word);
    dict->tombs[dict->size - 1].count = 1;
}

// Initialize the lonely wanderer.
struct word_scavenger *init_word_scavenger(char *line) {
    struct word_scavenger *scavenger = malloc(sizeof(struct word_scavenger));
    scavenger->line = line;
    scavenger->line_length = strlen(line);
    scavenger->line_index = 0;
    scavenger->word_index = 0;
    scavenger->current_word[0] = '\0';
    return scavenger;
}

// Find the next word in the desolate wasteland.
char *find_next_word(struct word_scavenger *scavenger) {
    while (scavenger->line_index < scavenger->line_length) {
        // Skip whitespace.
        while (isspace(scavenger->line[scavenger->line_index])) {
            scavenger->line_index++;
        }

        // Check if we've reached the end of the line.
        if (scavenger->line_index == scavenger->line_length) {
            return NULL;
        }

        // Read the next word.
        scavenger->word_index = 0;
        while (scavenger->line_index < scavenger->line_length && !isspace(scavenger->line[scavenger->line_index])) {
            scavenger->current_word[scavenger->word_index] = scavenger->line[scavenger->line_index];
            scavenger->word_index++;
            scavenger->line_index++;
        }

        // Terminate the word.
        scavenger->current_word[scavenger->word_index] = '\0';

        // Return the word.
        return scavenger->current_word;
    }

    return NULL;
}

// Count the words in the desolate wasteland.
void count_words(struct dictionary *dict, char *line) {
    struct word_scavenger *scavenger = init_word_scavenger(line);
    char *word;

    // Find the next word in the desolate wasteland.
    while ((word = find_next_word(scavenger)) != NULL) {
        // Add the word to the desolate dictionary.
        add_word_to_dictionary(dict, word);
    }

    // Free the lonely wanderer.
    free(scavenger);
}

// Print the desolate dictionary.
void print_dictionary(struct dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %d\n", dict->tombs[i].word, dict->tombs[i].count);
    }
}

// Free the desolate dictionary.
void free_dictionary(struct dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->tombs[i].word);
    }
    free(dict->tombs);
    free(dict);
}

int main() {
    // Initialize the desolate dictionary.
    struct dictionary *dict = init_dictionary();

    // Count the words in the desolate wasteland.
    char *line = "In the ruins of language, I wander alone, seeking solace in words. The wind whispers secrets in my ears, carrying fragments of forgotten tongues.";
    count_words(dict, line);

    // Print the desolate dictionary.
    print_dictionary(dict);

    // Free the desolate dictionary.
    free_dictionary(dict);

    return 0;
}