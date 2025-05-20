//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    size_t size;
} csv_line;

typedef struct {
    csv_line* lines;
    size_t size;
} csv_file;

csv_file* csv_read(const char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file data
    char* file_data = malloc(file_size + 1);
    if (file_data == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the file into memory
    size_t bytes_read = fread(file_data, 1, file_size, file);
    if (bytes_read != file_size) {
        free(file_data);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Parse the file data

    // Allocate memory for the csv file
    csv_file* csv = malloc(sizeof(csv_file));
    if (csv == NULL) {
        free(file_data);
        return NULL;
    }

    // Parse the file data into lines
    csv->lines = NULL;
    csv->size = 0;
    char* line = strtok(file_data, "\n");
    while (line != NULL) {
        // Allocate memory for the line
        csv_line* new_line = malloc(sizeof(csv_line));
        if (new_line == NULL) {
            // Free the memory that has been allocated so far
            for (size_t i = 0; i < csv->size; i++) {
                free(csv->lines[i].data);
            }
            free(csv->lines);
            free(csv);
            free(file_data);
            return NULL;
        }

        // Copy the line data into the new line
        new_line->data = strdup(line);
        if (new_line->data == NULL) {
            // Free the memory that has been allocated so far
            for (size_t i = 0; i < csv->size; i++) {
                free(csv->lines[i].data);
            }
            free(csv->lines);
            free(csv);
            free(file_data);
            free(new_line);
            return NULL;
        }

        // Get the line size
        new_line->size = strlen(new_line->data);

        // Add the new line to the csv file
        csv->lines = realloc(csv->lines, (csv->size + 1) * sizeof(csv_line));
        if (csv->lines == NULL) {
            // Free the memory that has been allocated so far
            for (size_t i = 0; i < csv->size; i++) {
                free(csv->lines[i].data);
            }
            free(csv->lines);
            free(csv);
            free(file_data);
            free(new_line->data);
            free(new_line);
            return NULL;
        }
        csv->lines[csv->size] = *new_line;
        csv->size++;

        // Get the next line
        line = strtok(NULL, "\n");
    }

    // Free the file data
    free(file_data);

    // Return the csv file
    return csv;
}

void csv_free(csv_file* csv) {
    // Free the lines
    for (size_t i = 0; i < csv->size; i++) {
        free(csv->lines[i].data);
    }

    // Free the csv file
    free(csv->lines);
    free(csv);
}

int main() {
    // Read the csv file
    csv_file* csv = csv_read("test.csv");
    if (csv == NULL) {
        printf("Error reading csv file\n");
        return 1;
    }

    // Print the csv file
    for (size_t i = 0; i < csv->size; i++) {
        printf("%s\n", csv->lines[i].data);
    }

    // Free the csv file
    csv_free(csv);

    return 0;
}