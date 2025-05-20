//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n, m, sum = 0, count = 0, num, limit;
    float avg;
    char again;

    srand(time(0));
    n = rand() % 10 + 1;
    m = rand() % 20 + 1;

    printf("Enter the number of integers to be generated: ");
    scanf("%d", &n);

    printf("Enter the lower limit of the integers: ");
    scanf("%d", &limit);

    printf("Enter the number of integers to be added: ");
    scanf("%d", &m);

    int arr[n];

    for (i = 0; i < n; i++) {
        arr[i] = rand() % (limit - 1) + 1;
    }

    for (i = 0; i < m; i++) {
        printf("Enter an integer to be added: ");
        scanf("%d", &num);
        sum += num;
        count++;
    }

    avg = (float) sum / count;

    printf("\nThe sum of %d integers is: %d\n", m, sum);
    printf("The average of %d integers is: %.2f\n", m, avg);

    printf("\nThe array of %d integers is:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nDo you want to generate another set of integers? (y/n): ");
    scanf(" %c", &again);

    if (again == 'y' || again == 'Y') {
        main();
    } else {
        return 0;
    }
}