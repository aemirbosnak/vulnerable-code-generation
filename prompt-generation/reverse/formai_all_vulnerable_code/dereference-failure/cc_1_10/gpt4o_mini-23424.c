//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define MAX_FILE_SIZE 104857600 // 100 MB
#define RECOVERED_FILE_PREFIX "recovered_"
#define BUFFER_SIZE 8192

void print_usage() {
    printf("Usage: data_recovery_tool <input_file> <output_file>\n");
}

void recover_data(const char *input_file, const char *output_file) {
    int input_fd = open(input_file, O_RDONLY);
    if (input_fd < 0) {
        perror("Error opening input file");
        return;
    }

    // Create or truncate the output file
    int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (output_fd < 0) {
        perror("Error creating output file");
        close(input_fd);
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("Error writing to output file");
            break;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading input file");
    }

    printf("Recovery complete. Recovered data has been written to %s\n", output_file);
    
    close(input_fd);
    close(output_fd);
}

char *generate_output_filename(char *output_file) {
    char *new_file_name = malloc(strlen(RECOVERED_FILE_PREFIX) + strlen(output_file) + 1);
    if (new_file_name == NULL) {
        perror("Error allocating memory for output file name");
        exit(EXIT_FAILURE);
    }
    sprintf(new_file_name, "%s%s", RECOVERED_FILE_PREFIX, output_file);
    return new_file_name;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Check for file size
    struct stat st;
    if (stat(input_file, &st) == -1) {
        perror("Error getting file size");
        return EXIT_FAILURE;
    }
    if (st.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "Input file is too large. Maximum file size is %d bytes.\n", MAX_FILE_SIZE);
        return EXIT_FAILURE;
    }

    // Generate output filename
    char *recovered_filename = generate_output_filename((char *)output_file);

    // Recover data
    recover_data(input_file, recovered_filename);

    free(recovered_filename);
    return EXIT_SUCCESS;
}