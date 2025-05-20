//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_DATA_SIZE 1024
#define SERVER_ADDRESS "192.168.1.1"
#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_len;
    char *message = "Hello, World!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to server.\n");

    ret = send(sockfd, message, strlen(message), 0);
    if (ret == -1) {
        printf("Error sending message: %s\n", strerror(errno));
        exit(1);
    }

    printf("Message sent successfully.\n");

    data_len = recv(sockfd, data, MAX_DATA_SIZE, 0);
    if (data_len == -1) {
        printf("Error receiving data: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received data:\n%s\n", data);

    close(sockfd);

    return 0;
}