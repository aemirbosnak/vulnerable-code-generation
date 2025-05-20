//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

void addEdge(Node* arr[], int u, int v){
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->val = v;
    node1->next = NULL;
    Node* temp1 = arr[u];
    if(temp1 == NULL){
        arr[u] = node1;
    }
    else{
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = node1;
    }
    
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->val = u;
    node2->next = NULL;
    Node* temp2 = arr[v];
    if(temp2 == NULL){
        arr[v] = node2;
    }
    else{
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = node2;
    }
}

void printGraph(Node* arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("Edges from node %d: ", i);
        Node* temp = arr[i];
        while(temp != NULL){
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dfs(Node* arr[], int visited[], int v){
    visited[v] = 1;
    printf("%d ", v);
    Node* temp = arr[v];
    while(temp != NULL){
        if(!visited[temp->val]){
            dfs(arr, visited, temp->val);
        }
        temp = temp->next;
    }
}

void bfs(Node* arr[], int visited[], int n, int start){
    int queue[n];
    int f=0, r=-1;
    
    queue[++r] = start;
    visited[start] = 1;
    
    while(f<=r){
        int curr = queue[f++];
        printf("%d ", curr);
        
        Node* temp = arr[curr];
        while(temp != NULL){
            int val = temp->val;
            if(!visited[val]){
                visited[val] = 1;
                queue[++r] = val;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main(){
    int n, e;
    printf("Enter number of nodes in graph: ");
    scanf("%d", &n);
    printf("Enter number of edges in graph: ");
    scanf("%d", &e);
    
    Node* arr[n];
    int i;
    for(i=0;i<n;i++){
        arr[i] = NULL;
    }
    
    printf("Enter edges in graph (u v): ");
    for(i=0;i<e;i++){
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(arr, u, v);
    }
    
    printf("Graph: \n");
    printGraph(arr, n);
    
    int visited[n];
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    
    printf("DFS: ");
    dfs(arr, visited, 0);
    printf("\n");
    
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    
    printf("BFS: ");
    bfs(arr, visited, n, 0);
    
    return 0;
}