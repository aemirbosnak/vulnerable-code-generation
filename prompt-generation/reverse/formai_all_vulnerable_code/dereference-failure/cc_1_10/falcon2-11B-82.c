//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    int fd;
    struct stat st;
    char* buffer;
    int bytesRead;

    // Open the /proc/cpuinfo file
    fd = open("/proc/cpuinfo", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Get the size of the file
    fstat(fd, &st);
    buffer = malloc(st.st_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read the file into memory
    bytesRead = read(fd, buffer, st.st_size);
    if (bytesRead < 0) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
    close(fd);

    // Check if the CPU temperature is available
    int i;
    for (i = 0; i < bytesRead; i++) {
        if (buffer[i] == '\n' && buffer[i+1] == 'C') {
            int temp = atoi(buffer + i + 2);
            printf("CPU Temperature: %d degrees Celsius\n", temp);
            break;
        }
    }

    // Free the memory
    free(buffer);

    return 0;
}