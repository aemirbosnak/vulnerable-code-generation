//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROW 6
#define COL 6

struct node {
    int x, y, cost;
};

int maze[ROW][COL] = {
    {0,0,0,0,1,0},
    {1,1,0,1,0,0},
    {0,0,0,0,1,0},
    {0,1,1,1,0,0},
    {0,0,0,1,0,0},
    {0,0,0,0,0,0}
};

int visited[ROW][COL] = {0};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2); // Manhattan Heuristic
}

int is_valid(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) {
        return 0;
    }
    return !maze[x][y] && !visited[x][y];
}

void reset_visited() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            visited[i][j] = 0;
        }
    }
}

void a_star(int start_x, int start_y, int goal_x, int goal_y) {
    struct node *queue = (struct node *)malloc(sizeof(struct node) * ROW * COL);
    int front = 0, rear = 0;
    
    struct node start_node = {start_x, start_y, 0};
    queue[rear++] = start_node;
    
    while(front != rear) {
        struct node current_node = queue[front++];
        if(current_node.x == goal_x && current_node.y == goal_y) {
            printf("Cost: %d\n", current_node.cost);
            return;
        }
        
        visited[current_node.x][current_node.y] = 1;
        
        // generate neighbors of current node
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                if(i==0 && j==0) continue;
                int neighbor_x = current_node.x + i;
                int neighbor_y = current_node.y + j;
                
                if(is_valid(neighbor_x, neighbor_y)) {
                    int neighbor_cost = current_node.cost + 1;
                    int neighbor_h = heuristic(neighbor_x, neighbor_y, goal_x, goal_y);
                    int neighbor_f = neighbor_cost + neighbor_h;
                    
                    struct node neighbor_node = {neighbor_x, neighbor_y, neighbor_f};
                    
                    queue[rear++] = neighbor_node;
                }
            }
        }
    }
    
    printf("No path found\n");
    reset_visited();
}

int main() {
    a_star(0, 0, 5, 5);
    return 0;
}