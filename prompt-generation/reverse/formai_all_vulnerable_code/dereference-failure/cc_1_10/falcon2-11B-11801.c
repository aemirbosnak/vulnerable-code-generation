//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <sys/select.h>

void connect_to_imap_server(const char *server, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server_host;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_host = gethostbyname(server);
    if (server_host == NULL) {
        fprintf(stderr, "Hostname lookup failed\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server_host->h_addr, (char *) &server_addr.sin_addr.s_addr, server_host->h_length);
    server_addr.sin_port = htons(143);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char cmd[256];
    sprintf(cmd, "LOGIN %s %s\r\n", username, password);
    send(sockfd, cmd, strlen(cmd), 0);

    char response[256];
    bzero(response, 256);

    int n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", response);
}

int main() {
    connect_to_imap_server("imap.example.com", "username", "password");

    while (1) {
        int n;
        fd_set rfds, wfds;

        FD_ZERO(&rfds);
        FD_ZERO(&wfds);
        FD_SET(0, &rfds);

        n = select(0, &rfds, NULL, NULL, NULL);
        if (n < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(0, &rfds)) {
            char cmd[256];
            char response[256];
            bzero(cmd, 256);
            bzero(response, 256);

            sprintf(cmd, "LIST \"*\"\r\n");
            send(0, cmd, strlen(cmd), 0);

            n = recv(0, response, sizeof(response), 0);
            if (n < 0) {
                perror("Receiving response failed");
                exit(EXIT_FAILURE);
            }

            printf("%s\n", response);
        }
    }

    return 0;
}