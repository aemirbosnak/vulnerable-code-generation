//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_usage(char* name) {
    printf("Usage: %s <file_name>\n", name);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char* file_name = argv[1];
    int file_descriptor = open(file_name, O_RDONLY);

    if (file_descriptor == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    struct stat file_stat;
    if (fstat(file_descriptor, &file_stat) == -1) {
        printf("Error getting file status: %s\n", strerror(errno));
        return 1;
    }

    char* buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    FILE* recovered_file = fopen("recovered.txt", "w");
    if (recovered_file == NULL) {
        printf("Error creating recovered file\n");
        return 1;
    }

    int bytes_read;
    int total_bytes_read = 0;
    while ((bytes_read = read(file_descriptor, buffer, BUFFER_SIZE)) > 0) {
        total_bytes_read += bytes_read;
        fwrite(buffer, sizeof(char), bytes_read, recovered_file);
    }

    if (bytes_read == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        return 1;
    }

    printf("Recovered %d bytes\n", total_bytes_read);

    close(file_descriptor);
    close(recovered_file);

    return 0;
}