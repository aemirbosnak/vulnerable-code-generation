//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 80

void scan_network(const char *ip_range) {
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    for(int i = 1; i <= 255; i++) {
        char ip_address[20];
        snprintf(ip_address, 20, "%s.%d", ip_range, i);
        if ((he = gethostbyname(ip_address)) == NULL) {
            continue;
        }
        addr_list = (struct in_addr **) he->h_addr_list;
        printf("Host %s is up (resolved to %s)\n", ip_address, inet_ntoa(*addr_list[0]));
        
        int socket_desc;
        struct sockaddr_in server;

        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            perror("socket");
            exit(1);
        }

        server.sin_addr.s_addr = inet_addr(ip_address);
        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);

        if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d open on %s\n", PORT, ip_address);
        }

        close(socket_desc);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [ip_range]\n", argv[0]);
        exit(1);
    }

    char *ip_range = argv[1];
    scan_network(ip_range);

    return 0;
}