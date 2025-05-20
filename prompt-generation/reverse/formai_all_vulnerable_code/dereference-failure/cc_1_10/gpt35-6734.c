//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <IP> <port> <filename>\n", argv[0]);
        exit(0);
    }

    char *filename = argv[3]; // The filename to upload
    int port = atoi(argv[2]); // FTP port
    char *ip = argv[1]; // FTP IP address

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //create socket
    if (sockfd < 0) {
        error("Could not create socket\n");
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(ip);
    serverAddress.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        error("Could not connect to server\n");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer,0,BUFFER_SIZE);

    int file = open(filename, O_RDONLY);
    if (file == -1) {
        error("Could not open file\n");
    }

    int bytes_read = 0;
    while ((bytes_read = read(file, buffer, BUFFER_SIZE)) > 0) {
        if (send(sockfd, buffer, bytes_read, 0) != bytes_read) {
            error("Error sending file\n");
        }
        memset(buffer,0,BUFFER_SIZE);
    }

    close(file);
    close(sockfd);

    printf("File %s was sent successfully\n", filename);
    return 0;
}