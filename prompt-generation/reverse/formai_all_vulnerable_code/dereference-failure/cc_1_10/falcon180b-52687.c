//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket! ");
        exit(1);
    }

    // Set up server address structure
    server = gethostbyname("127.0.0.1");
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = 8080;
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server! ");
        exit(1);
    }

    // Send message to server
    send(sockfd, "Hello, server! ", strlen("Hello, server! "), 0);

    // Receive message from server
    while (1) {
        bzero(buffer, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("Error receiving message! ");
            exit(1);
        }
        buffer[n] = '\0';
        printf("Server says: %s", buffer);
        if (strcmp(buffer, "Bye! ") == 0) {
            break;
        }
    }

    // Close socket
    close(sockfd);
    return 0;
}