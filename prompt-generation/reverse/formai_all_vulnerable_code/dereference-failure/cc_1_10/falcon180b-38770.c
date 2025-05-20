//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    int fd;
    char *file = "myfile.txt";
    char *p;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, 0, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(2);
    }

    // Open file for reading
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(3);
    }

    // Read file into shared memory segment
    read(fd, shmaddr, SIZE);

    // Close file
    close(fd);

    // Detach shared memory segment from process
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(4);
    }

    exit(0);
}