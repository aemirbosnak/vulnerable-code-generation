//FormAI DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
/* The Adventure of the Networked Client */
/* By Sherlock Holmes, Consulting Programmer */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LINE_LENGTH];
    if (argc < 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(0);
    }

    /* Look up the hostname. */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        return 1;
    }

    /* Create a socket. */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: failed to create socket\n");
        return 1;
    }

    /* Set up the server address. */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    /* Connect to the server. */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr,"Error: failed to connect\n");
        return 1;
    }

    /* Ask the server for its prompt. */
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        fprintf(stderr, "Error: failed to read from socket\n");
        return 1;
    }
    printf("%s", buffer);

    /* Loop, reading and writing data.
     * The client sends a line of text, and the server responds. */
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer) - 1, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            fprintf(stderr, "Error: failed to write to socket\n");
            return 1;
        }
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            fprintf(stderr, "Error: failed to read from socket\n");
            return 1;
        }
        printf("%s", buffer);
    }

    /* Close the socket and exit. */
    close(sockfd);
    return 0;
}