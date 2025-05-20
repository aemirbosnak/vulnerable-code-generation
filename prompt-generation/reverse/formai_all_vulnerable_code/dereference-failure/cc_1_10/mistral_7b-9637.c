//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct {
    char word[WORD_LENGTH];
    int count;
} word_t;

void str_trim_left(char *str, char c) {
    size_t i = 0;
    while (str[i] == c) {
        memmove(str, str + i + 1, strlen(str) - i);
        str[strlen(str)] = '\0';
        i--;
    }
}

int main(int argc, char **argv) {
    word_t word_table[MAX_WORDS];
    int num_words = 0;
    char line[1024];
    char *token;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        str_trim_left(line, ' ');
        str_trim_left(line, '\n');

        token = strtok(line, " ");
        while (token != NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, word_table[i].word) == 0) {
                    word_table[i].count++;
                    break;
                }
            }
            if (i == num_words) {
                if (num_words < MAX_WORDS) {
                    strcpy(word_table[num_words].word, token);
                    word_table[num_words].count = 1;
                    num_words++;
                } else {
                    printf("Table overflow\n");
                    fclose(fp);
                    return 1;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    for (int i = 0; i < num_words; i++) {
        printf("%s : %d\n", word_table[i].word, word_table[i].count);
    }

    return 0;
}