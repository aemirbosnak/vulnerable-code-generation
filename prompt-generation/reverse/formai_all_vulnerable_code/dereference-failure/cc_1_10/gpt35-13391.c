//FormAI DATASET v1.0 Category: Spell checking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 30

char *get_input_text() {
    char *input_text = (char *)malloc(sizeof(char) * 1000);
    printf("Enter some text:\n");
    fgets(input_text, 1000, stdin);

    return input_text;
}

char *get_dictionary() {
    char *dictionary_text = (char *)malloc(sizeof(char) * 500);
    strcpy(dictionary_text, "dictionary.txt");

    return dictionary_text;
}

char *str_lower(const char *str) {
    int len = strlen(str);
    char *lower_str = (char *)malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++) {
        lower_str[i] = tolower(str[i]);
    }

    return lower_str;
}

void check_spelling(char *input_text, char *dictionary_file) {
    FILE *fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file\n");
        exit(1);
    }

    char word[WORD_LEN];
    char *lower_input_text = str_lower(input_text);

    printf("Misspelled words:\n");
    while (fscanf(fp, "%s", word) != EOF) {
        char *lower_word = str_lower(word);
        if (strstr(lower_input_text, lower_word) == NULL) {
            printf("%s\n", word);
        }
        free(lower_word);
    }

    free(lower_input_text);
    fclose(fp);
}

int main() {
    char *input_text = get_input_text();
    char *dictionary_file = get_dictionary();

    check_spelling(input_text, dictionary_file);

    free(input_text);
    free(dictionary_file);

    return 0;
}