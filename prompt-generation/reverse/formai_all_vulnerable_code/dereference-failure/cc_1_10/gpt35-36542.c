//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <IP> <PORT> <PATH>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Prepare server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        return 1;
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send HTTP request
    char *request = malloc(BUFFER_SIZE);
    memset(request, 0, BUFFER_SIZE);
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s:%d\r\n\r\n", path, ip, port);
    if(send(sock, request, strlen(request), 0) < 0) {
        perror("send() failed");
        return 1;
    }
    free(request);

    // Receive HTTP response
    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    int total_received = 0;
    int bytes_received;
    while((bytes_received = recv(sock, response+total_received, BUFFER_SIZE-total_received-1, 0)) > 0) {
        total_received += bytes_received;
        if(total_received >= BUFFER_SIZE-1) {
            break;
        }
    }
    if(bytes_received < 0) {
        perror("recv() failed");
        return 1;
    }

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(sock);

    return 0;
}