//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_HEADER "Watermark"
#define MAX_MSG_LEN 100
#define MAX_WATERMARK_LEN 100
#define MAX_FILENAME_LEN 100

void watermark_file(const char *filename, const char *watermark)
{
    // Open file for reading and writing in binary mode
    FILE *file = fopen(filename, "rb+");

    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return;
    }

    // Read watermark header from the file
    char header[strlen(WATERMARK_HEADER) + 1];
    fread(header, sizeof(char), strlen(WATERMARK_HEADER), file);
    header[strlen(WATERMARK_HEADER)] = '\0';

    // Check if file already has watermark
    if (strcmp(header, WATERMARK_HEADER) == 0) {
        fprintf(stderr, "Error: File '%s' already has a watermark\n", filename);
        fclose(file);
        return;
    }

    // Move file pointer to the end and get file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);

    // Move file pointer back to the beginning
    rewind(file);

    // Calculate watermark length and total file size after watermarking
    int watermark_len = strlen(watermark);
    int total_size = file_size + strlen(WATERMARK_HEADER) + watermark_len + 1;

    // Allocate memory for new file data and read file content into it
    char *file_data = (char *)malloc(total_size);
    fread(file_data, sizeof(char), file_size, file);

    // Append watermark to file data
    strcat(file_data, WATERMARK_HEADER);
    strcat(file_data, watermark);

    // Write file data back to file
    rewind(file);
    fwrite(file_data, sizeof(char), total_size, file);

    printf("Watermarked file '%s' with '%s'\n", filename, watermark);

    // Clean up
    free(file_data);
    fclose(file);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename> <watermark>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *watermark = argc > 2 ? argv[2] : "Hello World!";

    watermark_file(filename, watermark);

    return 0;
}