//Falcon-180B DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, portno, opt = 1;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(cli_addr);
    int valread;

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 0;
    }

    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0)
        error_handling("socket failed");

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    // Bind
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("bind failed");

    // Listen
    if (listen(sockfd, 5) < 0)
        error_handling("listen");

    printf("Server is listening on IP %s and port %d\n", argv[1], portno);

    while (1) {
        // Accept a connection
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, (socklen_t*)&addrlen);
        if (newsockfd < 0)
            error_handling("accept");

        printf("Connection accepted from IP %s and port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Send welcome message
        strcpy(buffer, "Welcome to the server!");
        send(newsockfd, buffer, strlen(buffer), 0);

        // Receive message
        valread = read(newsockfd, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("Connection closed\n");
            close(newsockfd);
        } else {
            printf("Received message: %s\n", buffer);
            // Send response
            strcpy(buffer, "Hello, client! ");
            send(newsockfd, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}