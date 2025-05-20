//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to read a line of the CSV file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error reading line\n");
        exit(1);
    }
    return line;
}

// Function to split a line of the CSV file into fields
char** split_line(char* line) {
    int num_fields = 0;
    char** fields = malloc(sizeof(char*));
    char* current_field = strtok(line, ",");
    while (current_field!= NULL) {
        num_fields++;
        fields = realloc(fields, sizeof(char*) * num_fields);
        fields[num_fields-1] = current_field;
        current_field = strtok(NULL, ",");
    }
    fields[num_fields] = NULL;
    return fields;
}

// Function to print the contents of a row
void print_row(char** row) {
    for (int i = 0; row[i]!= NULL; i++) {
        printf("%s ", row[i]);
    }
    printf("\n");
}

// Function to read the entire CSV file and print its contents
void read_csv_file(FILE* file) {
    char* line = read_line(file);
    while (line!= NULL) {
        char** row = split_line(line);
        print_row(row);
        free(row);
        line = read_line(file);
    }
}

int main() {
    FILE* file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    read_csv_file(file);
    fclose(file);
    return 0;
}