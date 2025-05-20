//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_LINE 100

typedef struct {
    char *data;
    int size;
} string_t;

void init(string_t *str) {
    str->data = (char *)malloc(MAX_SIZE * sizeof(char));
    str->size = 0;
}

void append(string_t *str, char c) {
    if (str->size >= MAX_SIZE) {
        printf("Error: String is too long.\n");
        exit(1);
    }
    str->data[str->size] = c;
    str->size++;
}

void print(string_t str) {
    printf("%s", str.data);
}

int main() {
    FILE *file;
    char line[MAX_LINE];
    string_t search_word, line_str;

    init(&search_word);
    init(&line_str);

    printf("Enter the search word: ");
    fgets(line, MAX_LINE, stdin);
    strcpy(search_word.data, line);

    file = fopen("file.txt", "r");

    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, file)!= NULL) {
        if (strstr(line, search_word.data)!= NULL) {
            append(&line_str, '\n');
            append(&line_str, line);
        }
    }

    fclose(file);

    if (line_str.size == 0) {
        printf("Search word not found.\n");
    } else {
        printf("Search results:\n");
        print(line_str);
    }

    free(search_word.data);
    free(line_str.data);

    return 0;
}