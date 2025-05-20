//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Assign server address and port to struct sockaddr_in
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: hostname could not be resolved\n");
        return 1;
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        return 1;
    }

    // Send data to server
    char buf[100];
    bzero(buf, sizeof(buf));
    printf("Enter a message: ");
    fgets(buf, sizeof(buf), stdin);
    send(sockfd, buf, strlen(buf), 0);

    // Receive data from server
    n = recv(sockfd, buf, sizeof(buf), 0);
    printf("Received: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}