//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct hostent *he = gethostbyname(host);
    if (!he) {
        fprintf(stderr, "Error: could not resolve host '%s'\n", host);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, he->h_addr_list[0], he->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: could not connect to server");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);

    int bytes_sent = send(sockfd, buf, BUFSIZE, 0);
    if (bytes_sent == -1) {
        perror("Error: could not send data");
        exit(EXIT_FAILURE);
    }

    int bytes_recv = recv(sockfd, buf, BUFSIZE, 0);
    if (bytes_recv == -1) {
        perror("Error: could not receive data");
        exit(EXIT_FAILURE);
    }

    printf("Received %d bytes from server: %s\n", bytes_recv, buf);

    close(sockfd);

    return EXIT_SUCCESS;
}