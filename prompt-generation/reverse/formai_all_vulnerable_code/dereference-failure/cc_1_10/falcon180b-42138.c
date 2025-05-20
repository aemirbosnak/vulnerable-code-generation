//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 10
#define MAX_HOSTNAME_LENGTH 100
#define MAX_PORT_LENGTH 6

struct host {
    char hostname[MAX_HOSTNAME_LENGTH];
    char ip[16];
    int port;
    int is_alive;
};

int main() {
    int num_hosts = 0;
    struct host hosts[MAX_HOSTS];
    char input_buffer[1024];
    char *token;
    int i;

    printf("Welcome to the post-apocalyptic network topology mapper!\n");
    printf("Please enter the hostnames and ports separated by spaces:\n");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    token = strtok(input_buffer, " ");
    while (token!= NULL) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Error: maximum number of hosts (%d) exceeded.\n", MAX_HOSTS);
            exit(1);
        }

        strcpy(hosts[num_hosts].hostname, token);
        hosts[num_hosts].is_alive = 0;
        num_hosts++;

        token = strtok(NULL, " ");
    }

    for (i = 0; i < num_hosts; i++) {
        if (gethostname(hosts[i].ip, sizeof(hosts[i].ip)) == -1) {
            printf("Error: failed to get local hostname.\n");
            exit(1);
        }

        if (inet_pton(AF_INET, hosts[i].ip, &hosts[i].ip) <= 0) {
            printf("Error: invalid local IP address.\n");
            exit(1);
        }
    }

    for (i = 0; i < num_hosts; i++) {
        struct addrinfo hints, *res;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        if (getaddrinfo(hosts[i].hostname, NULL, &hints, &res)!= 0) {
            printf("Error: failed to resolve hostname '%s'.\n", hosts[i].hostname);
            exit(1);
        }

        memcpy(&hosts[i].ip, res->ai_addr, sizeof(hosts[i].ip));
        freeaddrinfo(res);

        hosts[i].port = atoi(strchr(hosts[i].hostname, ':') + 1);
        hosts[i].is_alive = 1;
    }

    printf("Hosts:\n");
    for (i = 0; i < num_hosts; i++) {
        printf("%s (%s:%d)\n", hosts[i].hostname, hosts[i].ip, hosts[i].port);
    }

    return 0;
}