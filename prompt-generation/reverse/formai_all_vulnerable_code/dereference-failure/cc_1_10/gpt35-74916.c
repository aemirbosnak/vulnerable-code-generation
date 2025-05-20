//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to represent a node in the topology
struct Node{
    int id;
    char *ip_address;
    int num_connections;
    int *connections;
};

//Function to add connections between nodes
void addConnection(struct Node *nodes, int node_id, int connection_id){
    int num_connections = nodes[node_id].num_connections;
    nodes[node_id].connections = realloc(nodes[node_id].connections, (num_connections+1)*sizeof(int));
    nodes[node_id].connections[num_connections] = connection_id;
    nodes[node_id].num_connections ++;
}

//Function to generate a random IP address
char* generateIP(){
    char *ip = malloc(16*sizeof(char));
    sprintf(ip, "%d.%d.%d.%d", rand()%256, rand()%256, rand()%256, rand()%256);
    return ip;
}

int main(){
    int num_nodes = 10;
    struct Node *nodes = malloc(num_nodes*sizeof(struct Node));

    //Initialize nodes with random IP addresses and IDs
    for(int i=0; i<num_nodes; i++){
        nodes[i].id = i;
        nodes[i].ip_address = generateIP();
        nodes[i].num_connections = 0;
        nodes[i].connections = malloc(sizeof(int));
    }

    //Add random connections to the nodes
    for(int i=0; i<num_nodes; i++){
        int num_connections = rand()%5 + 1;
        for(int j=0; j<num_connections; j++){
            int connection_id = rand()%num_nodes;
            if(connection_id != i){
                addConnection(nodes, i, connection_id);
                addConnection(nodes, connection_id, i);
            }
        }
    }

    //Print the topology
    printf("Topology:\n");
    for(int i=0; i<num_nodes; i++){
        printf("Node %d (IP: %s) is connected to nodes: ", i, nodes[i].ip_address);
        for(int j=0; j<nodes[i].num_connections; j++){
            printf("%d ", nodes[i].connections[j]);
        }
        printf("\n");
    }

    //Free memory allocated for nodes
    for(int i=0; i<num_nodes; i++){
        free(nodes[i].ip_address);
        free(nodes[i].connections);
    }
    free(nodes);

    return 0;
}