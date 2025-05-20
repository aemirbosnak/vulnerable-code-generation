//Falcon-180B DATASET v1.0 Category: File handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_SIZE);
    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to count the number of words in a line
int count_words(char* line) {
    int count = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to sort lines by word count in ascending order
int compare_lines(const void* a, const void* b) {
    char* line1 = *(char**) a;
    char* line2 = *(char**) b;
    int count1 = count_words(line1);
    int count2 = count_words(line2);
    if (count1 < count2) {
        return -1;
    } else if (count1 > count2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    char* line;
    int line_count = 0;
    char** lines = (char**) malloc(MAX_LINE_SIZE * sizeof(char*));

    // Read lines from input file and store in array
    while ((line = read_line(input_file))!= NULL) {
        lines[line_count] = line;
        line_count++;
    }

    // Sort lines by word count in ascending order
    qsort(lines, line_count, sizeof(char*), compare_lines);

    // Write sorted lines to output file
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < line_count; i++) {
        write_line(output_file, lines[i]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}