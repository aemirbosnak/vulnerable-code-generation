//FormAI DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 10000

void remove_punctuation(char *word) {
    int i, j;
    for (i = 0, j = 0; i < strlen(word); i++, j++) {
        if (ispunct(word[i])) {
            j--;
            continue;
        }
        word[j] = tolower(word[i]);
    }
    word[j] = '\0';
}

int check_spelling(char *word, char *dictionary[], int dict_size) {
    int i;
    for (i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *dictionary[MAX_DICTIONARY_SIZE];
    int dict_size = 0;

    FILE *dict_file = fopen("dictionary.txt", "r");
    if (!dict_file) {
        printf("Failed to open dictionary file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dict_file)) {
        dictionary[dict_size] = (char *) malloc(strlen(line) + 1);
        strcpy(dictionary[dict_size], line);
        dictionary[dict_size][strlen(dictionary[dict_size]) - 1] = '\0';
        dict_size++;
    }

    fclose(dict_file);

    printf("Enter text to check the spelling:\n");

    char word[MAX_WORD_LENGTH];
    while (scanf("%s", word) != EOF) {
        remove_punctuation(word);

        if (!check_spelling(word, dictionary, dict_size)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    return 0;
}