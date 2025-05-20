//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define PORT 80
#define MAX_HOSTS 255
#define MAX_IP_LEN 16
#define MAX_NAME_LEN 256

typedef struct node {
    char name[MAX_NAME_LEN];
    char ip[MAX_IP_LEN];
    struct node* next;
} node_t;

node_t* head = NULL;

void add_node(char* name, char* ip) {
    node_t* temp = malloc(sizeof(node_t));
    strncpy(temp->name, name, MAX_NAME_LEN);
    strncpy(temp->ip, ip, MAX_IP_LEN);
    temp->next = head;
    head = temp;
}

int main(int argc, char** argv) {
    char subnet_ip[MAX_IP_LEN];
    int subnet_mask;
    char ip[MAX_IP_LEN];
    char* temp_ip;
    char name[MAX_NAME_LEN];
    struct sockaddr_in server;
    int fd, ret;
    char buffer[1024];
    char request[1024];
    int i, hosts_found = 0;

    if(argc < 3) {
        printf("Usage: %s <subnet_ip>/<subnet_mask> <hostname>\n", argv[0]);
        return -1;
    }

    strncpy(subnet_ip, strtok(argv[1], "/"), MAX_IP_LEN);
    subnet_mask = atoi(strtok(NULL, "/"));
    snprintf(request, 1024, "HEAD / HTTP/1.0\r\nHost: %s\r\n\r\n", argv[2]);

    for(i = 1; i < (1 << (32 - subnet_mask)); i++) {
        snprintf(ip, MAX_IP_LEN, "%s.%d", subnet_ip, i);
        temp_ip = strdup(ip);

        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);

        if(inet_pton(AF_INET, ip, &server.sin_addr) != 1) {
            fprintf(stderr, "inet_pton failed for: %s\n", ip);
            continue;
        }

        fd = socket(AF_INET, SOCK_STREAM, 0);

        if(fd == -1) {
            fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
            continue;
        }

        ret = connect(fd, (struct sockaddr*)&server, sizeof(server));

        if(ret == -1) {
            close(fd);
            continue;
        }

        ret = send(fd, request, strlen(request), 0);

        if(ret == -1) {
            fprintf(stderr, "Failed to send request: %s\n", strerror(errno));
            close(fd);
            continue;
        }

        ret = recv(fd, buffer, 1024, 0);

        if(ret == -1) {
            fprintf(stderr, "Failed to receive response: %s\n", strerror(errno));
            close(fd);
            continue;
        }

        buffer[ret] = '\0';

        if(ret > 0) {
            add_node(argv[2], temp_ip);
            hosts_found++;
        }

        close(fd);
    }

    if(head == NULL) {
        printf("No hosts found in subnet.\n");
        return 0;
    }

    printf("\nTopology map:\n");

    for(node_t* node = head; node != NULL; node = node->next) {
        printf("%s (%s)\n", node->name, node->ip);
    }

    printf("\nFound %d hosts in subnet.\n", hosts_found);

    return 0;
}