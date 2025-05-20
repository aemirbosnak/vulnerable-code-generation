//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_RECEIVE_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN - 1);
    hostname[MAX_HOSTNAME_LEN - 1] = '\0';

    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char send_buffer[MAX_RECEIVE_BUFFER];
    sprintf(send_buffer, "PING %s\r\n", hostname);

    send(sock, send_buffer, strlen(send_buffer), 0);

    char receive_buffer[MAX_RECEIVE_BUFFER];
    memset(receive_buffer, 0, MAX_RECEIVE_BUFFER);

    int bytes_received = recv(sock, receive_buffer, MAX_RECEIVE_BUFFER, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data from server\n");
        close(sock);
        return 1;
    }

    receive_buffer[bytes_received] = '\0';

    printf("Received response: %s\n", receive_buffer);

    close(sock);
    return 0;
}