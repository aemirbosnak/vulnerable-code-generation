//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BLOCK_SIZE 4096
#define RECOVERY_LIMIT 100
#define DATA_FILE "recovered_data.txt"

void print_error(const char *message) {
    fprintf(stderr, "[ERROR] %s: %s\n", message, strerror(errno));
}

void recover_data(const char *path) {
    int source_fd = open(path, O_RDONLY);
    if (source_fd < 0) {
        print_error("Failed to open source file");
        return;
    }

    FILE *recovered_file = fopen(DATA_FILE, "w");
    if (!recovered_file) {
        print_error("Failed to open recovery file");
        close(source_fd);
        return;
    }

    char buffer[BLOCK_SIZE];
    ssize_t bytes_read;
    int blocks_recovered = 0;

    while ((bytes_read = read(source_fd, buffer, BLOCK_SIZE)) > 0) {
        // Writing the read block to the recovery file
        fwrite(buffer, sizeof(char), bytes_read, recovered_file);
        blocks_recovered++;

        if (blocks_recovered >= RECOVERY_LIMIT) {
            printf("Reached recovery limit of %d blocks.\n", RECOVERY_LIMIT);
            break;
        }
    }

    if (bytes_read < 0) {
        print_error("Error reading from source file");
    } else {
        printf("Successfully recovered %d blocks.\n", blocks_recovered);
    }

    close(source_fd);
    fclose(recovered_file);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <file_to_recover>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Attempt to recover data from the given file
    recover_data(argv[1]);

    printf("Recovery process completed. Check '%s' for recovered data.\n", DATA_FILE);
    return EXIT_SUCCESS;
}