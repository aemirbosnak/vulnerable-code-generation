//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    size_t len;
} String;

String *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    String *str = malloc(sizeof(String));
    str->data = NULL;
    str->len = 0;

    char *buffer = malloc(MAX_LINE_LENGTH);
    char *ptr = buffer;
    while (fgets(ptr, MAX_LINE_LENGTH - (ptr - buffer), fp)!= NULL) {
        size_t new_len = str->len + strlen(buffer);
        str->data = realloc(str->data, new_len + 1);
        strcpy(str->data + str->len, buffer);
        str->len += strlen(buffer);
        ptr += strlen(buffer) - 1;
    }

    fclose(fp);
    free(buffer);

    return str;
}

int main() {
    String *csv_data = read_file("data.csv");
    printf("CSV data:\n%s\n", csv_data->data);

    String *line = strtok(csv_data->data, "\n");
    while (line!= NULL) {
        printf("Line: %s\n", line->data);
        String *cell = strtok(line->data, ",");
        while (cell!= NULL) {
            printf("Cell: %s\n", cell->data);
            cell = strtok(NULL, ",");
        }
        line = strtok(NULL, "\n");
    }

    free(csv_data->data);
    free(csv_data);
    return 0;
}