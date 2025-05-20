//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_HOSTNAME_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LENGTH];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LENGTH);
    hostname[MAX_HOSTNAME_LENGTH - 1] = '\0';

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        printf("Error: %s\n", gai_strerror(errno));
        return 1;
    }

    struct sockaddr_in *addr = (struct sockaddr_in *)result->ai_addr;
    char ip_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addr->sin_addr, ip_address, INET_ADDRSTRLEN);

    printf("Pinging %s (%s)...\n", hostname, ip_address);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    if (connect(sock, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Host unreachable\n");
        close(sock);
        return 1;
    }

    printf("Host is reachable\n");
    close(sock);
    return 0;
}