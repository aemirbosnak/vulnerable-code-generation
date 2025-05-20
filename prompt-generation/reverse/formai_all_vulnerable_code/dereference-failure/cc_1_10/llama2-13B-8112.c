//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <sys/mman.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_SIZE 1024*1024*10

typedef struct {
    char *filename;
    size_t filesize;
    size_t linesize;
    size_t num_lines;
    size_t total_size;
} file_info_t;

file_info_t *files;
int num_files;

void analyze_log_file(const char *filename) {
    file_info_t *file = calloc(1, sizeof(file_info_t));
    file->filename = strdup(filename);
    file->filesize = 0;
    file->linesize = 0;
    file->num_lines = 0;
    file->total_size = 0;

    // Open the file and read its contents
    FILE *file_ptr = fopen(filename, "r");
    if (!file_ptr) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    size_t line_len;
    while ((line_len = fread(line, 1, MAX_LINE_LENGTH, file_ptr)) > 0) {
        file->linesize += line_len;
        file->num_lines++;
        file->total_size += line_len;
    }

    // Calculate the average line length and print it
    double average_line_len = (double)file->linesize / file->num_lines;
    printf("Average line length: %f\n", average_line_len);

    // Calculate the total file size and print it
    size_t total_file_size = file->filesize + file->total_size;
    printf("Total file size: %zu\n", total_file_size);

    // Add the file to the list of analyzed files
    files = realloc(files, (num_files + 1) * sizeof(file_info_t));
    files[num_files] = *file;
    num_files++;

    // Close the file
    fclose(file_ptr);
}

int main(int argc, char *argv[]) {
    // Check if the user provided any command-line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    // Iterate over the command-line arguments and analyze each log file
    for (int i = 1; i < argc; i++) {
        analyze_log_file(argv[i]);
    }

    // Print the summary of the analyzed files
    printf("Summary of analyzed files:\n");
    for (int i = 0; i < num_files; i++) {
        printf("File %s: %zu lines, %zu bytes\n", files[i].filename, files[i].num_lines, files[i].total_size);
    }

    return 0;
}