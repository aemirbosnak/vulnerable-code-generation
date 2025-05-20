//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to lowercase
void str_lower(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to remove whitespace from a string
void str_trim(char *str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (isspace(str[i])) i++;
    while (isspace(str[j])) j--;
    str[j] = '\0';
    strcpy(str, &str[i]);
}

// Function to split a string into an array of strings
char **str_split(char *str, char delimiter) {
    char **array = (char **)malloc(sizeof(char *));
    int count = 0;
    char *token = strtok(str, delimiter);
    while (token!= NULL) {
        array = (char **)realloc(array, sizeof(char *) * ++count);
        array[count - 1] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    return array;
}

// Function to print an array of strings
void str_array_print(char **array) {
    int i = 0;
    while (array[i]!= NULL) {
        printf("%s\n", array[i]);
        i++;
    }
}

// Function to free an array of strings
void str_array_free(char **array) {
    int i = 0;
    while (array[i]!= NULL) {
        free(array[i]);
        i++;
    }
    free(array);
}

int main() {
    char *input_file = "input.html";
    char *output_file = "output.html";
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    char *input_string = (char *)malloc(sizeof(char) * 1000000);
    fread(input_string, sizeof(char), 1000000, input);
    fclose(input);

    // Convert string to lowercase
    str_lower(input_string);

    // Remove whitespace
    str_trim(input_string);

    // Split string into lines
    char **lines = str_split(input_string, '\n');

    // Print lines
    str_array_print(lines);

    // Free lines
    str_array_free(lines);

    return 0;
}