//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: authentic
/* FTP Client Example Program */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024 //Buffer size for sending/receiving messages

int main(int argc, char **argv) {
    int sock; // Socket descriptor
    struct sockaddr_in server_addr; // Server address
    char msg[BUF_SIZE]; // Message to send/receive
    char buffer[BUF_SIZE];
    char filename[BUF_SIZE];
    ssize_t filesize;
    FILE *fp;

    // Check for correct usage
    if(argc != 3) {
        printf("Usage: %s [ip address] [port number]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr)); // Set server address to all null bytes
    server_addr.sin_family = AF_INET; // Set address family to IPv4
    server_addr.sin_addr.s_addr = inet_addr(argv[1]); // Set IP address
    server_addr.sin_port = htons(atoi(argv[2])); // Set port number

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    // Prompt user for filename to download
    printf("Enter filename to download: ");
    scanf("%s", filename);

    // Send filename to server
    if(send(sock, filename, strlen(filename), 0) != strlen(filename)) {
        perror("Filename send failed");
        exit(EXIT_FAILURE);
    }

    // Receive file size from server
    if(recv(sock, &filesize, sizeof(filesize), 0) < 0) {
        perror("File size receive failed");
        exit(EXIT_FAILURE);
    }

    // Open file for writing
    fp = fopen(filename, "wb");
    if(fp == NULL) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    // Receive file data from server
    while(filesize > 0) {
        int bytes_received = recv(sock, buffer, BUF_SIZE, 0);
        fwrite(buffer, 1, bytes_received, fp);
        filesize -= bytes_received;
    }

    // Close file and socket
    fclose(fp);
    close(sock);

    return 0;
}