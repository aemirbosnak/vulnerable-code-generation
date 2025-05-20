//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOST_NAME 100
#define MAX_DATA_SIZE 100
#define WAIT_TIME 5

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./ping <IP Address>\n");
        return 0;
    }

    char hostname[MAX_HOST_NAME];
    strcpy(hostname, argv[1]);

    struct sockaddr_in server;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 0;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
        printf("Connection failed\n");
        return 0;
    }

    char data[MAX_DATA_SIZE];
    sprintf(data, "PING %s\n", hostname);

    send(sock, data, strlen(data), 0);

    char buffer[MAX_DATA_SIZE];
    memset(buffer, 0, sizeof(buffer));

    int bytes_received = recv(sock, buffer, sizeof(buffer), 0);

    if (bytes_received <= 0) {
        printf("No response from server\n");
        return 0;
    }

    printf("Response from server:\n%s\n", buffer);

    close(sock);
    return 0;
}