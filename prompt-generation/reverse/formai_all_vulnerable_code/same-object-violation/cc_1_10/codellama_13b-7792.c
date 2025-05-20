//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 143
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *command;
    char *response;

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    /* Set up server address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    /* Send command to server */
    command = "a001 CAPABILITY\r\n";
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error sending command");
        exit(1);
    }

    /* Receive response from server */
    response = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (response < 0) {
        perror("Error receiving response");
        exit(1);
    }

    /* Print response */
    printf("Response: %s\n", buffer);

    /* Close socket */
    close(sockfd);

    return 0;
}