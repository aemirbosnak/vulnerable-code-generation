//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAXSIZE 1024

void upload(int sockfd, char *filename) {
    char buff[MAXSIZE];
    int fd = open(filename, O_RDONLY);

    if(fd < 0) { // Error opening file
        printf("Failed to open file\n");
        return;
    }

    int n;
    while((n = read(fd, buff, MAXSIZE)) > 0) {
        send(sockfd, buff, n, 0);
    }

    close(fd);
}

void download(int sockfd, char *filename) {
    char buff[MAXSIZE];
    int fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, 0666);

    if(fd < 0) { //Error creating file
        printf("Failed to create file\n");
        return;
    }

    int n;
    while((n = recv(sockfd, buff, MAXSIZE, 0)) > 0) {
        write(fd, buff, n);
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if(argc != 4) { //Arguments should be IP, PORT, and filename
        printf("Usage: %s <ip> <port> <filename>\n", argv[0]);
        return -1;
    }

    // Creating a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    //Setting the server information
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    //Connecting to server
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    printf("Connected to server\n");

    char *filename = argv[3];

    // Sending file to server
    printf("Uploading %s to server...\n", filename);
    upload(sockfd, filename);
    printf("File uploaded successfully\n");

    // Downloading file from server
    printf("Downloading %s from server...\n", filename);
    download(sockfd, filename);
    printf("File downloaded successfully\n");

    // Closing the socket
    close(sockfd);

    return 0;
}