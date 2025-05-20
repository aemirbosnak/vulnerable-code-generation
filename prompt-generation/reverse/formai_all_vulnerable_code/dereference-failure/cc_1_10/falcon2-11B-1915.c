//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept the connection from the client
        if ((n = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Receive the file name from the client
        if (read(sockfd, argv[2], sizeof(argv[2]))!= sizeof(argv[2])) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Open the file in write mode
        FILE *fp = fopen(argv[2], "w");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open file: %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        // Receive the file data from the client
        char buffer[1024];
        while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
            fwrite(buffer, 1, n, fp);
        }

        // Close the file
        fclose(fp);

        // Close the socket
        close(sockfd);
    }

    return 0;
}