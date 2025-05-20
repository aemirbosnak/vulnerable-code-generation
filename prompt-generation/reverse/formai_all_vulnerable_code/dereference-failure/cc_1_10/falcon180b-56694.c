//Falcon-180B DATASET v1.0 Category: System administration ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/file.h>

#define BUF_SIZE 1024 // Buffer size for reading and writing

int main() {
    char *cmd = "ls -l"; // command to execute
    char *args[] = {cmd, NULL}; // arguments for command
    pid_t pid; // process id
    int status; // exit status of process
    FILE *fp; // file pointer for reading and writing
    char buf[BUF_SIZE]; // buffer for reading and writing

    // execute command and redirect output to file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    pid = fork();
    if (pid == -1) {
        printf("Error forking\n");
        return 1;
    } else if (pid == 0) {
        dup2(fileno(fp), STDOUT_FILENO); // redirect output to file
        execvp(cmd, args); // execute command
        printf("Error executing command\n");
        return 1;
    } else {
        waitpid(pid, &status, 0); // wait for process to finish
        fclose(fp); // close file
    }

    // read output file and print to console
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fgets(buf, BUF_SIZE, fp)!= NULL) {
        printf("%s", buf);
    }
    fclose(fp);

    return 0;
}