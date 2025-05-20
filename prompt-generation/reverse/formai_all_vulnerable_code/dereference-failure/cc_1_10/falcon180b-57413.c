//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[BUFFER_SIZE];
    strcpy(hostname, argv[1]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    send(sock, "PING", strlen("PING"), 0);

    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        exit(1);
    }

    printf("Received: %s\n", buffer);

    close(sock);
    return 0;
}