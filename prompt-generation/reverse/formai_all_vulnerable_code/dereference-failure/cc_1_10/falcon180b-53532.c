//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Structure for passing data to thread
struct v{
    int *a;
    int n;
};

// Function to be executed by thread
void *sum(void *arg){
    struct v *v = (struct v*)arg;
    int i,sum=0;
    for(i=0;i<v->n;i++){
        sum+=*(v->a+i);
    }
    pthread_exit(0);
}

// Main function
int main(){
    pthread_t threads[5];
    int i,n,sum=0,*a;

    // Allocate memory dynamically
    a=(int*)malloc(10*sizeof(int));

    // Initialize array elements
    for(i=0;i<10;i++){
        *(a+i)=i;
    }

    // Divide array into 5 parts
    int part_size=10/5;

    // Create 5 threads
    for(i=0;i<5;i++){
        struct v *v=(struct v*)malloc(sizeof(struct v));
        v->a=a+i*part_size;
        v->n=part_size;
        pthread_create(&threads[i],NULL,sum,v);
    }

    // Join all threads
    for(i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }

    // Free dynamically allocated memory
    free(a);

    // Print sum
    printf("Sum of array elements: %d\n",sum);

    return 0;
}