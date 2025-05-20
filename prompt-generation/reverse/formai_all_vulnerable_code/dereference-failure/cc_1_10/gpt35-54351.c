//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        error("ERROR, no such host");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send user credentials to authenticate
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    while (1) {
        // Get the size of the next email from the server
        snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
        send(sockfd, buffer, strlen(buffer), 0);
        
        // Read the server response
        memset(response, 0, BUFFER_SIZE);
        n = recv(sockfd, response, BUFFER_SIZE, 0);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s", response);

        // Check if there are any emails left
        if (strstr(response, "0 messages") != NULL) {
            break;
        }

        // Parse out the email size and retrieve the email
        char *token = strtok(response, "\r\n");
        while (token != NULL) {
            if (strstr(token, "+OK") != NULL) {
                token = strtok(NULL, "\r\n");
                break;
            }
            token = strtok(NULL, "\r\n");
        }

        snprintf(buffer, BUFFER_SIZE, "RETR %s\r\n", token);
        send(sockfd, buffer, strlen(buffer), 0);

        while (1) {
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (n < 0) {
                error("ERROR reading from socket");
            }
            printf("%s", buffer);
            if (strstr(buffer, ".\r\n") != NULL) {
                break;
            }
        }
    }

    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);
    return 0;
}