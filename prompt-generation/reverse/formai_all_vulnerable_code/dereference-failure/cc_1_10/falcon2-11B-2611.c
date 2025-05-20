//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to split a string into an array of substrings using a delimiter
char **split_string(char *str, char delimiter) {
    int num_substrings = 0;
    char **substrings = NULL;
    int i = 0;
    int j = 0;

    // Count the number of substrings
    while (str[i]!= delimiter) {
        num_substrings++;
        i++;
    }

    // Allocate memory for the array of substrings
    substrings = (char **)malloc(num_substrings * sizeof(char *));
    if (substrings == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Split the string into substrings
    j = 0;
    while (str[i]!= delimiter) {
        substrings[j] = (char *)malloc((strlen(str) + 1) * sizeof(char));
        if (substrings[j] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strncpy(substrings[j], str, strlen(str));
        str = str + i;
        i++;
        j++;
    }

    // Add the final substring
    substrings[j] = (char *)malloc((strlen(str) + 1) * sizeof(char));
    if (substrings[j] == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strncpy(substrings[j], str, strlen(str));

    // Return the array of substrings
    return substrings;
}

// Function to parse a resume line by line
void parse_resume(FILE *file) {
    char line[1000];
    char **substrings;
    int num_substrings;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Split the line into substrings using commas as the delimiter
        substrings = split_string(line, ',');
        num_substrings = strlen(substrings[0]);

        // Print each substring on a new line
        for (int i = 0; i < num_substrings; i++) {
            printf("%s\n", substrings[i]);
        }
    }

    // Free the memory allocated for the array of substrings
    for (int i = 0; i < num_substrings; i++) {
        free(substrings[i]);
    }
    free(substrings);
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Parse the resume line by line
    parse_resume(file);

    // Close the file
    fclose(file);

    return 0;
}