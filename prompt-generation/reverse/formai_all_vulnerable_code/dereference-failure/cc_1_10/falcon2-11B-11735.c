//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip address> <port number>\n", argv[0]);
        exit(0);
    }

    int sockfd;
    struct sockaddr_in server;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    char buffer[MAXLINE];
    int numbytes;
    char line[MAXLINE];

    while ((numbytes = recv(sockfd, line, MAXLINE, 0)) > 0) {
        printf("%s\n", line);
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "This is a test message\n");
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("ERROR sending message");
            exit(1);
        }
    }

    return 0;
}