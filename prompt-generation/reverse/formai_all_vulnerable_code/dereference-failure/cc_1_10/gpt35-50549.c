//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_NODES 10

struct node {
    char *name;
    char *ip_address;
};

int main() {

    printf("Welcome to the Network Topology Mapper!\n\n");
    printf("Please enter the number of nodes in your network: ");

    int num_nodes;
    scanf("%d", &num_nodes);

    if (num_nodes > MAX_NODES) {
        printf("Error: Maximum number of nodes allowed is %d.\n", MAX_NODES);
        exit(1);
    }

    struct node nodes[MAX_NODES];

    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the name and IP address of node %d: ", i+1);
        char name[50];
        char ip_address[16];
        scanf("%s%s", name, ip_address);
        nodes[i].name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
        nodes[i].ip_address = (char *) malloc(sizeof(char) * (strlen(ip_address) + 1));
        strcpy(nodes[i].name, name);
        strcpy(nodes[i].ip_address, ip_address);
    }

    printf("\nNode list:\n\n");
    printf("Name \t IP Address\n");
    printf("---- \t ----------\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s \t %s\n", nodes[i].name, nodes[i].ip_address);
    }

    printf("\nStarting network mapping...\n\n");

    for (int i = 0; i < num_nodes; i++) {

        printf("Mapping connections for node %s (%s):\n", nodes[i].name, nodes[i].ip_address);

        for (int j = 0; j < num_nodes; j++) {

            if (i != j) {
                struct sockaddr_in server_address;
                server_address.sin_family = AF_INET;
                server_address.sin_addr.s_addr = inet_addr(nodes[j].ip_address);
                server_address.sin_port = htons(80);

                int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

                if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == 0) {
                    printf("%s is connected to %s.\n", nodes[i].name, nodes[j].name);
                }

                close(socket_fd);

            }

        }

        printf("\n");

    }

    printf("Network mapping complete!\n");

    return 0;
}