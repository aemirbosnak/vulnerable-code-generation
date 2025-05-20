//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: could not connect to server");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", hostname);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "AUTH LOGIN\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "MAIL FROM: <%s>\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "RCPT TO: <%s>\r\n", argv[6]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "Subject: %s\r\n", argv[7]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "\r\n%s\r\n", argv[8]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, ".\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: could not send data to server");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error: could not receive data from server");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}