//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define MAXBUF 1024
#define TIMEOUT 60

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void sig_handler(int signo)
{
    if(signo == SIGALRM) {
        printf("\nConnection timed out.\n");
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = sig_handler;
    if(sigaction(SIGALRM, &act, NULL) < 0)
        error("Error: setting handler for alarm signal");

    int sock, n, i = 0, total_pkt_cnt = 0, total_bytes = 0;
    char buffer[MAXBUF + 1];
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0)
        error("Error: invalid address");

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("Error: creating socket");

    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
        error("Error: connecting");

    printf("\nConnected to server %s:%s\n", argv[1], argv[2]);

    alarm(TIMEOUT);

    while((n = read(sock, buffer, MAXBUF)) > 0) {
        total_pkt_cnt++;
        total_bytes += n;
        buffer[n] = 0;
        printf("%s", buffer);
        if(++i >= 10) {
            printf("\n");
            i = 0;
        }
        memset(buffer, 0, MAXBUF);
        alarm(TIMEOUT);
    }

    if(n < 0)
        error("Error: reading from socket");

    printf("\nTotal packets received: %d\n", total_pkt_cnt);
    printf("Total bytes received: %d\n\n", total_bytes);

    close(sock);
    return 0;
}