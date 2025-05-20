//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: hostname not found\n");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    char buffer[1024];
    int n;

    printf("Enter your message:\n");
    fgets(buffer, sizeof(buffer), stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    printf("Message sent successfully.\n");

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }

    printf("Server's response:\n%s", buffer);

    close(sockfd);
    return 0;
}