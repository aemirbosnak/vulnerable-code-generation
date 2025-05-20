//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

typedef struct {
    int num_rows;
    int num_cols;
    int row_index;
    int col_index;
    Person *row;
} Reader;

void parse_csv(const char *filename, Reader *reader) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%s %d %s", reader->row->name, &reader->row->age, reader->row->address) == 3) {
            reader->row++;
            reader->row_index++;
        } else {
            fprintf(stderr, "Invalid line format: %s\n", line);
            break;
        }
    }

    fclose(file);
    reader->num_rows = reader->row_index;
}

void print_csv(const Reader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        printf("%s %d %s\n", reader->row[i].name, reader->row[i].age, reader->row[i].address);
    }
}

int main() {
    Reader reader;
    parse_csv("sample.csv", &reader);
    print_csv(&reader);
    return 0;
}