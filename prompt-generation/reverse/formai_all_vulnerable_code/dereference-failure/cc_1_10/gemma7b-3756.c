//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SRAM_SIZE 1024

int main()
{
    int i, j, ram_usage = 0, address, size_used = 0;
    char *sram = (char *)malloc(SRAM_SIZE);

    for (i = 0; i < SRAM_SIZE; i++)
    {
        sram[i] = 0;
    }

    while (1)
    {
        printf("Enter address: ");
        scanf("%d", &address);

        if (address < 0 || address >= SRAM_SIZE)
        {
            printf("Invalid address.\n");
            continue;
        }

        printf("Enter size of data: ");
        scanf("%d", &size_used);

        if (size_used < 0)
        {
            printf("Invalid size.\n");
            continue;
        }

        for (j = 0; j < size_used; j++)
        {
            sram[address] = 1;
            address++;
        }

        ram_usage++;

        printf("RAM usage: %d%%.\n", ram_usage * 100 / SRAM_SIZE);
    }

    free(sram);

    return 0;
}