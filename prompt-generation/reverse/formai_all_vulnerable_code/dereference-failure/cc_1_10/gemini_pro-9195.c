//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAXHOSTNAME 1024

int main(int argc, char **argv)
{
    int sockfd, port;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char hostname[MAXHOSTNAME];
    char buf[BUF_SIZE];
    int n;

    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    if ((server = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s:%d\n", hostname, port);

    while (1) {
        printf("> ");
        if (fgets(buf, BUF_SIZE, stdin) == NULL) {
            break;
        }

        n = strlen(buf);
        if (buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
        }

        if (write(sockfd, buf, n) < 0) {
            perror("write");
            break;
        }

        if (read(sockfd, buf, BUF_SIZE) < 0) {
            perror("read");
            break;
        }

        printf("%s\n", buf);
    }

    close(sockfd);

    return 0;
}