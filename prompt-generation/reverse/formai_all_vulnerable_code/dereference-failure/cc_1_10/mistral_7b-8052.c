//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    char *hello = "HELLO WORLD FROM C SOCKET PROGRAMMING!";

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS> <PORT_NUMBER>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        die("ERROR connecting");
    }

    write(sockfd, hello, strlen(hello) + 1);
    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;

    char *garbage = "X";
    int j = 0;

    while (j < 10000) {
        int k = rand() % 256;
        garbage[j] = k;
        j++;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi("12345"));
    inet_pton(AF_INET, "192.168.1.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        die("ERROR connecting");
    }

    write(sockfd, garbage, sizeof(garbage));

    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);

    printf("Received: %s\n", buffer);

    close(sockfd);
}