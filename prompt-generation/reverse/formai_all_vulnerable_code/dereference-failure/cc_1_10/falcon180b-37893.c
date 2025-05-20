//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to split a line of text into fields based on the comma delimiter
int split_line(char* line, char** fields) {
    char* token = strtok(line, ",");
    int count = 0;

    while (token!= NULL) {
        fields[count] = token;
        count++;
        token = strtok(NULL, ",");
    }

    return count;
}

// Function to read a CSV file and print its contents
void read_csv(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char** fields = NULL;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Split the line into fields
        num_fields = split_line(line, fields);

        // Print the fields
        for (int i = 0; i < num_fields; i++) {
            printf("%s ", fields[i]);
        }
        printf("\n");

        // Free the memory allocated for the fields
        for (int i = 0; i < num_fields; i++) {
            free(fields[i]);
        }
        free(fields);
        fields = NULL;
    }
}

int main() {
    FILE* file = fopen("example.csv", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    read_csv(file);

    fclose(file);
    return 0;
}