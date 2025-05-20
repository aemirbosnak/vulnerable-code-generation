//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define BLOCK_SIZE 512
#define MAGIC_NUMBER 0xDEADBEEF

typedef struct {
    int magic;
    char file_name[255];
    char file_data[BLOCK_SIZE - sizeof(int) - 255];
} Block;

void print_usage(const char *prog_name) {
    printf("Usage: %s <device> <output_dir>\n", prog_name);
}

int recover_data(const char *device, const char *output_dir) {
    int fd = open(device, O_RDONLY);
    if (fd == -1) {
        perror("Error opening device");
        return -1;
    }

    Block block;
    ssize_t bytes_read;
    int file_count = 0;

    while ((bytes_read = read(fd, &block, sizeof(block))) > 0) {
        if (block.magic == MAGIC_NUMBER) {
            char output_file[512];
            snprintf(output_file, sizeof(output_file), "%s/%s_%d.dat", output_dir, 
                     block.file_name, file_count++);
            
            FILE *outFile = fopen(output_file, "wb");
            if (!outFile) {
                perror("Error creating output file");
                close(fd);
                return -1;
            }
            
            fwrite(block.file_data, sizeof(block.file_data), 1, outFile);
            fclose(outFile);
            printf("Recovered: %s\n", output_file);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading device");
    }

    close(fd);
    return 0;
}

int create_output_directory(const char *output_dir) {
    if (mkdir(output_dir, 0755) == -1) {
        if (errno != EEXIST) {
            perror("Error creating output directory");
            return -1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *device = argv[1];
    const char *output_dir = argv[2];

    if (create_output_directory(output_dir) == -1) {
        return EXIT_FAILURE;
    }

    if (recover_data(device, output_dir) == -1) {
        return EXIT_FAILURE;
    }

    printf("Data recovery completed successfully.\n");
    return EXIT_SUCCESS;
}