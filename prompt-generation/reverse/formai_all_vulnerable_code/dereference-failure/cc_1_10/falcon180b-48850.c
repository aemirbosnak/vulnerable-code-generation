//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUM_STRINGS 1000

// Function prototypes
void read_strings(char **strings, int *num_strings);
void reverse_strings(char **strings, int num_strings);
void print_strings(char **strings, int num_strings);

int main() {
    char **strings;
    int num_strings;

    // Read in strings
    read_strings(&strings, &num_strings);

    // Reverse strings
    reverse_strings(strings, num_strings);

    // Print reversed strings
    printf("Reversed strings:\n");
    print_strings(strings, num_strings);

    // Free memory
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}

// Reads in strings from standard input and stores them in an array
void read_strings(char **strings, int *num_strings) {
    char input[MAX_STRING_LENGTH];
    int string_count = 0;

    // Read in strings until end of input is reached
    while (fgets(input, MAX_STRING_LENGTH, stdin)!= NULL) {
        // Remove newline character from end of string
        input[strcspn(input, "\n")] = '\0';

        // Allocate memory for string and add to array
        strings[string_count] = malloc(strlen(input) + 1);
        strcpy(strings[string_count], input);

        string_count++;
    }

    // Set number of strings
    *num_strings = string_count;
}

// Reverses the order of the strings in the array
void reverse_strings(char **strings, int num_strings) {
    for (int i = 0; i < num_strings / 2; i++) {
        char *temp = strings[i];
        strings[i] = strings[num_strings - i - 1];
        strings[num_strings - i - 1] = temp;
    }
}

// Prints out the strings in the array
void print_strings(char **strings, int num_strings) {
    for (int i = 0; i < num_strings; i++) {
        printf("%s\n", strings[i]);
    }
}