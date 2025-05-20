//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr,"Usage: %s [ip address] [port number]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("ERROR invalid server IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to NeoNet v1.0! Please type your message:\n");

    char buffer[BUFSIZE] = {0};
    while(1) {
        memset(buffer, 0, BUFSIZE);
        fgets(buffer, BUFSIZE, stdin);

        int n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, BUFSIZE);
        n = read(sockfd, buffer, BUFSIZE-1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "Bye", 3) == 0 || strncmp(buffer, "bye", 3) == 0) {
            printf("Server terminates the connection.\n");
            break;
        }

        printf("Server: %s", buffer);
    }

    close(sockfd);

    return 0;
}