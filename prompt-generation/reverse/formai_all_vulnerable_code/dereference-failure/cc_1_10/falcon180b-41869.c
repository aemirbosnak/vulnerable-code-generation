//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file_path> <output_file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    char *output_file_path = argv[2];

    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        printf("Error: Failed to open file %s\n", file_path);
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        printf("Error: Failed to get file status for %s\n", file_path);
        return 1;
    }

    int file_size = st.st_size;
    void *file_data = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        printf("Error: Failed to mmap file %s\n", file_path);
        return 1;
    }

    char *output_data = malloc(file_size);
    if (output_data == NULL) {
        printf("Error: Failed to allocate memory for output data\n");
        return 1;
    }

    int j = 0;
    for (int i = 0; i < file_size; i += PAGE_SIZE) {
        int k = 0;
        while (k < PAGE_SIZE && i + k < file_size) {
            output_data[j++] = ((char *)file_data)[i + k];
            k++;
        }
    }

    munmap(file_data, file_size);
    close(fd);

    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        printf("Error: Failed to open output file %s\n", output_file_path);
        return 1;
    }

    fwrite(output_data, 1, file_size, output_file);
    fclose(output_file);

    free(output_data);

    printf("Done.\n");

    return 0;
}