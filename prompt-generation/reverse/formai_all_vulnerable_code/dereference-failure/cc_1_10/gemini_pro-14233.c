//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdbool.h>

#define MAX_HOPS    30
#define MAX_NODES   100
#define TIMEOUT_MS  500

struct node {
    char        ip_addr[16];
    char        hostname[64];
    int         hop_count;
    bool        visited;
};

struct queue {
    struct node nodes[MAX_NODES];
    int         head;
    int         tail;
};

void queue_init(struct queue *q) {
    q->head = 0;
    q->tail = 0;
}

bool queue_is_empty(struct queue *q) {
    return q->head == q->tail;
}

bool queue_is_full(struct queue *q) {
    return (q->tail + 1) % MAX_NODES == q->head;
}

void queue_enqueue(struct queue *q, struct node *n) {
    if (!queue_is_full(q)) {
        q->nodes[q->tail++] = *n;
        q->tail %= MAX_NODES;
    }
}

struct node *queue_dequeue(struct queue *q) {
    if (!queue_is_empty(q)) {
        return &q->nodes[q->head++];
    }
    return NULL;
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in create_sockaddr_in(char *ip_addr, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(port);
    return addr;
}

void send_ping(int sockfd, struct sockaddr_in *addr, char *hostname) {
    char buf[1024];
    int len = sprintf(buf, "PING %s", hostname);
    if (sendto(sockfd, buf, len, 0, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }
}

struct node *recv_ping(int sockfd, struct sockaddr_in *addr, int timeout_ms) {
    fd_set rfds;
    struct timeval timeout;
    char buf[1024];
    int len;
    
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    timeout.tv_sec = timeout_ms / 1000;
    timeout.tv_usec = (timeout_ms % 1000) * 1000;

    if (select(sockfd + 1, &rfds, NULL, NULL, &timeout) > 0) {
        len = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)addr, sizeof(*addr));
        if (len > 0) {
            struct node *n = malloc(sizeof(*n));
            if (n) {
                sscanf(buf, "PONG %s %d", n->hostname, &n->hop_count);
                return n;
            }
        }
    }
    return NULL;
}

void map_network(char *gateway_ip_addr) {
    int sockfd = create_socket();
    struct sockaddr_in addr = create_sockaddr_in(gateway_ip_addr, 80);
    struct queue q;
    struct node *n;
    
    queue_init(&q);
    
    n = malloc(sizeof(*n));
    if (n) {
        strcpy(n->ip_addr, gateway_ip_addr);
        strcpy(n->hostname, gateway_ip_addr);
        n->hop_count = 0;
        n->visited = false;
        queue_enqueue(&q, n);
    }
    
    while (!queue_is_empty(&q)) {
        n = queue_dequeue(&q);
        if (!n->visited) {
            send_ping(sockfd, &addr, n->hostname);
            struct node *r = recv_ping(sockfd, &addr, TIMEOUT_MS);
            if (r) {
                printf("%s (%s, %d hops)\n", r->hostname, r->ip_addr, r->hop_count);
                r->visited = true;
                if (r->hop_count < MAX_HOPS) {
                    queue_enqueue(&q, r);
                } else {
                    free(r);
                }
            }
        }
    }
    
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <gateway_ip_addr>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    map_network(argv[1]);
    
    return EXIT_SUCCESS;
}