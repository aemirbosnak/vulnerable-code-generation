//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in target;
    char buffer[BUFFER_SIZE];
    char *hostname;
    int port;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    ret = inet_pton(AF_INET, hostname, &target.sin_addr);
    if (ret == 0) {
        fprintf(stderr, "Invalid hostname\n");
        exit(1);
    }

    // Connect to target
    ret = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
    if (ret == -1) {
        fprintf(stderr, "Error connecting to target: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Connected to %s:%d\n", hostname, port);

    // Send and receive data
    ret = send(sockfd, "PING", strlen("PING"), 0);
    if (ret == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        exit(1);
    }

    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (ret == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Received %d bytes of data:\n%s\n", ret, buffer);

    close(sockfd);
    return 0;
}