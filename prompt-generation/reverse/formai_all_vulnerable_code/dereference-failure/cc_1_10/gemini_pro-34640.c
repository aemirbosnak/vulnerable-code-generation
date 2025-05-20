//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        printf("Error: Could not resolve hostname\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *) *host->h_addr_list;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Could not create socket");
        return EXIT_FAILURE;
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("Error: Could not set socket timeout");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        printf("Error: Could not connect to host\n");
        return EXIT_FAILURE;
    }

    printf("Pinging %s (%s)...\n", argv[1], inet_ntoa(addr.sin_addr));

    char buffer[4096];
    ssize_t bytes_read;
    while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0) {
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        perror("Error: Could not read from host");
        return EXIT_FAILURE;
    }

    close(sock);

    return EXIT_SUCCESS;
}