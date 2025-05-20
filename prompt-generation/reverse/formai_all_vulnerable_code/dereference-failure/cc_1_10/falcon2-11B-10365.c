//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 143

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server_name;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((server_name = gethostbyname("localhost")) == NULL) {
        perror("gethostbyname");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a command to the server
    char command[256];
    sprintf(command, "login user%s password%s", argv[1], argv[2]);
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char response[256];
    if (recv(sockfd, response, 256, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response from the server
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}