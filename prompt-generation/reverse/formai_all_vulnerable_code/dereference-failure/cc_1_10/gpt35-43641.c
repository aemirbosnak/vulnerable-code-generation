//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<errno.h>

int main(int argc, char *argv[]) {
    
    int sock, optval, numbytes;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct hostent *server;
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if(argc < 2) {
        printf("Usage: %s [hostname]\n", argv[0]);
        return 0;
    }

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %d\n", errno);
        return 1;
    }

    // Set timeout of 1 second for this socket
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    // Get server hostname
    if((server = gethostbyname(argv[1])) == NULL) {
        printf("Error getting host by name: %d\n", h_errno);
        return 1;
    }

    // Set server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(80);
    bcopy((char*)server->h_addr, (char*)&serverAddr.sin_addr.s_addr, server->h_length);

    // Connect to server
    if(connect(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        printf("Socket connection error: %d\n", errno);
        return 1;
    }

    optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const void*)&optval, sizeof(int));

    // Send HTTP GET request
    sprintf(buffer, "GET /\r\n");
    if(send(sock, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending data: %d\n", errno);
        return 1;
    }

    // Receive server response
    if((numbytes = recv(sock, buffer, sizeof(buffer)-1, 0)) == -1) {
        printf("Error receiving data: %d\n", errno);
        return 1;
    }

    close(sock);

    printf("%s\n", buffer);

    return 0;

}