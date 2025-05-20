//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_PORT_LEN 6
#define BUFFER_SIZE 1024

typedef struct {
    char host[MAX_HOST_LEN];
    char port[MAX_PORT_LEN];
} host_port;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];

    int port_num = atoi(port);
    if (port_num <= 0 || port_num > 65535) {
        printf("Invalid port number\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Error resolving host name\n");
        close(sock);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to host\n");
        close(sock);
        return 1;
    }

    printf("Port %s is open\n", port);
    close(sock);
    return 0;
}