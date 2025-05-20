//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the metadata buffer
#define MAX_METADATA_SIZE 1024

// Define the max length of the content type string
#define MAX_CONTENT_TYPE_NAME_LEN 50

// Define the max length of the content length string
#define MAX_CONTENT_LENGTH_LEN 20

// Define the content structure to store the extracted metadata
typedef struct content {
    char* type;                 // Content Type
    char* length;               // Content Length
} content;

// Function to extract the metadata from a given buffer
content extract_metadata(char* buffer) {
    // Allocate memory for the metadata structure
    content metadata;
    metadata.type = calloc(MAX_CONTENT_TYPE_NAME_LEN, sizeof(char));
    metadata.length = calloc(MAX_CONTENT_LENGTH_LEN, sizeof(char));

    // Split the buffer by newline character to get individual metadata lines
    char* line = strtok(buffer, "\n");

    // Loop through the lines until end of file or max size
    while (line != NULL && strlen(line) <= MAX_METADATA_SIZE) {
        // Check each line for Content Type and Content Length
        if (strstr(line, "Content-Type:") != NULL) {
            // Copy the content type into the metadata type field
            char* type_start = strstr(line, "Content-Type:") + strlen("Content-Type:");
            char* type_end = strstr(line, ";") - 1;
            strncpy(metadata.type, type_start, type_end - type_start + 1);
        } else if (strstr(line, "Content-Length:") != NULL) {
            // Copy the content length into the metadata length field
            char* length_start = strstr(line, "Content-Length:") + strlen("Content-Length:");
            char* length_end = line + strlen(line) - 1;
            strncpy(metadata.length, length_start, length_end - length_start + 1);
        }

        // Get the next line
        line = strtok(NULL, "\n");
    }

    // Return the extracted metadata structure
    return metadata;
}

int main() {
    // Create a sample buffer with metadata
    char* test_buffer = "GET /index.html HTTP/1.1\n"
                        "Host: www.example.com\n"
                        "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3\n"
                        "Content-Type: text/html; charset=utf-8\n"
                        "Content-Length: 128\n"
                        "Accept-Language: en-US,en;q=0.8\n\n"
                        "<!DOCTYPE html>\n<html>\n<head>\n<title>Example Page</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n<p>This is an example page.</p>\n</body>\n</html>";

    // Extract the metadata from the sample buffer
    content metadata = extract_metadata(test_buffer);

    // Print the extracted content type and length
    printf("Content Type: %s\nContent Length: %s\n", metadata.type, metadata.length);

    // Free the allocated memory
    free(metadata.type);
    free(metadata.length);

    return 0;
}