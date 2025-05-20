//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#define MAX_BUF_SIZE 256

int shmid;
int semid;
char *buff = NULL;

void initSemaphore()
{
    struct sembuf semBuf;

    semBuf.sem_num = 0;
    semBuf.sem_op = 1; 
    semBuf.sem_flg = 0;
    
    semop(semid, &semBuf, 1);
}

void signalHandler(int signo)
{
    if(signo == SIGINT)
    {
        printf("Program exiting due to SIGINT signal...\n");

        if(buff != NULL)
        {
            shmdt(buff);
        }

        if(shmid > 0)
        {
            shmctl(shmid, IPC_RMID, NULL);
        }

        if(semid > 0)
        {
            semctl(semid, 0, IPC_RMID);
        }

        exit(0);
    }
}

int levenshteinDistance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int** matrix = (int**) calloc(len1+1, sizeof(int*));
    int i = 0, j = 0, result = 0;

    for(i=0; i<=len1; i++)
    {
        matrix[i] = (int*) calloc(len2+1, sizeof(int));
        matrix[i][0] = i;
    }

    for(j=0; j<=len2; j++)
    {
        matrix[0][j] = j;
    }

    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else
            {
                matrix[i][j] = 1 + (matrix[i-1][j] < matrix[i][j-1] ? matrix[i-1][j] : matrix[i][j-1]);
                matrix[i][j] = (matrix[i][j] < matrix[i-1][j-1]+1 ? matrix[i][j] : matrix[i-1][j-1]+1);
            }
        }
    }

    result = matrix[len1][len2];

    for(i=0; i<=len1; i++)
    {
        free(matrix[i]);
    }

    free(matrix);

    return result;
}

void reader(int semid, char *buff, int size)
{
    struct sembuf semBuf;

    semBuf.sem_num = 0;
    semBuf.sem_op = -1; 
    semBuf.sem_flg = 0;
    
    semop(semid, &semBuf, 1);

    printf("Enter the first string: ");
    fgets(buff, MAX_BUF_SIZE, stdin);
    buff[strcspn(buff, "\n")] = 0;
    
    semBuf.sem_op = 1;
    semop(semid, &semBuf, 1);
}

void writer(int semid, char *buff, int size)
{
    struct sembuf semBuf;

    usleep(10000);
    
    semBuf.sem_num = 0;
    semBuf.sem_op = -1; 
    semBuf.sem_flg = 0;

    semop(semid, &semBuf, 1);

    printf("Enter the second string: ");
    fgets(buff+strlen(buff), MAX_BUF_SIZE-strlen(buff), stdin);
    buff[strcspn(buff, "\n")] = 0;

    initSemaphore();

    semBuf.sem_op = 1;
    semop(semid, &semBuf, 1);
}

void calculator(int semid, char *buff, int size)
{
    struct sembuf semBuf;

    usleep(20000);
    
    semBuf.sem_num = 0;
    semBuf.sem_op = -1; 
    semBuf.sem_flg = 0;
    
    semop(semid, &semBuf, 1);

    printf("\nCalculating the Levenshtein Distance...\n");

    int length = strlen(buff);
    char* str1 = (char*) calloc(length+1, sizeof(char));
    strncpy(str1, buff, length);

    char* str2 = (char*) calloc(length+1, sizeof(char));
    strncpy(str2, buff+length+1, length);

    int result = levenshteinDistance(str1, str2);

    printf("The Levenshtein Distance between %s and %s is %d.\n\n", str1, str2, result);

    free(str1);
    free(str2);
    
    initSemaphore();

    semBuf.sem_op = 1;
    semop(semid, &semBuf, 1);
}

int main()
{
    signal(SIGINT, signalHandler);

    key_t key = ftok(".", 'A');
    shmid = shmget(key, MAX_BUF_SIZE, 0666);
    semid = semget(key, 1, 0666);
    buff = shmat(shmid, 0, 0);

    if(buff == (char*)-1 || shmid == -1 || semid == -1)
    {
        printf("Error: Failed to create Shared Memory or Semaphore.\nExiting...\n");

        if(buff != NULL)
        {
            shmdt(buff);
        }

        if(shmid > 0)
        {
            shmctl(shmid, IPC_RMID, NULL);
        }

        if(semid > 0)
        {
            semctl(semid, 0, IPC_RMID);
        }

        exit(1);
    }
    else
    {
        memset(buff, 0, MAX_BUF_SIZE);
    }

    initSemaphore();

    printf("Levenshtein Distance Calculator\n");

    while(1)
    {
        printf("\nPress:\n1. To enter the strings.\n2. To calculate the Levenshtein Distance.\n3. To exit.\n");

        char choice[2];
        memset(choice, 0, sizeof(choice));
        fgets(choice, sizeof(choice), stdin);

        switch(choice[0])
        {
            case '1':
                writer(semid, buff, MAX_BUF_SIZE);
                break;

            case '2':
                calculator(semid, buff, MAX_BUF_SIZE);
                break;

            case '3':
                printf("Exiting the program...\n");

                if(buff != NULL)
                {
                    shmdt(buff);
                }

                if(shmid > 0)
                {
                    shmctl(shmid, IPC_RMID, NULL);
                }

                if(semid > 0)
                {
                    semctl(semid, 0, IPC_RMID);
                }

                exit(0);
                break;

            default:
                printf("Invalid choice. Try again...\n");
                break;
        }
    }

    return 0;
}