//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Could not create socket");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: Could not connect to server");
        return EXIT_FAILURE;
    }

    char buf[BUF_SIZE];
    for (int i = 0; i < BUF_SIZE; i++) {
        buf[i] = 'a';
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);
    int bytes_sent = send(sock, buf, BUF_SIZE, 0);
    if (bytes_sent == -1) {
        perror("Error: Could not send data to server");
        return EXIT_FAILURE;
    }
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
    double speed = (bytes_sent * 8.0) / (elapsed / 1000.0);

    printf("Speed: %.2f Mbps\n", speed);

    close(sock);
    return EXIT_SUCCESS;
}