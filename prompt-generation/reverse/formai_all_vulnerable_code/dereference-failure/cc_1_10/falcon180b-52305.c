//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIME_OUT 5

/* Function to print error message and exit */
void error(char *message) {
    perror(message);
    exit(1);
}

/* Function to print usage message */
void usage() {
    printf("Usage:./ping hostname\n");
}

/* Function to send and receive data */
int send_recv(int sock, char *data, int data_len, int timeout) {
    int ret;
    struct timeval tv;

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    ret = setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv));
    if (ret < 0) {
        error("setsockopt");
    }

    ret = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
    if (ret < 0) {
        error("setsockopt");
    }

    ret = send(sock, data, data_len, 0);
    if (ret < 0) {
        error("send");
    }

    memset(data, 0, MAX_DATA);
    ret = recv(sock, data, MAX_DATA, 0);
    if (ret < 0) {
        error("recv");
    }

    return ret;
}

/* Function to ping the host */
int ping(char *hostname, int port) {
    int sock;
    struct sockaddr_in serv_addr;
    char data[MAX_DATA];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        error("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        close(sock);
        return -1;
    }

    send_recv(sock, "PING", strlen("PING"), TIME_OUT);
    close(sock);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        usage();
        exit(1);
    }

    char *hostname = argv[1];
    strncpy(hostname, argv[1], MAX_HOSTNAME);

    int port = 80;

    if (ping(hostname, port) == -1) {
        printf("Host is down\n");
    } else {
        printf("Host is up\n");
    }

    return 0;
}