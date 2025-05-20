//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define READ_END 0
#define WRITE_END 1

int main() {
    int i, n = 5;
    int cpu_usage = 0;
    pid_t pid;
    int fd[2];
    char buffer[25];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        close(fd[READ_END]);

        while (1) {
            cpu_usage = 0;

            // read /proc/stat file to get CPU usage
            FILE* file = fopen("/proc/stat", "r");

            if (file == NULL) {
                perror("fopen");
                exit(1);
            }

            char line[100];
            fgets(line, sizeof(line), file);

            char* token = strtok(line, " ");

            for (i = 0; i < n; i++) {
                token = strtok(NULL, " ");
                cpu_usage += atoi(token);
            }

            fclose(file);

            // write CPU usage to parent process
            sprintf(buffer, "%d", cpu_usage);
            write(fd[WRITE_END], buffer, strlen(buffer)+1);

            // wait 1 second before getting CPU usage again
            sleep(1);
        }

        close(fd[WRITE_END]);
    } else {
        close(fd[WRITE_END]);

        while (1) {
            // read CPU usage from child process
            read(fd[READ_END], buffer, sizeof(buffer));

            printf("CPU usage: %d\n", atoi(buffer));

            // wait 1 second before getting CPU usage again
            sleep(1);
        }

        close(fd[READ_END]);
    }

    return 0;
}