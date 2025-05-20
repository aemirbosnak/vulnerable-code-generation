//Falcon-180B DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024

int main() {
    char line[MAX_LINE];
    char *args[MAX_LINE];
    int count = 0;
    pid_t pid;
    int status;

    while(fgets(line, MAX_LINE, stdin)!= NULL) {
        count++;
        args[count] = strdup(line);
        args[count][strcspn(args[count], "\n")] = '\0';
    }

    if(count == 0) {
        printf("Error: No command entered.\n");
        exit(1);
    }

    pid = fork();
    if(pid == 0) {
        // Child process
        execvp(args[0], args);
    } else if(pid < 0) {
        printf("Error: Failed to fork.\n");
        exit(1);
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WNOHANG);
        } while(status == 0);
    }

    for(int i = 0; i < count; i++) {
        free(args[i]);
    }

    return 0;
}