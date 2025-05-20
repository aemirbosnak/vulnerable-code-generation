//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // This is the program that will scan all the ports on your computer
    printf("Welcome to my awesome port scanner!\n");
    printf("I'm about to find out which ports are open on your computer.\n");
    printf("Please hold on while I scan all the ports...\n");

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if (argc < 2) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket!\n");
        exit(0);
    }

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server!\n");
        exit(0);
    }

    // Send some data to the server
    n = send(sockfd, "Hello, world!", 13, 0);
    if (n < 0) {
        printf("Error sending data to server!\n");
        exit(0);
    }

    // Close the socket
    close(sockfd);

    return 0;
}