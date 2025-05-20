//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 7
#define MAX 100
#define SA struct sockaddr

void die(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sd, i, j, n, ret, len;
    int maxfd;
    struct hostent *he;
    struct sockaddr_in addr;
    char buf[MAX];
    fd_set readfds;

    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    if ((he = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "gethostbyname error for %s: %s\n", argv[1], hstrerror(h_errno));
        exit(1);
    }

    if (he->h_addrtype!= AF_INET) {
        fprintf(stderr, "Host is not an AF_INET host\n");
        exit(1);
    }

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket");

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sd, (SA *)&addr, sizeof(addr)) < 0)
        die("connect");

    printf("Enter lines, terminated by ^D:\n");
    for (i = 0; i < MAX; i++) {
        if (fgets(buf, MAX, stdin) == NULL)
            break;
        if (buf[0] == 4) {
            buf[strcspn(buf, "\r\n")] = '\0';
            send(sd, buf, strlen(buf), 0);
        }
    }

    close(sd);
    exit(0);
}