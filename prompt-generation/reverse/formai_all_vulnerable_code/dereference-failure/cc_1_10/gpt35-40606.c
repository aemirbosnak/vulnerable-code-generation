//FormAI DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define DICT_SIZE 10000 // Maximum dictionary size
#define HASH_SIZE 200   // Size of hash table

// Structure for hash table
struct entry {
    char word[30];
    struct entry *next;
};

struct entry *hash_table[HASH_SIZE] = { NULL }; // Initialize hash table to NULL

// Hash function
unsigned int hash(const char *word) {
    unsigned int hash_val = 0;

    while (*word) {
        hash_val = (hash_val << 5) + *word++;
    }

    return hash_val % HASH_SIZE;
}

// Load dictionary into hash table
void load_dict(const char *filename) {
    FILE *f = fopen(filename, "r");

    if (f == NULL) {
        printf("Error: Could not open dictionary file %s\n", filename);
        exit(1);
    }

    char word[30];

    while (fscanf(f, "%s", word) != EOF) {
        struct entry *e = malloc(sizeof(struct entry));
        strcpy(e->word, word);
        int h = hash(word);
        e->next = hash_table[h];
        hash_table[h] = e;
    }

    fclose(f);
}

// Check spelling of given word
int check_word(const char *word) {
    char lower[30];

    // Convert word to lowercase
    for (int i = 0; word[i]; i++) {
        lower[i] = tolower(word[i]);
    }

    int h = hash(lower);
    struct entry *e = hash_table[h];

    while (e != NULL) {
        if (strcmp(lower, e->word) == 0) {
            return 1; // Word found in dictionary
        }
        e = e->next;
    }

    return 0; // Word not found in dictionary
}

int main() {
    char word[30];

    load_dict("dictionary.txt");

    while (1) {
        printf("\nEnter a word (or 'q' to quit): ");
        scanf("%s", word);

        if (strcmp(word, "q") == 0) {
            break; // Quit program
        }

        if (check_word(word)) {
            printf("%s is spelled correctly!\n", word);
        } else {
            printf("%s is spelled incorrectly!\n", word);

            // Suggestions for misspelled word
            printf("Suggestions:\n");

            // Generate all possible combinations of the misspelled word
            int len = strlen(word);
            char temp[30];

            for (int i = 0; i < len; i++) {
                // Delete a character
                strcpy(temp, word);
                memmove(&temp[i], &temp[i+1], len-i);
                if (check_word(temp)) {
                    printf("%s\n", temp);
                }

                // Replace a character
                for (char c = 'a'; c <= 'z'; c++) {
                    strcpy(temp, word);
                    temp[i] = c;
                    if (check_word(temp)) {
                        printf("%s\n", temp);
                    }
                }

                // Insert a character
                for (char c = 'a'; c <= 'z'; c++) {
                    strcpy(temp, word);
                    memmove(&temp[i+1], &temp[i], len-i);
                    temp[i] = c;
                    if (check_word(temp)) {
                        printf("%s\n", temp);
                    }
                }
            }
        }
    }

    return 0;
}