//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100000
#define MIN_NUM -100000

typedef struct {
    int num;
    struct node *next;
} node;

node *head = NULL;

void generateRandomNumbers() {
    node *newNode, *temp;
    int randomNum;

    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        newNode = (node*) malloc(sizeof(node));
        newNode->num = rand() % (MAX - MIN_NUM + 1) + MIN_NUM;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            continue;
        }

        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int sumOfDigits(int num) {
    int sum = 0;
    int tempNum = num;

    while (tempNum != 0) {
        sum += tempNum % 10;
        tempNum /= 10;
    }

    return sum;
}

int maxOfThree(int num1, int num2, int num3) {
    int max;

    if (num1 > num2 && num1 > num3) {
        max = num1;
    } else if (num2 > num1 && num2 > num3) {
        max = num2;
    } else {
        max = num3;
    }

    return max;
}

int main() {
    int num1, num2, num3, sum, result;
    int tempSum, max;

    generateRandomNumbers();

    node *current = head;

    while (current != NULL) {
        num1 = current->num;
        current = current->next;

        if (current != NULL) {
            num2 = current->num;
            current = current->next;

            if (current != NULL) {
                num3 = current->num;

                sum = sumOfDigits(num1) + sumOfDigits(num2) + sumOfDigits(num3);
                tempSum = num1 + num2 + num3;
                max = maxOfThree(num1, num2, num3);

                result = max * sum;

                printf("Numbers: %d, %d, %d\n", num1, num2, num3);
                printf("Sum of digits: %d\n", sum);
                printf("Sum of numbers: %d\n", tempSum);
                printf("Maximum number: %d\n", max);
                printf("Result: %d\n", result);
                printf("\n");
            }
        }
    }

    return 0;
}