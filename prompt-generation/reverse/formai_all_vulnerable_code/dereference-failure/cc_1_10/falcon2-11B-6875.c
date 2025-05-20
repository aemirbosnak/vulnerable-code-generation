//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 110
#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, connfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFERSIZE];
    char *user, *password;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    user = argv[1];
    password = argv[2];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server.\n");

    n = read(sockfd, buffer, BUFFERSIZE);
    if (n <= 0) {
        perror("read");
        exit(1);
    }

    printf("Server: %s\n", buffer);

    if (strncmp(buffer, "USER", 4) == 0) {
        write(sockfd, user, strlen(user));
        printf("Sent username: %s\n", user);

        n = read(sockfd, buffer, BUFFERSIZE);
        if (n <= 0) {
            perror("read");
            exit(1);
        }

        printf("Server: %s\n", buffer);

        if (strncmp(buffer, "OK", 2) == 0) {
            write(sockfd, password, strlen(password));
            printf("Sent password: %s\n", password);

            n = read(sockfd, buffer, BUFFERSIZE);
            if (n <= 0) {
                perror("read");
                exit(1);
            }

            printf("Server: %s\n", buffer);

            if (strncmp(buffer, "OK", 2) == 0) {
                printf("Logged in successfully.\n");
            } else {
                printf("Invalid username or password.\n");
            }
        } else {
            printf("Invalid username or password.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    close(sockfd);
    return 0;
}