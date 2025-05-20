//Falcon2-11B DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    char hostname[1024];
    strncpy(hostname, argv[1], sizeof(hostname));

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_read < 0) {
            fprintf(stderr, "Error: Failed to read from socket\n");
            exit(1);
        }

        if (bytes_read == 0) {
            printf("Server disconnected\n");
            break;
        }

        printf("Received: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_written = send(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_written < 0) {
            fprintf(stderr, "Error: Failed to write to socket\n");
            exit(1);
        }

        printf("Sent: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}