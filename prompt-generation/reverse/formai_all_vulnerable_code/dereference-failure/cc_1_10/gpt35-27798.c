//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

#define PUZZLE_SIZE 3   // defining the size of the puzzle

// function to display the puzzle
void display_puzzle(int** puzzle){
    for(int i=0;i<PUZZLE_SIZE;i++){
        for(int j=0;j<PUZZLE_SIZE;j++){
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

// function to check if the puzzle is solved
int check_puzzle(int** puzzle){
    int value = 1;
    for(int i=0;i<PUZZLE_SIZE;i++){
        for(int j=0;j<PUZZLE_SIZE;j++){
            if(puzzle[i][j] != value){
                return 0;
            }
            value++;
        }
    }
    return 1;
}

int main(){
    int shmid;   // shared memory id
    key_t key = 5678;   // key value for shared memory

    // creating shared memory segment
    shmid = shmget(key, sizeof(int*)*PUZZLE_SIZE, IPC_CREAT);
    if(shmid < 0){
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // attaching the shared memory segment to the process' address space
    int** puzzle = shmat(shmid, NULL, 0);   // puzzle is a 2D array

    // initializing the puzzle
    for(int i=0;i<PUZZLE_SIZE;i++){
        puzzle[i] = (int*)malloc(sizeof(int)*PUZZLE_SIZE);
        for(int j=0;j<PUZZLE_SIZE;j++){
            puzzle[i][j] = rand()%9 + 1;
        }
    }

    display_puzzle(puzzle);  // displaying the initial puzzle

    pid_t pid = fork();   // creating a child process

    if(pid < 0){
        printf("Error creating child process\n");
        exit(1);
    }
    else if(pid == 0){   // child process
        while(1){
            int row = rand()%PUZZLE_SIZE;
            int col = rand()%PUZZLE_SIZE;

            int temp = puzzle[row][col];
            puzzle[row][col] = puzzle[(row+1)%PUZZLE_SIZE][(col+1)%PUZZLE_SIZE];
            puzzle[(row+1)%PUZZLE_SIZE][(col+1)%PUZZLE_SIZE] = temp;

            if(check_puzzle(puzzle)){
                printf("Puzzle Solved by process with PID: %d\n", getpid());
                exit(0);
            }
        }
    }
    else{   // parent process
        pid_t wpid;
        int status = 0;
        while((wpid = wait(&status)) > 0);   // waiting for child process to finish

        display_puzzle(puzzle);   // displaying the final puzzle after solving
    }

    // detaching and removing the shared memory segment
    shmdt(puzzle);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}