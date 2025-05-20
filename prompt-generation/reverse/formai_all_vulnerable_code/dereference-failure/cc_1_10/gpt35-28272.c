//FormAI DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the file content into a string
char* read_file(char* filename) {
    FILE *file;
    char *content;
    long int size;

    // Open the file in read mode
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file: %s", filename);
        return NULL;
    }

    // Find the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to store the file content
    content = (char*) malloc(size + 1);

    // Read the content of the file into the string
    fread(content, 1, size, file);
    content[size] = '\0';

    // Close the file
    fclose(file);

    return content;
}

// Function to tokenize the string based on the delimiters
char** tokenize(char* str, char* delimiters, int* count) {
    char* token;
    int index = 0;
    char** tokens = (char**) malloc(sizeof(char*) * strlen(str));

    token = strtok(str, delimiters);
    while (token != NULL) {
        tokens[index] = token;
        index++;
        token = strtok(NULL, delimiters);
    }

    *count = index;
    return tokens;
}

// Function to calculate the frequency of each token in the string
int* calculate_frequency(char** tokens, int total_tokens) {
    int* frequency = (int*) malloc(sizeof(int) * total_tokens);
    int i, j;

    for (i = 0; i < total_tokens; i++) {
        frequency[i] = 1;
        for (j = i+1; j < total_tokens; j++) {
            if (strcmp(tokens[i], tokens[j]) == 0) {
                frequency[i]++;
            }
        }
    }

    return frequency;
}

// Function to sort the tokens based on their frequency
void sort_tokens(char** tokens, int* frequency, int total_tokens) {
    int i, j, max_frequency;
    char* temp_token;
    int temp_frequency;

    for (i = 0; i < total_tokens - 1; i++) {
        max_frequency = i;
        for (j = i+1; j < total_tokens; j++) {
            if (frequency[j] > frequency[max_frequency]) {
                max_frequency = j;
            }
        }
        if (max_frequency != i) {
            // Swap the tokens and their frequency
            temp_token = tokens[i];
            tokens[i] = tokens[max_frequency];
            tokens[max_frequency] = temp_token;

            temp_frequency = frequency[i];
            frequency[i] = frequency[max_frequency];
            frequency[max_frequency] = temp_frequency;
        }
    }
}

// Function to print the summary of the text
void print_summary(char** tokens, int* frequency, int total_tokens, int summary_length) {
    int i;

    printf("Summary:\n");
    for (i = 0; i < summary_length; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

// Main function
int main() {
    char* content;
    char** tokens;
    int* frequency;
    int total_tokens;
    int summary_length;

    // Read the file content into a string
    content = read_file("sample.txt");

    // Tokenize the string based on the delimiters
    tokens = tokenize(content, " \n\t", &total_tokens);

    // Calculate the frequency of each token in the string
    frequency = calculate_frequency(tokens, total_tokens);

    // Sort the tokens based on their frequency
    sort_tokens(tokens, frequency, total_tokens);

    // Get the summary length from the user
    printf("Enter the summary length: ");
    scanf("%d", &summary_length);

    // Print the summary of the text
    print_summary(tokens, frequency, total_tokens, summary_length);

    // Free the allocated memory
    free(content);
    free(tokens);
    free(frequency);

    return 0;
}