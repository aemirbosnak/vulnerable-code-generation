//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove excess whitespace from a string
char* trim_whitespace(char* str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate
    *(end + 1) = '\0';

    return str;
}

// Function to capitalize words in a string
void capitalize_words(char* str) {
    int in_word = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        if(isalpha(str[i])) {
            if(!in_word) {
                str[i] = toupper(str[i]);
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }
}

// Function to count words in a string
int count_words(char* str) {
    int count = 0;
    char* token = strtok(str, " \t\n");

    while(token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }

    return count;
}

// Function to count lines in a file
int count_lines(FILE *file) {
    int count = 0;
    char ch;

    while((ch = fgetc(file)) != EOF) {
        if(ch == '\n') {
            count++;
        }
    }

    rewind(file); // reset file position to the beginning
    return count;
}

// Function to read the content of a file into an array
char** read_file_content(char* filename, int* line_count) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return NULL;
    }

    *line_count = count_lines(file);
    char **lines = malloc((*line_count) * sizeof(char*));
    size_t len = 0;

    for(int i = 0; i < *line_count; i++) {
        lines[i] = NULL;
        getline(&lines[i], &len, file); // dynamically allocate memory for each line
        lines[i] = trim_whitespace(lines[i]); // trim whitespaces
        capitalize_words(lines[i]); // capitalize the first letter of each word
    }

    fclose(file);
    return lines;
}

// Function to write processed content to a new file
void write_to_file(char* filename, char** lines, int line_count) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return;
    }

    for(int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", lines[i]); // Write each line to the file
        free(lines[i]); // Free the memory for each line
    }

    free(lines); // Free the array of lines
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    int line_count;
    
    // Read file content and process
    char** lines = read_file_content(input_file, &line_count);
    if(lines == NULL) {
        return EXIT_FAILURE; // Error already printed in read_file_content
    }

    // Write processed content to the output file
    write_to_file(output_file, lines, line_count);

    printf("Processing complete. Check the output file: %s\n", output_file);
    return EXIT_SUCCESS;
}