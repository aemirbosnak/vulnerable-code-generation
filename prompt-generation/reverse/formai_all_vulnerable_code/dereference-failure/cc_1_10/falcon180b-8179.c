//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

struct hostent *gethostbyname(const char *name);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address/hostname>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct hostent *host_entry = gethostbyname(ip_address);

    if (host_entry == NULL) {
        herror("gethostbyname");
        return 1;
    }

    char *hostname = inet_ntoa(*(struct in_addr *)host_entry->h_addr);

    printf("Hostname: %s\n", hostname);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    char buffer[BUF_SIZE];
    memset(buffer, 0, BUF_SIZE);

    send(sock, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "), 0);

    int bytes_received = recv(sock, buffer, BUF_SIZE, 0);

    if (bytes_received == -1) {
        perror("recv");
        close(sock);
        return 1;
    }

    buffer[bytes_received] = '\0';

    printf("Received response:\n%s\n", buffer);

    close(sock);

    return 0;
}