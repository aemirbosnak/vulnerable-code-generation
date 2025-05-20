//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(2);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(3);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(4);
    }

    while (1) {
        printf("Enter message to send: ");
        fgets(buffer, sizeof(buffer), stdin);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send failed");
            exit(5);
        }
        printf("Sent %d bytes\n", n);
        bzero(buffer, sizeof(buffer));
        printf("Enter message to receive: ");
        fgets(buffer, sizeof(buffer), stdin);
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("recv failed");
            exit(6);
        }
        printf("Received %d bytes\n", n);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}