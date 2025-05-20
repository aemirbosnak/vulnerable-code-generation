//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm *time_info;

   time(&current_time);
   time_info = localtime(&current_time);

   int year = time_info->tm_year;
   int month = time_info->tm_mon;
   int day = time_info->tm_mday;
   int hour = time_info->tm_hour;
   int min = time_info->tm_min;

   printf("Welcome to the Time Travel Simulator!\n");

   int choice;

   do {
      printf("\nChoose a year to travel to:\n");
      printf("1. 1969\n");
      printf("2. 1985\n");
      printf("3. 2015\n");
      printf("4. Exit\n");

      scanf("%d", &choice);

      switch (choice) {
         case 1:
            year = 69;
            break;
         case 2:
            year = 85;
            break;
         case 3:
            year = 115;
            break;
         case 4:
            printf("Goodbye!\n");
            exit(0);
         default:
            printf("Invalid choice, please try again.\n");
      }
   } while (choice < 1 || choice > 4);

   printf("\nYou travel back in time to the year %d!\n", (year + 1900));

   printf("\nChoose a month to travel to:\n");

   if (year == 69) {
      printf("1. June\n");
      printf("2. July\n");
      printf("3. August\n");
   } else if (year == 85) {
      printf("1. October\n");
      printf("2. November\n");
      printf("3. December\n");
   } else if (year == 115) {
      printf("1. May\n");
      printf("2. June\n");
      printf("3. July\n");
   }

   scanf("%d", &choice);

   while (choice < 1 || choice > 3) {
      printf("Invalid choice, please try again.\n");

      scanf("%d", &choice);
   }

   month = (year == 69) ? choice + 5 : (year == 85) ? choice + 9 : choice + 4;

   printf("\nYou travel back in time to %d/%d/%d!\n", month, day, (year + 1900));

   printf("\nChoose an hour to travel to:\n");

   if (month == 6 || month == 7 || month == 8) {
      printf("1. 10am\n");
      printf("2. 2pm\n");
      printf("3. 6pm\n");
   } else if (month == 10 || month == 11 || month == 12) {
      printf("1. 8am\n");
      printf("2. 1pm\n");
      printf("3. 6pm\n");
   } else if (month == 5 || month == 6 || month == 7) {
      printf("1. 9am\n");
      printf("2. 12pm\n");
      printf("3. 3pm\n");
   }

   scanf("%d", &choice);

   while (choice < 1 || choice > 3) {
      printf("Invalid choice, please try again.\n");

      scanf("%d", &choice);
   }

   hour = (choice == 1) ? 10 : (choice == 2) ? 14 : 18;

   printf("\nYou travel back in time to %d/%d/%d at %d:%d!\n", month, day, (year + 1900), hour, min);

   return 0;
}