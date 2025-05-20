//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 12

char maze[ROWS][COLS]= {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

enum directions{UP, RIGHT, DOWN, LEFT};

struct Position{
    int row;
    int col;
};

typedef struct Position Position;
typedef Position* posPtr;

posPtr makePosition(int row, int col){
    posPtr position= (posPtr)malloc(sizeof(Position));
    position->row= row;
    position->col= col;
    return position;
}

void freePosition(posPtr position){
    free(position);
}

int checkPosition(posPtr position){
    return position->row>=0 && position->row<= ROWS && position->col>=0 && position->col<=COLS && maze[position->row][position->col]== '.';
}

int comparePositions(posPtr pos1, posPtr pos2){
    return pos1->row == pos2 ->row && pos1 ->col== pos2 ->col;
}

void printMaze(){
    for (int row=0; row<ROWS; row++){
        for(int col=0; col<COLS; col++){
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

int move(posPtr pos, int direction){
    switch (direction){
        case UP:
            pos->row -= 1;
            break;
        case RIGHT:
            pos->col += 1;
            break;
        case DOWN:
            pos->row += 1;
            break;
        case LEFT:
            pos->col -= 1;
            break;
    }
    return checkPosition(pos);
}

int findRoute(posPtr start, posPtr end){
    int routing= 0;
    posPtr current= makePosition(start->row, start->col);

    int directions[4]={UP, RIGHT, DOWN, LEFT};
    int len= 4;
    int randomIndex;
    while(!comparePositions(current,end)){
        int found= 0;
        while(!found){
            if(len== 0){
                freePosition(current);
                return routing;
            }
            randomIndex= rand() % len;
            int direction= directions[randomIndex];
            directions[randomIndex]= directions[len-1];
            len--;

            found= move(current, direction);
        }
        len= 4;
        routing++;
        maze[current->row][current->col]=(char) routing % 10 + '0';
    }
    freePosition(current);
    return routing;
}

int main(){
    srand((unsigned int) time(NULL));
    posPtr start= makePosition(1,1);
    posPtr end= makePosition(ROWS-2, COLS-2);
    printMaze();
    printf("Routing Length: %d\n", findRoute(start, end));
    printMaze();
    freePosition(start);
    freePosition(end);
    return 0;
}