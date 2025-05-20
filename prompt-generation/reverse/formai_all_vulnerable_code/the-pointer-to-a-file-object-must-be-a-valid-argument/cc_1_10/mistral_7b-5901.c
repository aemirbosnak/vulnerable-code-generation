//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define NUM_LINES 10

void die(const char *msg) {
        perror(msg);
        exit(1);
}

int main() {
        int fd, i;
        char *args[NUM_LINES + 2], lines[NUM_LINES][MAX_LINE_LENGTH];
        char filename[] = "input.txt";

        args[0] = "sh";
        args[1] = "-c";

        if ((fd = open(filename, O_RDONLY)) < 0)
                die("Failed to open file");

        int lines_read = 0;
        while (fgets(lines[lines_read], sizeof(lines[lines_read]), fd) != NULL) {
                lines_read++;
                if (lines_read >= NUM_LINES) {
                        fprintf(stderr, "Error: Too many lines in input file\n");
                        close(fd);
                        exit(1);
                }
        }

        close(fd);

        for (i = 0; i < lines_read; i++) {
                args[i + 2] = lines[i];
        }

        args[i + 2] = NULL;

        pid_t pid = fork();

        if (pid < 0) {
                perror("Fork Failed");
                exit(1);
        } else if (pid == 0) {
                execvp(args[0], args);
                perror("Exec Failed");
                exit(1);
        } else {
                wait(NULL);
        }

        return 0;
}