//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for buffer and maximum file size
#define BUFFER_SIZE 2048
#define MAX_FILE_SIZE 100000

// Declare the xml_parser function
void xml_parser(char* file_string);

int main(int argc, char* argv[]) {
    char* file_string = (char*)malloc(MAX_FILE_SIZE); // Allocate memory for file string
    
    if (file_string == NULL) { // Check if memory allocation was successful
        printf("Error: Memory allocation failed"); // Print error message and exit program
        return 1;
    }
    
    FILE* file = fopen(argv[1], "r"); // Open the file in read mode
    
    if (file == NULL) { // Check if file could be opened successfully
        printf("Error: Could not open file"); // Print error message and exit program
        return 1;
    }
    
    fseek(file, 0L, SEEK_END); // Set file position to end of file
    long file_size = ftell(file); // Get file size in bytes
    rewind(file); // Set file position back to beginning of file
    
    if (file_size > MAX_FILE_SIZE) { // Check if file size is within limit
        printf("Error: File size exceeds limit"); // Print error message and exit program
        return 1;
    }
    
    fread(file_string, file_size, 1, file); // Read file into the file string
    
    fclose(file); // Close the file
    
    xml_parser(file_string); // Call the xml_parser function with the file string as argument
    
    free(file_string); // Free the memory allocated for the file string
    
    return 0; // Exit program
}

// Define the xml_parser function
void xml_parser(char* file_string) {
    char buffer[BUFFER_SIZE]; // Initialize buffer array
    
    char* start_tag = NULL; // Declare pointer for start tag
    char* end_tag = NULL; // Declare pointer for end tag
    
    start_tag = strchr(file_string, '<'); // Find first occurrence of '<' in file string
    
    while (start_tag != NULL) { // Loop through file string until all tags are parsed
        end_tag = strchr(start_tag, '>'); // Find first occurrence of '>' after start tag
        memcpy(buffer, start_tag, end_tag - start_tag + 1); // Copy the tag into the buffer
        buffer[end_tag - start_tag + 1] = '\0'; // Add null terminator to buffer
        
        printf("%s\n", buffer); // Print the tag
        
        start_tag = strchr(end_tag, '<'); // Find next occurrence of '<' after end tag
    }
}