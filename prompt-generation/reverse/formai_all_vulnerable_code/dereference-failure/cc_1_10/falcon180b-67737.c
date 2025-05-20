//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>

#define SIZE 10

int main(){
    int shmid;
    char *shmptr;
    int id;
    int i;

    shmid = shmget(IPC_PRIVATE, SIZE*sizeof(int), IPC_CREAT|0666);

    if(shmid == -1){
        printf("Error in shmget\n");
        exit(0);
    }

    shmptr = (char*)shmat(shmid, NULL, 0);

    if((int)shmptr == -1){
        printf("Error in shmat\n");
        exit(0);
    }

    for(i=0; i<SIZE; i++){
        *(shmptr+i) = i;
    }

    id = fork();

    if(id == 0){
        for(i=0; i<SIZE; i++){
            printf("%d ", *(shmptr+i));
        }
        printf("\n");
    }
    else{
        wait(NULL);
    }

    shmdt(shmptr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}