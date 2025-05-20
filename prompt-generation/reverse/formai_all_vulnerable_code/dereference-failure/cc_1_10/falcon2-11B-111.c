//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 1024

struct buffer_info {
    char buffer[BUF_SIZE];
    int size;
};

typedef struct buffer_info buffer_t;

void handle_client(buffer_t* buffer, int socket) {
    char request[BUF_SIZE];
    int n = read(socket, request, BUF_SIZE - 1);
    if (n == -1) {
        perror("read() failed");
        close(socket);
        return;
    }
    buffer->size = n;
    buffer->buffer[buffer->size] = '\0';
    printf("Received: %s\n", buffer->buffer);
}

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    buffer_t buffer;
    char host[NI_MAXHOST];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    buffer.size = 0;
    buffer.buffer[0] = '\0';

    while (1) {
        handle_client(&buffer, sockfd);
    }

    return 0;
}