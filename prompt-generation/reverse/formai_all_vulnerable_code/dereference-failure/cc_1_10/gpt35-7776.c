//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, nBytes, cliLen;
    char buffer[65536];
    struct sockaddr_in servAddr, cliAddr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Port>\n", argv[0]);
        exit(1);
    }

    if ((sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        error("Failed to create socket!");
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(argv[1]));

    if (bind(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        error("Failed to bind socket!");
    }

    cliLen = sizeof(cliAddr);
    while (1) {
        if ((nBytes=recvfrom(sock, buffer, 65536, 0, (struct sockaddr *)&cliAddr, &cliLen)) < 0) {
            error("Failed to receive packet!");
        }

        printf("Received %d bytes from %s:%d\n", nBytes, inet_ntoa(cliAddr.sin_addr), ntohs(cliAddr.sin_port));

        // Process the packet
        // ...

        printf("Processed packet\n");
    }

    close(sock);

    return 0;
}