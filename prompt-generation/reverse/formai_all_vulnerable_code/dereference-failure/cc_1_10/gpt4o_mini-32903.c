//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// A brave knight ready to traverse the CSV forests
typedef struct {
    char **fields;
    int field_count;
} CSVRow;

// The wise guide, here to declare the realm of CSV
void initialize_row(CSVRow *row) {
    row->fields = malloc(MAX_FIELDS * sizeof(char *));
    for (int i = 0; i < MAX_FIELDS; i++) {
        row->fields[i] = NULL;
    }
    row->field_count = 0;
}

// The hearts of fields shall be freed
void free_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

// A brave legendary function to organize the CSV reading adventure
int parse_line(char *line, CSVRow *row) {
    char *token = strtok(line, ",");
    while (token) {
        if (row->field_count < MAX_FIELDS) {
            row->fields[row->field_count] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(row->fields[row->field_count], token);
            row->field_count++;
        }
        token = strtok(NULL, ",");
    }
    return row->field_count;
}

// A magical portal to the CSV realm
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Oh dear! The file of destiny %s cannot be found!\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    printf("✨ Crossing into the land of %s... ✨\n", filename);
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        CSVRow row;
        initialize_row(&row);
        if (parse_line(line, &row) > 0) {
            printf("📜 Row %d: ", line_number);
            for (int i = 0; i < row.field_count; i++) {
                printf("'%s'", row.fields[i]);
                if (i < row.field_count - 1) {
                    printf(" | ");
                }
            }
            printf("\n");
        }
        free_row(&row);
    }
    fclose(file);
    printf("🌈 Adventure completed! The scrolls have been unveiled!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("🏰 Welcome, brave squire! Please provide the path to the CSV scroll!\n");
        printf("Usage: %s <path_to_csv_file>\n", argv[0]);
        return 1;
    }

    read_csv(argv[1]);
    return 0;
}