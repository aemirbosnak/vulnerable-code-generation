//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

struct sockaddr_in server_addr;
int sockfd = 0;
char send_buffer[BUFFER_SIZE];
char recv_buffer[BUFFER_SIZE];

int main() {
    int opt = 1;
    int addrlen = sizeof(server_addr);
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed with error: %d\n", errno);
        exit(0);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("setsockopt failed with error: %d\n", errno);
        exit(0);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, addrlen);
    if (ret == -1) {
        printf("Connect failed with error: %d\n", errno);
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        memset(recv_buffer, 0, BUFFER_SIZE);

        if (send(sockfd, "PING", strlen("PING"), 0) == -1) {
            printf("Send failed with error: %d\n", errno);
            exit(0);
        }

        if (recv(sockfd, recv_buffer, BUFFER_SIZE, 0) == -1) {
            printf("Recv failed with error: %d\n", errno);
            exit(0);
        }

        printf("Received from server: %s\n", recv_buffer);
    }

    close(sockfd);
    return 0;
}