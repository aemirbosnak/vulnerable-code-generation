//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

int main(int argc, char **argv)
{
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char *host, *username, *password, *command;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s host username password command\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    username = argv[2];
    password = argv[3];
    command = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);
    ret = inet_pton(AF_INET, host, &serv_addr.sin_addr);
    if (ret <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    ret = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the greeting message from the server
    char buffer[1024];
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // Send the login command to the server
    sprintf(buffer, "LOGIN %s %s\r\n", username, password);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // Send the command to the server
    sprintf(buffer, "%s\r\n", command);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}