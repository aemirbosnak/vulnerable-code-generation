//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <pthread.h>

#define PORT 5000

int main() {
    // Create a socket
    int sockfd;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Initialize socket variables
    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket to a port
    if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listening");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a connection, blocking if no connections are available
        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd < 0) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        // Read data from the socket
        char buffer[1024];
        bzero(buffer, 1024);
        int bytesRead = recv(clientfd, buffer, 1024, 0);
        if (bytesRead < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        // Process the data
        char* command = strtok(buffer, " ");
        int lightState = atoi(command);
        printf("Received command: %s\n", command);

        // Send response to the client
        send(clientfd, "Success", strlen("Success"), 0);

        // Close the connection
        close(clientfd);
    }

    close(sockfd);
    return 0;
}