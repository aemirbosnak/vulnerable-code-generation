//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    // Define variables
    int sockfd, portno, new_fd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Get port number from command line
    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Bind to port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen
    listen(sockfd, 5);

    // Accept connections
    while (1) {
        new_fd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (new_fd < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[1024];
        printf("Received connection from: ");
        while ((n = read(new_fd, buffer, sizeof(buffer))) > 0) {
            printf("%s", buffer);
        }
        printf("\n");
        close(new_fd);
    }

    return 0;
}