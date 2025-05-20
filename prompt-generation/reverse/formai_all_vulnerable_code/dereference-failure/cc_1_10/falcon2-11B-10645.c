//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    char buffer[256];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], portno);

    while (1) {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("Error receiving data");
            break;
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}