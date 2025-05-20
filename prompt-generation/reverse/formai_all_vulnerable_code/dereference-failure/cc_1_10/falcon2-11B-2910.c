//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 12345
#define MAX_CLIENTS 10
#define MAX_MSG_LEN 256

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX_MSG_LEN], msg[MAX_MSG_LEN];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Resolve server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Bind to socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for client connection
    listen(sockfd, MAX_CLIENTS);

    printf("Server is ready to accept connections\n");

    for (;;) {
        // Accept client connection
        if ((n = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&portno)) == -1) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Receive message from client
        bzero(buffer, MAX_MSG_LEN);
        n = recv(sockfd, buffer, MAX_MSG_LEN, 0);
        if (n == -1) {
            perror("ERROR receiving data");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';

        printf("Received message: %s\n", buffer);

        // Send message to all other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (i!= n) {
                send(sockfd, msg, strlen(msg), 0);
            }
        }

        // Close client connection
        close(sockfd);
    }

    return 0;
}