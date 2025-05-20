//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char* word;
    int count;
} WordCount;

char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    char* word = (char*) malloc(MAX_WORD_LENGTH * sizeof(char));
    int word_count = 0;

    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return NULL;
    }

    char* start = line;
    char* end = strtok(start, " ");

    while (end!= NULL) {
        strcpy(word, end);
        WordCount* wc = (WordCount*) malloc(sizeof(WordCount));
        wc->word = word;
        wc->count = 1;

        if (start == line) {
            word_count = 1;
        } else {
            word_count = 0;
        }

        if (word_count == 0) {
            printf("%s: 1\n", wc->word);
        } else {
            printf("%s: %d\n", wc->word, wc->count);
        }

        start = NULL;
        end = strtok(NULL, " ");
    }

    return line;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char* line = read_line(file);

    while (line!= NULL) {
        printf("\n");
        line = read_line(file);
    }

    fclose(file);
    return 0;
}