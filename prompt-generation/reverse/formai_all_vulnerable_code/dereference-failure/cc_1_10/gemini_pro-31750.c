//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    printf("Connected to server %s on port %d\n", argv[1], portno);

    while (1) {
        bzero(buffer, BUFSIZE);
        printf("Enter command: ");
        fgets(buffer, BUFSIZE - 1, stdin);

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to server");
            break;
        }

        bzero(buffer, BUFSIZE);
        n = read(sockfd, buffer, BUFSIZE - 1);
        if (n < 0) {
            perror("Error reading from server");
            break;
        }

        printf("Server response: %s", buffer);
    }

    close(sockfd);

    return 0;
}