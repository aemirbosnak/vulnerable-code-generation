//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 10

typedef struct{
    int id;
    char name[20];
    int age;
}person;

int main(){

    int shmid;
    key_t key;
    int i;
    int *shmaddr;
    person *ptr;

    key = ftok("shmfile",65);

    shmid = shmget(key,sizeof(person)*SIZE,IPC_CREAT|0666);

    if(shmid < 0){
        printf("shmget failed\n");
        exit(1);
    }

    shmaddr = shmat(shmid,NULL,0);

    if((long)shmaddr == -1){
        printf("shmat failed\n");
        exit(1);
    }

    ptr = (person*)shmaddr;

    for(i=0;i<SIZE;i++){
        ptr[i].id = i+1;
        strcpy(ptr[i].name,"Name ");
        ptr[i].age = 20;
    }

    printf("Shared memory attached successfully\n");

    for(i=0;i<SIZE;i++){
        printf("ID = %d, Name = %s, Age = %d\n",ptr[i].id,ptr[i].name,ptr[i].age);
    }

    if(shmdt(shmaddr) == -1){
        printf("shmdt failed\n");
        exit(1);
    }

    if(shmctl(shmid,IPC_RMID,NULL) == -1){
        printf("shmctl failed\n");
        exit(1);
    }

    return 0;
}