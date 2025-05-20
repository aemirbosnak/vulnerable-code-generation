//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int num, i, total, sum;
    int arr[6];
    char choice;

    printf("Enter the total number of dices to be thrown: ");
    scanf("%d", &num);

    printf("Enter the number of dices to be thrown each time (max 6): ");
    scanf("%d", &total);

    printf("Enter the number of sides of each dice: ");
    scanf("%d", &arr[0]);

    for(i=1; i<total; i++){
        printf("Enter the number of sides of dice %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter 'y' to continue or any other key to exit: ");
    scanf(" %c", &choice);

    while(choice=='y'){

        int temp[total];
        int j;

        for(i=0; i<total; i++){
            temp[i] = rand()%arr[i] + 1;
        }

        printf("The values on the dices are: ");
        for(i=0; i<total; i++){
            printf("%d ", temp[i]);
        }

        printf("\nThe total sum is: ");
        sum = 0;
        for(i=0; i<total; i++){
            sum += temp[i];
        }
        printf("%d\n", sum);

        printf("Enter 'y' to continue or any other key to exit: ");
        scanf(" %c", &choice);

    }

    return 0;
}