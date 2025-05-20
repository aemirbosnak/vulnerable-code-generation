//Falcon2-11B DATASET v1.0 Category: System boot optimizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is less than 2
    if (argc < 2) {
        printf("Usage: %s <service>\n", argv[0]);
        return 1;
    }

    // Check if the specified service is a valid one
    if (strcmp(argv[1], "bootloader")!= 0 &&
        strcmp(argv[1], "kernel")!= 0 &&
        strcmp(argv[1], "initrd")!= 0 &&
        strcmp(argv[1], "init")!= 0 &&
        strcmp(argv[1], "fs")!= 0 &&
        strcmp(argv[1], "network")!= 0 &&
        strcmp(argv[1], "userspace")!= 0 &&
        strcmp(argv[1], "desktop")!= 0 &&
        strcmp(argv[1], "audio")!= 0) {
        printf("Invalid service\n");
        return 1;
    }

    // Create a child process for each service
    pid_t child[10];
    for (int i = 0; i < 10; i++) {
        child[i] = fork();
        if (child[i] < 0) {
            perror("fork");
            return 1;
        } else if (child[i] == 0) {
            // Child process executes the specified service
            switch (i) {
                case 0:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Bootloader'", (char *) NULL);
                    break;
                case 1:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Kernel'", (char *) NULL);
                    break;
                case 2:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Initrd'", (char *) NULL);
                    break;
                case 3:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Init'", (char *) NULL);
                    break;
                case 4:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'FS'", (char *) NULL);
                    break;
                case 5:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Network'", (char *) NULL);
                    break;
                case 6:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Userspace'", (char *) NULL);
                    break;
                case 7:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Desktop'", (char *) NULL);
                    break;
                case 8:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Audio'", (char *) NULL);
                    break;
                case 9:
                    execl("/bin/sh", "/bin/sh", "-c", "sleep 10; echo 'Services'", (char *) NULL);
                    break;
            }
            return 0;
        } else {
            // Parent process waits for all child processes to finish
            int status;
            waitpid(child[i], &status, 0);
        }
    }
    return 0;
}