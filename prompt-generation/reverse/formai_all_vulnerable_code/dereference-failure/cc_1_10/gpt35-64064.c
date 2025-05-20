//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_DOMAIN "example.com"
#define SMTP_PORT 25

/* Function to handle errors */
void error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

int main()
{
    /* Variables declaration */
    int sockfd, n;
    int send_size, total_size = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024], message[1024];

    /* DNS lookup */
    server = gethostbyname(SMTP_DOMAIN);
    if (server == NULL) {
        fprintf(stderr,"Cannot resolve hostname: %s\n", SMTP_DOMAIN);
        exit(EXIT_FAILURE);
    }

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    /* Connect to SMTP server */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    /* Read the welcome message from the server */
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("Error reading from server");
    }
    printf("%s", buffer);

    /* Send EHLO message to the server */
    sprintf(message, "EHLO %s\r\n", SMTP_DOMAIN);
    send_size = strlen(message);
    total_size = send(sockfd, message, send_size, 0);
    if (total_size < send_size) {
        error("Error sending command to server");
    }

    /* Read the response from the server */
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("Error reading from server");
    }
    printf("%s", buffer);

    /* Send QUIT message to the server */
    sprintf(message, "QUIT\r\n");
    send_size = strlen(message);
    total_size = send(sockfd, message, send_size, 0);
    if (total_size < send_size) {
        error("Error sending command to server");
    }

    /* Read the response from the server */
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        error("Error reading from server");
    }
    printf("%s", buffer);

    /* Close the socket */
    close(sockfd);

    return 0;
}