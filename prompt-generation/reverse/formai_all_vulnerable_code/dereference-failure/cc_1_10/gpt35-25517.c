//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short checksum(char *buff, int len);

int main()
{
    char input[200];          // buffer to read input
    int len = 0;              // length of input string
    unsigned short sum = 0;   // checksum value

    // Welcome message
    printf("Welcome to the C Checksum Calculator!\n");
    printf("Please enter a string to calculate the checksum:\n");

    fgets(input, sizeof(input), stdin);      // read input string
    len = strlen(input) - 1;                  // calculate length (excluding \n)

    sum = checksum(input, len);               // calculate checksum

    printf("\nThe checksum of the input string is: %04X\n", sum);   // print checksum value

    return 0;
}

unsigned short checksum(char *buff, int len)
{
    unsigned int sum = 0;               // intermediate sum
    unsigned short cksum = 0;           // final checksum value
    int i = 0;                          // loop iterator

    // calculate sum of 2-byte chunks
    for (i = 0; i < len - 1; i += 2)
    {
        sum += ((unsigned char)buff[i] << 8) + (unsigned char)buff[i + 1];
    }

    // handle odd length
    if (len % 2 != 0)
    {
        sum += (unsigned char)buff[len - 1];
    }

    // fold sum into 2-byte checksum
    while (sum >> 16)
    {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    cksum = ~sum;       // take 1's complement of sum

    return cksum;
}