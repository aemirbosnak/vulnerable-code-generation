//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    int sockfd, valread;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton failed");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        return 1;
    }

    printf("Connected to %s on port %s\n", argv[1], argv[2]);

    while(1) {
        valread = recv(sockfd, buffer, sizeof(buffer), 0);
        if (valread < 0) {
            perror("recv failed");
            return 1;
        } else if (valread == 0) {
            printf("Connection closed\n");
            return 0;
        }
        printf("Received: %s\n", buffer);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    return 0;
}