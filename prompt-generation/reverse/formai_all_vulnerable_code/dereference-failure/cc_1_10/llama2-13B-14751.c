//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char *filename = "example.txt";
    char *buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if(buffer == MAP_FAILED) {
        perror("mmap failed");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        perror("fopen failed");
        munmap(buffer, BUFFER_SIZE);
        return 1;
    }

    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
    if(bytes_read < BUFFER_SIZE) {
        printf("Read %zu bytes\n", bytes_read);
    } else {
        printf("Read entire file\n");
    }

    fclose(file);

    // now we have the entire contents of the file in the buffer
    // let's modify it and write it back to the file
    char *ptr = buffer;
    while(*ptr != '\0') {
        *ptr++ = *ptr + 1;
    }

    FILE *file2 = fopen(filename, "w");
    if(file2 == NULL) {
        perror("fopen failed");
        return 1;
    }
    size_t bytes_written = fwrite(buffer, 1, BUFFER_SIZE, file2);
    if(bytes_written < BUFFER_SIZE) {
        printf("Wrote %zu bytes\n", bytes_written);
    } else {
        printf("Wrote entire file\n");
    }

    fclose(file2);

    munmap(buffer, BUFFER_SIZE);
    return 0;
}