//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_RESULTS 10

typedef struct {
    char *name;
    char *address;
    int port;
} result_t;

void print_results(result_t *results, int count) {
    printf("Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s:%d (%s)\n", results[i].name, results[i].port, results[i].address);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    struct addrinfo hints, *result;
    int error;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((error = getaddrinfo(ip_address, NULL, &hints, &result))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        return 1;
    }

    char hostname[NI_MAXHOST];
    char service[NI_MAXSERV];

    if (getnameinfo(result->ai_addr, result->ai_addrlen, hostname, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        printf("Hostname: %s\n", hostname);
        printf("Service: %s\n", service);
    }

    freeaddrinfo(result);

    return 0;
}