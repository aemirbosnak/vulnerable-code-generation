//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10
#define MAGIC_NUMBER 0xCAFEBABE

int main() {
    // Create a new file with a unique name
    char *file_name = malloc(100);
    sprintf(file_name, "unique_file_%d", getpid());

    // Open the file in write-only mode
    int fd = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write some magic numbers to the file
    char magic[10];
    sprintf(magic, "%08x%08x%08x", MAGIC_NUMBER, getpid(), getuid());
    write(fd, magic, strlen(magic));

    // Write some data to the file
    char data[100];
    sprintf(data, "This is a unique file created by process %d", getpid());
    write(fd, data, strlen(data));

    // Set the file size to a random value
    off_t file_size = rand() % MAX_FILE_SIZE;
    lseek(fd, file_size, SEEK_SET);

    // Close the file
    close(fd);

    // Check if the file is still there after a few seconds
    sleep(5);
    if (access(file_name, F_OK) == -1) {
        perror("File has been deleted");
        return 1;
    }

    // Print a success message
    printf("File created successfully\n");

    return 0;
}