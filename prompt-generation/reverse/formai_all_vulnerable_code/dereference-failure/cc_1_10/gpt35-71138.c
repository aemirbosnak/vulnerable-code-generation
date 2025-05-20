//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    struct hostent *host;
    struct in_addr ip_addr;
    char *host_name;
    int sock, status, protocol, port = 80;
    fd_set read_fd;
    struct timeval tv;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host_name = argv[1];

    if (inet_aton(host_name, &ip_addr)) {
        host = gethostbyaddr(&ip_addr, sizeof(ip_addr), AF_INET);
    } else {
        host = gethostbyname(host_name);
    }

    if (!host) {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = *(long*)host->h_addr;

    protocol = IPPROTO_TCP;

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof server_addr) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&read_fd);
    FD_SET(sock, &read_fd);

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    status = select(sock + 1, &read_fd, NULL, NULL, &tv);

    if (status == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (status == 0) {
        printf("No response.\n");
    } else {
        recv(sock, buffer, sizeof buffer, 0);

        printf("Received:\n%s\n", buffer);
    }

    close(sock);

    return 0;    
}