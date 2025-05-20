//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PORT 65535
#define MAX_BUFFER_SIZE 1024

struct node {
    char *ip_address;
    int *ports;
    int num_ports;
};

void scan_ports(char *ip_addr, struct node *nodes, int num_nodes) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER_SIZE];

    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(ip_addr, nodes[i].ip_address) == 0) {
            for (int j = 0; j < nodes[i].num_ports; j++) {
                sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd < 0) {
                    perror("Socket error");
                    continue;
                }

                memset(&serv_addr, 0, sizeof(serv_addr));
                serv_addr.sin_family = AF_INET;
                serv_addr.sin_port = htons(nodes[i].ports[j]);
                inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr);

                if (connect(sockfd, (const struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
                    printf("%s:%d is open\n", ip_addr, nodes[i].ports[j]);
                }

                close(sockfd);
            }
        }
    }
}

int main() {
    char *host_name = "localhost";
    struct addrinfo hints, *res, *p;
    int status;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host_name, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    struct node *nodes;
    int num_nodes = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    nodes = (struct node *) malloc(num_nodes * sizeof(struct node));

    for (int i = 0; i < num_nodes; i++) {
        int num_ports;
        char ip_addr[20];

        printf("Enter IP address for node %d: ", i+1);
        scanf("%s", ip_addr);
        printf("Enter the number of ports to scan for node %d: ", i+1);
        scanf("%d", &num_ports);

        nodes[i].ip_address = (char *) malloc(strlen(ip_addr) + 1);
        strcpy(nodes[i].ip_address, ip_addr);
        nodes[i].num_ports = num_ports;
        nodes[i].ports = (int *) malloc(num_ports * sizeof(int));

        printf("Enter the ports to be scanned (space separated) for node %d: ", i+1);
        for (int j = 0; j < num_ports; j++) {
            scanf("%d", &nodes[i].ports[j]);
        }

        scan_ports(ip_addr, nodes, num_nodes);
    }

    freeaddrinfo(res);
    return 0;
}