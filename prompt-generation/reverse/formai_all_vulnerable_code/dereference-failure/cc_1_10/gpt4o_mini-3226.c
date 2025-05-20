//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFF_SIZE 4096
#define FILE_EXT ".recov"

void yonder(const char *s, int fd) {
    write(fd, s, strlen(s));
}

void treasure_hunt(const char *input_file) {
    int src_fd, dest_fd;
    char buffer[BUFF_SIZE];
    ssize_t bytes_read;

    if ((src_fd = open(input_file, O_RDONLY)) < 0) {
        perror("Can't open source file");
        return;
    }

    char *output_file = malloc(strlen(input_file) + strlen(FILE_EXT) + 1);
    if (!output_file) {
        perror("Memory allocation failure");
        close(src_fd);
        return;
    }

    snprintf(output_file, strlen(input_file) + strlen(FILE_EXT) + 1, "%s%s", input_file, FILE_EXT);

    if ((dest_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) < 0) {
        perror("Can't open/create destination file");
        close(src_fd);
        free(output_file);
        return;
    }

    while ((bytes_read = read(src_fd, buffer, BUFF_SIZE)) > 0) {
        // This is where the data recovery magic happens
        // Filtering out binary data
        for (ssize_t i = 0; i < bytes_read; i++) {
            if ((buffer[i] >= 32 && buffer[i] <= 126) || buffer[i] == '\n' || buffer[i] == '\r') {
                continue;
            } else {
                buffer[i] = ' '; // replace non-printable chars
            }
        }
        // Write the modified buffer to the recovery file
        write(dest_fd, buffer, bytes_read);
    }

    if (bytes_read < 0) {
        perror("Error reading the source file");
    }

    close(src_fd);
    close(dest_fd);
    free(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_to_recover>\n", argv[0]);
        return EXIT_FAILURE;
    }

    treasure_hunt(argv[1]);
    yonder("Recovery complete! Look for your file with a .recov extension.\n", STDOUT_FILENO);
    return EXIT_SUCCESS;
}