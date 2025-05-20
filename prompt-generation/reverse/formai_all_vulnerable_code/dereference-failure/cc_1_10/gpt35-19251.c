//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error: opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: no such host: %s\n", argv[1]);
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr_list[0], (char *) &serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: connecting");
        exit(1);
    }

    printf("Enter message: ");
    memset(buffer, 0, BUFSIZE);
    fgets(buffer, BUFSIZE - 1, stdin);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("Error: writing to socket");
        exit(1);
    }

    memset(buffer, 0, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);

    if (n < 0) {
        perror("Error: reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);
    close(sockfd);

    return 0;
}