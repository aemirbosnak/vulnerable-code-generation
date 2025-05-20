//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>

#define MAX_LINE_LENGTH 1024
#define DELIMITER ','

// Function to read a line from a CSV file and store it in a buffer
void read_line(FILE* file, char* buffer) {
    char c;
    int i = 0;

    while ((c = fgetc(file))!= EOF) {
        if (i >= MAX_LINE_LENGTH - 1) {
            printf("Line too long\n");
            exit(1);
        }
        if (c == '\n') {
            buffer[i] = '\0';
            break;
        }
        buffer[i++] = c;
    }
}

// Function to split a line into fields based on a delimiter
char** split_line(char* line) {
    int i = 0;
    char** fields = malloc(sizeof(char*));
    char* field = strtok(line, DELIMITER);

    while (field!= NULL) {
        fields[i++] = field;
        field = strtok(NULL, DELIMITER);
    }
    fields[i] = NULL;

    return fields;
}

// Function to print the contents of a row
void print_row(char** row) {
    for (int i = 0; row[i]!= NULL; i++) {
        printf("%s ", row[i]);
    }
    printf("\n");
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char** row;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        read_line(file, line);
        row = split_line(line);
        print_row(row);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    read_csv_file(file);

    fclose(file);
    return 0;
}