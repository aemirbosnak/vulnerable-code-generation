//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10 //number of rows in the map
#define COLS 10 //number of columns in the map

//A struct to represent a point in the map
typedef struct Point{
    int x;
    int y;
}Point;

//A struct to represent a node in the search tree
typedef struct Node{
    Point point;
    struct Node* parent;
    bool visited;
    bool isStart;
    bool isGoal;
}Node;

//A function to create a new node
Node* createNode(Point point, bool isStart, bool isGoal, Node* parent){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point = point;
    newNode->parent = parent;
    newNode->visited = false;
    newNode->isStart = isStart;
    newNode->isGoal = isGoal;
    return newNode;
}

//A function to check if a point is within the boundaries of the map
bool isPointInsideMap(Point point){
    return (point.x >= 0 && point.x < COLS && point.y >=0 && point.y < ROWS);
}

//A function to check if a point can be traversed (i.e., not an obstacle)
bool canTraverse(int map[ROWS][COLS], Point point){
    return map[point.y][point.x] != 1;
}

//A function to check if a point is the goal point
bool isGoal(Point point, Point goal){
    return (point.x == goal.x && point.y == goal.y);
}

//A function to print the path from start to goal
void printPath(Point start, Point goal, Node* goalNode){
    printf("Path from (%d,%d) to (%d,%d):\n", start.x, start.y, goal.x, goal.y);
    printf("-------------------------------\n");
    Node* currentNode = goalNode;
    while(currentNode != NULL){
        printf("(%d,%d)\n", currentNode->point.x, currentNode->point.y);
        currentNode = currentNode->parent;
    }
}

//Depth-First Search algorithm (Recursive implementation)
Node* DFS(Point current, Point goal, int map[ROWS][COLS]){
    if(isGoal(current, goal)){
        return createNode(current, false, true, NULL);
    }
    //mark current node as visited
    Node* currentNode = createNode(current, false, false, NULL);
    currentNode->visited = true;
    //explore neighboring nodes
    Point neighbors[4];
    neighbors[0] = (Point){current.x, current.y-1};
    neighbors[1] = (Point){current.x+1, current.y};
    neighbors[2] = (Point){current.x, current.y+1};
    neighbors[3] = (Point){current.x-1, current.y};
    for(int i=0; i<4; i++){
        if(isPointInsideMap(neighbors[i]) && canTraverse(map, neighbors[i])){
            if(!currentNode->visited){
                Node* childNode = DFS(neighbors[i], goal, map);
                if(childNode != NULL){
                    childNode->parent = currentNode;
                    return childNode;
                }
            }
        }
    }
    return NULL; //no path found
}

//Main program
int main(){
    Point start = {0,0};
    Point goal = {9,9};
    int map[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,1,1,0},
        {0,1,0,1,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,1,1,1,0,1,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,1,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    Node* goalNode = DFS(start, goal, map);
    if(goalNode != NULL){
        printPath(start, goal, goalNode);
    }
    return 0;
}