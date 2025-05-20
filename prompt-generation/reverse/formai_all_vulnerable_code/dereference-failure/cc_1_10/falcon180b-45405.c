//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#define MAX 5

typedef struct
{
    int data;
    struct node* next;
}node;

node* front=NULL;
node* rear=NULL;
pthread_mutex_t mutex;
pthread_cond_t empty;
pthread_cond_t full;
sem_t sem;

void init()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&empty,NULL);
    pthread_cond_init(&full,NULL);
    sem_init(&sem,0,0);
}

void enqueue(int val)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=val;
    new_node->next=NULL;

    pthread_mutex_lock(&mutex);
    if(rear==NULL)
    {
        front=new_node;
        rear=new_node;
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
    printf("%d enqueued\n",val);
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);
    sem_post(&sem);
}

void dequeue()
{
    int val;
    node* temp;

    pthread_mutex_lock(&mutex);
    while(front==NULL)
    {
        printf("Queue is empty\n");
        pthread_cond_wait(&empty,&mutex);
    }
    temp=front;
    front=front->next;
    val=temp->data;
    free(temp);
    printf("%d dequeued\n",val);
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);
    sem_wait(&sem);
}

void* consumer(void* arg)
{
    int i;

    for(i=0;i<10;i++)
    {
        dequeue();
        sleep(1);
    }

    return NULL;
}

void* producer(void* arg)
{
    int i;

    for(i=1;i<=10;i++)
    {
        enqueue(i);
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t thread_id[2];
    int i;

    init();

    pthread_create(&thread_id[0],NULL,producer,NULL);
    pthread_create(&thread_id[1],NULL,consumer,NULL);

    for(i=0;i<2;i++)
    {
        pthread_join(thread_id[i],NULL);
    }

    return 0;
}