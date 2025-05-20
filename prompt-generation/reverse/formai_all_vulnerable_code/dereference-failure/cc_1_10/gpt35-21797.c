//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int imap_client(const char *hostname, const char *username, const char *password)
{
    int sockfd, ret;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr;
    struct hostent *server;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    /* Server address resolution */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        return -1;
    }

    /* Initializing server information */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(143);
    memcpy(&servaddr.sin_addr, server->h_addr, server->h_length);

    /* Connecting to the server */
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("Error connecting to server");
        return -1;
    }

    /* Receiving server greeting message */
    memset(buffer, 0, BUFFER_SIZE);
    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving greeting message");
        return -1;
    }

    printf("%s", buffer);

    /* Sending login credentials */
    snprintf(buffer, BUFFER_SIZE, "LOGIN %s %s\r\n", username, password);
    ret = send(sockfd, buffer, strlen(buffer), 0);
    if (ret < 0) {
        perror("Error sending login credentials");
        return -1;
    }

    /* Receiving login response */
    memset(buffer, 0, BUFFER_SIZE);
    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving login response");
        return -1;
    }

    printf("%s", buffer);

    /* Logout & exit */
    snprintf(buffer, BUFFER_SIZE, "LOGOUT\r\n");
    ret = send(sockfd, buffer, strlen(buffer), 0);
    if (ret < 0) {
        perror("Error sending logout command");
    }

    close(sockfd);

    return 0;
}

int main()
{
    const char *hostname = "imap.example.com";
    const char *username = "exampleuser";
    const char *password = "examplepassword";

    printf("Connecting to IMAP server %s...\n", hostname);
    int ret = imap_client(hostname, username, password);
    if (ret == 0) {
        printf("IMAP session closed\n");
    } else {
        printf("Error closing IMAP session\n");
    }

    return ret;
}