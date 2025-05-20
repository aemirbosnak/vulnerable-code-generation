//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];
    char *ip;
    int port;
    int opt;
    struct hostent *he;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = atoi(argv[2]);

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // set options
    opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // resolve IP address
    he = gethostbyname(ip);
    if (he == NULL) {
        printf("Error resolving IP address\n");
        return 1;
    }
    memcpy(&server.sin_addr.s_addr, he->h_addr, he->h_length);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        // receive data from server
        memset(buffer, 0, BUF_SIZE);
        if (recv(sock, buffer, BUF_SIZE, 0) <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        // print received data
        printf("%s", buffer);
    }

    // close socket
    close(sock);

    return 0;
}