//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_PORTS 65536

struct host_port {
    char hostname[MAX_HOSTNAME_LEN];
    int port;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct host_port *hosts = malloc(MAX_PORTS * sizeof(struct host_port));
    if (hosts == NULL) {
        perror("memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char hostname[MAX_HOSTNAME_LEN];
    int port;

    printf("Enter a range of IP addresses to scan (e.g. 192.168.0.1-192.168.0.254): ");
    fgets(hostname, MAX_HOSTNAME_LEN, stdin);

    char *token = strtok(hostname, "-");
    while (token != NULL && i < MAX_PORTS) {
        inet_pton(AF_INET, token, &hosts[i].hostname);
        port = atoi(strtok(NULL, "-"));
        if (port == 0) {
            printf("Invalid port number\n");
            continue;
        }
        hosts[i].port = htons(port);
        i++;
        token = strtok(NULL, "-");
    }

    if (i == 0) {
        printf("No IP addresses or ports specified\n");
        exit(EXIT_SUCCESS);
    }

    for (int j = 0; j < i; j++) {
        if (connect(sock, (struct sockaddr *)&hosts[j], sizeof(struct sockaddr)) < 0) {
            perror("connect failed");
            continue;
        }
        printf("Port %d open on %s\n", hosts[j].port, hosts[j].hostname);
        close(sock);
    }

    free(hosts);
    return EXIT_SUCCESS;
}