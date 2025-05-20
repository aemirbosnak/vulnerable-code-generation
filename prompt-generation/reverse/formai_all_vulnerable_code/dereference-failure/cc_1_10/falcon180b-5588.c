//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/user.h>
#include <sys/ptrace.h>

#define STACK_SIZE (1024*1024) // 1 MB

static int child_stack = 0;
static void *stack_base;
static void *stack_ptr;

static int child_pid;

static void setup_stack() {
    stack_base = mmap(0, STACK_SIZE, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (stack_base == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    stack_ptr = stack_base + STACK_SIZE;
}

static void child_func(int argc, char **argv) {
    char *p;
    p = (char *)stack_ptr;
    *p = 'A';
    p--;
    *p = 'B';
    p--;
    *p = 'C';
    p--;
    *p = 'D';
    p--;
    *p = 'E';
    p--;
    *p = 0;

    while (1) {
        sleep(1);
    }
}

int main(int argc, char **argv) {
    int status;
    pid_t pid;

    setup_stack();

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid > 0) { // parent
        child_pid = pid;
        waitpid(child_pid, &status, 0);
    } else { // child
        child_func(argc, argv);
        exit(0);
    }

    return 0;
}