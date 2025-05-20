//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Host not found\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Socket creation failed - %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, host->h_addr, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed - %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char send_data[MAX_DATA];
    memset(send_data, 'A', MAX_DATA);
    int len = send(sock, send_data, MAX_DATA, 0);
    if (len == -1) {
        printf("Error: Send failed - %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char recv_data[MAX_DATA];
    int recv_len = recv(sock, recv_data, MAX_DATA, 0);
    if (recv_len == -1) {
        printf("Error: Receive failed - %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    close(sock);

    if (recv_len == 0) {
        printf("Host is down or unreachable\n");
    } else {
        printf("Host is up and running\n");
    }

    return 0;
}