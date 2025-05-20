//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string into an array of substrings based on a delimiter
char **split_string(char *str, char delimiter) {
    char **substrings = NULL;
    int length = strlen(str);
    int i = 0;
    int j = 0;

    // Allocate memory for substrings array
    substrings = (char **)malloc(sizeof(char *) * (length + 1));

    // Iterate through each character in the string
    for (i = 0; i < length; i++) {
        if (str[i] == delimiter) {
            // Append the substring to the substrings array
            substrings[j] = (char *)malloc(sizeof(char) * (i + 1));
            strcpy(substrings[j], str + i);
            j++;
        }
    }

    // Append the last substring to the substrings array
    substrings[j] = (char *)malloc(sizeof(char) * (i + 1));
    strcpy(substrings[j], str + i);

    // Return the substrings array
    return substrings;
}

// Function to print the substrings array
void print_substrings(char **substrings, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%s\n", substrings[i]);
    }
}

int main() {
    // Example string
    char str[] = "Hello, world! How are you?";
    char delimiter = '!';

    // Split the string into substrings using the delimiter
    char **substrings = split_string(str, delimiter);

    // Print the substrings array
    print_substrings(substrings, strlen(str));

    // Free memory allocated for substrings array
    for (int i = 0; i < strlen(str); i++) {
        free(substrings[i]);
    }
    free(substrings);

    return 0;
}