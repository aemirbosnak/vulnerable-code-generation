//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <syslog.h>
#include <pthread.h>

#define MAX_LINE 1024

void *worker_thread(void *arg) {
    int fd = (int)arg;
    char buf[MAX_LINE];
    int n;
    while ((n = read(fd, buf, MAX_LINE)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }
    if (n == 0) {
        printf("Connection closed\n");
    } else {
        printf("Error reading from socket: %s\n", strerror(errno));
    }
    close(fd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[2]);
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        printf("Error resolving hostname: %s\n", argv[1]);
        return 1;
    }
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];
    if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(fd);
        return 1;
    }
    printf("Connected to server\n");
    pthread_t tid;
    if (pthread_create(&tid, NULL, worker_thread, (void *)fd) != 0) {
        printf("Error creating thread: %s\n", strerror(errno));
        close(fd);
        return 1;
    }
    pthread_detach(tid);
    char buf[MAX_LINE];
    while (1) {
        printf("> ");
        fflush(stdout);
        if (fgets(buf, MAX_LINE, stdin) == NULL) {
            break;
        }
        buf[strlen(buf) - 1] = '\0';  // Remove newline
        if (strcmp(buf, "quit") == 0) {
            break;
        }
        write(fd, buf, strlen(buf) + 1);  // Include null terminator
    }
    close(fd);
    return 0;
}