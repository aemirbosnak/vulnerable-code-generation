//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, ret;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int opt = 1;
    char buffer[MAX];
    char *filename;
    FILE *fp;

    if (argc < 3) {
        printf("Usage:./ftp_client <IP_address> <filename>\n");
        exit(0);
    }

    strcpy(filename, argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    // Set options on the socket
    ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (ret == -1) {
        printf("Error setting socket option\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(PORT);

    // Connect to remote server
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    // Send filename
    send(sockfd, filename, strlen(filename), 0);

    // Receive data from server
    memset(buffer, 0, MAX);
    ret = recv(sockfd, buffer, MAX, 0);
    if (ret == -1) {
        printf("Error receiving data from server\n");
        exit(0);
    }

    printf("Data received from server:\n%s\n", buffer);

    // Open file
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    // Write data to file
    while ((ret = recv(sockfd, buffer, MAX, 0)) > 0) {
        fwrite(buffer, sizeof(char), ret, fp);
    }

    // Close file and socket
    fclose(fp);
    close(sockfd);

    return 0;
}