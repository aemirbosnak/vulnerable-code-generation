//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    // Step 1: Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Step 2: Resolve the server's IP address and port
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    portno = htons(8888);

    // Step 3: Connect to the server
    serv_addr.sin_family = AF_INET;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = *(unsigned long *) server->h_addr;
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Step 4: Send a message to the server
    printf("Enter your message: ");
    fgets(buffer, sizeof(buffer), stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    // Step 5: Receive the response from the server
    bzero(buffer, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server response: %s\n", buffer);

    // Step 6: Close the socket
    close(sockfd);

    return 0;
}