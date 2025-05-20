//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
int count_lines_in_file(FILE *fp);
int count_words_in_line(char *line);
void print_line_numbers(FILE *fp);
void reverse_string(char *str);

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Count total number of lines in file
    int total_lines = count_lines_in_file(fp);

    // Print line numbers
    printf("Line numbers:\n");
    print_line_numbers(fp);

    // Close file
    fclose(fp);

    // Count total number of words in file
    int total_words = 0;
    fp = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        total_words += count_words_in_line(line);
    }
    fclose(fp);

    // Reverse each line in file
    fp = fopen(filename, "r+");
    rewind(fp);
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        reverse_string(line);
        fseek(fp, -strlen(line), SEEK_CUR);
        fputs(line, fp);
    }
    fclose(fp);

    // Print reversed file
    fp = fopen(filename, "r");
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}

// Counts the number of lines in a file
int count_lines_in_file(FILE *fp) {
    int count = 0;
    char c;
    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            count++;
        }
    }
    return count;
}

// Counts the number of words in a line
int count_words_in_line(char *line) {
    int count = 0;
    char *word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Prints line numbers
void print_line_numbers(FILE *fp) {
    int line_num = 1;
    char c;
    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            printf("%d\n", line_num);
            line_num++;
        }
    }
}

// Reverses a string
void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
    }
}