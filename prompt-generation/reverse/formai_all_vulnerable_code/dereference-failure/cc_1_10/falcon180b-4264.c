//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_LINE 1024
#define SERVER_PORT 21
#define USERNAME "anonymous"
#define PASSWORD "anonymous@example.com"
#define FTP_COMMAND "STOR "

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char server_ip[20];
    char *filename;
    char command[100];
    FILE *fp;
    char buffer[MAX_LINE];
    char ch;

    if (argc < 3) {
        printf("Usage: %s <server_ip> <filename>\n", argv[0]);
        exit(0);
    }

    strcpy(server_ip, argv[1]);
    filename = argv[2];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(0);
    }

    // Connect to server
    server = gethostbyname(server_ip);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(0);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: connection failed\n");
        exit(0);
    }

    // Login to server
    sprintf(command, "USER %s\r\n", USERNAME);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, MAX_LINE);
    n = recv(sockfd, buffer, MAX_LINE, 0);
    if (n < 0) {
        printf("Error: failed to receive response\n");
        exit(0);
    }
    printf("Response: %s", buffer);

    sprintf(command, "PASS %s\r\n", PASSWORD);
    send(sockfd, command, strlen(command), 0);
    memset(buffer, 0, MAX_LINE);
    n = recv(sockfd, buffer, MAX_LINE, 0);
    if (n < 0) {
        printf("Error: failed to receive response\n");
        exit(0);
    }
    printf("Response: %s", buffer);

    // Upload file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: failed to open file\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);
    ch = fgetc(fp);
    while (ch!= EOF) {
        send(sockfd, &ch, sizeof(ch), 0);
        memset(buffer, 0, MAX_LINE);
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n < 0) {
            printf("Error: failed to receive response\n");
            exit(0);
        }
        printf("Response: %s", buffer);
        ch = fgetc(fp);
    }
    fclose(fp);

    // Close socket
    close(sockfd);

    return 0;
}