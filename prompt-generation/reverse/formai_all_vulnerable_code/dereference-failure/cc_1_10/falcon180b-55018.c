//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_SERVICE_LEN 64
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <data>\n", argv[0]);
        exit(1);
    }

    char host[MAX_HOST_LEN] = {0};
    strncpy(host, argv[1], MAX_HOST_LEN - 1);

    char service[MAX_SERVICE_LEN] = {0};
    strncpy(service, argv[2], MAX_SERVICE_LEN - 1);

    char data[MAX_DATA_LEN] = {0};
    strncpy(data, argv[3], MAX_DATA_LEN - 1);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(service));

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "gethostbyname() failed: %s\n", strerror(errno));
        exit(1);
    }

    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    send(sock, data, strlen(data), 0);

    char buffer[MAX_DATA_LEN] = {0};
    int bytes_received = recv(sock, buffer, MAX_DATA_LEN, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "recv() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received response:\n%s\n", buffer);

    close(sock);
    return 0;
}