//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int port;
} ScanTarget;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

ScanTarget generate_random_target() {
    ScanTarget target;
    struct hostent *host;
    char ipstr[INET_ADDRSTRLEN];

    host = gethostbyname("localhost");
    if (!host) {
        die("gethostbyname: unknown host localhost");
    }

    strcpy(target.ip, inet_ntoa(*(struct in_addr *)host->h_addr));
    target.port = rand() % 65535 + 1;

    printf("[+] Generated target: %s:%d\n", target.ip, target.port);
    return target;
}

int port_is_open(int sockfd, int port) {
    struct sockaddr_in serv_addr;
    int ret = -1;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) >= 0) {
        close(sockfd);
        ret = 1;
    }

    return ret;
}

int main() {
    int sockfd, ret, i;
    ScanTarget target;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("socket: failed to create socket");
    }

    target = generate_random_target();

    while (1) {
        if (port_is_open(sockfd, target.port)) {
            printf("[+] Found open port %d on %s\n", target.port, target.ip);
            break;
        }

        i++;
        if (i % 100 == 0) {
            target = generate_random_target();
            printf("[*] Trying new target: %s:%d\n", target.ip, target.port);
        }

        target.port++;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}