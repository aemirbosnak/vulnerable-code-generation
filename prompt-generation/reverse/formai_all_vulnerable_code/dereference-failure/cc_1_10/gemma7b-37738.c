//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 256

typedef struct subnet
{
    int address;
    int mask;
    struct subnet* next;
} subnet_t;

subnet_t* create_subnet(int address, int mask)
{
    subnet_t* subnet = (subnet_t*)malloc(sizeof(subnet_t));
    subnet->address = address;
    subnet->mask = mask;
    subnet->next = NULL;

    return subnet;
}

void add_subnet(subnet_t* head, int address, int mask)
{
    subnet_t* subnet = create_subnet(address, mask);

    if (head == NULL)
    {
        head = subnet;
    }
    else
    {
        subnet_t* current = head;

        while (current->next)
        {
            current = current->next;
        }

        current->next = subnet;
    }
}

int calculate_subnet(subnet_t* head, int address)
{
    subnet_t* current = head;

    while (current)
    {
        if (address >= current->address && address < current->address + (1 << (32 - current->mask)))
        {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int main()
{
    subnet_t* head = NULL;

    add_subnet(head, 192, 24);
    add_subnet(head, 192, 25);
    add_subnet(head, 192, 26);

    if (calculate_subnet(head, 192) == 1)
    {
        printf("Address is in subnet.\n");
    }
    else
    {
        printf("Address is not in subnet.\n");
    }

    return 0;
}