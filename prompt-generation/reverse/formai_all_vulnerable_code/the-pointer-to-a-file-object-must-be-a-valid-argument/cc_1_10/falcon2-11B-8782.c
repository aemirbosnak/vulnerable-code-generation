//Falcon2-11B DATASET v1.0 Category: CPU usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

#define BUF_SIZE 1000

int main(int argc, char *argv[])
{
    char buf[BUF_SIZE];
    int pid, status, fd;
    FILE *fp;
    struct stat st;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // child process
        close(0);
        dup(1);
        close(1);
        dup(2);
        close(2);
        open(argv[1], O_WRONLY | O_CREAT, 0600);
        fp = fdopen(fileno(stdin), "r");
        fgets(buf, BUF_SIZE, fp);
        fclose(fp);
        exit(0);
    }

    while (1) {
        if (waitpid(pid, &status, 0) < 0) {
            perror("waitpid");
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Child process %d exited with status %d\n", pid, WEXITSTATUS(status));
            break;
        }
    }

    if (stat(argv[1], &st) < 0) {
        perror("stat");
        return 1;
    }

    fp = fopen(argv[1], "r");
    fgets(buf, BUF_SIZE, fp);
    fclose(fp);

    printf("Child process %d wrote the following to the file:\n%s\n", pid, buf);

    return 0;
}