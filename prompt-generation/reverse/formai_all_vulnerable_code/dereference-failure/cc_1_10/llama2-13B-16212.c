//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

struct node {
    int sock;
    char *ip;
    int ram_usage;
};

void *malloc_aligned(size_t size, size_t alignment) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    if (alignment > 0) {
        size_t align = alignment - (size_t)ptr % alignment;
        memset(ptr, 0, align);
        ptr += align;
    }
    return ptr;
}

void *mmap_aligned(void *addr, size_t size, size_t alignment) {
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    if (alignment > 0) {
        size_t align = alignment - (size_t)ptr % alignment;
        munmap(ptr, size);
        ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
        if (ptr == MAP_FAILED) {
            perror("mmap");
            exit(EXIT_FAILURE);
        }
        memset(ptr, 0, align);
        ptr += align;
    }
    return ptr;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize the distributed RAM usage monitor
    struct node *nodes = malloc(sizeof(struct node) * (argc - 1));
    int i;
    for (i = 0; i < argc - 1; i++) {
        nodes[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (nodes[i].sock == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }
        nodes[i].ip = inet_pton(AF_INET, argv[i + 1], &(nodes[i].sock));
        if (nodes[i].ip == NULL) {
            perror("inet_pton");
            exit(EXIT_FAILURE);
        }
        nodes[i].ram_usage = -1;
    }

    // Start the distributed RAM usage monitor
    for (i = 0; i < argc - 1; i++) {
        if (connect(nodes[i].sock, (struct sockaddr *)&nodes[i].ip, sizeof(struct sockaddr_in)) < 0) {
            perror("connect");
            exit(EXIT_FAILURE);
        }
    }

    // Periodically collect RAM usage from each node
    while (1) {
        // Send a request to each node to report its RAM usage
        for (i = 0; i < argc - 1; i++) {
            send(nodes[i].sock, "RAM_USAGE_REQ", strlen("RAM_USAGE_REQ"), 0);
        }

        // Receive the RAM usage reports from each node
        for (i = 0; i < argc - 1; i++) {
            char buffer[BUFFER_SIZE];
            recv(nodes[i].sock, buffer, BUFFER_SIZE, 0);
            nodes[i].ram_usage = atoi(buffer);
        }

        // Display the RAM usage reports from each node
        for (i = 0; i < argc - 1; i++) {
            printf("%d: %d %%\n", nodes[i].ip, nodes[i].ram_usage);
        }

        // Sleep for a short period of time before checking again
        sleep(1);
    }

    return 0;
}