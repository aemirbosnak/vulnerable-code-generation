//FormAI DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <email server address> <email server port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LENGTH];
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, portno, n;

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket.\n");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: host not found.\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    printf("Connected to email server.\n");

    // Send HELLO command to identify the client to the server
    char *hello_msg = "HELLO";
    send(sockfd, hello_msg, strlen(hello_msg), 0);

    memset(buffer, 0, MAX_LENGTH);
    n = recv(sockfd, buffer, MAX_LENGTH, 0);

    if (n < 0) {
        printf("Error receiving response from server.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer);

    // Send QUIT command to close the connection
    char *quit_msg = "QUIT";
    send(sockfd, quit_msg, strlen(quit_msg), 0);

    close(sockfd);

    printf("Disconnected from email server.\n");

    return 0;
}