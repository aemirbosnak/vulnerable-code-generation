//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string based on delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Function to read a CSV file and print its contents
void read_csv(FILE *file) {
    char line[1024];
    char delimiter = ',';
    char **fields = NULL;

    // Read each line of the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Split the line into fields
        fields = split(line, delimiter);

        // Print each field
        for (int i = 0; fields[i]!= NULL; i++) {
            printf("%s\n", fields[i]);
        }

        // Free the memory allocated for fields
        for (int i = 0; fields[i]!= NULL; i++) {
            free(fields[i]);
        }
        free(fields);
        fields = NULL;
    }
}

int main() {
    FILE *file;
    char filename[256];

    // Get the filename from the user
    printf("Enter CSV filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the CSV file and print its contents
    read_csv(file);

    // Close the file
    fclose(file);

    return 0;
}