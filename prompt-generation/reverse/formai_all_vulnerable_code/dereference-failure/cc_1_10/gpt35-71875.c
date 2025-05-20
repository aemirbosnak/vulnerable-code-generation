//FormAI DATASET v1.0 Category: Spam Detection System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *word;
    int count;
} DictEntry;

// Function declarations
int is_spam(char *text, DictEntry *dictionary, int dict_size);
int get_word_index(char *word, DictEntry *dictionary, int dict_size);
void add_to_dictionary(char *word, DictEntry *dictionary, int *dict_size);
int compare_entries(const void *a, const void *b);

int main() {
    // Initialize dictionary
    int dict_size = 0;
    DictEntry *dictionary = malloc(sizeof(DictEntry) * 1000);

    // Read in spam_words.txt file and add entries to dictionary
    FILE *spam_words_file = fopen("spam_words.txt", "r");
    if (spam_words_file == NULL) {
        printf("Error opening spam_words.txt file!\n");
        exit(1);
    }
    char word[100];
    while (fscanf(spam_words_file, "%s", word) == 1) {
        add_to_dictionary(word, dictionary, &dict_size);
    }
    fclose(spam_words_file);

    // Test spam detection
    char text[1000];
    printf("Enter some text: ");
    fgets(text, 1000, stdin);
    int result = is_spam(text, dictionary, dict_size);
    if (result) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    // Free dictionary memory
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i].word);
    }
    free(dictionary);

    return 0;
}

// Determines if the given text contains any spam words
int is_spam(char *text, DictEntry *dictionary, int dict_size) {
    // Tokenize text into words using whitespace as delimiter
    char *word;
    word = strtok(text, " \n\t\r\f");
    while (word != NULL) {
        // Check if word exists in dictionary
        int index = get_word_index(word, dictionary, dict_size);
        if (index != -1) {
            // Word found in dictionary, increment count
            dictionary[index].count++;
            if (dictionary[index].count >= 3) {
                // Word has appeared at least 3 times, consider it spam
                return 1;
            }
        }
        // Get next word
        word = strtok(NULL, " \n\t\r\f");
    }
    return 0;
}

// Returns the index of the given word in the dictionary, or -1 if not found
int get_word_index(char *word, DictEntry *dictionary, int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return i;
        }
    }
    return -1;
}

// Adds the given word to the dictionary if it does not already exist
void add_to_dictionary(char *word, DictEntry *dictionary, int *dict_size) {
    int index = get_word_index(word, dictionary, *dict_size);
    if (index == -1) {
        // Word not found in dictionary, add it
        dictionary[*dict_size].word = malloc(sizeof(char) * (strlen(word) + 1));
        strcpy(dictionary[*dict_size].word, word);
        dictionary[*dict_size].count = 0;
        (*dict_size)++;
    }
}

// Comparison function used for sorting dictionary by word count in descending order
int compare_entries(const void *a, const void *b) {
    const DictEntry *entry_a = (const DictEntry *) a;
    const DictEntry *entry_b = (const DictEntry *) b;
    if (entry_a->count > entry_b->count) {
        return -1;
    } else if (entry_a->count < entry_b->count) {
        return 1;
    } else {
        return 0;
    }
}