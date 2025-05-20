//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sd, ret;
    struct hostent *he;
    struct sockaddr_in sadr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);

    if ((he = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Host %s not found\n", hostname);
        exit(1);
    }

    memset(&sadr, 0, sizeof(sadr));
    sadr.sin_family = AF_INET;
    sadr.sin_port = htons(7); // Echo port
    memcpy(&sadr.sin_addr, he->h_addr, he->h_length);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket creation failed\n");
        exit(1);
    }

    if (connect(sd, (struct sockaddr *)&sadr, sizeof(sadr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        exit(1);
    }

    strcpy(data, "PING");
    send(sd, data, strlen(data), 0);

    ret = recv(sd, data, MAX_DATA, 0);
    if (ret <= 0) {
        fprintf(stderr, "No response from host\n");
        exit(1);
    }

    printf("Response from %s: %s\n", hostname, data);

    close(sd);
    exit(0);
}