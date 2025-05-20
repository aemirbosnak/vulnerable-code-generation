//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the CSV file
char* read_line(FILE* csv_file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    char ch;
    int index = 0;

    while ((ch = fgetc(csv_file))!= EOF && ch!= '\n') {
        line[index++] = ch;
        if (index == MAX_LINE_LENGTH - 1) {
            fprintf(stderr, "Error: Line too long in CSV file.\n");
            exit(1);
        }
    }

    line[index] = '\0';
    return line;
}

// Function to parse a line into fields
char** parse_line(char* line) {
    char** fields = (char**) malloc(100 * sizeof(char*));
    int num_fields = 0;
    char* field;
    char* delimiter = ",";

    field = strtok(line, delimiter);
    while (field!= NULL) {
        fields[num_fields++] = field;
        field = strtok(NULL, delimiter);
    }

    return fields;
}

// Function to print the contents of a CSV file
void print_csv_file(FILE* csv_file) {
    char* line;
    char** fields;
    int num_fields;

    while ((line = read_line(csv_file))!= NULL) {
        fields = parse_line(line);
        num_fields = 0;

        while (fields[num_fields]!= NULL) {
            printf("%s ", fields[num_fields++]);
        }

        printf("\n");

        for (int i = 0; i < num_fields; i++) {
            free(fields[i]);
        }
        free(fields);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE* csv_file = fopen(argv[1], "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error: Could not open CSV file.\n");
        return 1;
    }

    print_csv_file(csv_file);

    fclose(csv_file);
    return 0;
}