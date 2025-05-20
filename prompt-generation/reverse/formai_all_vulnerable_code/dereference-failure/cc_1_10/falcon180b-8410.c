//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define CHECKSUM_SIZE 16

void generate_checksum(char* message, char* checksum)
{
    int i, j, sum = 0;
    for (i = 0; i < strlen(message); i++)
    {
        sum += message[i];
    }
    sprintf(checksum, "%04x", sum);
}

int validate_checksum(char* message, char* checksum)
{
    int i, sum = 0;
    for (i = 0; i < strlen(message); i++)
    {
        sum += message[i];
    }
    return sum == strtol(checksum, NULL, 16);
}

int main()
{
    char message[MAX_SIZE];
    char checksum[CHECKSUM_SIZE];

    printf("Enter a message: ");
    fgets(message, MAX_SIZE, stdin);

    generate_checksum(message, checksum);

    printf("Message: %s\n", message);
    printf("Checksum: %s\n", checksum);

    if (validate_checksum(message, checksum))
    {
        printf("Checksum is valid.\n");
    }
    else
    {
        printf("Checksum is invalid.\n");
    }

    return 0;
}