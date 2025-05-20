//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DICTIONARY_SIZE 200000

/* Define a struct to contain a dictionary entry */
typedef struct dict_entry {
    char word[50];
} dict_entry;

/* Load the dictionary */
void load_dict(dict_entry *dictionary) {
    FILE *fptr;
    char word[50];
    int i = 0;

    fptr = fopen("dictionary.txt", "r");

    while (fgets(word, 50, fptr) != NULL && i < DICTIONARY_SIZE) {
        /* Remove newline character from word */
        word[strcspn(word, "\n")] = 0;

        /* Copy word into dictionary entry */
        strcpy(dictionary[i].word, word);

        i++;
    }

    fclose(fptr);
}

/* Check if a word is spelled correctly */
int is_spelled_correctly(char *word, dict_entry *dictionary) {
    int i;
    for (i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Main function */
int main() {
    dict_entry dictionary[DICTIONARY_SIZE];
    char word[50];

    /* Load dictionary */
    load_dict(dictionary);

    /* Get input word from user */
    printf("Enter a word to check the spelling: ");
    fgets(word, 50, stdin);

    /* Remove newline character from word */
    word[strcspn(word, "\n")] = 0;

    /* Check if word is spelled correctly */
    if (is_spelled_correctly(word, dictionary)) {
        printf("Spelling is correct!\n");
    } else {
        printf("Spelling is incorrect!\n");
    }

    return 0;
}