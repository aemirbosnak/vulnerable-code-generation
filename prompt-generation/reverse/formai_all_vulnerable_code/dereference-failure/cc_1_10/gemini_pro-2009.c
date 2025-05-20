//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Romeo and Juliet
// Romeo and Juliet Word Frequency Counter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet's heart
typedef struct wfreq {
    char* word;
    int freq;
} wfreq;

// A love story
typedef struct wfreq_list {
    wfreq* words;
    int size;
} wfreq_list;

// Create a new wfreq_list
wfreq_list* wfreq_list_create() {
    wfreq_list* list = malloc(sizeof(wfreq_list));
    list->words = NULL;
    list->size = 0;
    return list;
}

// Add a word to the wfreq_list
void wfreq_list_add(wfreq_list* list, char* word) {
    int i;

    // Find the word in the list
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->words[i].word, word) == 0) {
            // Word found, increment frequency
            list->words[i].freq++;
            return;
        }
    }

    // Word not found, add it to the list
    list->words = realloc(list->words, (list->size + 1) * sizeof(wfreq));
    list->words[list->size].word = strdup(word);
    list->words[list->size].freq = 1;
    list->size++;
}

// Print the wfreq_list
void wfreq_list_print(wfreq_list* list) {
    int i;

    for (i = 0; i < list->size; i++) {
        printf("%s: %d\n", list->words[i].word, list->words[i].freq);
    }
}

// Free the wfreq_list
void wfreq_list_free(wfreq_list* list) {
    int i;

    for (i = 0; i < list->size; i++) {
        free(list->words[i].word);
    }

    free(list->words);
    free(list);
}

// Count the words in a file
wfreq_list* word_count(char* filename) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    wfreq_list* list;

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Create a wfreq_list
    list = wfreq_list_create();

    // Read the file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        char* word;

        // Tokenize the line
        word = strtok(line, " \n\t\r");
        while (word != NULL) {
            // Add the word to the list
            wfreq_list_add(list, word);

            // Get the next word
            word = strtok(NULL, " \n\t\r");
        }
    }

    // Free the line
    free(line);

    // Close the file
    fclose(fp);

    return list;
}

// Main function
int main(int argc, char* argv[]) {
    wfreq_list* list;

    // Check for arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Count the words in the file
    list = word_count(argv[1]);

    // Print the wfreq_list
    wfreq_list_print(list);

    // Free the wfreq_list
    wfreq_list_free(list);

    return 0;
}