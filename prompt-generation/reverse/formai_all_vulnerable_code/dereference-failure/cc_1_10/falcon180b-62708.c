//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

struct entry {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

void build_dictionary(char *filename, struct entry *dictionary, int *entries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        if (dictionary[index].frequency == 0) {
            strcpy(dictionary[index].word, word);
            dictionary[index].frequency = 1;
            (*entries)++;
        } else {
            dictionary[index].frequency++;
        }
    }

    fclose(file);
}

int hash(char *word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += tolower(word[i]);
    }
    return sum % MAX_DICTIONARY_SIZE;
}

void spell_check(char *filename, struct entry *dictionary, int entries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        if (dictionary[index].frequency == 0) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary_filename[MAX_WORD_LENGTH];
    strcpy(dictionary_filename, argv[1]);

    char text_filename[MAX_WORD_LENGTH];
    strcpy(text_filename, argv[2]);

    struct entry dictionary[MAX_DICTIONARY_SIZE];
    int entries = 0;

    build_dictionary(dictionary_filename, dictionary, &entries);
    spell_check(text_filename, dictionary, entries);

    return 0;
}