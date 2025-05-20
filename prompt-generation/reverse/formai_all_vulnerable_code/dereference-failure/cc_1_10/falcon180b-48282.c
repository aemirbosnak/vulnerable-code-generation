//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = NULL;
    char *temp = str;

    // Count the number of tokens in the string
    while (*temp!= '\0') {
        if (*temp == delimiter) {
            count++;
        }
        temp++;
    }

    // Allocate memory for the tokens
    tokens = malloc(sizeof(char *) * (count + 1));

    // Set the first token to the entire string
    tokens[0] = strdup(str);

    // Loop through the string and split it into tokens
    temp = str;
    for (int i = 1; i < count; i++) {
        while (*temp!= delimiter && *temp!= '\0') {
            temp++;
        }
        *temp = '\0';
        token = strdup(temp + 1);
        tokens[i] = token;
        temp++;
    }

    // Set the last token to NULL
    tokens[count] = NULL;

    return tokens;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file) {
    char line[1024];
    char delimiter;
    char **tokens;

    // Read the first line and determine the delimiter
    fgets(line, sizeof(line), file);
    delimiter = line[0];

    // Read the rest of the file and print each line
    while (fgets(line, sizeof(line), file)!= NULL) {
        tokens = split(line, delimiter);
        for (int i = 0; tokens[i]!= NULL; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
        for (int i = 0; tokens[i]!= NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char delimiter = argv[2][0];

    read_csv_file(file);

    fclose(file);

    return 0;
}