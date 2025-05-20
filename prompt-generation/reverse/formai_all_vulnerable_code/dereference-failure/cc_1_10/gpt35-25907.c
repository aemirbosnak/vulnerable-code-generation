//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define BUFSIZE 1024        // buffer size
#define SLEEP_DURATION 5    // sleep duration in seconds

bool check_connection_quality(int sockfd, struct sockaddr_in servaddr) {
    fd_set set;
    struct timeval timeout;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    timeout.tv_sec = 5;         // 5 second timeout
    timeout.tv_usec = 0;
    int error;
    socklen_t len = sizeof(error);
    int ret = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len);
    if (ret == 0 && error == 0) {
        char message[BUFSIZE];
        sprintf(message, "Connection to %s:%d established successfully!\n", 
                        inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));
        printf("%s", message);
        return true;
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }
    struct sockaddr_in servaddr;    // server address
    // Creating socket file descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    // Initializing server address structure
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);  // set nonblocking mode
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        if (errno != EINPROGRESS) {
            perror("Connection error");
            exit(1);
        }
    }
    else {
        if (check_connection_quality(sockfd, servaddr)) {
            printf("QoS monitor successfully terminated.\n");
            exit(0);
        }
    }
    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);
    struct timeval timeout;
    timeout.tv_sec = SLEEP_DURATION;
    timeout.tv_usec = 0;
    int num_ready_fds = select(sockfd + 1, NULL, &set, NULL, &timeout);
    if (num_ready_fds < 0) {
        perror("Error in select()");
        exit(EXIT_FAILURE);
    }
    else if (num_ready_fds == 0) {
        char message[BUFSIZE];
        sprintf(message, "Timeout (%d seconds) reached while waiting for connection.\n", SLEEP_DURATION);
        printf("%s", message);
        exit(EXIT_FAILURE);
    }
    else {
        if (check_connection_quality(sockfd, servaddr)) {
            printf("QoS monitor successfully terminated.\n");
            exit(0);
        }
        else {
            perror("Error in check_connection_quality()");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}