//Falcon2-11B DATASET v1.0 Category: Networking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, new_socket, n;
    struct sockaddr_in server_addr;
    char buffer[256];
    char client_message[256];
    char server_message[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        exit(1);
    }

    memset(buffer, '\0', sizeof(buffer));
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    printf("Client: %s\n", argv[1]);

    strcpy(buffer, argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    printf("Sent %d bytes to server.\n", n);

    bzero(buffer, sizeof(buffer));

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0)
        error("ERROR reading from socket");

    printf("Received %d bytes from server.\n", n);

    strcpy(server_message, buffer);
    printf("Server: %s\n", server_message);

    close(sockfd);
    return 0;
}