//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 256

void checksum_calculator(char **arr, int n)
{
    int i, j, k, sum = 0, carry = 0, flag = 0;
    char *p, *q;

    for (i = 0; i < n; i++)
    {
        sum = 0;
        p = arr[i];
        for (j = 0; p[j] != '\0'; j++)
        {
            k = p[j] - '0';
            sum += k * k;
        }

        if (carry)
            sum += carry;

        if (sum > MAX_DIGITS)
        {
            flag = 1;
            carry = sum / MAX_DIGITS;
            sum %= MAX_DIGITS;
        }

        arr[i][0] = '0' + sum;
        if (carry)
            arr[i][1] = '0' + carry;
    }

    if (flag)
        printf("Error: checksum too large.\n");
}

int main()
{
    char **arr = NULL;
    int n;

    printf("Enter the number of checksum calculations: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        arr[i] = malloc(2 * MAX_DIGITS);

    checksum_calculator(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("Checksum for array %d: ", i + 1);
        for (int j = 0; arr[i][j] != '\0'; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }

    return 0;
}