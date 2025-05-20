//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    char send_data[MAX_DATA_SIZE] = "PING";
    int bytes_sent = send(sockfd, send_data, strlen(send_data), 0);
    if (bytes_sent == -1) {
        printf("Error sending data\n");
        close(sockfd);
        exit(1);
    }

    char recv_data[MAX_DATA_SIZE];
    int bytes_received = recv(sockfd, recv_data, MAX_DATA_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving data\n");
        close(sockfd);
        exit(1);
    }

    close(sockfd);

    if (strncmp(recv_data, "PONG", strlen("PONG")) == 0) {
        printf("Server is up and running\n");
    } else {
        printf("Server is down or not responding\n");
    }

    return 0;
}