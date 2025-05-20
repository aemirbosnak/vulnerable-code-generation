//FormAI DATASET v1.0 Category: System boot optimizer ; Style: curious
#include <stdio.h>

int main() {
   printf("Hello, welcome to the C System Boot Optimizer!\n");
   printf("This program will optimize your system boot times by rearranging boot programs.\n");

   // Get number of boot programs
   int numOfPrograms;
   printf("How many boot programs do you have? ");
   scanf("%d", &numOfPrograms);

   // Get boot programs
   char programs[numOfPrograms][20];
   for (int i = 0; i < numOfPrograms; i++) {
      printf("Enter the name of boot program #%d: ", (i+1));
      scanf("%s", programs[i]);
   }

   // Show current boot program order
   printf("Current boot program order: ");
   for(int i = 0; i < numOfPrograms; i++) {
      printf("%s ", programs[i]);
   }

   // Ask user if they want to optimize boot programs
   char response;
   printf("\n\nDo you want to optimize your boot programs? (y/n): ");
   scanf(" %c", &response);

   if(response == 'y') {
      // rearrange boot program order
      char temp[20];
      for(int i = 0; i < numOfPrograms - 1; i++) {
         for(int j = i+1; j < numOfPrograms; j++) {
            printf("\nComparing %s with %s\n", programs[i], programs[j]);

            if(programs[i][0] > programs[j][0]) {
               // swap program order
               printf("Swapping %s with %s\n", programs[i], programs[j]);
               strcpy(temp, programs[i]);
               strcpy(programs[i], programs[j]);
               strcpy(programs[j], temp);
            }
         }
      }

      // Show new boot program order
      printf("\nNew boot program order: ");
      for(int i = 0; i < numOfPrograms; i++) {
         printf("%s ", programs[i]);
      }

      printf("\n\nBoot programs optimized! Enjoy your faster boot times!\n");
   } else {
      printf("\nNo problem, your current boot program order will remain unchanged.\n");
   }

   return 0;
}