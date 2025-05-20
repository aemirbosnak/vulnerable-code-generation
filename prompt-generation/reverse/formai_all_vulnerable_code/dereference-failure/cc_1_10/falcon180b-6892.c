//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define BUFFSIZE 1024

void die(char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char *argv[]) {
    int s, ret, i, j, port, count = 0;
    struct sockaddr_in server;
    char buf[BUFFSIZE];

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 0;
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1)
        die("socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &server.sin_addr) == 0) {
        printf("Invalid address/hostname\n");
        return 0;
    }

    for (i = 1; i <= MAX; i++) {
        if (i == atoi(argv[2]))
            continue;

        ret = connect(s, (struct sockaddr *)&server, sizeof(server));
        if (ret!= -1 && ret!= 0) {
            close(s);
            s = -1;
            printf("Port %d is open\n", i);
            count++;
        }
    }

    if (s!= -1)
        close(s);

    if (count == 0)
        printf("No open ports found\n");

    return 0;
}