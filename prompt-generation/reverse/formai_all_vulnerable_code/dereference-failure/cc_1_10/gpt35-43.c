//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100    // maximum line length of the csv file
#define MAX_FIELD_LENGTH 50    // maximum length of each field in the csv file

int main() {
    FILE *csv_file = fopen("example.csv", "r"); // open the csv file for reading

    if (csv_file == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);    // exit with a non-zero status
    }

    char line[MAX_LINE_LENGTH]; // buffer for reading each line from the csv file
    int line_num = 0;   // keep track of the current line number

    // loop through each line in the csv file
    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        line_num++;

        char *token;    // pointer to the current token in the line
        char *delimiter = ","; // delimiter to split each line into fields
        
        // allocate memory for an array to hold each field in the line
        char **fields = malloc(sizeof(char*) * MAX_LINE_LENGTH);

        // loop through each field in the line
        int field_num = 0;
        token = strtok(line, delimiter);
        while (token != NULL) {
            field_num++;

            // allocate memory for a string to hold the current field
            char *field = malloc(sizeof(char) * MAX_FIELD_LENGTH);

            // copy the current token into the field string
            strncpy(field, token, MAX_FIELD_LENGTH);
            
            // add the field to the array of fields
            fields[field_num - 1] = field;

            // get the next token in the line
            token = strtok(NULL, delimiter);
        }

        // print out the fields in the current line
        printf("Line %d:\n", line_num);
        for (int i = 0; i < field_num; i++) {
            printf("Field %d: %s\n", i+1, fields[i]);
        }

        // free memory allocated for the array of fields
        for (int i = 0; i < field_num; i++) {
            free(fields[i]);
        }
        free(fields);
    }

    fclose(csv_file);  // close the csv file
    return 0;   // exit with a zero status
}