//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 10

typedef struct subnet
{
    int address;
    int mask;
    struct subnet* next;
} subnet_t;

subnet_t* subnet_create(int address, int mask)
{
    subnet_t* subnet = (subnet_t*)malloc(sizeof(subnet_t));
    subnet->address = address;
    subnet->mask = mask;
    subnet->next = NULL;
    return subnet;
}

void subnet_add(subnet_t* head, int address, int mask)
{
    subnet_t* subnet = subnet_create(address, mask);
    if (head == NULL)
    {
        head = subnet;
    }
    else
    {
        subnet_t* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = subnet;
    }
}

void subnet_print(subnet_t* head)
{
    subnet_t* current = head;
    while (current)
    {
        printf("Address: %x, Mask: %x\n", current->address, current->mask);
        current = current->next;
    }
}

int main()
{
    subnet_t* subnet_head = NULL;

    subnet_add(subnet_head, 192, 255);
    subnet_add(subnet_head, 192, 254);
    subnet_add(subnet_head, 192, 252);

    subnet_print(subnet_head);

    return 0;
}