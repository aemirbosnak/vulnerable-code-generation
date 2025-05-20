//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int sockfd, portno;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    portno = atoi(argv[1]);

    server_addr.sin_port = htons(portno);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    printf("Enter message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[MAX_BUFFER_SIZE];
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("Received: %s\n", response);

    close(sockfd);
    return 0;
}