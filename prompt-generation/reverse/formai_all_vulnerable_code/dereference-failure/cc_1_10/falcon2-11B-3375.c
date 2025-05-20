//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // get server address information
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(9000);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    while (1) {
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }
        printf("Received: %s\n", buffer);
        printf("Enter your message: ");
        scanf("%s", buffer);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}