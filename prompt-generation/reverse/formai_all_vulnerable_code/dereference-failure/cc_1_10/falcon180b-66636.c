//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

struct rlimit rlim;

void set_limits(int nofile, int memlock) {
    rlim.rlim_cur = nofile;
    rlim.rlim_max = nofile;
    setrlimit(RLIMIT_NOFILE, &rlim);

    rlim.rlim_cur = memlock;
    rlim.rlim_max = memlock;
    setrlimit(RLIMIT_MEMLOCK, &rlim);
}

int main(int argc, char *argv[]) {
    int i, j, k, max_fd, num_processes, memlock;
    pid_t pid;
    struct rusage usage;

    // Check if user is root
    if (getuid()!= 0) {
        printf("You must be root to run this program.\n");
        return 1;
    }

    // Get number of processes from command line argument
    if (argc < 2) {
        printf("Usage: %s <number of processes>\n", argv[0]);
        return 1;
    }
    num_processes = atoi(argv[1]);

    // Get memory lock limit from command line argument
    if (argc < 3) {
        memlock = 65536;
    } else {
        memlock = atoi(argv[2]);
    }

    // Fork num_processes children
    for (i = 0; i < num_processes; i++) {
        pid = fork();

        if (pid < 0) {
            printf("Fork failed.\n");
            return 1;
        } else if (pid == 0) {
            // Child process
            break;
        }
    }

    // Child process
    set_limits(1024, memlock);

    for (j = 0; j < 10; j++) {
        for (k = 0; k < 1000000; k++) {
            sin(k);
        }
    }

    return 0;
}