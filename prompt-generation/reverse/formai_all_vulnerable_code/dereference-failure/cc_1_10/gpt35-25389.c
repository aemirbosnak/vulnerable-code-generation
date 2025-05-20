//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 8
#define COL 8
#define WALL 9

struct Node
{
    int row;
    int col;
    int f;
    int g;
    int h;
    struct Node *parent;
};

int terrain[ROW][COL] = {{0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,WALL},
                         {0,0,0,0,0,0,0,WALL},
                         {0,WALL,0,0,0,0,0,WALL},
                         {0,0,0,WALL,0,0,0,WALL},
                         {0,WALL,0,0,0,0,0,WALL},
                         {0,WALL,WALL,WALL,0,0,0,0},
                         {0,0,0,0,0,0,0,0}};

struct Node* createNode(int row, int col, int f, int g, int h, struct Node* parent){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->row = row;
    temp->col = col;
    temp->f = f;
    temp->g = g;
    temp->h = h;
    temp->parent = parent;
    
    return temp;
}

int calcH(int x1, int y1, int x2, int y2){
    return (int)sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int isDestination(int row, int col, struct Node* dest){
    return (row==dest->row && col==dest->col);
}

int isBlocked(int row, int col){
    return (terrain[row][col]==WALL);
}

void printPath(struct Node* current){
    if(current==NULL) return;
    printPath(current->parent);
    printf("(%d,%d) -> ", current->row, current->col);
}


void findPath(struct Node *src, struct Node *dest){
    if(src==NULL || dest==NULL){
        printf("Invalid source or destination node!");
        return;
    }

    if(isBlocked(src->row,src->col) || isBlocked(dest->row,dest->col)){
        printf("Source or destination is blocked!");
        return;
    }
    
    if(isDestination(src->row,src->col,dest)){
        printf("Source and destination are the same!\n");
        return;
    }
    
    int closedList[ROW][COL];
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            closedList[i][j] = 0;
        }
    }
    
    struct Node *openList[ROW*COL];
    int openListCount = 0;
    
    src->f = 0;
    src->g = 0;
    src->h = 0;
    src->parent = NULL;
    
    openList[openListCount++] = src;
    
    while(openListCount>0){
        struct Node *current = openList[0];
        int currentIndex = 0;
        
        for(int i=1;i<openListCount;i++){
            if(openList[i]->f < current->f){
                current = openList[i];
                currentIndex = i;
            }
        }
        
        openListCount--;
        openList[currentIndex] = openList[openListCount];
        
        closedList[current->row][current->col] = 1;
        
        if(isDestination(current->row,current->col,dest)){
            printf("Path found!\n");
            printPath(current);
            return;
        }
        
        struct Node *temp;
        int i,j;
        //Move up
        i = current->row-1;
        j = current->col;
        if(i>=0 && !isBlocked(i,j) ){
            if(!closedList[i][j]){
                int gNew = current->g+1;
                int hNew = calcH(i,j,dest->row,dest->col);
                int fNew = gNew+hNew;
                temp = createNode(i,j,fNew,gNew,hNew,current);
                openList[openListCount++] = temp;
            }
        }
        //Move down
        i = current->row+1;
        j = current->col;
        if(i<ROW && !isBlocked(i,j)){
            if(!closedList[i][j]){
                int gNew = current->g+1;
                int hNew = calcH(i,j,dest->row,dest->col);
                int fNew = gNew+hNew;
                temp = createNode(i,j,fNew,gNew,hNew,current);
                openList[openListCount++] = temp;
            }
        }
        //Move left
        i = current->row;
        j = current->col-1;
        if(j>=0 && !isBlocked(i,j)){
            if(!closedList[i][j]){
                int gNew = current->g+1;
                int hNew = calcH(i,j,dest->row,dest->col);
                int fNew = gNew+hNew;
                temp = createNode(i,j,fNew,gNew,hNew,current);
                openList[openListCount++] = temp;
            }
        }
        //Move right
        i = current->row;
        j = current->col+1;
        if(j<COL && !isBlocked(i,j)){
            if(!closedList[i][j]){
                int gNew = current->g+1;
                int hNew = calcH(i,j,dest->row,dest->col);
                int fNew = gNew+hNew;
                temp = createNode(i,j,fNew,gNew,hNew,current);
                openList[openListCount++] = temp;
            }
        }
    }
    
    printf("Path not found!\n");
}


int main(){
    struct Node *source = createNode(0,0,0,0,0,NULL);
    struct Node *dest = createNode(ROW-1,COL-1,0,0,0,NULL);
    findPath(source,dest);
    return 0;
}