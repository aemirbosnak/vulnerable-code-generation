//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *hostname = strtok(url, "/");
    char *path = strtok(NULL, "");

    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Unable to resolve hostname\n");
        return 1;
    }

    struct sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80);
    remote_addr.sin_addr.s_addr = *(long*)(host->h_addr);

    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        printf("Unable to create socket\n");
        return 1;
    }

    if (connect(socket_desc, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) != 0) {
        printf("Unable to connect to remote host\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];

    snprintf(buffer, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    if (send(socket_desc, buffer, strlen(buffer), 0) == -1) {
        printf("Unable to send request\n");
        return 1;
    }

    int received_bytes = 0;
    int total_bytes = 0;

    memset(buffer, '\0', BUFFER_SIZE);

    while ((received_bytes = recv(socket_desc, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        total_bytes += received_bytes;
        printf("%s", buffer);
        memset(buffer, '\0', BUFFER_SIZE);
    }

    if (received_bytes == -1) {
        printf("Unable to receive response\n");
        return 1;
    }

    printf("\n\nReceived %d bytes from server\n", total_bytes);

    close(socket_desc);

    return 0;
}