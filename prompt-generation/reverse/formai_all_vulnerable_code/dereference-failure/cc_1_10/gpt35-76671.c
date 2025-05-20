//FormAI DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 80

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    struct hostent *host;
    struct sockaddr_in server;
    int sock_fd, status;
    float elapsed_time;
    clock_t start, end;

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname failed");
        exit(1);
    }

    printf("Starting ping test on %s\n", hostname);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memcpy(&server.sin_addr, host->h_addr_list[0], host->h_length);

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    start = clock();

    if ((status = connect(sock_fd, (struct sockaddr*)&server, sizeof(server))) == -1) {
        perror("connect failed");
        exit(1);
    }

    end = clock();
    elapsed_time = ((float)end - (float)start) / CLOCKS_PER_SEC * 1000;

    printf("Connected to %s in %.2fms\n", hostname, elapsed_time);

    close(sock_fd);

    return 0;
}