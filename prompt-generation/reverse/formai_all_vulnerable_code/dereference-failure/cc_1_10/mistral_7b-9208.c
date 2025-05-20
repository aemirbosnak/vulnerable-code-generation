//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 4096
#define FILE_NAME "corrupted_file.bin"
#define MAGIC_NUMBER 0xDEADBEEF

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int fd, ret;
    char buffer[BLOCK_SIZE];
    size_t bytes_read;

    fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) die("Failed to open file.");

    lseek(fd, 0, SEEK_SET);
    if (read(fd, buffer, sizeof(int)) != sizeof(int)) {
        close(fd);
        die("Failed to read magic number.");
    }

    if (*(int*)buffer != MAGIC_NUMBER) {
        printf("This is not our file!\n");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Magic number verified! Starting recovery...\n");

    size_t bytes_to_read = lseek(fd, 0, SEEK_END);
    if (lseek(fd, 0, SEEK_SET) < 0) die("Failed to reset file pointer.");

    char *recovered_data = malloc(bytes_to_read);
    if (!recovered_data) die("Failed to allocate memory for recovered data.");

    for (size_t i = 0; i < bytes_to_read; i += BLOCK_SIZE) {
        if (read(fd, buffer, BLOCK_SIZE) != BLOCK_SIZE) {
            free(recovered_data);
            close(fd);
            die("Failed to read data block.");
        }

        memcpy(recovered_data + i, buffer, BLOCK_SIZE);
    }

    close(fd);

    FILE *output_file = fopen("recovered_file.bin", "wb");
    if (!output_file) die("Failed to create output file.");

    fwrite(recovered_data, bytes_to_read, 1, output_file);
    fclose(output_file);

    free(recovered_data);
    printf("Recovery complete! Check 'recovered_file.bin' for result.\n");

    return EXIT_SUCCESS;
}