//FormAI DATASET v1.0 Category: Interprocess communication ; Style: retro
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

#define SHMSZ 27 
  
int main() 
{ 
    int shmid; 
    key_t key; 
    char *shm, *s; 
  
    // generate unique key 
    key = ftok(".", 'M'); 
  
    // create the shared memory segment 
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) { 
        perror("shmget"); 
        exit(1); 
    } 
  
    // attach the shared memory segment to the data segment 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { 
        perror("shmat"); 
        exit(1); 
    } 
  
    // write data to the shared memory segment 
    s = shm; 
    for (char c = 'A'; c <= 'Z'; c++) 
        *s++ = c; 
    *s = '\0'; 
  
    // wait until other process changes the first character to '*'
    while (*shm != '*') 
        sleep(1); 
  
    // read data from the shared memory segment 
    for (s = shm; *s != '\0'; s++) 
        putchar(*s); 
    putchar('\n'); 
  
    // detach the shared memory segment from the data segment 
    if (shmdt(shm) == -1) { 
        perror("shmdt"); 
        exit(1); 
    } 
  
    // delete the shared memory segment 
    if (shmctl(shmid, IPC_RMID, 0) == -1) { 
        perror("shmctl"); 
        exit(1); 
    } 
  
    return 0; 
}