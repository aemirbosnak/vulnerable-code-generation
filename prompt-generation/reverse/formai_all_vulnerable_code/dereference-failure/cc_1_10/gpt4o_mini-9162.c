//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void read_html_file(const char *filename);
int count_words(const char *content);
void process_content(const char *content);
void free_memory(char *content);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_html_file(argv[1]);
    return EXIT_SUCCESS;
}

// Function to read HTML file and return its content
void read_html_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(size + 1);
    if (!content) {
        perror("Failed to allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(content, 1, size, file);
    content[size] = '\0'; // Null-terminate the string

    process_content(content);

    free_memory(content);
    fclose(file);
}

// Function to count the number of words in the content
int count_words(const char *content) {
    int count = 0;
    const char *temp = content;
    
    while (*temp) {
        while (*temp && (*temp == ' ' || *temp == '\n' || *temp == '\t')) 
            temp++; // skip whitespace
        if (*temp) 
            count++; // found a word
        while (*temp && (*temp != ' ' && *temp != '\n' && *temp != '\t')) 
            temp++; // skip the word
    }
    
    return count;
}

// Function to process content from a webpage
void process_content(const char *content) {
    int word_count = count_words(content);
    printf("The number of words in the parsed content is: %d\n", word_count);
}

// Function to free allocated memory
void free_memory(char *content) {
    free(content);
}