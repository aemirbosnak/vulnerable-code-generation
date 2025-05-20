//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char *msg;
    socklen_t size;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);
    printf("Attempting to connect to localhost:%d...\n", portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("ERROR converting address");
        exit(1);
    }

    size = sizeof(serv_addr);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, size) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connection successful!\n");
    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        msg = buffer;
        while (*msg!= '\0') {
            printf("%c", *msg);
            msg++;
        }
        printf("\n");
    }

    close(sockfd);
    return 0;
}