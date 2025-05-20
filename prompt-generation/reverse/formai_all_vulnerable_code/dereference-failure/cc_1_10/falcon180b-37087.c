//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP Address/Hostname> <Port>\n", argv[0]);
        return 1;
    }

    char host[MAX_HOST_NAME] = {0};
    strncpy(host, argv[1], MAX_HOST_NAME - 1);

    int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/hostname\n");
        close(sockfd);
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed\n");
        close(sockfd);
        return 1;
    }

    char send_data[MAX_DATA_SIZE] = "PING";
    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA_SIZE] = {0};
    recv(sockfd, recv_data, MAX_DATA_SIZE, 0);

    printf("Received data: %s\n", recv_data);

    close(sockfd);
    return 0;
}