//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 10

char* read_csv_line(FILE* file);
int count_csv_fields(char* line);
char** parse_csv_fields(char* line, int num_fields);
void free_csv_fields(char** fields, int num_fields);

int main() {
    char filename[MAX_FILENAME_SIZE];
    printf("Enter the filename to read from: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char* line = read_csv_line(file);
    int num_fields = count_csv_fields(line);
    printf("Number of fields: %d\n", num_fields);

    char** fields = parse_csv_fields(line, num_fields);
    printf("Fields:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("- %s\n", fields[i]);
    }

    free_csv_fields(fields, num_fields);
    free(line);
    fclose(file);

    return 0;
}

char* read_csv_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE * sizeof(char));
    fgets(line, MAX_LINE_SIZE, file);
    line[strcspn(line, "\r\n")] = '\0'; // remove trailing newline characters
    return line;
}

int count_csv_fields(char* line) {
    int num_fields = 1;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] == ',') {
            num_fields++;
        }
    }
    return num_fields;
}

char** parse_csv_fields(char* line, int num_fields) {
    char** fields = malloc(num_fields * sizeof(char*));
    char* field = strtok(line, ",");
    int i = 0;
    while (field != NULL && i < num_fields) {
        fields[i] = malloc(strlen(field) * sizeof(char));
        strcpy(fields[i], field);
        field = strtok(NULL, ",");
        i++;
    }
    return fields;
}

void free_csv_fields(char** fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}