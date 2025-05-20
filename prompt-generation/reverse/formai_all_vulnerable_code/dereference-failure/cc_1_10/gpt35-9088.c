//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10 //The size of the maze is N x N

// The structure to represent nodes in the grid
typedef struct {
  int x,y;
  int f,g,h;
  bool wall;
  bool visited;
  struct Node *parent;
} Node;

Node* create_Node(int x,int y){ // Function to create a new Node
  Node *node = (Node*)malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->f = 0;
  node->g = 0;
  node->h = 0;
  node->wall = false;
  node->visited = false;
  node->parent = NULL;
  return node;
}

void print_grid(Node *grid[N][N]){ // Function to print grid
  printf("Grid:\n");
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(grid[i][j]->wall){
        printf("###");
      }
      else{
        printf("%3d",grid[i][j]->f);
      }
    }
    printf("\n");
  }
}

bool is_valid(int x,int y){ // Function to check if a cell is valid
  return (x>=0 && x<N && y>=0 && y<N);
}

bool is_wall(Node *grid[N][N],int x,int y){ // Function to check if a cell is a wall
  return grid[x][y]->wall;
}

bool is_visited(Node *grid[N][N],int x,int y){ // Function to check if a cell is visited
  return grid[x][y]->visited;
}

bool is_destination(int x,int y,int dest_x,int dest_y){ // Function to check if a cell is a destination node
  return (x==dest_x && y==dest_y);
}

int calculate_h(int x,int y,int dest_x,int dest_y){ // Function to calculate h for a node
  return abs(x-dest_x)+abs(y-dest_y);
}

int calculate_g(Node *current){ // Function to calculate g for a node
  return current->g+1;
}

int calculate_f(Node *current,int dest_x,int dest_y){ // Function to calculate f for a node
  return current->g+calculate_h(current->x,current->y,dest_x,dest_y);
}

Node** get_neighbours(Node *grid[N][N],Node *current){ // Function to get the neighbouring nodes for a node
  int x = current->x;
  int y = current->y;
  Node **neighbours = (Node**)malloc(4*sizeof(Node*));
  
  neighbours[0] = is_valid(x-1,y)?grid[x-1][y]:NULL;
  neighbours[1] = is_valid(x+1,y)?grid[x+1][y]:NULL;
  neighbours[2] = is_valid(x,y-1)?grid[x][y-1]:NULL;
  neighbours[3] = is_valid(x,y+1)?grid[x][y+1]:NULL;

  return neighbours;
}

void mark_wall(Node *grid[N][N],int x,int y){ // Function to mark a cell as a wall
  grid[x][y]->wall = true;
}

void mark_visited(Node *grid[N][N],int x,int y){ // Function to mark a cell as visited
  grid[x][y]->visited = true;
}

void update_node(Node *current,Node *neighbour,int dest_x,int dest_y){ // Function to update g,h and f values for a node
  int new_g = calculate_g(current);
  if(new_g < neighbour->g){
    neighbour->g = new_g;
    neighbour->h = calculate_h(neighbour->x,neighbour->y,dest_x,dest_y);
    neighbour->f = calculate_f(neighbour,dest_x,dest_y);
    neighbour->parent = current;
  }
}

Node** perform_astar(Node *grid[N][N],int start_x,int start_y,int dest_x,int dest_y){ // Function to perform A* pathfinding algorithm
  Node **path = (Node**)malloc(N*N*sizeof(Node*));
  int path_length = 0;

  Node *start_node = grid[start_x][start_y];
  Node *destination_node = grid[dest_x][dest_y];

  start_node->g = 0;
  start_node->h = calculate_h(start_x,start_y,dest_x,dest_y);
  start_node->f = calculate_f(start_node,dest_x,dest_y);
  
  Node *open_list[N*N];
  int open_list_length = 0;

  open_list[open_list_length++] = start_node;

  Node *current;

  while(open_list_length > 0){
    int lowest_f_index = 0;
    for(int i=0;i<open_list_length;i++){
      if(open_list[i]->f < open_list[lowest_f_index]->f){
        lowest_f_index = i;
      }
    }

    current = open_list[lowest_f_index];
    if(is_destination(current->x,current->y,dest_x,dest_y)){
      path[path_length++] = current;
      while(current->parent != NULL){
        path[path_length++] = current->parent;
        current = current->parent;
      }
      break;
    }

    open_list[lowest_f_index] = open_list[--open_list_length];

    Node **neighbours = get_neighbours(grid,current);

    for(int i=0;i<4;i++){
      if(neighbours[i] == NULL || is_wall(grid,neighbours[i]->x,neighbours[i]->y)){
        continue;
      }

      if(!is_visited(grid,neighbours[i]->x,neighbours[i]->y)){
        mark_visited(grid,neighbours[i]->x,neighbours[i]->y);
        open_list[open_list_length++] = neighbours[i];
        update_node(current,neighbours[i],dest_x,dest_y);
      }
    }

    free(neighbours);
  }

  return path;
}

int main(){
  Node *grid[N][N];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      grid[i][j] = create_Node(i,j);
    }
  }

  mark_wall(grid,2,2);
  mark_wall(grid,3,2);
  mark_wall(grid,4,2);

  printf("Performing A* pathfinding algorithm from (0,0) to (9,9)\n");

  Node **path = perform_astar(grid,0,0,9,9);

  if(path[0] != NULL){
    printf("Path found!\n");
    for(int i=0;i<N*N;i++){
      if(path[i] == NULL){
        break;
      }
      printf("(%d,%d) ",path[i]->x,path[i]->y);
    }
    printf("\n");
  }
  else{
    printf("Path not found.\n");
  }

  print_grid(grid);

  return 0;
}