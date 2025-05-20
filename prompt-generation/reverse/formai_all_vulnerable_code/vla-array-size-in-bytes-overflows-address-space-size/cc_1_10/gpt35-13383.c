//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
/*
In this program, we will implement the A* Pathfinding Algorithm in Ada Lovelace style!
A* Pathfinding Algorithm is an algorithm that finds the shortest path between two points on a graph or network, with the help of heuristic function.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//create a struct for node that includes x and y coordinates, f, g, h values, parent node and a boolean flag for visited nodes
typedef struct node{
    int x,y;
    int f,g,h;
    struct node* parent;
    int visited;
}node;

//function to calculate heuristic value (h) using Euclidean distance between two points
int calculateHeuristic(int x1, int y1, int x2, int y2){
    int h_value = (int)sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    return h_value;
}

//function to check if a node is within the boundaries of the grid
int checkBoundary(int x, int y, int ROW, int COL){
    if(x>=0 && x<ROW && y>=0 && y<COL){
        return 1;
     }
     else{
        return 0;
     }
}

//function to check if a node is blocked or not
int checkBlocked(int x, int y, int grid[][100]){
    if(grid[x][y]==0){
        return 1;
     }
     else{
        return 0;
     }
}

//function to check if a node is a destination node or not
int checkDestination(int x, int y, node destNode){
    if(x==destNode.x && y==destNode.y){
        return 1;
    }
    else{
        return 0;
    }
}

//function to update the f,g,h values of a node
void updateValues(node* temp, int g_value, node destNode){
    temp->g = g_value;
    temp->h = calculateHeuristic(temp->x,temp->y,destNode.x,destNode.y);
    temp->f = temp->g + temp->h;
}

//function to find the shortest path
void searchPath(int grid[][100], node* startNode, node destNode, int ROW, int COL){
    int i,j;
    node* temp;
    node openList[ROW*COL];
    int openListLen=0;
    node closedList[ROW*COL];
    int closedListLen=0;
    int g_value=0;
    int temp_x,temp_y;

    //initialize the start node values
    startNode->f = 0;
    startNode->g = 0;
    startNode->h = 0;
    startNode->parent = NULL;

    //add start node to open list
    openList[openListLen] = *startNode;
    openListLen++;

    while(openListLen>0){
        //select node with lowest f value from open list
        int min_index=0;
        for(i=0; i<openListLen; i++){
            if(openList[i].f < openList[min_index].f){
                min_index = i;
            }
        }

        //set current node
        temp = &openList[min_index];

        //if destination node is reached, print path and exit program
        if(checkDestination(temp->x, temp->y, destNode)){
            printf("Path Found!\n");
            node* pathList=(node*)malloc(sizeof(node));
            node* tempPath=pathList;
            while(temp->parent != NULL){
                tempPath->x=temp->x;
                tempPath->y=temp->y;
                tempPath->f=temp->f;
                tempPath->g=temp->g;
                tempPath->h=temp->h;

                temp = temp->parent;

                tempPath->parent = (node*)malloc(sizeof(node));
                tempPath=tempPath->parent;
            }
            tempPath->x=startNode->x;
            tempPath->y=startNode->y;
            tempPath->f=startNode->f;
            tempPath->g=startNode->g;
            tempPath->h=startNode->h;
            tempPath->parent=NULL;

            //display the path
            while(pathList->parent!=NULL){
                printf("(%d,%d) -> ",pathList->x,pathList->y);
                pathList=pathList->parent;
            }
            printf("(%d,%d)\n",pathList->x,pathList->y);

            return;
        }

        //remove current node from open list and add to closed list
        for(i=0; i<openListLen; i++){
            if(temp->x == openList[i].x && temp->y == openList[i].y){
                openList[i].visited=0;
                for(j=i;j<openListLen-1;j++){
                    openList[j]=openList[j+1];
                }
                openListLen--;
                break;
            }
        }

        temp->visited = 1;
        closedList[closedListLen] = *temp;
        closedListLen++;

        //search the neighbors of the current node
        for(i=-1; i<=1; i++){
            for(j=-1; j<=1; j++){
                temp_x = temp->x + i;
                temp_y = temp->y + j;

                //check if the temporary node is within the boundary
                if(checkBoundary(temp_x, temp_y, ROW, COL)){

                    //check if the temporary node is not a blocked cell
                    if(checkBlocked(temp_x,temp_y,grid)){

                        //skip the current iteration if it is the current node itself
                        if(i==0 && j==0){
                            continue;
                        }

                        //create temporary node
                        node* neighborNode = (node*)malloc(sizeof(node));
                        neighborNode->x = temp_x;
                        neighborNode->y = temp_y;
                        neighborNode->parent = temp;

                        //check if the neighbor node is in the closed list
                        int isInClosedList=0;
                        for(int k=0;k<closedListLen;k++){
                            if(closedList[k].x == temp_x && closedList[k].y == temp_y){
                                isInClosedList=1;
                                break;
                            }
                        }
                        if(isInClosedList){
                            continue;
                        }

                        //update the f,g,h values of the neighbor node and add to open list
                        g_value = temp->g + calculateHeuristic(temp->x,temp->y,temp_x,temp_y);
                        updateValues(neighborNode,g_value,destNode);

                        //check if the neighbor node is in the open list
                        int isInOpenList=0;
                        for(int k=0;k<openListLen;k++){
                            if(openList[k].x == temp_x && openList[k].y == temp_y){
                                isInOpenList=1;
                                break;
                            }
                        }
                        if(isInOpenList && neighborNode->g >= openList[openListLen-1].g){
                            continue;
                        }

                        openList[openListLen] = *neighborNode;
                        openListLen++;
                    }
                }
            }
        }
    }
    printf("Path not found!\n");
    return;
}

int main(){
    int ROW,COL;
    node startNode,destNode;

    //take input for rows and columns of the grid
    printf("Enter the number of rows: ");
    scanf("%d",&ROW);
    printf("Enter the number of columns: ");
    scanf("%d",&COL);
    int grid[ROW][COL];

    //take input for the grid, where 0 means blocked and 1 means unblocked
    printf("Enter the grid:\n");
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            scanf("%d",&grid[i][j]);
        }
    }

    //take input for the start node
    printf("Enter the x and y coordinates for the start node: ");
    scanf("%d %d",&startNode.x,&startNode.y);
    startNode.visited=0;

    //take input for the destination node
    printf("Enter the x and y coordinates for the destination node: ");
    scanf("%d %d",&destNode.x,&destNode.y);
    destNode.visited=0;

    searchPath(grid,&startNode,destNode,ROW,COL);

    return 0;
}