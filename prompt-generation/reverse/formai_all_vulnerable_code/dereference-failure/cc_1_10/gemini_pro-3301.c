//GEMINI-pro DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

// Romeo and Juliet style network communication
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <family> <socket_type>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int family = atoi(argv[1]);
    int socket_type = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(family, socket_type, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address
    struct sockaddr_un addr = { .sun_family = AF_UNIX, .sun_path = "/tmp/romeo" };
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    int connfd = accept(sockfd, NULL, NULL);
    if (connfd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send a message to Juliet
    char buf[BUFSIZE] = "My mistress' eyes are nothing like the sun";
    if (send(connfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive a message from Juliet
    if (recv(connfd, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the message from Juliet
    printf("Juliet says: %s\n", buf);

    // Close the connection
    close(connfd);
    close(sockfd);

    return EXIT_SUCCESS;
}