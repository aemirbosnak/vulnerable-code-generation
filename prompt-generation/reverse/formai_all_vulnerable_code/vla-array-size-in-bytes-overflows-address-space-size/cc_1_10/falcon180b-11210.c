//Falcon-180B DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    int sum = 0;
    int count = 0;
    int max = 0;
    int min = 100;
    int avg;
    int mode = 0;
    int frequency = 0;
    int i = 0;

    srand(time(0));
    printf("Enter the number of integers you want to generate: ");
    scanf("%d", &num);

    int arr[num];

    for(i=0; i<num; i++) {
        arr[i] = rand() % 101;
        sum += arr[i];
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    avg = sum / num;

    for(i=0; i<num; i++) {
        if(arr[i] == max) {
            frequency++;
        }
        if(arr[i] == min) {
            frequency++;
        }
    }

    if(frequency > 1) {
        mode = max;
    }
    else if(frequency == 1) {
        mode = min;
    }

    printf("The array is: ");
    for(i=0; i<num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The sum of the array is: %d\n", sum);
    printf("The average of the array is: %.2f\n", avg);
    printf("The maximum value in the array is: %d\n", max);
    printf("The minimum value in the array is: %d\n", min);
    printf("The mode of the array is: %d\n", mode);

    return 0;
}