//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Shocking C Compression Algorithm Example

int main()
{
   printf("Oh boy, hold on tight, because you're in for a wild ride with this shocking C compression algorithm example!\n\n");

   // prepare input data
   char original_str[] = "This is the original string that we want to compress";
   
   // let's see the original data first
   printf("Original String: %s\n", original_str);
   printf("Original String Length: %lu\n", strlen(original_str));
   
   // allocate memory for compressed string
   char *compressed_str = (char*) malloc(sizeof(char) * strlen(original_str));
   
   // start compressing the string
   int i, j, count, len = strlen(original_str);
   j = 0;
   for(i = 0; i < len; i++)
   {
      count = 1;
      while(i < len - 1 && original_str[i] == original_str[i + 1])
      {
         count++;
         i++;
      }

      if(count == 1)
      {
         compressed_str[j] = original_str[i];
         j++;
      }
      else
      {
         compressed_str[j] = original_str[i];
         compressed_str[j + 1] = count + '0'; // converting integer to char and appending to compressed string
         j += 2;
      }
   }

   // add null termination at the end of compressed string
   compressed_str[j] = '\0';

   // show the compressed string
   printf("\nCompressed String: %s\n", compressed_str);
   printf("Compressed String Length: %lu\n", strlen(compressed_str));

   // free the allocated memory
   free(compressed_str);

   printf("\nThat's it, folks! This shocking C compression algorithm just compressed your string like never before.\n");

   return 0;
}