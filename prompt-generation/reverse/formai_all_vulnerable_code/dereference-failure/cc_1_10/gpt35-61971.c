//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define CRLF "\r\n"

int main(int argc, char *argv[]) {
    int sockfd, ret;
    char buffer[BUFFER_SIZE];
    struct addrinfo hints, *result, *rp;
    const char *host = "imap.example.com";
    const char *port = "993";
    const char *user = "username@example.com";
    const char *pass = "password";
    const char *tag = "A01";
    const char *cmd = "CAPABILITY";

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // Use getaddrinfo() to find a list of possible connections
    if ((ret = getaddrinfo(host, port, &hints, &result)) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    // Loop through the list and try to connect to the first one that works
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
            continue;

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break; // Success

        close(sockfd);
    }

    if (rp == NULL) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    // Read the greeting message from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the login command
    sprintf(buffer, "%s LOGIN %s %s%s", tag, user, pass, CRLF);
    send(sockfd, buffer, strlen(buffer), 0);

    // Read the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send the capability command
    sprintf(buffer, "%s %s%s", tag, cmd, CRLF);
    send(sockfd, buffer, strlen(buffer), 0);

    // Read the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}