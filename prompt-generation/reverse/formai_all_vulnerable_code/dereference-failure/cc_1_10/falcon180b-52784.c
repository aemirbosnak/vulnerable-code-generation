//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 10

//structure for passing data to threads
struct v{
    int *arr;
    int start;
    int end;
};

void *runner(void *param); //prototype for the thread

int main(){
    int arr[MAX] = {1,3,5,7,9,2,4,6,8,0};
    int target = 5;
    pthread_t thread_id[MAX/2]; //creating maximum threads possible
    struct v data[MAX/2]; //creating data structure for passing to threads

    //splitting the array into two parts
    for(int i=0;i<MAX/2;i++){
        data[i].arr = &arr[i*2];
        data[i].start = i*2;
        data[i].end = (i*2)+1;
    }

    //creating threads
    for(int i=0;i<MAX/2;i++){
        pthread_create(&thread_id[i],NULL,runner,&data[i]);
    }

    //joining threads
    for(int i=0;i<MAX/2;i++){
        pthread_join(thread_id[i],NULL);
    }

    //printing the result
    if(target==-1){
        printf("Element not found in the array\n");
    }
    else{
        printf("Element found at position %d\n",target);
    }

    return 0;
}

void *runner(void *param){
    struct v *data = param;
    int start = data->start;
    int end = data->end;

    if(start>end){
        start = end;
        end = data->start;
    }

    if(data->arr[start] == -1){
        pthread_exit(0);
    }

    if(data->arr[start] == data->arr[end]){
        data->arr[start] = -1;
        pthread_exit(0);
    }

    if(data->arr[start] > data->arr[end]){
        data->arr[start] = data->arr[start] + data->arr[end];
        data->arr[end] = data->arr[start] - data->arr[end];
        data->arr[start] = data->arr[start] - data->arr[end];
    }

    else{
        data->arr[end] = data->arr[start] + data->arr[end];
        data->arr[start] = data->arr[end] - data->arr[start];
        data->arr[end] = data->arr[end] - data->arr[start];
    }

    if(data->arr[start] == -1 || data->arr[end] == -1){
        pthread_exit(0);
    }
}