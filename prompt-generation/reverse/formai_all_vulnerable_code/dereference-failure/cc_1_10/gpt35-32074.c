//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define BUFFER_SIZE 1024
#define FILENAME "example.txt"

int main(void) {
    int fd = open(FILENAME, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU|S_IRGRP|S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        return errno;
    }
    
    int epoll_fd = epoll_create1(0);
    struct epoll_event event, events[MAX_EVENTS];
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);
    
    char buffer[BUFFER_SIZE];
    bool running = true;
    int event_count = 0;
    
    while (running) {
        event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        for (int i = 0; i < event_count; i++) {
            if (events[i].data.fd == fd) {
                memset(buffer, 0, BUFFER_SIZE);
                int read_result = read(events[i].data.fd, buffer, BUFFER_SIZE);
                if (read_result == 0) {
                    running = false;
                    break;
                }
                if (read_result < 0) {
                    perror("Error reading file");
                    return errno;
                }
                printf("Received message: %s", buffer);
            }
        }
    }
    
    close(fd);
    return 0;
}