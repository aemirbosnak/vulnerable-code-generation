//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOST_LEN 100

struct host_info {
    int port;
    char host[MAX_HOST_LEN];
};

void init_host_info(struct host_info *info, int port) {
    info->port = port;
    memset(info->host, 0, MAX_HOST_LEN);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    int port_range = atoi(argv[1]);
    if (port_range < 1 || port_range > PORT_RANGE) {
        printf("Invalid port range: %d\n", port_range);
        return 2;
    }

    struct host_info info;
    init_host_info(&info, 0);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 3;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(info.port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char buffer[1024];
    int bytes_read = recv(sock, buffer, 1024, 0);
    if (bytes_read < 0) {
        perror("recv() failed");
        return 4;
    }

    printf("Received packet: %s\n", buffer);

    // Scan for open ports
    for (int i = 1; i <= port_range; i++) {
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(i);
        inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket() failed");
            continue;
        }

        int bytes_written = sendto(sock, buffer, bytes_read, 0,
                                  (struct sockaddr *)&client_addr,
                                  sizeof(client_addr));
        if (bytes_written < 0) {
            perror("sendto() failed");
            close(sock);
            continue;
        }

        close(sock);

        struct host_info *host_info = malloc(sizeof(struct host_info));
        host_info->port = i;
        strcpy(host_info->host, inet_ntoa(client_addr.sin_addr));
        printf("Host %s found on port %d\n", host_info->host, host_info->port);

        // Print the host information
        printf("Host: %s\nPort: %d\n", host_info->host, host_info->port);
    }

    close(sock);

    return 0;
}