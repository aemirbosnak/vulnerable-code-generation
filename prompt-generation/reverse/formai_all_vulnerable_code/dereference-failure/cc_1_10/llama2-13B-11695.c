//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096
#define PROCESS_COUNT 4

struct process {
    int pid;
    int fd;
};

void *async_process(void *arg) {
    struct process *proc = arg;
    char *buf = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    size_t bytes_read = 0;

    while (1) {
        ssize_t ret = read(proc->fd, buf + bytes_read, BUFFER_SIZE - bytes_read);
        if (ret < 0) {
            break;
        }
        bytes_read += ret;

        if (bytes_read == BUFFER_SIZE) {
            // Buffer is full, write to file and start new process
            write(proc->fd, buf, bytes_read);
            proc->pid = fork();
            if (proc->pid == 0) {
                // Child process
                close(proc->fd);
                async_process(proc);
            } else {
                // Parent process
                wait(NULL);
            }
            bytes_read = 0;
        }
    }

    munmap(buf, BUFFER_SIZE);
    return NULL;
}

int main() {
    int fd[PROCESS_COUNT];
    struct process proc[PROCESS_COUNT];

    for (int i = 0; i < PROCESS_COUNT; i++) {
        proc[i].pid = fork();
        if (proc[i].pid == 0) {
            // Child process
            close(fd[i]);
            async_process(&proc[i]);
        } else {
            // Parent process
            fd[i] = proc[i].fd;
        }
    }

    for (int i = 0; i < PROCESS_COUNT; i++) {
        wait(NULL);
    }

    return 0;
}