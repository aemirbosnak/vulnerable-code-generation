//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    char *server_address = argv[1];
    struct hostent *server = gethostbyname(server_address);

    if (server == NULL) {
        printf("Invalid server address.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}