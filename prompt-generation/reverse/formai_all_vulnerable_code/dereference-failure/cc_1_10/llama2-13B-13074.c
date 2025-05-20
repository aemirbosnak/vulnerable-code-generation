//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100
#define MAX_BUFFER_SIZE 1024 * 1024

void load_file(const char *file_name, char **buffer, size_t *buffer_size) {
    size_t file_size = 0;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);
    *buffer_size = file_size;
    *buffer = malloc(*buffer_size);
    if (*buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return;
    }
    read(fileno(file), *buffer, file_size);
    fclose(file);
}

void save_file(const char *file_name, const char *buffer, size_t buffer_size) {
    size_t written = 0;
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    written = fwrite(buffer, 1, buffer_size, file);
    fclose(file);
    if (written != buffer_size) {
        perror("Failed to write to file");
    }
}

int main() {
    char *buffer = NULL;
    size_t buffer_size = 0;
    const char *file_name = "example.txt";

    // Load file
    load_file(file_name, &buffer, &buffer_size);

    // Print contents of buffer
    printf("File contents:\n");
    for (size_t i = 0; i < buffer_size; i++) {
        printf("%c", buffer[i]);
    }

    // Modify contents of buffer
    buffer[10] = 'X';

    // Save modified buffer to file
    save_file(file_name, buffer, buffer_size);

    // Print contents of modified file
    printf("Modified file contents:\n");
    load_file(file_name, &buffer, &buffer_size);
    for (size_t i = 0; i < buffer_size; i++) {
        printf("%c", buffer[i]);
    }

    return 0;
}