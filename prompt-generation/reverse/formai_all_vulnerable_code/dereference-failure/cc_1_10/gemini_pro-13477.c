//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *hp;
    struct sockaddr_in server;

    if ((hp = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        return EXIT_FAILURE;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    memcpy((char *) &server.sin_addr, hp->h_addr, hp->h_length);

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect()");
        return EXIT_FAILURE;
    }

    char buf[BUFSIZE];
    int nbytes;
    while ((nbytes = read(sockfd, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, nbytes) == -1) {
            perror("write()");
            return EXIT_FAILURE;
        }
    }

    if (nbytes == -1) {
        perror("read()");
        return EXIT_FAILURE;
    }

    if (close(sockfd) == -1) {
        perror("close()");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}