//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, valread;
    struct sockaddr_in servaddr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("ERROR converting IP");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting to server");
        exit(EXIT_FAILURE);
    }

    while (1) {
        valread = read(sockfd, buffer, sizeof(buffer));
        if (valread < 0) {
            perror("ERROR reading from socket");
            exit(EXIT_FAILURE);
        }

        if (valread == 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}