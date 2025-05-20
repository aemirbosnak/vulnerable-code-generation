//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} string;

void init_string(string *s) {
    s->data = (char *)malloc(MAX_SIZE * sizeof(char));
    s->size = 0;
}

void append_string(string *s, char *str) {
    int len = strlen(str);
    if (s->size + len >= MAX_SIZE) {
        printf("Error: string too long\n");
        exit(1);
    }
    strcpy(&s->data[s->size], str);
    s->size += len;
}

void print_string(string s) {
    printf("%s", s.data);
}

void free_string(string *s) {
    free(s->data);
}

int main() {
    FILE *file;
    char line[MAX_SIZE];
    string text = {0};

    init_string(&text);

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    while (fgets(line, MAX_SIZE, file)!= NULL) {
        append_string(&text, line);
    }

    fclose(file);

    printf("The text in the file is:\n");
    print_string(text);

    free_string(&text);

    return 0;
}