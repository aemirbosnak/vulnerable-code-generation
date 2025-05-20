//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

void send_message(int sockfd, char *msg) {
    send(sockfd, msg, strlen(msg), 0);
}

void receive_message(int sockfd) {
    char buf[256];
    bzero(buf, sizeof(buf));
    ssize_t len = recv(sockfd, buf, sizeof(buf), 0);
    if (len <= 0) {
        perror("Error receiving message");
        exit(1);
    }
    printf("Received message: %s\n", buf);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-ip>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    send_message(sockfd, "Hello, server!");
    receive_message(sockfd);

    close(sockfd);
    return 0;
}