//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY (IPC_PRIVATE+1000)
#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shm;
    int fd;
    char *filename = "shared_file.txt";
    int filesize;

    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    shm = (char *)shmat(shmid, NULL, 0);
    if ((int)shm == -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Write data to shared memory
    strcpy(shm, "Hello, world!\n");

    // Open the shared file
    fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        printf("Error opening file\n");
        exit(1);
    }

    // Write data to file
    write(fd, shm, strlen(shm));

    // Close the file
    close(fd);

    // Detach from shared memory
    if (shmdt(shm) == -1) {
        printf("Error detaching from shared memory segment\n");
        exit(1);
    }

    // Remove the shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error removing shared memory segment\n");
        exit(1);
    }

    return 0;
}