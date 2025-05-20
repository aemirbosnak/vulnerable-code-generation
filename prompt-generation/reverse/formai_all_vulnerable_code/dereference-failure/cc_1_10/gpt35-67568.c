//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char ipAddress[15];

    if (argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    strcpy(ipAddress, argv[1]);

    // create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    printf("Starting TCP Port Scan....\n");
    printf("Scanning Ports 1 to %d on %s ...\n", MAX_PORTS, ipAddress);

    // scan all ports from 1 to MAX_PORTS
    for (int i = 1; i <= MAX_PORTS; i++) {
        server.sin_addr.s_addr = inet_addr(ipAddress);
        server.sin_family = AF_INET;
        server.sin_port = htons(i);

        // connect to the target port
        if (connect(sock , (struct sockaddr *)&server , sizeof(server)) == 0) {
            printf("+");
            fflush(stdout);
            close(sock);
            sock = socket(AF_INET , SOCK_STREAM , 0);
            if (sock == -1) {
                printf("Could not create socket");
                return 1;
            }
        } else {
            printf(".");
            fflush(stdout);
        }
    }

    printf("\n");
    printf("TCP Port Scan Completed.\n");

    return 0;
}