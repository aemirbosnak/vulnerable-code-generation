//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOST 100

struct host {
    char name[MAX_HOST];
    char ip[20];
};

int main(int argc, char *argv[]) {
    int sock, port, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int num_hosts = 0;
    struct host hosts[MAX_HOST];

    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    strcpy(hosts[num_hosts].name, "localhost");
    strcpy(hosts[num_hosts].ip, argv[1]);
    num_hosts++;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    port = 1234;
    addrlen = sizeof(struct sockaddr_in);

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for host discovery requests...\n");
        memset(buffer, 0, sizeof(buffer));
        addrlen = sizeof(struct sockaddr_in);
        if (recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, &addrlen) == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", buffer);

        for (int i = 0; i < num_hosts; i++) {
            if (strcmp(buffer, hosts[i].name) == 0) {
                strcpy(client_addr.sin_zero, hosts[i].ip);
                sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_addr, sizeof(struct sockaddr_in));
                break;
            }
        }
    }

    close(sock);
    return 0;
}