//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
///GRAPH DATA STRUCTURE
typedef struct node{
    int to;
    struct node *next;
}n;
typedef struct list{
    int num;
    n* head;
}l;
typedef struct graph{
    int num;
    l* arr;
}g;
///GRAPH FUNCTIONS
g* g_init(int v){
    g* graph=(g*)calloc(1,sizeof(g));
    graph->num=v;
    graph->arr=(l*)calloc(v,sizeof(l));
    for(int i=0;i<v;i++){
        graph->arr[i].num=0;
        graph->arr[i].head=NULL;
    }
    return graph;
}
void g_addEdge(g* graph,int v,int u){
    n* new=(n*)calloc(1,sizeof(n));
    new->to=u;
    new->next=graph->arr[v].head;
    graph->arr[v].head=new;
    graph->arr[v].num++;
}
void printGraph(g* graph){
    for(int i=0;i<graph->num;i++){
        printf("%d -------->",i);
        n* t=graph->arr[i].head;
        while(t){
            printf(" %d ",t->to);
            t=t->next;
        }
        printf("\n");
    }
}
///TEST
int main(){
    ///TEST EXAMPLE
    g* graph=g_init(6);
    g_addEdge(graph,0,1);
    g_addEdge(graph,0,2);
    g_addEdge(graph,1,2);
    g_addEdge(graph,1,4);
    g_addEdge(graph,2,3);
    g_addEdge(graph,3,4);
    printGraph(graph);
    return 0;
}