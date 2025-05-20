//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <signal.h>
#include <unistd.h>

void start_server(const char *port) {
    int sockfd;
    int newsockfd;
    int clength;
    int n;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not open socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(port));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Could not bind socket");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        clength = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clength);
        if (newsockfd < 0) {
            perror("Error: Could not accept connection");
            exit(1);
        }

        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("Error: Could not read from socket");
            exit(1);
        }

        printf("Here is the message: %s\n", buffer);

        bzero(buffer, 256);
        strcpy(buffer, "HTTP/1.1 200 OK\r\n\r\n<html>\n\t<head>\n\t\t<title>Thank You</title>\n\t</head>\n\t<body>\n\t\t<h1>Thank you for connecting!</h1>\n\t</body>\n</html>");
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error: Could not write to socket");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    start_server(argv[1]);

    return 0;
}