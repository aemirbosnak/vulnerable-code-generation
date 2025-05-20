//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int row_count;
    int col_count;
    char** data;
} CSV_Reader;

CSV_Reader* create_csv_reader(char* file_name) {
    CSV_Reader* reader = malloc(sizeof(CSV_Reader));
    reader->row_count = 0;
    reader->col_count = 0;
    reader->data = NULL;

    FILE* fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file '%s'\n", file_name);
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, ",")) {
            char* token = strtok(line, ",");
            reader->col_count++;
            reader->data = realloc(reader->data, sizeof(char*) * reader->col_count);
            reader->data[reader->col_count - 1] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(reader->data[reader->col_count - 1], token);
        } else if (strstr(line, "\\n")) {
            reader->row_count++;
        }
    }

    fclose(fp);

    return reader;
}

void destroy_csv_reader(CSV_Reader* reader) {
    for (int i = 0; i < reader->col_count; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    CSV_Reader* reader = create_csv_reader("data.csv");
    if (reader == NULL) {
        fprintf(stderr, "Error creating reader\n");
        return 1;
    }

    printf("File name: %s\n", reader->data[0]);
    printf("Column count: %d\n", reader->col_count);
    printf("Row count: %d\n", reader->row_count);

    destroy_csv_reader(reader);

    return 0;
}