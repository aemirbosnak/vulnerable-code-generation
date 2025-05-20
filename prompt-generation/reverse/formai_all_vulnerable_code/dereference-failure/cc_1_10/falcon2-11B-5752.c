//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_NUM_NODES 100

typedef struct {
    char ip[16];
    int port;
} Node;

Node nodes[MAX_NUM_NODES];
int num_nodes = 0;

void add_node(char* ip, int port) {
    Node node;
    strncpy(node.ip, ip, sizeof(node.ip));
    node.port = port;
    nodes[num_nodes++] = node;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host1:port1> [host2:port2]... [hostN:portN]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i += 2) {
        add_node(argv[i], atoi(argv[i + 1]));
    }

    if (num_nodes == 0) {
        printf("No nodes added.\n");
        return 1;
    }

    int num_connected_nodes = 0;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            Node node1 = nodes[i];
            Node node2 = nodes[j];
            int sockfd1, sockfd2;
            struct sockaddr_in addr1, addr2;
            char buffer[100];

            sockfd1 = socket(AF_INET, SOCK_STREAM, 0);
            addr1.sin_family = AF_INET;
            addr1.sin_port = htons(node1.port);
            addr1.sin_addr.s_addr = inet_addr(node1.ip);
            bind(sockfd1, (struct sockaddr*)&addr1, sizeof(addr1));
            connect(sockfd1, (struct sockaddr*)&addr2, sizeof(addr2));

            sockfd2 = socket(AF_INET, SOCK_STREAM, 0);
            addr2.sin_family = AF_INET;
            addr2.sin_port = htons(node2.port);
            addr2.sin_addr.s_addr = inet_addr(node2.ip);
            bind(sockfd2, (struct sockaddr*)&addr2, sizeof(addr2));
            connect(sockfd2, (struct sockaddr*)&addr1, sizeof(addr1));

            snprintf(buffer, sizeof(buffer), "%s-%d", node1.ip, node1.port);
            if (write(sockfd1, buffer, strlen(buffer)) == -1) {
                perror("write");
                return 1;
            }

            snprintf(buffer, sizeof(buffer), "%s-%d", node2.ip, node2.port);
            if (write(sockfd2, buffer, strlen(buffer)) == -1) {
                perror("write");
                return 1;
            }

            if (read(sockfd1, buffer, sizeof(buffer)) == -1) {
                perror("read");
                return 1;
            }

            if (strcmp(buffer, node2.ip) == 0) {
                num_connected_nodes++;
            }

            if (read(sockfd2, buffer, sizeof(buffer)) == -1) {
                perror("read");
                return 1;
            }

            if (strcmp(buffer, node1.ip) == 0) {
                num_connected_nodes++;
            }

            close(sockfd1);
            close(sockfd2);
        }
    }

    printf("Number of connected nodes: %d\n", num_connected_nodes);

    return 0;
}