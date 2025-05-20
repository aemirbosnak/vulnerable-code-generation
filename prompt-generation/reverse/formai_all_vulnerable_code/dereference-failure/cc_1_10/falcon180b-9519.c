//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s hostname count\n", argv[0]);
        exit(1);
    }

    char hostname[100];
    strcpy(hostname, argv[1]);
    int count = atoi(argv[2]);

    int sock;
    struct hostent *host;
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);

    if(host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(0);
    server.sin_addr = *(struct in_addr *)host->h_addr;

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buffer[1024];
    int bytes_received;

    for(int i = 0; i < count; i++) {
        memset(buffer, 0, sizeof(buffer));

        send(sock, "PING", strlen("PING"), 0);

        bytes_received = recv(sock, buffer, sizeof(buffer), 0);

        if(bytes_received > 0) {
            printf("PING %d (%d bytes received)\n", i+1, bytes_received);
        } else {
            printf("PING %d failed\n", i+1);
        }

        usleep(100000);
    }

    close(sock);
    return 0;
}