//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

struct sockaddr_in server_addr;
int sock;
char buffer[BUFFER_SIZE];

int main(int argc, char *argv[]) {
    int port = 8080;
    char *ip = "127.0.0.1";

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    if (argc > 2) {
        ip = argv[2];
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", buffer);
    }

    close(sock);

    return 0;
}