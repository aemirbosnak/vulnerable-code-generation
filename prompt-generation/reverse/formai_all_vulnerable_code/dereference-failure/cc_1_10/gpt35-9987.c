//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 100 // Max size of watermark to be embedded
#define MAX_FILE_NAME_SIZE 50 // Max size of file name to be embedded in

// Function to embed the watermark by adding a custom string before the content
void embed_watermark(char *file_path, char *watermark) {
    FILE *fp;
    long file_size;
    char *buffer;
    char *file_name = strrchr(file_path, '/') + 1; // Extract file name from path
    char new_file_path[MAX_FILE_NAME_SIZE + strlen(file_path)]; // Modify file path to save as a new file with the embedded watermark

    // Open input file for reading in binary mode
    fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    // Determine file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for file content
    buffer = (char*) malloc(sizeof(char) * file_size);
    if (buffer == NULL) {
        printf("Memory error.\n");
        return;
    }

    // Read file to buffer
    fread(buffer, 1, file_size, fp);

    // Close input file
    fclose(fp);

    // Open output file for writing in binary mode
    strncpy(new_file_path, file_path, strlen(file_path) - strlen(file_name)); // Create new file path
    strcat(new_file_path, watermark); // Add custom string to file path
    strcat(new_file_path, "_"); // Add separator
    strcat(new_file_path, file_name); // Append original file name to new file path
    fp = fopen(new_file_path, "wb");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    // Write watermark to output file
    fprintf(fp, "%s", watermark);

    // Write file content to output file
    fwrite(buffer, 1, file_size, fp);

    // Close output file
    fclose(fp);

    // Free memory
    free(buffer);
}

// Function to extract the watermark by reading the custom string added before the content
void extract_watermark(char *file_path) {
    FILE *fp;
    long file_size;
    char *buffer;
    char *watermark;
    char *file_name = strrchr(file_path, '/') + 1; // Extract file name from path

    // Open input file for reading in binary mode
    fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    // Determine file size
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for file content
    buffer = (char*) malloc(sizeof(char) * file_size);
    if (buffer == NULL) {
        printf("Memory error.\n");
        return;
    }

    // Read file to buffer
    fread(buffer, 1, file_size, fp);

    // Close input file
    fclose(fp);

    // Extract watermark from file content
    watermark = strtok(buffer, "_");
    printf("Watermark: %s\n", watermark);

    // Free memory
    free(buffer);
}

// Main function
int main() {
    char file_path[] = "example.txt"; // Path of file to be watermarked
    char watermark[] = "This is a unique watermark."; // Custom string to be embedded as watermark
    
    embed_watermark(file_path, watermark);
    extract_watermark("This_is_a_unique_watermark._example.txt"); // Example file path after watermarking
    return 0;
}