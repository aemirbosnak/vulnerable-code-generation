//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// function to print error messages
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // check if all required arguments are provided
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    // retrieve file from server
    printf("Enter file name to download:\n");
    memset(buffer, 0, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE-1, stdin);

    // send file name to server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("Error writing to socket");
    }

    // open file for writing
    FILE *file = fopen(strtok(buffer, "\n"), "wb");
    if (!file) {
        error("Error opening file");
    }

    // receive file data from server in chunks and write to file
    memset(buffer, 0, BUFFER_SIZE);
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, file);
    }
    if (n < 0) {
        error("Error receiving file data");
    }

    // close file and socket
    fclose(file);
    close(sockfd);

    printf("File download complete.\n");

    return 0;
}