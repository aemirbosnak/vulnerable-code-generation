//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int color;
    int num;
    struct node* next;
};

//function to print the adjacency list of the graph
void print_list(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    //initialize random seed
    srand(time(NULL));

    printf("Welcome to the surreal world of Graph Coloring!\n");

    int n; //number of nodes
    int e; //number of edges
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node* adj_list[n+1]; //adjacency list for graph representation

    //initialize adjacency list with NULL pointers
    for(int i=1; i<=n; i++){
        adj_list[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    //create random edges between nodes
    for(int i=0; i<e; i++){
        int n1 = rand() % n + 1;
        int n2 = rand() % n + 1;

        //check if edge already exists
        struct node* temp = adj_list[n1];
        while(temp != NULL){
            if(temp->num == n2){
                break;
            }
            temp = temp->next;
        }
        if(temp != NULL){
            continue;
        }

        //initialize new nodes for the linked list
        struct node* node1 = (struct node*)malloc(sizeof(struct node));
        node1->color = -1;
        node1->num = n1;
        node1->next = NULL;

        struct node* node2 = (struct node*)malloc(sizeof(struct node));
        node2->color = -1;
        node2->num = n2;
        node2->next = NULL;

        //add node2 to the linked list for node1
        if(adj_list[n1] == NULL){
            adj_list[n1] = node2;
        }
        else{
            temp = adj_list[n1];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node2;
        }

        //add node1 to the linked list for node2
        if(adj_list[n2] == NULL){
            adj_list[n2] = node1;
        }
        else{
            temp = adj_list[n2];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node1;
        }
    }

    printf("The adjacency list for the graph is:\n");
    for(int i=1; i<=n; i++){
        printf("Node %d: ", i);
        print_list(adj_list[i]);
    }

    printf("The graph has been randomly generated!\n");

    //start the surreal graph coloring algorithm
    for(int i=1; i<=n; i++){
        struct node* temp = adj_list[i];
        int used_colors[100] = {0};
        while(temp != NULL){
            if(temp->color != -1){
                used_colors[temp->color]++;
            }
            temp = temp->next;
        }
        int j = 0;
        while(used_colors[j] != 0){
            j++;
        }
        adj_list[i]->color = j;
    }

    printf("The colors assigned to the nodes are:\n");
    for(int i=1; i<=n; i++){
        printf("Node %d: %d\n", i, adj_list[i]->color);
    }

    printf("Welcome to the surreal world of Graph Coloring!\n");
    return 0;
}