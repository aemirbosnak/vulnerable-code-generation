//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024 * 1024 * 10

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = 80;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *server = gethostbyname(server_ip);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        close(sock);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    char request[MAX_DATA_LEN];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server_ip);

    if (send(sock, request, strlen(request), 0) == -1) {
        printf("Error sending request\n");
        close(sock);
        return 1;
    }

    time_t start_time = time(NULL);
    char buffer[MAX_DATA_LEN];
    int bytes_received = 0;

    while (bytes_received < MAX_DATA_LEN) {
        int result = recv(sock, buffer + bytes_received, MAX_DATA_LEN - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    close(sock);

    time_t end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    double speed = bytes_received / elapsed_time;

    printf("Download speed: %.2f KB/s\n", speed / 1024.0);

    return 0;
}