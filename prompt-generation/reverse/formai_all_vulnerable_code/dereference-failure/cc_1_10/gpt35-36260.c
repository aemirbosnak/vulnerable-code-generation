//FormAI DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char recover_data(char data[], int start, int end);

int main()
{
    char original_data[MAX_SIZE];
    char recovered_data[MAX_SIZE];
    int start, end;
    int i;

    printf("Enter the original data: ");
    fgets(original_data, MAX_SIZE, stdin);

    printf("Enter the start position: ");
    scanf("%d", &start);

    printf("Enter the end position: ");
    scanf("%d", &end);

    recovered_data[start-1] = recover_data(original_data, start-1, end-1);

    printf("\nRecovered Data:\n");
    for (i = 0; i < strlen(original_data); i++)
    {
        if (recovered_data[i] != 0)
        {
            printf("%c", recovered_data[i]);
        }
        else
        {
            printf(".");
        }
    }

    return 0;
}

char recover_data(char data[], int start, int end)
{
    char recovered = 0;
    int i;

    for (i = start; i <= end; i++)
    {
        if (data[i] != '\n')
        {
            recovered ^= data[i];
        }
        else
        {
            break;
        }
    }

    return recovered;
}