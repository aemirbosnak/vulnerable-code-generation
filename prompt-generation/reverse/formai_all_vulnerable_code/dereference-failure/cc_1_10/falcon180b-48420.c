//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 110
#define USER "user"
#define PASS "pass"

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char *ptr;
    int n;
    int len;
    char *user = USER;
    char *pass = PASS;

    // Look up the domain name
    if ((host = gethostbyname("localhost")) == NULL) {
        printf("Error: could not resolve host name\n");
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    // Send the username
    len = strlen(user);
    send(sockfd, user, len, 0);

    // Send the password
    len = strlen(pass);
    send(sockfd, pass, len, 0);

    // Receive the welcome message
    n = recv(sockfd, buf, BUF_SIZE, 0);
    buf[n] = '\0';
    printf("Received: %s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}