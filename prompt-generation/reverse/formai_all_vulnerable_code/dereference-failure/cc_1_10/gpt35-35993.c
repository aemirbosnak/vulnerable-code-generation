//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t currentTime = time(NULL);
   struct tm startTime = *localtime(&currentTime);
   
   printf("Welcome to the Time Travel Simulator!\n\n");
   
   printf("It's currently %d:%02d %s on %d/%d/%d\n", 
          (startTime.tm_hour % 12 == 0) ? 12 : startTime.tm_hour % 12,
          startTime.tm_min, 
          (startTime.tm_hour >= 12) ? "PM" : "AM", 
          startTime.tm_mday, 
          startTime.tm_mon + 1, 
          startTime.tm_year + 1900);
   
   printf("Where/When would you like to go? Please enter a year: ");
   int year;
   scanf("%d", &year);
   
   printf("\nOk, traveling to year %d...\n", year);
   struct tm travelTime = {0};
   travelTime.tm_year = year - 1900;
   travelTime.tm_mday = 1;
   mktime(&travelTime);
   
   printf("\nYou have arrived on %d/%d/%d\n", 
          travelTime.tm_mday, 
          travelTime.tm_mon + 1, 
          travelTime.tm_year + 1900);
   
   printf("\nWhat would you like to do now? Please enter a number from the options below:\n");
   printf("1. Explore the city\n");
   printf("2. Meet historical figures\n");
   printf("3. Witness important events\n");
   printf("4. Return to present time\n");
   
   int choice;
   scanf("%d", &choice);
   
   switch(choice) {
      case 1:
         printf("\nGreat, let's explore the city!\n");
         break;
         
      case 2:
         printf("\nWhich historical figure would you like to meet? Please enter a name: ");
         char name[50];
         scanf("%s", name);
         printf("\nOk, let's find %s...\n", name);
         //code for finding and meeting historical figure
         break;
         
      case 3:
         printf("\nWhich event would you like to witness? Please enter a description: ");
         char event[100];
         scanf("%s", event);
         printf("\nOk, let's go to %s...\n", event);
         //code for witnessing event
         break;
         
      case 4:
         printf("\nReturning to present time...\n");
         break;
         
      default:
         printf("\nInvalid choice.\n");
         break;
   }
   
   printf("\nThank you for using the Time Travel Simulator! Goodbye.\n");
   return 0;
}