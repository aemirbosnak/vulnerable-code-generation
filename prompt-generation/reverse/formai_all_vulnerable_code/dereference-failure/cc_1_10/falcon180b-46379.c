//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char **argv) {
    int sock, opt = TRUE;
    struct sockaddr_in server_addr;
    char buffer[MAX_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    while (opt) {
        bzero(buffer, MAX_SIZE);
        fgets(buffer, MAX_SIZE, stdin);

        if (send(sock, buffer, strlen(buffer), 0)!= strlen(buffer)) {
            printf("Error sending data.\n");
            exit(1);
        }

        bzero(buffer, MAX_SIZE);
        if (recv(sock, buffer, MAX_SIZE, 0) <= 0) {
            printf("Error receiving data.\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sock);
    exit(0);
}