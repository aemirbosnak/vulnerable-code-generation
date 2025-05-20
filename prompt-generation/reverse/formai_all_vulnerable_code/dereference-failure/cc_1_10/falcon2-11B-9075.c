//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <signal.h>

void sig_handler(int sig) {
    printf("Signal %d received. Exiting...\n", sig);
    exit(0);
}

int main() {
    struct sockaddr_in server;
    struct hostent *host;
    struct sigaction sa;
    int s, portno;

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    if (bind(s, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(s, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((host = gethostbyname("www.example.com")) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    portno = ntohs(*(unsigned short *)host->h_addr_list[0]);

    while (1) {
        if ((portno = accept(s, NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[256];
        int n = read(portno, buffer, sizeof(buffer));

        if (n == 0) {
            close(portno);
            continue;
        }

        if (strcmp(buffer, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n") == 0) {
            close(portno);
            printf("Website is up!\n");
        } else {
            close(portno);
            printf("Website is down!\n");
        }

        sleep(1);
    }

    return 0;
}