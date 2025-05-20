//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOST_NAME 100
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in serv_addr;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        printf("Error: Could not connect to host\n");
        exit(1);
    }

    send(sock, "PING", strlen("PING"), 0);
    ret = recv(sock, data, MAX_DATA_SIZE, 0);
    if (ret == -1) {
        printf("Error: Could not receive data\n");
        exit(1);
    }

    printf("Received data: %s\n", data);

    close(sock);

    return 0;
}