//FormAI DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30

int is_alpha(const char c);
void to_lower(char *str);
void trim(char *str);
int spell_check(char *word, char *dict[], int n);

int main(void) {
    char *dict[] = {
        "apple",
        "banana",
        "cat",
        "dog",
        "elephant",
        "fox",
        "goose",
        "house",
        "igloo",
        "jungle",
        "kangaroo",
        "lion",
        "monkey",
        "nectar",
        "ocean",
        "panda",
        "queen",
        "rabbit",
        "sun",
        "tree",
        "unicorn",
        "violet",
        "whale",
        "xylophone",
        "yellow",
        "zebra"
    };
    int n = 26;
    char word[MAX_WORD_LENGTH + 1];
    
    printf("Enter a word: ");
    fgets(word, MAX_WORD_LENGTH + 1, stdin);
    trim(word);
    to_lower(word);
    
    if (spell_check(word, dict, n)) {
        printf("The word is spelled correctly!\n");
    } else {
        printf("The word is spelled incorrectly :(\n");
    }
    
    return 0;
}

int spell_check(char *word, char *dict[], int n) {
    int i;
    char *tmp_word;
    
    tmp_word = malloc((strlen(word) + 1) * sizeof(char));
    if (!tmp_word) {
        perror("memory allocation error");
        exit(EXIT_FAILURE);
    }
    
    strcpy(tmp_word, word);
    to_lower(tmp_word);
    
    for (i = 0; i < n; i++) {
        if (strcmp(tmp_word, dict[i]) == 0) {
            free(tmp_word);
            return 1;
        }
    }
    
    free(tmp_word);
    return 0;
}

int is_alpha(const char c) {
    return isalpha(c) || (c == '\'');
}

void to_lower(char *str) {
    int i;
    
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void trim(char *str) {
    int i, j, k;
    
    for (i = 0; isspace(str[i]); i++);
    if (i > 0) {
        for (j = 0; str[i]; i++, j++) {
            str[j] = str[i];
        }
        str[j] = '\0';
    }
    
    for (i = strlen(str) - 1; isspace(str[i]); i--);
    str[i + 1] = '\0';
}