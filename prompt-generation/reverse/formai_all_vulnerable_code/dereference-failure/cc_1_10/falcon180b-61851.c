//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 64
#define MAX_BOOK_SIZE 1000

typedef struct {
    char *title;
    char *author;
    char *content;
} Book;

typedef struct {
    char *word;
    int count;
} WordCount;

char *read_line(FILE *fp) {
    char *line = malloc(MAX_LINE_SIZE);
    if (line == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    fgets(line, MAX_LINE_SIZE, fp);
    return line;
}

char *trim_string(char *str) {
    char *end;
    if (str == NULL) {
        return NULL;
    }
    end = str + strlen(str) - 1;
    while (isspace(*end)) {
        end--;
    }
    end[1] = '\0';
    return str;
}

bool is_word(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

void count_words(char *content, char *word, int *count) {
    char *pos = strstr(content, word);
    while (pos!= NULL) {
        *count += 1;
        pos = strstr(pos + 1, word);
    }
}

void print_word_counts(WordCount *counts, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }
}

int main() {
    FILE *fp;
    char *line;
    Book book;
    WordCount counts[MAX_WORD_SIZE];
    int count = 0;

    fp = fopen("book.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open book file\n");
        exit(1);
    }

    line = read_line(fp);
    while (line!= NULL) {
        if (strcasecmp(line, "Title:") == 0) {
            book.title = trim_string(read_line(fp));
        } else if (strcasecmp(line, "Author:") == 0) {
            book.author = trim_string(read_line(fp));
        } else {
            strcat(book.content, line);
            strcat(book.content, "\n");
        }
        line = read_line(fp);
    }
    fclose(fp);

    printf("Book Title: %s\n", book.title);
    printf("Book Author: %s\n", book.author);

    count_words(book.content, "the", &counts[0].count);
    count_words(book.content, "and", &counts[1].count);
    count_words(book.content, "to", &counts[2].count);
    count_words(book.content, "of", &counts[3].count);
    count_words(book.content, "a", &counts[4].count);

    print_word_counts(counts, 5);

    return 0;
}