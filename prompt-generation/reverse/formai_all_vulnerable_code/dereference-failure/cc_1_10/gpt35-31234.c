//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("Welcome to my introspective data mining program!\n\n");

    int size;
    printf("Please enter the size of your data set: ");
    scanf("%d", &size);

    int* data = (int*)malloc(size * sizeof(int));
    if(data == NULL){
        printf("Error: Memory allocation failed.");
        return 1;
    }

    printf("\nEnter your data set of %d integers: ", size);
    for(int i=0; i<size; i++){
        scanf("%d", &data[i]);
    }

    //Calculate average
    float sum = 0.0, mean;
    for(int i=0; i<size; i++){
        sum += data[i];
    }
    mean = sum/size;

    printf("\nData set mean: %f\n", mean);

    //Calculate standard deviation
    float variance = 0.0, std_deviation;
    for(int i=0; i<size; i++){
        variance += (data[i] - mean) * (data[i] - mean);
    }
    variance = variance/size;
    std_deviation = sqrt(variance);

    printf("Data set standard deviation: %f\n", std_deviation);

    //Find maximum value
    int max = data[0];
    for(int i=1; i<size; i++){
        if(data[i] > max){
            max = data[i];
        }
    }

    printf("Maximum value in data set: %d\n", max);

    //Find minimum value
    int min = data[0];
    for(int i=1; i<size; i++){
        if(data[i] < min){
            min = data[i];
        }
    }

    printf("Minimum value in data set: %d\n", min);

    free(data);

    printf("\nThank you for using my introspective data mining program!");

    return 0;
}