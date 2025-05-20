//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[2048];

    if (argc < 2) {
        printf("Error: Please provide a port number\n");
        exit(1);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    puts("Socket created");

    // Set socket options
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not bind socket\n");
        exit(1);
    }

    puts("Socket bound to port");

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error: Could not listen on socket\n");
        exit(1);
    }

    puts("Socket listening for connections");

    // Accept incoming connections
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        printf("Error: Could not accept incoming connection\n");
        exit(1);
    }

    puts("Connection accepted");

    // Send welcome message to client
    ret = send(newsockfd, "Welcome to the future!\n", 28, 0);
    if (ret < 0) {
        printf("Error: Could not send welcome message\n");
        exit(1);
    }

    // Receive data from client
    ret = recv(newsockfd, buffer, 2048, 0);
    if (ret < 0) {
        printf("Error: Could not receive data from client\n");
        exit(1);
    }

    puts("Data received from client:");
    printf("%s", buffer);

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}