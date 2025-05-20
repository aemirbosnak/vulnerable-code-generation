//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} String;

String *create_string() {
    String *s = (String *) malloc(sizeof(String));
    if (s == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    s->data = NULL;
    s->size = 0;
    return s;
}

void append_string(String *s, const char *data, size_t size) {
    if (s->data == NULL) {
        s->data = (char *) malloc(size + 1);
        if (s->data == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
        s->size = size;
    } else {
        char *new_data = (char *) realloc(s->data, s->size + size + 1);
        if (new_data == NULL) {
            printf("Out of memory\n");
            exit(1);
        }
        s->data = new_data;
        s->size += size;
    }
    memcpy(s->data + s->size - size, data, size);
    s->data[s->size] = '\0';
}

void destroy_string(String *s) {
    free(s->data);
    free(s);
}

String *read_line(FILE *fp) {
    String *line = create_string();
    char ch;
    while ((ch = fgetc(fp))!= EOF && ch!= '\n') {
        append_string(line, &ch, 1);
    }
    if (ch == '\n') {
        fgetc(fp); // consume newline character
    }
    return line;
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(1);
    }
    String *header = read_line(fp);
    String *data = read_line(fp);
    while (data!= NULL) {
        printf("Data: %s\n", data->data);
        destroy_string(data);
        data = read_line(fp);
    }
    destroy_string(header);
    fclose(fp);
    return 0;
}