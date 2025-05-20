//Falcon-180B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to compare two strings (case insensitive)
int compare_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 0;
    }

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to write data to a file
void write_to_file(FILE *fp, char *data) {
    fputs(data, fp);
    fputc('\n', fp);
}

// Function to read data from a file
char *read_from_file(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, fp);

    return strdup(line);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read input file line by line
    char *line = read_from_file(input_file);

    while (line!= NULL) {
        int num_words = count_words(line);

        // Check if the line contains the word "error"
        if (num_words >= 2 && compare_strings(line, "error")) {
            write_to_file(output_file, line);
        }

        // Free memory and read next line
        free(line);
        line = read_from_file(input_file);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}