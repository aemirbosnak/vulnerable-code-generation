//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    int n;
    char *username = "your_username";
    char *password = "your_password";
    char *command = "STAT";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    host = gethostbyname("pop.gmail.com");
    if (host == NULL) {
        fprintf(stderr, "Error: gethostbyname() failed: %s\n", strerror(errno));
        exit(1);
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy(host->h_addr, &serveraddr.sin_addr, host->h_length);
    serveraddr.sin_port = htons(110);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        fprintf(stderr, "Error: connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Connected to POP3 server\n");

    if (send(sockfd, username, strlen(username), 0) == -1) {
        fprintf(stderr, "Error: send() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        fprintf(stderr, "Error: send() failed: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Authenticated\n");

    if (send(sockfd, command, strlen(command), 0) == -1) {
        fprintf(stderr, "Error: send() failed: %s\n", strerror(errno));
        exit(1);
    }

    if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) == -1) {
        fprintf(stderr, "Error: recv() failed: %s\n", strerror(errno));
        exit(1);
    }

    buffer[n] = '\0';
    fprintf(stdout, "Response: %s\n", buffer);

    close(sockfd);
    return 0;
}