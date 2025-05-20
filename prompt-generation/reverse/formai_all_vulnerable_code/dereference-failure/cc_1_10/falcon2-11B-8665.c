//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd, newfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[1024];

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    // initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind socket to port
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    // listen for incoming connections
    if (listen(sockfd, 3) == -1) {
        perror("listen");
        exit(1);
    }

    // accept incoming connection
    if ((newfd = accept(sockfd, NULL, NULL)) == -1) {
        perror("accept");
        exit(1);
    }

    printf("Connected to server.\n");

    // send file name to server
    strcpy(buffer, argv[1]);
    write(newfd, buffer, strlen(buffer));

    // receive file from server
    n = read(newfd, buffer, 1024);
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Received %d bytes from server.\n", n);

    // close socket
    close(newfd);
    close(sockfd);

    return 0;
}