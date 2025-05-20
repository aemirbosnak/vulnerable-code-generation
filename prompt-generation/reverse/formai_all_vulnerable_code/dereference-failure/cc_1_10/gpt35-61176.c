//FormAI DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// function to handle client connections
void handle_client(int sockfd) {
    char buffer[256];
    
    while (1) {
        bzero(buffer,256);
        int n = read(sockfd, buffer, 255); // read message from client

        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        printf("Message received: %s", buffer);

        int m = write(sockfd, "I got your message", 18); // send message to client

        if (m < 0) {
            perror("Error writing to socket");
            exit(1);
        }
    }
}

// main function
int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "Please provide a port number\n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    // configure server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    // listen for incoming connections
    listen(sockfd, 5);
    printf("Server is listening on port %d...\n", portno);

    clilen = sizeof(cli_addr);

    // accept incoming connections and handle them
    while(1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("Error on accept");
            exit(1);
        }

        printf("Connection established with client on port %d\n", ntohs(cli_addr.sin_port));

        handle_client(newsockfd);
    }

    return 0;
}