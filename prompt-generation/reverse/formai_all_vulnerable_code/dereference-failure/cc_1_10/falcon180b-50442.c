//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

/* Function to remove leading/trailing white spaces from a string */
void trim(char* str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
}

/* Function to read a line from a file */
char* read_line(FILE* fp) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, fp);
    trim(line);
    return line;
}

/* Function to write data to a file */
void write_data(FILE* fp, char* data) {
    fprintf(fp, "%s\n", data);
}

/* Function to count the number of words in a string */
int count_words(char* str) {
    int count = 0;
    char* token;
    token = strtok(str, " ");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

/* Function to count the number of characters in a string */
int count_chars(char* str) {
    int count = 0;
    while (*str) {
        count++;
        str++;
    }
    return count;
}

/* Function to count the number of lines in a file */
int count_lines(FILE* fp) {
    int count = 0;
    char* line;
    while ((line = read_line(fp))!= NULL) {
        count++;
        free(line);
    }
    return count;
}

/* Function to calculate the average word length in a file */
double avg_word_length(FILE* fp) {
    int total_chars = 0;
    int total_words = 0;
    char* line;
    while ((line = read_line(fp))!= NULL) {
        total_chars += count_chars(line);
        total_words += count_words(line);
        free(line);
    }
    return (double) total_chars / total_words;
}

int main() {
    FILE* fp;
    char* filename;

    /* Get filename from user */
    printf("Enter the filename: ");
    scanf("%s", filename);

    /* Open the file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    /* Count the number of lines, words, and characters in the file */
    int num_lines = count_lines(fp);
    int num_words = count_words(read_line(fp));
    int num_chars = count_chars(read_line(fp));

    /* Calculate the average word length */
    double avg_word_len = avg_word_length(fp);

    /* Print the results */
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_chars);
    printf("Average word length: %.2f\n", avg_word_len);

    /* Close the file */
    fclose(fp);

    return 0;
}