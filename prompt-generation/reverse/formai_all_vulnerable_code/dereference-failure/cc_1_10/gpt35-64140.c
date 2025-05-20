//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define MAX_ROUTERS 100

// Structure to represent a router
struct Router {
    char name[20];
    int neighbors[MAX_ROUTERS];
    int num_neighbors;
};

// Function to parse the network topology file and create the routers
int parse_topology_file(char* filename, struct Router* routers) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    char line[BUFFER_SIZE];
    int num_routers = 0;

    while (fgets(line, BUFFER_SIZE, fp)) {
        if (line[0] == '#') continue;
        char* token = strtok(line, " ");
        if (strcmp(token, "router") == 0) {
            strcpy(routers[num_routers].name, strtok(NULL, " "));
            routers[num_routers].num_neighbors = 0;
            while ((token = strtok(NULL, " \n")) != NULL) {
                routers[num_routers].neighbors[routers[num_routers].num_neighbors] = atoi(token);
                routers[num_routers].num_neighbors++;
            }
            num_routers++;
        }
    }

    fclose(fp);
    return num_routers;
}

// Function to perform depth-first search on the network topology
void dfs(int curr_router, struct Router* routers, int* visited) {
    visited[curr_router] = 1;
    printf("%s\n", routers[curr_router].name);
    for (int i = 0; i < routers[curr_router].num_neighbors; i++) {
        if (!visited[routers[curr_router].neighbors[i]]) {
            dfs(routers[curr_router].neighbors[i], routers, visited);
        }
    }
}

// Function to create a socket and connect to a router
int connect_to_router(char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Could not connect to router\n");
        return -1;
    }

    return sock;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <network_topology_file> <router_name>\n", argv[0]);
        return 0;
    }

    char* filename = argv[1];
    char* router_name = argv[2];
    struct Router routers[MAX_ROUTERS];
    int num_routers = parse_topology_file(filename, routers);
    
    if (num_routers < 0) {
        return -1;
    }

    int start_router = -1;
    for (int i = 0; i < num_routers; i++) {
        if (strcmp(routers[i].name, router_name) == 0) {
            start_router = i;
            break;
        }
    }

    if (start_router < 0) {
        printf("Error: Router with name %s not found\n", router_name);
        return -1;
    }

    int visited[MAX_ROUTERS] = {0};
    dfs(start_router, routers, visited);

    for (int i = 0; i < num_routers; i++) {
        if (visited[i] == 0) {
            printf("Warning: Router %s is not reachable from %s\n", routers[i].name, router_name);
        }
    }

    int socket_fd = connect_to_router("192.168.1.1", 5000);
    if(socket_fd == -1){
        return -1;
    }

    char* message = "Hello from client";
    int message_length = strlen(message);

    if (send(socket_fd, message, message_length, 0) != message_length) {
        printf("Error: Failed to send message\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        printf("Error: Failed to receive message\n");
        return -1;
    }

    buffer[bytes_received] = '\0';
    printf("Received message: %s\n", buffer);

    close(socket_fd);

    return 0;
}