//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define INTERVAL 60

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "error creating socket\n");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    int addr_res = getaddrinfo(argv[1], "http", &hints, &res);
    if (addr_res != 0) {
        fprintf(stderr, "error getting address info: %s\n", gai_strerror(addr_res));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = *(struct sockaddr_in *) res->ai_addr;
    addr.sin_port = htons(80);
    freeaddrinfo(res);

    int addr_len = sizeof(addr);

    char request[BUFSIZE];
    snprintf(request, BUFSIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    int request_len = strlen(request);

    while (1) {
        clock_t start = clock();

        int send_res = sendto(sock_fd, request, request_len, 0, (struct sockaddr *) &addr, addr_len);
        if (send_res < 0) {
            fprintf(stderr, "error sending request\n");
            continue;
        }

        char response[BUFSIZE];
        int response_len = recvfrom(sock_fd, response, BUFSIZE, 0, (struct sockaddr *) &addr, &addr_len);
        if (response_len < 0) {
            fprintf(stderr, "error receiving response\n");
            continue;
        }

        clock_t end = clock();

        double elapsed_seconds = (double) (end - start) / CLOCKS_PER_SEC;

        printf("Response received in %lf seconds\n", elapsed_seconds);

        sleep(INTERVAL);
    }

    close(sock_fd);

    return 0;
}