//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numOfElements, i;
    int *data;

    printf("Enter the number of elements: ");
    scanf("%d", &numOfElements);

    // Dynamically allocate memory for the data array
    data = (int*) malloc(numOfElements * sizeof(int));
    
    // Validate if malloc is successful or not
    if(data == NULL){
        printf("Memory allocation failed");
        return -1;
    }

    printf("Enter elements of array:\n");
    for (i = 0; i < numOfElements; i++) {
        scanf("%d", &data[i]);
    }

    // Display the array of elements
    printf("The array of elements is: [ ");
    for (i = 0; i < numOfElements; i++) {
        printf("%d ", data[i]);
    }
    printf("]\n");

    // Data Mining operations
    int sum = 0;
    float average = 0;
    int max = 0;
    int min = data[0];

    for (i = 0; i < numOfElements; i++) {
        sum += data[i];

        if (data[i] > max) {
            max = data[i];
        }

        if (data[i] < min) {
            min = data[i];
        }
    }

    average = (float)sum / numOfElements;

    //Display Data Mining Results
    printf("The sum of elements is: %d\n", sum);
    printf("The average of elements is: %.2f\n", average);
    printf("The maximum element is: %d\n", max);
    printf("The minimum element is: %d\n", min);

    free(data);
    data = NULL;

    return 0;
}