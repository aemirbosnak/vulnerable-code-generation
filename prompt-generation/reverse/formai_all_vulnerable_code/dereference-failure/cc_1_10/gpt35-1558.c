//FormAI DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the input string.

char *read_input() {
    char *input = calloc(MAX_SIZE, sizeof(char));
    printf("Enter your sentence: ");
    fgets(input, MAX_SIZE, stdin);
    return input;
}

char **get_words(char *input, int *word_count) {
    char **words = calloc(MAX_SIZE, sizeof(char*));
    char *token = strtok(input, " ");
    while (token != NULL) {
        words[*word_count] = token;
        (*word_count)++;
        token = strtok(NULL, " ");
    }
    return words;
}

char *sanitize_word(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            memmove(word+i, word+i+1, len-i);
            len--;
        }
        else {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}

int spell_check(char **dictionary, int dict_size, char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char **dictionary = calloc(MAX_SIZE, sizeof(char*));
    int dict_size = 0;

    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), file)) {
        dictionary[dict_size] = calloc(MAX_SIZE, sizeof(char));
        strcpy(dictionary[dict_size], line);
        dict_size++;
    }
    fclose(file);

    char *input = read_input();
    int word_count = 0;
    char **words = get_words(input, &word_count);

    printf("The following words are misspelled:\n");
    for (int i = 0; i < word_count; i++) {
        char *word = sanitize_word(words[i]);
        if (!spell_check(dictionary, dict_size, word)) {
            printf("%s\n", word);
        }
    }

    for(int i = 0; i < dict_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    free(input);
    free(words);
    
    return 0;
}