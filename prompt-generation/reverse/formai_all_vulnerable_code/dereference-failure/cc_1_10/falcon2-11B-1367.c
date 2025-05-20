//Falcon2-11B DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char message[100];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    n = read(sockfd, message, sizeof(message));
    if (n <= 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Received: %s\n", message);

    n = write(sockfd, "Hello, World!", sizeof("Hello, World!"));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    printf("Sent: Hello, World!\n");

    close(sockfd);

    return 0;
}