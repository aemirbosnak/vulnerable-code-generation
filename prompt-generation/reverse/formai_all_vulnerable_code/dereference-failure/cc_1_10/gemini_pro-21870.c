//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file into a buffer
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate a buffer for the file contents
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        fclose(file);
        return NULL;
    }

    // Read the file contents into the buffer
    fread(buffer, size, 1, file);
    fclose(file);

    // Add a null-terminator to the end of the buffer
    buffer[size] = '\0';

    return buffer;
}

// Function to write a buffer to a file
int write_file(const char *filename, const char *buffer) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the buffer to the file
    fwrite(buffer, strlen(buffer), 1, file);
    fclose(file);

    return 0;
}

// Function to count the number of words in a string
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

// Function to reverse a string
char *reverse_string(char *str) {
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }

    return str;
}

// Function to print the usage information
void print_usage(const char *program_name) {
    printf("Usage: %s <input_file> <output_file>\n", program_name);
    printf("Example: %s input.txt output.txt\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return -1;
    }

    // Read the input file into a buffer
    char *input_buffer = read_file(argv[1]);
    if (input_buffer == NULL) {
        return -1;
    }

    // Count the number of words in the input buffer
    int word_count = count_words(input_buffer);

    // Reverse the input buffer
    char *reversed_buffer = reverse_string(input_buffer);

    // Write the reversed buffer to the output file
    int write_result = write_file(argv[2], reversed_buffer);
    if (write_result != 0) {
        return -1;
    }

    // Free the input and reversed buffers
    free(input_buffer);
    free(reversed_buffer);

    return 0;
}