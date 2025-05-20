//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int n;
int *colors;
int **graph;

sem_t mutex;

void colorGraph(int node) {
    int c=1;
    while(1) {
        int flag=1;
        for(int i=0;i<n;i++) {
            if(graph[node][i] && colors[i]==c) {
                flag=0;
                break;
            }
        }
        if(flag) {
            colors[node]=c;
            break;
        }
        c++;
    }
}

void *threadFunction(void * arg) {
    int node=*(int*)arg;
    sem_wait(&mutex);
    colorGraph(node);
    sem_post(&mutex);
    return NULL;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    colors=(int*)calloc(n,sizeof(int));
    graph=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++) {
        graph[i]=(int*)malloc(n*sizeof(int));
    }

    printf("Enter the edges of the graph:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&graph[i][j]);
        }
    }

    sem_init(&mutex,0,1);

    pthread_t tid[n];
    int threadArgs[n];
    for(int i=0;i<n;i++) {
        threadArgs[i]=i;
    }

    for(int i=0;i<n;i++) {
        pthread_create(&tid[i],NULL,threadFunction,(void*)&threadArgs[i]);
    }

    for(int i=0;i<n;i++) {
        pthread_join(tid[i],NULL);
    }

    printf("\nColoring of nodes:\n");
    for(int i=0;i<n;i++) {
        printf("Node %d: Color %d\n",i+1,colors[i]);
    }

    sem_destroy(&mutex);

    for(int i=0;i<n;i++) {
        free(graph[i]);
    }
    free(graph);
    free(colors);

    return 0;
}