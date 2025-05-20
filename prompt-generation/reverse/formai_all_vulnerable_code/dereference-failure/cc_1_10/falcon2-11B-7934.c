//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_IP "192.168.1.1"
#define PORT 12345

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", SERVER_IP, PORT);

    // Send data
    if (send(sockfd, argv[1], strlen(argv[1]), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive data
    if ((n = recv(sockfd, argv[1], sizeof(argv[1]), 0)) < 0) {
        perror("recv");
        exit(1);
    } else {
        printf("Received: %s\n", argv[1]);
    }

    // Close connection
    close(sockfd);

    return 0;
}