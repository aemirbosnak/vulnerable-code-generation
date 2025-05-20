//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct {
    char *data;
    int size;
    int pos;
} csv_reader;

csv_reader* csv_reader_create(const char* filename) {
    csv_reader* reader = (csv_reader*)malloc(sizeof(csv_reader));
    reader->data = (char*)malloc(BUF_SIZE);
    reader->size = BUF_SIZE;
    reader->pos = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        free(reader->data);
        free(reader);
        return NULL;
    }
    fread(reader->data, sizeof(char), BUF_SIZE, file);
    fclose(file);
    return reader;
}

void csv_reader_destroy(csv_reader* reader) {
    free(reader->data);
    free(reader);
}

int csv_reader_read_line(csv_reader* reader) {
    if (reader->pos >= reader->size) {
        reader->pos = 0;
        reader->size = BUF_SIZE;
        FILE* file = fopen(reader->data, "r");
        if (file == NULL) {
            free(reader->data);
            free(reader);
            return -1;
        }
        fread(reader->data, sizeof(char), BUF_SIZE, file);
        fclose(file);
    }
    int len = strlen(reader->data);
    int new_pos = reader->pos + len;
    char* line = (char*)malloc(new_pos + 1);
    strncpy(line, reader->data, new_pos);
    line[new_pos] = '\0';
    reader->pos = new_pos;
    return 0;
}

int main() {
    csv_reader* reader = csv_reader_create("example.csv");
    while (csv_reader_read_line(reader) == 0) {
        printf("%s\n", reader->data);
    }
    csv_reader_destroy(reader);
    return 0;
}