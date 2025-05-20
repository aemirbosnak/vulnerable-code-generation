//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 10

struct node{
    int row;
    int col;
    int fval;
    int gval;
    int hval;
    struct node* parent;
};
typedef struct node Node;

Node* openList[ROW*COL];
int openListSize=0;
int closeList[ROW][COL];

char grid[ROW][COL]={
    {1,1,1,0,1,0,0,0,0,1},
    {0,1,1,1,1,1,0,0,0,1},
    {0,0,0,0,0,1,0,0,0,1},
    {0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,1,1,0,0},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1,1},
};

int isGoal(int row,int col){
    if(row==9 && col==9) return 1;
    else return 0;
}

int isObstacle(int row,int col){
    if(grid[row][col]==0) return 1;
    else return 0;
}

void insertOpenList(Node* node){
    int i;
    for(i=0;i<openListSize;i++){
        if(openList[i]->fval>node->fval){
            int j;
            for(j=openListSize-1;j>=i;j--){
                openList[j+1]=openList[j];
            }
            openList[i]=node;
            openListSize++;
            return ;
        }
    }
    openList[openListSize++]=node;
}

Node* createNode(int row,int col,int g,Node* parent){
    Node* node=(Node*)malloc(sizeof(Node));
    node->row=row;
    node->col=col;
    node->gval=g;
    node->hval=abs(row-9)+abs(col-9);
    node->fval=node->gval+node->hval;
    node->parent=parent;
    return node;
}

Node* getSuccessor(Node* node){
    int row=node->row,col=node->col;
    int r[4]={1,-1,0,0};
    int c[4]={0,0,1,-1};
    Node* suc[4];
    int count=0;
    int i;
    for(i=0;i<4;i++){
        int newr=row+r[i];
        int newc=col+c[i];
        if(newr>=0 && newr<ROW && newc>=0 && newc<COL && !isObstacle(newr,newc)){
            suc[count++]=createNode(newr,newc,node->gval+1,node);
        }
    }
    if(count)return suc[rand()%count];
    else return NULL;
}

void printPath(Node* node){
    if(node==NULL)return ;
    printPath(node->parent);
    printf("(%d,%d)\n",node->row,node->col);
}

void AstarSearch(){
    Node* start=createNode(0,0,0,NULL);
    insertOpenList(start);
    while(openListSize){
        Node* node=openList[0];
        openListSize--;
        int i;
        for(i=0;i<openListSize;i++)
            openList[i]=openList[i+1];
        closeList[node->row][node->col]=1;
        if(isGoal(node->row,node->col)){
            printPath(node);
            return ;
        }
        Node* suc=getSuccessor(node);
        while(suc){
            if(!closeList[suc->row][suc->col]){
                insertOpenList(suc);
            }
            suc=getSuccessor(node);
        }
    }
    printf("No path found!");
}

int main(){
    AstarSearch();
    return 0;
}