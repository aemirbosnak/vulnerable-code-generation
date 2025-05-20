//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void ping_host(char* hostname, int port) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[512];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        printf("PING %s (%s): ", hostname, inet_ntoa(serv_addr.sin_addr));
        n = write(sockfd, "PING ", 5);
        if (n < 0) {
            perror("Error sending data");
            exit(1);
        }
        n = read(sockfd, buffer, 512);
        if (n <= 0) {
            perror("Error reading data");
            exit(1);
        }
        printf("%s\n", buffer);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    ping_host(argv[1], atoi(argv[2]));
    return 0;
}