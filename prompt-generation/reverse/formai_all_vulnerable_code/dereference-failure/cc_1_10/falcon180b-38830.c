//Falcon-180B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to remove leading/trailing whitespaces from a string
void trim(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (isspace(str[i])) i++;
    while (isspace(str[j])) j--;
    if (i > j) {
        str[0] = '\0';
        return;
    }
    memmove(str, str + i, j - i + 1);
    str[j - i + 1] = '\0';
}

int main() {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char delimiter[MAX_LINE_LENGTH];

    // Get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    trim(filename);

    // Get delimiter from user
    printf("Enter delimiter: ");
    fgets(delimiter, MAX_LINE_LENGTH, stdin);
    trim(delimiter);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        return 1;
    }

    // Read file line by line, splitting each line into fields based on delimiter
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char* field = strtok(line, delimiter);
        while (field!= NULL) {
            printf("%s\n", field);
            field = strtok(NULL, delimiter);
        }
    }

    // Close file
    fclose(file);

    return 0;
}