//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: excited
#include <stdlib.h>
#include <stdio.h>

int main() {
  // Let's get excited about memory management!
  int* my_array = (int*)malloc(sizeof(int) * 100);

  // Time to fill our array with cool numbers!
  for (int i = 0; i < 100; i++) {
    my_array[i] = i * i;
    printf("Yay! %d squared is %d!\n", i, my_array[i]);
  }

  // But wait, there's more! Let's free our memory like a pro!
  free(my_array);
  printf("Ta-da! Memory released!\n");

  // Let's try something a bit different...
  struct my_struct {
    int a;
    char b;
    double c;
  };

  // Here we go, allocating memory for our fancy struct!
  struct my_struct* my_struct_ptr = (struct my_struct*)malloc(sizeof(struct my_struct));

  // Now let's set our struct values!
  my_struct_ptr->a = 123;
  my_struct_ptr->b = 'X';
  my_struct_ptr->c = 3.14159;

  // Time to showcase our struct values!
  printf("Check it out! a is %d, b is %c, and c is %f!\n", my_struct_ptr->a, my_struct_ptr->b, my_struct_ptr->c);

  // Don't forget to tidy up! Let's free our struct memory!
  free(my_struct_ptr);
  printf("Yay! Memory management on point!\n");

  // Last but not least, let's experiment with realloc!
  int* my_realloc_array = (int*)malloc(sizeof(int) * 10);

  // Oops, we need more space! Let's reallocate our array!
  my_realloc_array = (int*)realloc(my_realloc_array, sizeof(int) * 20);

  // Now let's fill our expanded array!
  for (int i = 10; i < 20; i++) {
    my_realloc_array[i] = i * i;
    printf("Wahoo! %d squared is %d!\n", i, my_realloc_array[i]);
  }

  // Time to say goodbye! Let's free our reallocated memory!
  free(my_realloc_array);
  printf("Huzzah! Memory management triumph!\n");

  return 0;
}