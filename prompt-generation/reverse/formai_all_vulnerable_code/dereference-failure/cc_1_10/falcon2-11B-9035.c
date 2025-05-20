//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <net/if.h>
#include <pthread.h>
#include <signal.h>

#define MAX_LINES 100

void signal_handler(int signo) {
    printf("Signal %d received.\n", signo);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, valread, n;
    struct sockaddr_in serverAddr;
    struct hostent *server;
    char recvBuf[MAX_LINES];
    char sendBuf[MAX_LINES];
    char ssid[MAX_LINES];
    char bssid[MAX_LINES];
    char channel[MAX_LINES];
    char rssi[MAX_LINES];
    char quality[MAX_LINES];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: hostname not found\n");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    memcpy(&serverAddr.sin_addr.s_addr, *(long *)server->h_addr, server->h_length);
    serverAddr.sin_port = htons(80);

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: socket() failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        fprintf(stderr, "Error: connect() failed\n");
        exit(1);
    }

    strcpy(recvBuf, "GET / HTTP/1.1\r\nHost: ");
    strcat(recvBuf, argv[1]);
    strcat(recvBuf, "\r\n\r\n");
    write(sockfd, recvBuf, strlen(recvBuf));

    do {
        valread = read(sockfd, recvBuf, MAX_LINES);
        if (valread == -1) {
            perror("Error: read() failed");
            exit(1);
        }
        n = strcspn(recvBuf, "\r\n");
        recvBuf[n] = '\0';

        printf("%s", recvBuf);
        fflush(stdout);

        strcpy(sendBuf, "GET / HTTP/1.1\r\nHost: ");
        strcat(sendBuf, argv[1]);
        strcat(sendBuf, "\r\n\r\n");
        write(sockfd, sendBuf, strlen(sendBuf));
    } while (strcmp(recvBuf, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"));

    printf("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    fflush(stdout);

    return 0;
}