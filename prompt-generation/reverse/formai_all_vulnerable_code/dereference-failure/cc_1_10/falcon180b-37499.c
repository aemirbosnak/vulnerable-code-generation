//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE], recvbuffer[BUFFER_SIZE];
    int valid_input = 0, bytes_sent, bytes_received;
    char *filename = NULL;
    FILE *fp;

    // Check if correct number of arguments provided
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <filename>\n", argv[0]);
        exit(1);
    }

    // Get hostname and port from command line arguments
    strcpy(sendbuffer, argv[1]);
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed\n");
        exit(1);
    }

    // Set up server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, sendbuffer, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed\n");
        exit(1);
    }

    // Get filename from command line arguments
    strcpy(sendbuffer, argv[3]);

    // Send filename to server
    if (send(sockfd, sendbuffer, strlen(sendbuffer), 0) < 0) {
        printf("Send failed\n");
        exit(1);
    }

    // Receive response from server
    if ((bytes_received = recv(sockfd, recvbuffer, BUFFER_SIZE, 0)) <= 0) {
        printf("Receive failed\n");
        exit(1);
    }

    // Print response from server
    printf("Response from server: %s\n", recvbuffer);

    // Open file for writing
    filename = strtok(recvbuffer, " ");
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    // Receive file from server
    while ((bytes_received = recv(sockfd, recvbuffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(recvbuffer, 1, bytes_received, fp);
    }

    // Close file and socket
    fclose(fp);
    close(sockfd);

    return 0;
}