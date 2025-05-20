//FormAI DATASET v1.0 Category: Memory management ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void* paranoid_malloc(size_t size);
void* paranoid_calloc(size_t nmemb, size_t size);
void* paranoid_realloc(void* ptr, size_t size);
void paranoid_free(void* ptr);

int main()
{
   void *ptr1, *ptr2;
   ptr1 = paranoid_malloc(10 * sizeof(int));
   ptr2 = paranoid_calloc(5, sizeof(int)); 
   paranoid_free(ptr2);
   paranoid_free(ptr1);
   void* ptr3 = paranoid_realloc(NULL, 10 * sizeof(int));
   paranoid_free(ptr3);

   return 0;
}


void* paranoid_malloc(size_t size)
{
   int fd = open("/dev/random", O_RDONLY);
   if(fd == -1)
   {
      printf("Error opening random device file.");
      exit(EXIT_FAILURE);
   }

   unsigned int rand_num;
   ssize_t ret = read(fd, &rand_num, sizeof(rand_num));
   if(ret == -1)
   {
      printf("Error reading from random device file.");
      exit(EXIT_FAILURE);
   }
   close(fd);

   if(rand_num % 2 == 0)
   {
      printf("Malloc Failed. Out of Memory\n");
      exit(EXIT_FAILURE);
   }

   void* ptr = malloc(size);
   if(ptr == NULL)
   {
      printf("Malloc Failed. Out of Memory\n");
      exit(EXIT_FAILURE);
   }

   memset(ptr, 0, size);
   printf("Memory Allocated Successfully\n");
   return ptr;
}


void* paranoid_calloc(size_t nmemb, size_t size)
{
   int fd = open("/dev/random", O_RDONLY);
   if(fd == -1)
   {
      printf("Error opening random device file.");
      exit(EXIT_FAILURE);
   }

   unsigned int rand_num;
   ssize_t ret = read(fd, &rand_num, sizeof(rand_num));
   if(ret == -1)
   {
      printf("Error reading from random device file.");
      exit(EXIT_FAILURE);
   }
   close(fd);

   if(rand_num % 2 == 0)
   {
      printf("Calloc Failed. Out of Memory\n");
      exit(EXIT_FAILURE);
   }

   void* ptr = calloc(nmemb, size);
   if(ptr == NULL)
   {
      printf("Calloc Failed. Out of Memory\n");
      exit(EXIT_FAILURE);
   }

   printf("Memory Allocated Successfully\n");
   return ptr;
}


void* paranoid_realloc(void* ptr, size_t size)
{
   int fd = open("/dev/random", O_RDONLY);
   if(fd == -1)
   {
      printf("Error opening random device file.");
      exit(EXIT_FAILURE);
   }

   unsigned int rand_num;
   ssize_t ret = read(fd, &rand_num, sizeof(rand_num));
   if(ret == -1)
   {
      printf("Error reading from random device file.");
      exit(EXIT_FAILURE);
   }
   close(fd);

   if(rand_num % 2 == 0)
   {
      printf("Realloc Failed. Out of Memory\n");
      exit(EXIT_FAILURE);
   }

   void* new_ptr = realloc(ptr, size);
   if(new_ptr == NULL)
   {
      printf("Realloc Failed. Out of Memory\n");
      exit(EXIT_FAILURE);
   }

   printf("Memory Reallocated Successfully\n");
   return new_ptr;
}


void paranoid_free(void* ptr)
{
   if(ptr == NULL)
   {
      printf("Invalid Memory Address: Null pointer\n");
      return;
   }

   free(ptr);
   printf("Memory Deallocated Successfully\n");
}