//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_WORD_LEN 100

char* get_line(FILE* fp) {
    char* line = malloc(MAX_LINE_LEN * sizeof(char));
    fgets(line, MAX_LINE_LEN, fp);
    line[strcspn(line, "\n")] = '\0';
    return line;
}

char* get_word(char* line) {
    char* word = malloc(MAX_WORD_LEN * sizeof(char));
    char* token = strtok(line, " ");
    strcpy(word, token);
    return word;
}

void translate(char* word) {
    char* cat_word = malloc(MAX_WORD_LEN * sizeof(char));
    strcpy(cat_word, word);
    for (int i = 0; i < strlen(cat_word); i++) {
        if (isalpha(cat_word[i])) {
            cat_word[i] = tolower(cat_word[i]);
        }
    }
    printf("%s\n", cat_word);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char* line = get_line(fp);
    char* word = get_word(line);
    while (word!= NULL) {
        translate(word);
        word = get_word(line);
    }

    free(line);
    free(word);
    fclose(fp);
    return 0;
}