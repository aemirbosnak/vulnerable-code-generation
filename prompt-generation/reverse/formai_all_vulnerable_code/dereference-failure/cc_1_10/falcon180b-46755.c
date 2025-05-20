//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>

#define BUFSIZE 1024
#define SERVER "smtp.example.com"
#define PORT 587

int main(int argc, char *argv[]) {
    int sockfd, n, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFSIZE];
    fd_set master, readfds;
    struct timeval timeout;

    if (argc < 3) {
        printf("Usage: %s [username] [password]\n", argv[0]);
        return 1;
    }

    char *username = argv[1];
    char *password = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    memset(&master, 0, sizeof(master));
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    while (1) {
        master = readfds;
        ret = select(FD_SETSIZE, &master, &readfds, NULL, &timeout);

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            memset(buffer, 0, BUFSIZE);
            fgets(buffer, BUFSIZE, stdin);

            send(sockfd, buffer, strlen(buffer), 0);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            memset(buffer, 0, BUFSIZE);
            n = recv(sockfd, buffer, BUFSIZE, 0);

            if (n <= 0) {
                printf("Server disconnected\n");
                break;
            }

            printf("%s", buffer);
        }
    }

    close(sockfd);
    return 0;
}