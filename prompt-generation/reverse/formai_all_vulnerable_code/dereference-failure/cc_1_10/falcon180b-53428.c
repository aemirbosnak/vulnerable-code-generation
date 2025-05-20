//Falcon-180B DATASET v1.0 Category: Networking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100

void fatal(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char buffer[MAX];

    if (argc < 3) {
        printf("Usage:./server <port> <file>\n");
        return 0;
    }

    portno = atoi(argv[1]);
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error: File not found!\n");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Error: Socket creation failed!\n");
        return 0;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Bind failed!\n");
        return 0;
    }

    if (listen(sockfd, 5) < 0) {
        printf("Error: Listen failed!\n");
        return 0;
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("Error: Accept failed!\n");
            continue;
        }

        send(newsockfd, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

        while (fgets(buffer, MAX, file)!= NULL) {
            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    fclose(file);

    return 0;
}