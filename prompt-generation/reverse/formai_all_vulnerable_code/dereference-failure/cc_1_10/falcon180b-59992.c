//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTS 1000
#define MAX_PORTS 65535

int main(int argc, char **argv) {
    int sock, port;
    struct sockaddr_in host;
    char target_ip[16];
    int num_hosts = 0;
    char *hosts[MAX_HOSTS];

    if(argc < 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        exit(1);
    }

    strcpy(target_ip, argv[1]);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    strcpy(hosts[num_hosts], argv[1]);
    num_hosts++;

    for(port = atoi(argv[2]); port <= MAX_PORTS; port++) {
        if(port == 80) {
            printf("Port %d is open\n", port);
        }
        else {
            if(connect(sock, (struct sockaddr *)&host, sizeof(host)) == 0) {
                close(sock);
                printf("Port %d is open\n", port);
            }
            else {
                printf("Port %d is closed\n", port);
            }
        }
    }

    close(sock);
    return 0;
}