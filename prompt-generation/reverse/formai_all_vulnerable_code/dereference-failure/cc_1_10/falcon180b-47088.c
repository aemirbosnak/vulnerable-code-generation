//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define SLEEP_INTERVAL 1

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./ping <host>\n");
        exit(1);
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Invalid hostname\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        sendto(sock, "PING", strlen("PING"), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        usleep(SLEEP_INTERVAL * 1000);
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            if (strcmp(buffer, "PONG") == 0) {
                printf("Host is reachable\n");
                break;
            }
        }
        attempts++;
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Host is not reachable\n");
    }

    close(sock);
    return 0;
}