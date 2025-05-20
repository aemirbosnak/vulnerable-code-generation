//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm * time_info;
   char year[5], month[3], day[3], hour[3], minute[3], second[3];
   
   //Get current date and time
   time(&current_time);
   time_info = localtime(&current_time);
   
   //Display current date and time to the user
   printf("Current date and time: %s\n", asctime(time_info));
   
   //Ask user for a date and time to travel to
   printf("Enter a year (YYYY): ");
   scanf("%s", year);
   printf("Enter a month (MM): ");
   scanf("%s", month);
   printf("Enter a day (DD): ");
   scanf("%s", day);
   printf("Enter an hour (HH): ");
   scanf("%s", hour);
   printf("Enter a minute (MM): ");
   scanf("%s", minute);
   printf("Enter a second (SS): ");
   scanf("%s", second);
   
   //Set the date and time according to user input
   time_info->tm_year = atoi(year) - 1900;
   time_info->tm_mon = atoi(month) - 1;
   time_info->tm_mday = atoi(day);
   time_info->tm_hour = atoi(hour);
   time_info->tm_min = atoi(minute);
   time_info->tm_sec = atoi(second);
   
   //Convert entered date and time to time_t format
   current_time = mktime(time_info);
   
   //Check if selected date and time is in the past or future
   if(difftime(current_time, time(NULL)) < 0) {
      printf("You have traveled back in time!\n");
   }
   else if(difftime(current_time, time(NULL)) > 0) {
      printf("You have traveled to the future!\n");
   }
   else {
      printf("You are still in the present!\n");
   }
   
   //Display selected date and time to the user
   printf("Selected date and time: %s", asctime(localtime(&current_time)));
   
   return 0;
}