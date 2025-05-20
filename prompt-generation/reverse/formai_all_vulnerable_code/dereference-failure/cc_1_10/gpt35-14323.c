//FormAI DATASET v1.0 Category: Text Summarizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LEN 1000
#define MAX_SUMMARY_LEN 1000

// Function to read file and store each line in an array
int read_file(char *filename, char lines[][MAX_LINE_LEN]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    int line_count = 0;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: file '%s' not found.\n", filename);
        exit(1);
    }
    
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        strcpy(lines[line_count], line);
        line_count++;
        if (line_count == MAX_LINES) {
            printf("Error: file has too many lines.\n");
            exit(1);
        }
    }
    
    fclose(fp);
    return line_count;
}

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char prev_c = ' ';
    char c;
    int i;
    
    for (i = 0; i < strlen(line); i++) {
        c = line[i];
        if (c == ' ' && prev_c != ' ') {
            count++;
        }
        prev_c = c;
    }
    
    if (prev_c != ' ') { // Add one more word if the line doesn't end with a space
        count++;
    }
    
    return count;
}

// Function to add a line to the summary if it has not already been added
void add_to_summary(char *line, char *summary, int *summary_len) {
    char temp_line[MAX_LINE_LEN];
    int i, j;
    int already_added = 0;
    
    // Remove trailing newline character from line
    if (line[strlen(line)-1] == '\n') {
        line[strlen(line)-1] = '\0';
    }
    
    // Make sure line is not already in summary
    for (i = 0; i < (*summary_len); i++) {
        strncpy(temp_line, &summary[i], strlen(line));
        if (strcmp(line, temp_line) == 0) {
            already_added = 1;
        }
    }
    
    // Add line to summary if it hasn't already been added
    if (!already_added) {
        strcpy(&summary[(*summary_len)], line);
        (*summary_len) += strlen(line);
        summary[(*summary_len)] = '\n';
        (*summary_len)++;
    }
}

// Main program function
int main(int argc, char *argv[]) {
    char input_file[MAX_LINE_LEN];
    char output_file[MAX_LINE_LEN];
    char lines[MAX_LINES][MAX_LINE_LEN];
    char summary[MAX_SUMMARY_LEN];
    int line_count, i, j, word_count, summary_len;
    float percent;
    
    // Get input and output file names from command-line arguments
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <percent>\n", argv[0]);
        exit(1);
    }
    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
    percent = atof(argv[3]);
    if (percent < 0 || percent > 100) {
        printf("Error: percent must be between 0 and 100.\n");
        exit(1);
    }
    
    // Read file into array of lines
    line_count = read_file(input_file, lines);
    
    // Compute maximum number of lines to include in summary
    int max_lines = (int)(percent * line_count / 100);
    if (max_lines == 0) {
        printf("Error: file is too small to produce a summary with the given percentage.\n");
        exit(1);
    }
    
    // Initialize summary
    summary[0] = '\0';
    summary_len = 0;
    
    // Iterate through lines and add those with the most unique words to the summary
    for (i = 0; i < line_count; i++) {
        // Check if line has already been added to summary
        if (strstr(summary, lines[i]) != NULL) {
            continue;
        }
        
        // Count number of unique words in line, excluding those that have already been added to summary
        word_count = 0;
        char *token;
        char *saveptr;
        token = strtok_r(lines[i], " \n", &saveptr);
        while (token != NULL) {
            int unique = 1;
            for (j = 0; j < summary_len; j++) {
                if (summary[j] == '\n') { // Skip line breaks
                    continue;
                }
                if (strncmp(token, &summary[j], strlen(token)) == 0) { // Word has already been added to summary
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                word_count++;
            }
            token = strtok_r(NULL, " \n", &saveptr);
        }
        
        // Add line to summary if it has enough unique words
        if (word_count > 3 && summary_len < MAX_SUMMARY_LEN) {
            add_to_summary(lines[i], summary, &summary_len);
            if (summary_len >= MAX_SUMMARY_LEN) {
                break;
            }
        }
        
        // Stop adding lines to summary if we have reached the maximum number of lines
        if (summary_len > 0 && summary_len/strlen(summary) >= max_lines) {
            break;
        }
    }
    
    // Write summary to output file
    FILE *fp;
    fp = fopen(output_file, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing.\n", output_file);
        exit(1);
    }
    fprintf(fp, "%s", summary);
    fclose(fp);
    
    return 0;
}