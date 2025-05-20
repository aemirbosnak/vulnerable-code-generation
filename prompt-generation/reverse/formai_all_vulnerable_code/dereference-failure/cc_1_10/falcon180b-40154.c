//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char sendbuffer[MAX_BUFFER_SIZE], recvbuffer[MAX_BUFFER_SIZE];
    char *token;

    if (argc!= 4) {
        printf("Usage:./client <IP address> <port number> <file name>\n");
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    // Set up server address structure
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    // Send file name to server
    strcpy(sendbuffer, argv[3]);
    send(sockfd, sendbuffer, strlen(sendbuffer), 0);

    // Receive response from server
    n = read(sockfd, recvbuffer, MAX_BUFFER_SIZE);
    recvbuffer[n] = '\0';
    printf("Server response: %s\n", recvbuffer);

    // Receive file from server
    while ((n = read(sockfd, recvbuffer, MAX_BUFFER_SIZE)) > 0) {
        recvbuffer[n] = '\0';
        printf("%s", recvbuffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}