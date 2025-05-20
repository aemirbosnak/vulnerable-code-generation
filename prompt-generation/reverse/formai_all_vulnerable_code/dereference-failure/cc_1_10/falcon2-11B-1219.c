//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server-ip> <port>\n", argv[0]);
        return 1;
    }

    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    portno = atoi(argv[2]);
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to server.\n");
    printf("Enter message to send:\n");
    fgets(buffer, sizeof(buffer), stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    printf("Message sent.\n");

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Received message:\n%s\n", buffer);

    close(sockfd);

    return 0;
}