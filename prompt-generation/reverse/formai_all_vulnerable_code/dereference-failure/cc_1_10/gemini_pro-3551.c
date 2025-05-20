//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_HOPS 30
#define MAX_NODES 100

struct node {
    char ip[16];
    int hops;
    int visited;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
};

void initialize_queue(struct queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

void enqueue(struct queue *queue, struct node *node) {
    if (queue->tail == NULL) {
        queue->head = node;
        queue->tail = node;
        node->next = NULL;
    } else {
        queue->tail->next = node;
        queue->tail = node;
        node->next = NULL;
    }
}

struct node *dequeue(struct queue *queue) {
    struct node *node = queue->head;
    if (queue->head != NULL) {
        queue->head = queue->head->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
    }
    return node;
}

int is_empty(struct queue *queue) {
    return queue->head == NULL;
}

struct node *create_node(char *ip, int hops) {
    struct node *node = malloc(sizeof(struct node));
    strcpy(node->ip, ip);
    node->hops = hops;
    node->visited = 0;
    node->next = NULL;
    return node;
}

void print_node(struct node *node) {
    printf("%s (%d)\n", node->ip, node->hops);
}

void print_queue(struct queue *queue) {
    struct node *node = queue->head;
    while (node != NULL) {
        print_node(node);
        node = node->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <start_ip> <target_ip>\n", argv[0]);
        exit(1);
    }

    char *start_ip = argv[1];
    char *target_ip = argv[2];

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(start_ip);
    addr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    struct queue queue;
    initialize_queue(&queue);

    struct node *start_node = create_node(start_ip, 0);
    enqueue(&queue, start_node);

    while (!is_empty(&queue)) {
        struct node *node = dequeue(&queue);
        if (node->visited) {
            continue;
        }

        node->visited = 1;

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(target_ip);
        target_addr.sin_port = htons(33434);

        sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&target_addr, sizeof(target_addr));

        struct sockaddr_in from_addr;
        socklen_t from_len = sizeof(from_addr);

        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&from_addr, &from_len);

        char *ip = inet_ntoa(from_addr.sin_addr);

        if (strcmp(ip, target_ip) == 0) {
            printf("Target reached in %d hops:\n", node->hops + 1);
            print_node(node);
            break;
        } else if (node->hops < MAX_HOPS) {
            struct node *new_node = create_node(ip, node->hops + 1);
            enqueue(&queue, new_node);
        }
    }

    close(sockfd);

    return 0;
}