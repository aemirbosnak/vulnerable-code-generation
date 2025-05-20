//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <message>\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int port_number = atoi(argv[2]);
    char* message = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error_handling("socket failed");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handling("connect failed");

    send(sockfd, message, strlen(message), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0)
            break;
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}