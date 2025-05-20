//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));

    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int maze[rows][cols];

    //initialize all cells to be blocked
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            maze[i][j] = 1;
        }
    }

    //pick random starting location
    int startX = rand() % rows; //random row
    int startY = rand() % cols; //random column

    int currentX = startX;
    int currentY = startY;

    //mark starting location as visited
    maze[currentX][currentY] = 0;

    //generate maze
    while(1){
        //check if there are any unvisited neighbors
        int unvisitedNeighbors = 0;
        int neighborsX[4], neighborsY[4];

        //up
        if(currentX-2 >= 0 && maze[currentX-2][currentY] == 1){
            unvisitedNeighbors++;
            neighborsX[unvisitedNeighbors] = currentX-2;
            neighborsY[unvisitedNeighbors] = currentY;
        }

        //down
        if(currentX+2 < rows && maze[currentX+2][currentY] == 1){
            unvisitedNeighbors++;
            neighborsX[unvisitedNeighbors] = currentX+2;
            neighborsY[unvisitedNeighbors] = currentY;
        }

        //left
        if(currentY-2 >= 0 && maze[currentX][currentY-2] == 1){
            unvisitedNeighbors++;
            neighborsX[unvisitedNeighbors] = currentX;
            neighborsY[unvisitedNeighbors] = currentY-2;
        }

        //right
        if(currentY+2 < cols && maze[currentX][currentY+2] == 1){
            unvisitedNeighbors++;
            neighborsX[unvisitedNeighbors] = currentX;
            neighborsY[unvisitedNeighbors] = currentY+2;
        }

        if(unvisitedNeighbors > 0){
            //choose random unvisited neighbor
            int randomIndex = rand() % unvisitedNeighbors + 1;
            int newCurrentX = neighborsX[randomIndex];
            int newCurrentY = neighborsY[randomIndex];

            //remove wall between current cell and chosen neighbor
            if(newCurrentX < currentX){
                maze[currentX-1][currentY] = 0;
            }
            else if(newCurrentX > currentX){
                maze[currentX+1][currentY] = 0;
            }
            else if(newCurrentY < currentY){
                maze[currentX][currentY-1] = 0;
            }
            else if(newCurrentY > currentY){
                maze[currentX][currentY+1] = 0;
            }

            //mark chosen neighbor as visited and update current location
            maze[newCurrentX][newCurrentY] = 0;
            currentX = newCurrentX;
            currentY = newCurrentY;
        }
        else{
            //no unvisited neighbors, backtrack to nearest cell with unvisited neighbors
            int backtrackX, backtrackY;

            //find nearest cell with unvisited neighbors
            for(int i=currentX-1; i<=currentX+1; i++){
                if(i < 0 || i >= rows) continue;
                for(int j=currentY-1; j<=currentY+1; j++){
                    if(j < 0 || j >= cols) continue;
                    if(abs(i-currentX) == abs(j-currentY)) continue; //skip diagonals
                    if(maze[i][j] == 0) continue; //skip visited cells
                    if(i == currentX && j == currentY) continue; //skip current cell
                    if(i == backtrackX && j == backtrackY) continue; //skip previous cell
                    
                    //found unvisited neighbor
                    if(i < currentX){
                        maze[currentX-1][currentY] = 0;
                    }
                    else if(i > currentX){
                        maze[currentX+1][currentY] = 0;
                    }
                    else if(j < currentY){
                        maze[currentX][currentY-1] = 0;
                    }
                    else if(j > currentY){
                        maze[currentX][currentY+1] = 0;
                    }

                    //update backtrack location and current location
                    backtrackX = currentX;
                    backtrackY = currentY;
                    currentX = i;
                    currentY = j;
                }
            }

            //no unvisited neighbors found, maze is complete
            if(backtrackX == startX && backtrackY == startY){
                break;
            }
        }
    }

    //print maze
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(maze[i][j] == 1){
                printf("# ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}