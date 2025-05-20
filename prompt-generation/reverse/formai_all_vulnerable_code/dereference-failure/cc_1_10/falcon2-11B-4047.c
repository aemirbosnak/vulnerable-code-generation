//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

int main()
{
    int fd, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Create a new shared memory segment
    if ((fd = shm_open("/my_shared_memory", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) == -1) {
        perror("shm_open");
        exit(1);
    }

    // Map the shared memory segment into the process address space
    if ((char *)mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0) == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Write some data to the shared memory segment
    sprintf(buffer, "Hello from process 1!\n");
    bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("write");
        exit(1);
    }

    // Read the data from the shared memory segment
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }

    // Print the data that was read from the shared memory segment
    printf("Received: %s\n", buffer);

    // Close the shared memory segment
    close(fd);

    return 0;
}