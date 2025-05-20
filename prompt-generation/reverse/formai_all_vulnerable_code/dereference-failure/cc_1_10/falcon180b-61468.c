//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to split a line based on comma
char **split_line(char *line) {
    int num_tokens = 0;
    char *token;
    char **tokens = NULL;

    // Count the number of tokens in the line
    while (*line!= '\0') {
        if (*line == ',') {
            num_tokens++;
        }
        line++;
    }

    // Allocate memory for the tokens
    tokens = (char **) malloc((num_tokens + 1) * sizeof(char *));
    if (tokens == NULL) {
        printf("Error: could not allocate memory for tokens.\n");
        exit(1);
    }

    // Split the line into tokens
    token = strtok(line, ",");
    int i = 0;
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, ",");
    }
    tokens[i] = NULL;

    return tokens;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    char **tokens;

    // Read the file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Split the line into tokens
        tokens = split_line(line);

        // Print the tokens
        for (int i = 0; tokens[i]!= NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");

        // Free the memory allocated for the tokens
        for (int i = 0; tokens[i]!= NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the CSV file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'.\n", argv[1]);
        return 1;
    }

    // Read the CSV file and print its contents
    read_csv_file(file);

    // Close the CSV file
    fclose(file);

    return 0;
}