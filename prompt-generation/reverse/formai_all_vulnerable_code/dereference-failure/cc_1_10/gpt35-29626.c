//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s [ip address] [port]\n", argv[0]);
        exit(1);
    }

    int sockfd;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to server: %s:%s\n", argv[1], argv[2]);

    char buffer[MAXSIZE];
    memset(buffer, 0, sizeof(buffer));
    ssize_t n;

    while((n = read(sockfd, buffer, MAXSIZE-1)) > 0) {
        buffer[n] = '\0';
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    if(n == 0) {
        printf("Server closed connection\n");
    }
    else {
        perror("Error receiving data from server");
    }

    close(sockfd);
    return 0;
}