//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <file> <output>\n", argv[0]);
        return 1;
    }

    int input_fd = open(argv[1], O_RDONLY);
    if (input_fd == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    struct stat input_stat;
    if (fstat(input_fd, &input_stat) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(input_fd);
        return 1;
    }

    char *input_data = (char *)malloc(input_stat.st_size);
    if (input_data == NULL) {
        printf("Error: Memory allocation failed!\n");
        close(input_fd);
        return 1;
    }

    ssize_t bytes_read = read(input_fd, input_data, input_stat.st_size);
    if (bytes_read!= input_stat.st_size) {
        printf("Error: %s\n", strerror(errno));
        free(input_data);
        close(input_fd);
        return 1;
    }

    close(input_fd);

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: %s\n", strerror(errno));
        free(input_data);
        return 1;
    }

    fwrite(input_data, 1, input_stat.st_size, output_file);
    fclose(output_file);

    free(input_data);
    return 0;
}