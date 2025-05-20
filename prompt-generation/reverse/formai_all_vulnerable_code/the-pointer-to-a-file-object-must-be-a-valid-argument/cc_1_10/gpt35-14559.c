//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 20
#define MAX_EDGES 500

typedef struct Edge Edge;
typedef struct Node Node;

struct Edge{
    int start, end;
    double value;
};

struct Node{
    char* name;
    int id, num_edges, visited;
    double value, current, previous;
    Edge edges[MAX_EDGES];
};

Node nodes[MAX_NODES];
int num_nodes, num_edges;

bool contains(int arr[], int size, int x){
    for(int i=0; i<size; i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}

int get_node_id(char* name){
    for(int i=0; i<num_nodes; i++){
        if(strcmp(name, nodes[i].name) == 0){
            return nodes[i].id;
        }
    }
    return -1;
}

void add_edge(int start, int end, double value){
    nodes[start].edges[nodes[start].num_edges++] = (Edge){start, end, value};
}

void dfs(int u){
    nodes[u].visited = 1;
    for(int i=0; i<nodes[u].num_edges; i++){
        int v = nodes[u].edges[i].end;
        if(nodes[v].visited == 0){
            dfs(v);
        }
    }
}

bool has_cycle(){
    for(int i=0; i<num_nodes; i++){
        if(nodes[i].visited == 0){
            dfs(i);
        }
    }
    for(int i=0; i<num_nodes; i++){
        nodes[i].visited = 0;
    }
    int stack[MAX_NODES], top=-1;
    bool in_stack[MAX_NODES];
    memset(in_stack, false, sizeof(in_stack));
    for(int i=0; i<num_nodes; i++){
        if(nodes[i].num_edges == 0){
            stack[++top] = i;
            in_stack[i] = true;
        }
    }
    while(top >= 0){
        int u = stack[top--];
        in_stack[u] = false;
        for(int i=0; i<nodes[u].num_edges; i++){
            int v = nodes[u].edges[i].end;
            if(nodes[v].current < nodes[u].current + nodes[u].edges[i].value){
                nodes[v].current = nodes[u].current + nodes[u].edges[i].value;
                if(in_stack[v] == false){
                    stack[++top] = v;
                    in_stack[v] = true;
                }
            }
        }
    }

    for(int i=0; i<num_nodes; i++){
        if(nodes[i].visited == 0){
            dfs(i);
        }
    }
    for(int i=0; i<num_nodes; i++){
        nodes[i].visited = 0;
    }
    for(int i=0; i<num_nodes; i++){
        for(int j=0; j<nodes[i].num_edges; j++){
            int u = nodes[i].id, v = nodes[nodes[i].edges[j].end].id;
            double value = nodes[i].edges[j].value;
            if(nodes[v].value < nodes[u].value + value && nodes[v].visited == 1){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    double tolerance = 1e-9;
    while(true){
        bool no_changes = true;
        for(int i=0; i<num_nodes; i++){
            double sum = 0.0;
            for(int j=0; j<nodes[i].num_edges; j++){
                int u = nodes[i].id, v = nodes[nodes[i].edges[j].end].id;
                double value = nodes[i].edges[j].value;
                sum += (nodes[u].previous - nodes[v].previous) / value;
            }
            nodes[i].current = sum;
            if(nodes[i].current < nodes[i].value - tolerance || nodes[i].current > nodes[i].value + tolerance){
                no_changes = false;
            }
        }
        if(no_changes){
            break;
        }
        if(has_cycle()){
            printf("Circuit has a cycle\n");
            return;
        }
        for(int i=0; i<num_nodes; i++){
            nodes[i].previous = nodes[i].current;
        }
    }
    for(int i=0; i<num_nodes; i++){
        printf("%s = %lf\n", nodes[i].name, nodes[i].current);
    }
}

int main(){
    char buffer[100];
    FILE* fp = fopen("circuit.txt", "r");
    num_nodes = 0;
    while(fgets(buffer, 100, fp)){
        char* token = strtok(buffer, " ");
        nodes[num_nodes].name = strdup(token);
        nodes[num_nodes].id = num_nodes;
        nodes[num_nodes].current = nodes[num_nodes].previous = nodes[num_nodes].value = 0.0;
        nodes[num_nodes++].num_edges = 0;
        while(token != NULL){
            token = strtok(NULL, " ");
            if(token != NULL){
                char* endptr;
                double value = strtod(token, &endptr);
                if(endptr == token){
                    int id = get_node_id(token);
                    if(id == -1){
                        id = num_nodes++;
                        nodes[id].name = strdup(token);
                        nodes[id].id = id;
                        nodes[id].current = nodes[id].previous = nodes[id].value = 0.0;
                        nodes[id].num_edges = 0;
                    }
                    add_edge(id, nodes[num_nodes-1].id, 1.0);
                    add_edge(nodes[num_nodes-1].id, id, 1.0);
                }else{
                    add_edge(nodes[num_nodes-1].id, get_node_id(token), value);
                }
            }
        }
    }
    fclose(fp);
    solve();
    return 0;
}