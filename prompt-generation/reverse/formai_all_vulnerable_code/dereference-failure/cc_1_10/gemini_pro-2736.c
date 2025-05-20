//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Encrypted keys for future use
char *keys[] = {
    "101010110101",
    "110011000110",
    "010100100101",
    "001100110011"
};

// A custom protocol for communication
int protocol(int fd) {
    char buff[256];
    int n;
    
    // Receive encrypted data
    n = recv(fd, buff, sizeof(buff), 0);
    if (n < 0) {
        perror("Error receiving data");
        return -1;
    }

    // Decrypt the data using one of the keys
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            buff[j] ^= keys[i][j % strlen(keys[i])];
        }
    }

    // Print the decrypted message
    printf("%s\n", buff);

    // Send an acknowledgement
    n = send(fd, "ACK", 3, 0);
    if (n < 0) {
        perror("Error sending acknowledgement");
        return -1;
    }

    return 0;
}

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

    // Initialize the server address structure
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        return -1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        return -1;
    }

    while (1) {
        // Accept an incoming connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Handle the connection in a separate thread
        int *pnewsockfd = malloc(sizeof(int));
        *pnewsockfd = newsockfd;
        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *)) protocol, pnewsockfd);
        pthread_detach(thread);
    }

    // Close the socket
    close(sockfd);

    return 0;
}