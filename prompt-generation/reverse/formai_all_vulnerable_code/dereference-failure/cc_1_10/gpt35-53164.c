//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: medieval
// Medieval style FTP client program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: ./medieval-ftp-client [IP address] [port number]\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0) {
        printf("Error connecting to server.\n");
        return 1;
    }

    printf("Welcome to the Medieval FTP Client!\n");
    printf("Enter a command: ");

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        write(sockfd, buffer, strlen(buffer));
        if (strcmp(buffer, "quit\n") == 0) {
            printf("Closing connection.\n");
            close(sockfd);
            return 0;
        }

        memset(buffer, 0, sizeof(buffer));
        read(sockfd, buffer, sizeof(buffer));

        printf("%s", buffer);
        printf("Enter a command: ");
    }

    return 0;
}