//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
// FTP Client Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {

    // Check for correct number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: ./ftpclient hostname port filename\n");
        exit(EXIT_FAILURE);
    }

    // Get hostname, port & filename from command line
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *filename = argv[3];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Convert hostname to IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        perror("Error: No such host exists");
        exit(EXIT_FAILURE);
    }
    char *ip = inet_ntoa(*(struct in_addr *) server->h_addr);

    // Initialize server address structure
    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Could not connect to server");
        exit(EXIT_FAILURE);
    }

    // Send filename to server
    if (send(sockfd, filename, strlen(filename), 0) < 0) {
        perror("Error: Failed to send filename");
        exit(EXIT_FAILURE);
    }

    // Receive confirmation from server
    char response[MAXSIZE] = {0};
    if (recv(sockfd, response, MAXSIZE, 0) < 0) {
        perror("Error: Failed to receive response");
        exit(EXIT_FAILURE);
    }

    // Check if file exists on server
    if (strcmp(response, "FILE NOT FOUND") == 0) {
        printf("Error: File not found on server\n");
        exit(EXIT_FAILURE);
    }

    // Open file for writing
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error: Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Receive file data
    int bytes_recv, total_recv = 0;
    char buffer[MAXSIZE] = {0};
    while ((bytes_recv = recv(sockfd, buffer, MAXSIZE, 0)) > 0) {
        total_recv += bytes_recv;
        fwrite(buffer, sizeof(char), bytes_recv, fp);
    }

    // Close file and socket
    fclose(fp);
    close(sockfd);

    printf("File transfer successful! %d bytes received.\n", total_recv);

    return 0;
}