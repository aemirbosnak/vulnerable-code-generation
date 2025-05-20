//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void handle_client(int socket, char *buffer) {
    char request[1024];
    char response[1024];
    int len;

    len = read(socket, request, 1024);

    printf("Client Request: %s\n", request);

    if(strncmp(request, "GET /", 6) == 0) {
        snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>");
    } else {
        snprintf(response, sizeof(response), "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>");
    }

    len = write(socket, response, strlen(response));
    printf("Response Sent: %s\n", response);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage : %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, '\0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(0);
    }

    if (listen(sockfd, 3) < 0) {
        perror("ERROR on listen");
        exit(0);
    }

    while(1) {
        int newsockfd;
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(0);
        }

        printf("Connection from %s:%d established\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while(1) {
            char buffer[1024];
            int len = read(newsockfd, buffer, sizeof(buffer));
            handle_client(newsockfd, buffer);
        }
    }

    close(sockfd);
    return 0;
}