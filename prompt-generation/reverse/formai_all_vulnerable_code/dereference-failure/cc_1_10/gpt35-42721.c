//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *ptr1,*ptr2,*ptr3,*ptr4;

  //allocate memory for ptr1
  ptr1 = (int*) malloc(3*sizeof(int));

  //allocate memory for ptr2
  ptr2 = (int*) calloc(2,sizeof(int));

  //allocate memory for ptr3
  ptr3 = (int*) realloc(ptr1, 5*sizeof(int));

  //check if memory allocation is successful or not
  if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL)
  {
    printf("Memory allocation failed.\n");
    return 1;
  }
  else
  {
    //store values in ptr1
    ptr1[0] = 1;
    ptr1[1] = 2;
    ptr1[2] = 3;

    //store values in ptr2
    ptr2[0] = 4;
    ptr2[1] = 5;

    //store values in ptr3
    ptr3[3] = 6;
    ptr3[4] = 7;

    //print values from ptr1
    printf("Values from ptr1: \n");
    for (int i = 0; i < 3; i++)
    {
      printf("%d ", *(ptr1+i));
    }
    printf("\n");

    //print values from ptr2
    printf("Values from ptr2: \n");
    for (int i = 0; i < 2; i++)
    {
      printf("%d ", *(ptr2+i));
    }
    printf("\n");

    //print values from ptr3
    printf("Values from ptr3: \n");
    for (int i = 0; i < 5; i++)
    {
      printf("%d ", *(ptr3+i));
    }
    printf("\n");

    //deallocate memory for ptr1 and ptr2
    free(ptr1);
    free(ptr2);
    ptr1 = NULL;
    ptr2 = NULL;

    //allocate memory for ptr4
    ptr4 = (int*) calloc(4,sizeof(int));

    //store values in ptr4
    ptr4[0] = 8;
    ptr4[1] = 9;
    ptr4[2] = 10;
    ptr4[3] = 11;

    //print values from ptr4
    printf("Values from ptr4: \n");
    for (int i = 0; i < 4; i++)
    {
      printf("%d ", *(ptr4+i));
    }
    printf("\n");

    //deallocate memory for ptr3 and ptr4
    free(ptr3);
    free(ptr4);
    ptr3 = NULL;
    ptr4 = NULL;

    return 0;
  }
}