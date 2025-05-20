//FormAI DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define SHM_SIZE 1024
#define SEM_KEY 6666
#define SHM_KEY 4444

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
	int semid, shmid, pid;
	union semun sem_arg;
	struct sembuf sem_op;
	char *shared_mem, *input, *output;
	bool sem_ready = false;
	
	//Create semaphore
	semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT | IPC_EXCL);
	if(semid == -1) {
		if(errno == EEXIST) {
			semid = semget(SEM_KEY, 1, 0666);
			if(semid == -1) {
				perror("Semaphore already exists but could not be accessed\n");
				exit(EXIT_FAILURE);
			}
			sem_ready = true;
		}
		else {
			perror("Semaphore could not be created\n");
			exit(EXIT_FAILURE);
		}
	}
	else {
		sem_arg.val = 1;
		
		if(semctl(semid, 0, SETVAL, sem_arg) == -1) {
			perror("Failed to initialize semaphore\n");
			semctl(semid, 0, IPC_RMID);
			exit(EXIT_FAILURE);
		}
		
		sem_ready = true;
		printf("Semaphore created and initialized\n");
	}
	
	//Create shared memory
	shmid = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT | IPC_EXCL);
	if(shmid == -1) {
		if(errno == EEXIST) {
			shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
			if(shmid == -1) {
				perror("Shared memory already exists but could not be accessed\n");
				semctl(semid, 0, IPC_RMID); //Remove semaphore
				exit(EXIT_FAILURE);
			}
		}
		else {
			perror("Shared memory could not be created\n");
			semctl(semid, 0, IPC_RMID); //Remove semaphore
			exit(EXIT_FAILURE);
		}
	}
	else {
		printf("Shared memory created\n");
	}
	
	//Attach shared memory
	shared_mem = (char*) shmat(shmid, NULL, 0);
	if(shared_mem == (char*)-1) {
		perror("Failed to attach shared memory\n");
		semctl(semid, 0, IPC_RMID); //Remove semaphore
		shmctl(shmid, IPC_RMID, NULL); //Remove shared memory
		exit(EXIT_FAILURE);
	}
	
	//Fork child process
	pid = fork();
	if(pid == -1) {
		perror("Failed to fork child process\n");
		semctl(semid, 0, IPC_RMID); //Remove semaphore
		shmctl(shmid, IPC_RMID, NULL); //Remove shared memory
		exit(EXIT_FAILURE);
	}
	else if(pid == 0) { //Child process
		while(1) {
			sem_op.sem_num = 0;
			sem_op.sem_op = -1;
			sem_op.sem_flg = 0;
			
			if(semop(semid, &sem_op, 1) == -1) {
				perror("Semaphore wait operation failed\n");
				shmdt(shared_mem); //Detach shared memory
				exit(EXIT_FAILURE);
			}
			
			input = shared_mem;
			output = strtok(input, " ");
			while(output != NULL) {
				printf("Child read: %s\n", output);
				output = strtok(NULL, " ");
			}
			
			sem_op.sem_num = 0;
			sem_op.sem_op = 1;
			sem_op.sem_flg = 0;
			
			if(semop(semid, &sem_op, 1) == -1) {
				perror("Semaphore signal operation failed\n");
				shmdt(shared_mem); //Detach shared memory
				exit(EXIT_FAILURE);
			}
			
			sleep(1); //Pause for 1 second
		}
	}
	else { //Parent process
		while(1) {
			printf("Enter message: ");
			input = fgets(shared_mem, SHM_SIZE, stdin); //Read input from user and store in shared memory
			if(input != NULL) {
				*strchr(input, '\n') = '\0'; //Remove newline character from input
				
				sem_op.sem_num = 0;
				sem_op.sem_op = -1;
				sem_op.sem_flg = 0;
				
				if(semop(semid, &sem_op, 1) == -1) {
					perror("Semaphore wait operation failed\n");
					shmdt(shared_mem); //Detach shared memory
					exit(EXIT_FAILURE);
				}
				
				printf("Parent wrote: %s\n", shared_mem);
				
				sem_op.sem_num = 0;
				sem_op.sem_op = 1;
				sem_op.sem_flg = 0;
				
				if(semop(semid, &sem_op, 1) == -1) {
					perror("Semaphore signal operation failed\n");
					shmdt(shared_mem); //Detach shared memory
					exit(EXIT_FAILURE);
				}
			}
			else {
				printf("Error reading input\n");
			}
		}
	}
	
	//Detach shared memory
	if(shmdt(shared_mem) == -1) {
		perror("Failed to detach shared memory\n");
	}
	
	if(sem_ready) {
		//Remove semaphore
		if(semctl(semid, 0, IPC_RMID) == -1) {
			perror("Failed to remove semaphore\n");
		}
		else {
			printf("Semaphore removed\n");
		}
	}
	
	//Remove shared memory
	if(shmctl(shmid, IPC_RMID, NULL) == -1) {
		perror("Failed to remove shared memory\n");
	}
	else {
		printf("Shared memory removed\n");
	}
	
	return 0;
}