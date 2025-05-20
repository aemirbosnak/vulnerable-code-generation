//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage:./program [IP address/hostname]\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    struct hostent *host_info;

    if ((host_info = gethostbyname(ip_address)) == NULL) {
        printf("Invalid IP address/hostname\n");
        return 1;
    }

    char *hostname = host_info->h_name;

    printf("Hostname: %s\n", hostname);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(22);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to %s\n", hostname);
        close(sock);
        return 1;
    }

    printf("Connected to %s\n", hostname);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(sock);
            return 1;
        }

        printf("%s", buffer);
    }

    close(sock);
    return 0;
}