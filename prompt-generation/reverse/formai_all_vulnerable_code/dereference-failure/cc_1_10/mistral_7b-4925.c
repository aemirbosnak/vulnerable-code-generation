//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_SIZE 50

struct Word {
    char word[WORD_SIZE];
    int count;
};

void process_line(char line[], struct Word words[]) {
    int pos = 0;
    int i = 0;

    while (pos < strlen(line)) {
        while (isspace((unsigned char)line[pos])) pos++;

        if (pos >= strlen(line)) break;

        words[i].count = 1;
        strncpy(words[i].word, &line[pos], WORD_SIZE - 1);
        words[i++].word[WORD_SIZE - 1] = '\0';

        while (!isspace((unsigned char)line[++pos]));

        if (pos >= strlen(line)) break;

        while (isspace((unsigned char)line[pos])) pos++;

        if (pos >= strlen(line)) break;
    }

    words[i].count = 0;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char file_name[100];
    struct Word words[MAX_WORDS];
    int i = 0, j = 0;
    char line[1024];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(file_name, argv[1]);
    file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        process_line(line, words);
    }

    fclose(file);

    for (i = 0; words[i].count != 0; i++) {
        for (j = i + 1; words[j].count != 0; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    for (i = 0; words[i].count != 0; i++) {
        printf("\n%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}