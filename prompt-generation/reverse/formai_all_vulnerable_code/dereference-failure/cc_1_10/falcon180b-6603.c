//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

char *get_word(char *line) {
    char *word = malloc(MAX_WORD_LEN);
    char *start = line;
    int len = 0;

    while (isspace(*start)) start++;

    while (!isspace(*start) && len < MAX_WORD_LEN) {
        *(word + len) = tolower(*(start + len));
        start++;
        len++;
    }

    *(word + len) = '\0';
    return word;
}

void print_word_count(char *filename) {
    FILE *file;
    char line[MAX_LINE_LEN];
    char *word;
    int word_count = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, file)!= NULL) {
        word = get_word(line);

        if (word!= NULL) {
            printf("%s: %d\n", word, word_count);
            word_count++;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    print_word_count(argv[1]);

    return 0;
}