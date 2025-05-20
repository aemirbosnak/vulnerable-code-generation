//Falcon2-11B DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolving host address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    n = read(sockfd, buffer, sizeof(buffer));
    printf("Received message from server: %s\n", buffer);

    char message[100];
    printf("Enter the message to send to the server: ");
    scanf("%s", message);

    n = write(sockfd, message, sizeof(message));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return 0;
}