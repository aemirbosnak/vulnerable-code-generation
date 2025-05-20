//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

char *read_line(FILE *fp) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        printf("Error reading line.\n");
        exit(1);
    }
    return line;
}

void process_line(char *line) {
    char *word = malloc(MAX_WORD_LENGTH);
    int word_count = 0;
    char *delimiters = " \t\n\r\f\v\a\b\e\f\n\r\t";
    char *p = line;
    while ((p = strpbrk(p, delimiters))!= NULL) {
        if (strlen(word) == 0) {
            strcpy(word, "");
        }
        strcat(word, p);
        p++;
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Error: word too long.\n");
            exit(1);
        }
        word_count++;
        if (word_count == 10) {
            printf("Error: too many words.\n");
            exit(1);
        }
    }
    if (strlen(word) > 0) {
        strcat(word, "");
        printf("%s\n", word);
    }
    free(word);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char *line;
    while ((line = read_line(fp))!= NULL) {
        process_line(line);
    }
    fclose(fp);
    return 0;
}