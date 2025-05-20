//FormAI DATASET v1.0 Category: Interprocess communication ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int fd;
    char *ptr;
    const char *name = "/shared_mem"; // name of the shared memory region

    fd = shm_open(name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR); // create shared memory region
    if (fd == -1) {
        perror("Error creating shared memory");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, sizeof(char)*1024) == -1) { // resize shared memory region
        perror("Error resizing shared memory");
        exit(EXIT_FAILURE);
    }

    ptr = (char*) mmap(NULL, sizeof(char)*1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // map shared memory to process memory
    if (ptr == MAP_FAILED) {
        perror("Error mapping shared memory");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork(); // create child process
    if (pid < 0) {
        perror("Error forking child process");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // child process
        printf("Enter message to send: ");
        fgets(ptr, sizeof(char)*1024, stdin); // read input message from user

        if (munmap(ptr, sizeof(char)*1024) == -1) { // unmap shared memory from child process
            perror("Error unmapping shared memory from child process");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
    else { // parent process
        wait(NULL); // wait for child process to complete

        printf("Message received: %s", ptr); // print received message

        if (munmap(ptr, sizeof(char)*1024) == -1) { // unmap shared memory from parent process
            perror("Error unmapping shared memory from parent process");
            exit(EXIT_FAILURE);
        }

        if(shm_unlink(name) == -1){ // remove shared memory region
            perror("Error removing shared memory region");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
}