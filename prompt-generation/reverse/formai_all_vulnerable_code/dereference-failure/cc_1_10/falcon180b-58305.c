//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *server_ip;
    char buffer[1024];
    int n;
    FILE *fp;

    // Get server IP and port from command line arguments
    if (argc!= 3) {
        printf("Usage:./ftp_client <server_ip> <port>\n");
        exit(1);
    }

    server_ip = argv[1];
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Get server address
    server = gethostbyname(server_ip);
    if (server == NULL) {
        printf("Error getting server address\n");
        exit(1);
    }

    // Fill in server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send commands to server
    fp = fopen("commands.txt", "r");
    if (fp == NULL) {
        printf("Error opening commands file\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        printf("Received: %s\n", buffer);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}