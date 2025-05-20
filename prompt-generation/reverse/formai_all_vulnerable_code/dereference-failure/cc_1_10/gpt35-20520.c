//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s IP_address port_number\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection to server failed");
        exit(1);
    }

    // set the socket options for QoS monitoring
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_PRIORITY, &optval, sizeof(optval)) < 0) {
        perror("setsockopt(SO_PRIORITY) failed");
        exit(1);
    }

    // set the packet marking for QoS monitoring
    int mark = 0x3;
    if (setsockopt(sockfd, SOL_SOCKET, SO_MARK, &mark, sizeof(mark)) < 0) {
        perror("setsockopt(SO_MARK) failed");
        exit(1);
    }

    // send a test message to server
    char test_msg[] = "TEST";
    send(sockfd, test_msg, sizeof(test_msg), 0);

    printf("QoS monitor program started...\n");

    while (1) {
        // receive data from server
        char buffer[1024] = {0};
        int len = recv(sockfd, buffer, sizeof(buffer), 0);
        if (len < 0) {
            perror("recv failed");
            exit(1);
        }

        // print the received data
        printf("Received data: %s", buffer);
    }

    close(sockfd);
    return 0;
}