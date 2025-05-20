//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_DATA_SIZE 1024
#define TRUE 1
#define FALSE 0
#define PORT 7

typedef struct hostent HostEnt;

int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME];
    int sock, bytes_sent, bytes_recv, err;
    char data[MAX_DATA_SIZE];
    struct sockaddr_in server;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to %s\n", hostname);
        exit(1);
    }

    while (TRUE) {
        printf("Enter data to send (or type 'quit' to exit): ");
        fgets(data, MAX_DATA_SIZE, stdin);

        if (strcmp(data, "quit") == 0) {
            break;
        }

        bytes_sent = send(sock, data, strlen(data), 0);

        if (bytes_sent == -1) {
            printf("Error sending data\n");
            exit(1);
        }

        bytes_recv = recv(sock, data, MAX_DATA_SIZE, 0);

        if (bytes_recv == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("Received %d bytes of data:\n%s", bytes_recv, data);
    }

    close(sock);
    exit(0);
}