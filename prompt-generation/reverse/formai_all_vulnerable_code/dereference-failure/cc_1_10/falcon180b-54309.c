//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock, n;
    char buf[BUF_SIZE];
    struct hostent *host;
    struct sockaddr_in server_addr;

    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Could not resolve host %s\n", argv[1]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server %s on port %s\n", argv[1], argv[2]);

    while (fgets(buf, BUF_SIZE, stdin)!= NULL) {
        n = send(sock, buf, strlen(buf), 0);
        if (n == -1) {
            printf("Error: Could not send data\n");
            exit(1);
        }
    }

    close(sock);

    return 0;
}