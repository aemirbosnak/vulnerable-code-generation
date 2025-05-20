//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void calculate_subnet_mask(int prefix_length, char *subnet_mask)
{
    int i;

    subnet_mask = (char *)malloc(MAX_BUFFER_SIZE);

    switch (prefix_length)
    {
        case 0:
            subnet_mask = "0";
            break;
        case 1:
            subnet_mask = "1";
            break;
        case 2:
            subnet_mask = "11";
            break;
        case 3:
            subnet_mask = "111";
            break;
        case 4:
            subnet_mask = "1111";
            break;
        default:
            subnet_mask = "Error";
            break;
    }

    for (i = 0; subnet_mask[i] != '\0'; i++)
    {
        subnet_mask[i] = '1';
    }

    subnet_mask[prefix_length - 1] = '0';

    return;
}

int main()
{
    int prefix_length;
    char subnet_mask[MAX_BUFFER_SIZE];

    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    calculate_subnet_mask(prefix_length, subnet_mask);

    printf("The subnet mask is: %s\n", subnet_mask);

    return 0;
}