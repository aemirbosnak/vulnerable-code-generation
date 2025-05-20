//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 54000
#define MAX_HOSTS 100
#define BUFFER_SIZE 1024

struct node {
    char name[32];
    int sockfd;
    struct sockaddr_in addr;
    struct node *next;
};

struct node *head = NULL;

void err_quit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        err_quit("Can't create socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        err_quit("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        err_quit("Can't connect to remote host");
    }

    return sockfd;
}

void add_node(const char *name, int sockfd, struct sockaddr_in addr) {
    struct node *new_node = malloc(sizeof(struct node));

    strcpy(new_node->name, name);
    new_node->sockfd = sockfd;
    new_node->addr = addr;
    new_node->next = head;

    head = new_node;
}

void scan_network(int from, int to) {
    for (int i = from; i <= to; i++) {
        char ip_str[INET_ADDRSTRLEN];
        struct sockaddr_in server_addr;
        int sockfd = create_socket(inet_ntoa(server_addr.sin_addr), PORT);

        printf("[+] Scanning IP: %s:%d\n", inet_ntoa(server_addr.sin_addr), PORT);

        char buf[BUFFER_SIZE];
        recv(sockfd, buf, BUFFER_SIZE, 0);
        printf("[+] Received response: %s\n", buf);

        add_node("Unknown", sockfd, server_addr);

        close(sockfd);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Start IP> <End IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);

    scan_network(start, end);

    printf("\n[+] Found %d hosts:\n", MAX_HOSTS);
    struct node *current = head;
    for (int i = 0; i < MAX_HOSTS && current != NULL; i++) {
        printf("[%d] %s (%s)\n", i, current->name, inet_ntoa(current->addr.sin_addr));
        current = current->next;
    }

    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}