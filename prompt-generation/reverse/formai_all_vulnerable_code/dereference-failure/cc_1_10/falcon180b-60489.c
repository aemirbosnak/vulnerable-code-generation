//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024
#define MAX_NUM_STRINGS 1000

// Function to compare two strings
int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

// Function to sort strings in alphabetical order
void sort(char** arr, int num_strings) {
    qsort(arr, num_strings, sizeof(char*), cmp);
}

// Function to remove duplicates from an array of strings
int remove_duplicates(char** arr, int num_strings) {
    int i, j;
    for (i = 0; i < num_strings - 1; i++) {
        for (j = i + 1; j < num_strings; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                // Remove duplicate
                free(arr[j]);
                arr[j] = NULL;
                num_strings--;
                j--;
            }
        }
    }
    return num_strings;
}

// Function to read strings from a file
int read_strings_from_file(char** arr, int max_num_strings, FILE* fp) {
    int num_strings = 0;
    char line[MAX_STRING_LENGTH];

    while (fgets(line, MAX_STRING_LENGTH, fp)!= NULL && num_strings < max_num_strings) {
        // Add null terminator to end of string
        line[strcspn(line, "\n")] = '\0';
        // Allocate memory for string
        arr[num_strings] = malloc(strlen(line) + 1);
        // Copy string to allocated memory
        strcpy(arr[num_strings], line);
        // Increment number of strings
        num_strings++;
    }

    return num_strings;
}

// Function to write strings to a file
int write_strings_to_file(char** arr, int num_strings, FILE* fp) {
    int i;

    for (i = 0; i < num_strings; i++) {
        fprintf(fp, "%s\n", arr[i]);
    }

    return num_strings;
}

// Main function
int main() {
    char** strings = NULL;
    int num_strings = 0;

    // Read strings from file
    FILE* fp = fopen("strings.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    num_strings = read_strings_from_file(strings, MAX_NUM_STRINGS, fp);
    fclose(fp);

    // Sort strings alphabetically
    sort(strings, num_strings);

    // Remove duplicates
    num_strings = remove_duplicates(strings, num_strings);

    // Write sorted and unique strings to file
    FILE* fp_out = fopen("strings_sorted_unique.txt", "w");
    if (fp_out == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }
    num_strings = write_strings_to_file(strings, num_strings, fp_out);
    fclose(fp_out);

    // Free memory
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}