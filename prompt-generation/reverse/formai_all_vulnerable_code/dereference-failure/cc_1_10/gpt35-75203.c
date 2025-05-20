//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clientlen, n;
    bool connected = false;
    struct sockaddr_in server_address, client_address;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host");
        exit(1);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting");
        exit(1);
    } else {
        printf("Connected!\n");
        connected = true;
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = read(newsockfd, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        if (connected) {
            printf("Proxying data to server...\n");
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("Error writing to socket");
                exit(1);
            }
        } else {
            printf("Proxying data to client...\n");
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0) {
                perror("Error writing to socket");
                exit(1);
            }
        }
    }

    return 0;
}