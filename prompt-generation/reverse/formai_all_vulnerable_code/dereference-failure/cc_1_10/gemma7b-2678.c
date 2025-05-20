//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNET_MASK_BITS 32

typedef struct subnet_mask_t {
  int num_bits;
  int mask_value;
  struct subnet_mask_t* next;
} subnet_mask_t;

subnet_mask_t* subnet_mask_alloc(int num_bits)
{
  subnet_mask_t* mask = malloc(sizeof(subnet_mask_t));
  mask->num_bits = num_bits;
  mask->mask_value = pow(2, 32 - num_bits) - 1;
  mask->next = NULL;

  return mask;
}

void subnet_mask_print(subnet_mask_t* mask)
{
  printf("Subnet mask: ");
  for (int i = 0; i < mask->num_bits; i++)
  {
    if (mask->mask_value & (1 << i))
    {
      printf("1");
    }
    else
    {
      printf("0");
    }
  }
  printf("/%d", mask->num_bits);
  printf("\n");
}

int main()
{
  subnet_mask_t* mask_head = subnet_mask_alloc(24);
  subnet_mask_print(mask_head);

  mask_head = subnet_mask_alloc(16);
  subnet_mask_print(mask_head);

  mask_head = subnet_mask_alloc(32);
  subnet_mask_print(mask_head);

  return 0;
}