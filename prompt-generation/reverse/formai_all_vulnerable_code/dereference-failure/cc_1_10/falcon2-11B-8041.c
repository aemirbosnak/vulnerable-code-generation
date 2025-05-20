//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 100

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server ip>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        return 1;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(80);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    char buffer[MAX_LEN];
    memset(buffer, 0, sizeof(buffer));

    while (1) {
        int bytes_read = read(sockfd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}