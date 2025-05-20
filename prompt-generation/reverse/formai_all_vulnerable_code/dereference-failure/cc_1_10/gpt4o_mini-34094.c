//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *create_csv_row(int num_fields) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = malloc(sizeof(char*) * num_fields);
    for (int i = 0; i < num_fields; i++) {
        row->fields[i] = malloc(sizeof(char) * MAX_LINE_LENGTH);
    }
    row->num_fields = num_fields;
    return row;
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int parse_csv_line(const char *line, CSVRow *row) {
    const char *ptr = line;
    int field_idx = 0;
    
    while (*ptr != '\0') {
        if (field_idx >= row->num_fields) {
            break; // Avoid overflow
        }
        
        const char *start = ptr;
        while (*ptr != ',' && *ptr != '\0') {
            ptr++;
        }

        size_t length = ptr - start;
        strncpy(row->fields[field_idx], start, length);
        row->fields[field_idx][length] = '\0'; // Null-terminate the string

        field_idx++;

        if (*ptr == ',') {
            ptr++; // Skip the comma
        }
    }
    
    return field_idx; // Return number of fields parsed
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("Field %d: %s\n", i + 1, row->fields[i]);
    }
    printf("\n");
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    
    while (fgets(line, sizeof(line), file)) {
        line_count++;
        CSVRow *row = create_csv_row(MAX_FIELDS);
        int num_fields = parse_csv_line(line, row);
        
        printf("Row %d:\n", line_count);
        print_csv_row(row);
        free_csv_row(row);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }
    
    read_csv_file(argv[1]);
    
    return 0;
}