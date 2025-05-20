//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Initialize a new network topology mapper.
struct ntm {
    int sock;
    struct sockaddr_in addr;
    int addrlen;
};

// Create a new network topology mapper.
struct ntm *ntm_new(char *host, int port) {
    struct ntm *ntm = malloc(sizeof(struct ntm));
    if (!ntm) {
        return NULL;
    }

    ntm->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (ntm->sock < 0) {
        free(ntm);
        return NULL;
    }

    memset(&ntm->addr, 0, sizeof(ntm->addr));
    ntm->addr.sin_family = AF_INET;
    ntm->addr.sin_port = htons(port);
    inet_aton(host, &ntm->addr.sin_addr);
    ntm->addrlen = sizeof(ntm->addr);

    return ntm;
}

// Free a network topology mapper.
void ntm_free(struct ntm *ntm) {
    close(ntm->sock);
    free(ntm);
}

// Send a request to the network topology mapper.
int ntm_send(struct ntm *ntm, char *msg, int len) {
    return sendto(ntm->sock, msg, len, 0, (struct sockaddr *)&ntm->addr, ntm->addrlen);
}

// Receive a response from the network topology mapper.
int ntm_recv(struct ntm *ntm, char *buf, int len) {
    return recvfrom(ntm->sock, buf, len, 0, (struct sockaddr *)&ntm->addr, &ntm->addrlen);
}

// Get the network topology from the network topology mapper.
char *ntm_get(struct ntm *ntm) {
    char *buf = malloc(1024);
    if (!buf) {
        return NULL;
    }

    int len = ntm_send(ntm, "get", 3);
    if (len < 0) {
        free(buf);
        return NULL;
    }

    len = ntm_recv(ntm, buf, 1024);
    if (len < 0) {
        free(buf);
        return NULL;
    }

    return buf;
}

// Print the network topology.
void ntm_print(char *buf) {
    char *p = buf;
    while (*p) {
        printf("%s\n", p);
        p += strlen(p) + 1;
    }
}

// Main function.
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct ntm *ntm = ntm_new(argv[1], atoi(argv[2]));
    if (!ntm) {
        printf("Error: could not create network topology mapper.\n");
        return 1;
    }

    char *buf = ntm_get(ntm);
    if (!buf) {
        printf("Error: could not get network topology.\n");
        ntm_free(ntm);
        return 1;
    }

    ntm_print(buf);

    free(buf);
    ntm_free(ntm);

    return 0;
}