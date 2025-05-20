//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char* word;
    int line_number;
    int word_number;
} WordInfo;

int is_whitespace(char c);

int is_divider(char c);

char* to_lower_case(char* str);

int is_word(char* str);

void append_word(WordInfo** word_list, char* word, int line_number, int word_number);

void free_word_list(WordInfo** word_list, int size);

int main(int argc, char *argv[]) {
    char text[1000];

    const char* filename = argc > 1 ? argv[1] : NULL;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    int size = 10;
    int line_number = 1;
    int word_number = 1;
    int word_count = 0;

    WordInfo** words = malloc(size * sizeof(WordInfo*));

    while (fgets(text, sizeof(text), file)) {
        char* buffer = malloc(strlen(text) + 1);

        memcpy(buffer, text, strlen(text) + 1);
        char* token = strtok(buffer, " \r\n\t");

        while (token != NULL) {
            if (is_word(token)) {
                char* word = to_lower_case(token);
                append_word(words, word, line_number, word_number);
                word_count++;

                free(word);
            }

            token = strtok(NULL, " \r\n\t");
            word_number++;
        }

        free(buffer);
        line_number++;
        word_number = 1;
    }

    fclose(file);

    printf("Total Words: %d\n", word_count);

    for (int i = 0; i < word_count; i++) {
        WordInfo* word_info = words[i];
        char* word = word_info->word;

        if (strlen(word) <= 1) {
            printf("Potential issue: Single-letter word at line %d column %d\n", word_info->line_number, word_info->word_number);
        } else if (strlen(word) > 20) {
            printf("Potential issue: Long word at line %d column %d\n", word_info->line_number, word_info->word_number);
        }

        free(word);
        free(word_info);
    }

    free(words);

    return 0;
}

int is_whitespace(char c) {
    return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}

int is_divider(char c) {
    return is_whitespace(c) || c == ',' || c == '.' || c == ':' || c == '?' || c == '!' || c == ';' || c == '"';
}

char* to_lower_case(char* str) {
    char* result = malloc(strlen(str) + 1);

    for (int i = 0; i < strlen(str); i++) {
        result[i] = tolower(str[i]);
    }

    result[strlen(str)] = '\0';

    return result;
}

int is_word(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) return 0;
    }

    return 1;
}

void append_word(WordInfo** word_list, char* word, int line_number, int word_number) {
    static int size = 10;
    static int count = 0;

    if (count == size) {
        size *= 2;
        word_list = realloc(word_list, size * sizeof(WordInfo*));
    }

    WordInfo* word_info = malloc(sizeof(WordInfo));
    word_info->word = word;
    word_info->line_number = line_number;
    word_info->word_number = word_number;

    word_list[count] = word_info;

    count++;
}

void free_word_list(WordInfo** word_list, int size) {
    for (int i = 0; i < size; i++) {
        WordInfo* word_info = word_list[i];
        free(word_info->word);
        free(word_info);
    }

    free(word_list);
}