//Falcon-180B DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *data;
    size_t size;
} string_t;

string_t *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    string_t *result = malloc(sizeof(string_t));
    result->data = malloc(MAX_LINE_SIZE);
    result->size = 0;

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (result->size == MAX_LINE_SIZE) {
            result->data = realloc(result->data, result->size + MAX_LINE_SIZE);
        }
        result->data[result->size++] = ch;
    }

    fclose(file);
    return result;
}

void write_file(const char *filename, const char *data, size_t size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(data, 1, size, file);
    fclose(file);
}

void print_string(const char *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%c", data[i]);
    }
    printf("\n");
}

void recursive_reverse(string_t *str, size_t start, size_t end) {
    if (start >= end) {
        return;
    }

    char temp = str->data[start];
    str->data[start] = str->data[end];
    str->data[end] = temp;

    size_t new_start = start + 1;
    size_t new_end = end - 1;
    recursive_reverse(str, new_start, new_end);
}

void reverse_string(string_t *str) {
    recursive_reverse(str, 0, str->size - 1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    string_t *input_string = read_file(argv[1]);
    reverse_string(input_string);
    write_file(argv[2], input_string->data, input_string->size);

    free(input_string->data);
    free(input_string);

    return 0;
}