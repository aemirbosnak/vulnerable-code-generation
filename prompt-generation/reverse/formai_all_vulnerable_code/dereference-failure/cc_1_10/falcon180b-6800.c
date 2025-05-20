//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    char send_buffer[BUFFER_SIZE];
    strcpy(send_buffer, "PING");
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    char recv_buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if(bytes_received <= 0) {
        printf("Error receiving data from server\n");
        close(sockfd);
        exit(1);
    }

    printf("Received response from server: %s\n", recv_buffer);

    close(sockfd);
    return 0;
}