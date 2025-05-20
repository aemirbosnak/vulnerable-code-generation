//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv) {
    char *hostname;
    int port;
    struct hostent *host;
    struct sockaddr_in server;
    int sockfd;
    int result;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Invalid hostname\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    result = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (result == -1) {
        printf("Port %d is closed\n", port);
    }
    else {
        printf("Port %d is open\n", port);
        close(sockfd);
    }

    return 0;
}