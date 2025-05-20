//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void checkResponse(int responseCode) {
    if (responseCode < 200 || responseCode >= 300) {
        fprintf(stderr, "Error: IMAP server returned error code %d\n", responseCode);
        exit(1);
    }
}

int main(int argc, char * argv[]) {

    if (argc < 3) {
        fprintf(stderr, "Usage: %s server_address email_address\n", argv[0]);
        exit(1);
    }

    char * serverAddress = argv[1];
    char * emailAddress = argv[2];

    // Connect to the server
    struct hostent * server = gethostbyname(serverAddress);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve server address\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in serverAddressInfo;
    bzero((char *) &serverAddressInfo, sizeof(serverAddressInfo));
    serverAddressInfo.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&serverAddressInfo.sin_addr.s_addr, server->h_length);
    serverAddressInfo.sin_port = htons(143);

    if (connect(sockfd, (struct sockaddr *) &serverAddressInfo, sizeof(serverAddressInfo)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        exit(1);
    }

    // Wait for server greeting
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Login with email address
    sprintf(buffer, "a1 LOGIN %s\r\n", emailAddress);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    checkResponse(atoi(buffer));

    // Select the INBOX mailbox
    sprintf(buffer, "a2 SELECT INBOX\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    checkResponse(atoi(buffer));

    // Fetch the first 5 messages
    sprintf(buffer, "a3 FETCH 1:5 BODY[]\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);
    checkResponse(atoi(buffer));

    // Quit
    sprintf(buffer, "a4 LOGOUT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}