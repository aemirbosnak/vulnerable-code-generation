//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: unknown host\n");
        exit(EXIT_FAILURE);
    }

    portno = htons(PORT);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = portno;
    server_addr.sin_addr.s_addr = *(long *)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return 0;
}