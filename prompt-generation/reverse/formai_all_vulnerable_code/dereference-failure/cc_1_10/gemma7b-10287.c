//Gemma-7B DATASET v1.0 Category: Firewall ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Firewall
{
    char buffer[MAX_BUFFER_SIZE];
    int index;
    int capacity;
} Firewall;

Firewall* firewall_init(int capacity)
{
    Firewall* fw = malloc(sizeof(Firewall));
    fw->index = 0;
    fw->capacity = capacity;
    memset(fw->buffer, 0, MAX_BUFFER_SIZE);
    return fw;
}

void firewall_add(Firewall* fw, char data)
{
    if (fw->index >= fw->capacity)
    {
        return;
    }

    fw->buffer[fw->index++] = data;
}

int firewall_check(Firewall* fw, char data)
{
    for (int i = 0; i < fw->index; i++)
    {
        if (fw->buffer[i] == data)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    Firewall* fw = firewall_init(10);

    firewall_add(fw, 'a');
    firewall_add(fw, 'b');
    firewall_add(fw, 'c');
    firewall_add(fw, 'a');

    if (firewall_check(fw, 'a'))
    {
        printf("Data found.\n");
    }

    if (firewall_check(fw, 'x'))
    {
        printf("Data not found.\n");
    }

    return 0;
}