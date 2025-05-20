//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 128
#define DELIMITER ','

typedef struct {
    char **fields;
    int count;
} entry_t;

typedef struct {
    entry_t *entries;
    int count;
} csv_data_t;

void strip_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL)
        *pos = '\0';
}

char *to_lower(const char *str) {
    char *lowered = malloc(strlen(str) + 1);
    for (int i = 0; str[i]; i++) {
        lowered[i] = tolower(str[i]);
    }
    lowered[strlen(str)] = '\0';
    return lowered;
}

entry_t parse_line(char *line) {
    entry_t entry;
    entry.fields = malloc(MAX_FIELDS * sizeof(char *));
    entry.count = 0;

    char *token = strtok(line, ",");
    while (token != NULL && entry.count < MAX_FIELDS) {
        entry.fields[entry.count++] = strdup(token);
        token = strtok(NULL, ",");
    }
    return entry;
}

csv_data_t read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    csv_data_t csv_data;
    csv_data.count = 0;
    csv_data.entries = malloc(MAX_LINE_LENGTH * sizeof(entry_t));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        strip_newline(line);
        csv_data.entries[csv_data.count++] = parse_line(line);
    }

    fclose(file);
    return csv_data;
}

void free_csv_data(csv_data_t *data) {
    for (int i = 0; i < data->count; i++) {
        for (int j = 0; j < data->entries[i].count; j++) {
            free(data->entries[i].fields[j]);
        }
        free(data->entries[i].fields);
    }
    free(data->entries);
}

void display_data(const csv_data_t *data) {
    for (int i = 0; i < data->count; i++) {
        for (int j = 0; j < data->entries[i].count; j++) {
            printf("%s%c", data->entries[i].fields[j], 
                (j == data->entries[i].count - 1) ? '\n' : DELIMITER);
        }
    }
}

void cyberpunk_style_header() {
    printf("====================================\n");
    printf("       Cyberpunk CSV Reader        \n");
    printf("====================================\n");
    printf("  Enter data from the shadows...   \n");
    printf("====================================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./csv_reader <filename.csv>\n");
        exit(EXIT_FAILURE);
    }

    cyberpunk_style_header();

    csv_data_t data = read_csv(argv[1]);
    printf("\nData Retrieved from Matrix:\n");
    display_data(&data);

    free_csv_data(&data);
    return 0;
}