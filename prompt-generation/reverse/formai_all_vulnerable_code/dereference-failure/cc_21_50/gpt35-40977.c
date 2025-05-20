//FormAI DATASET v1.0 Category: Date and time ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   struct tm* local;
   time_t t = time(NULL);
   local = localtime(&t);
   char day[10], month[10], dayOfWeek[10];

   switch(local->tm_wday){
      case 0:
         strcpy(dayOfWeek, "Sunday");
         break;

      case 1:
         strcpy(dayOfWeek, "Monday");
         break;

      case 2:
         strcpy(dayOfWeek, "Tuesday");
         break;

      case 3:
         strcpy(dayOfWeek, "Wednesday");
         break;

      case 4:
         strcpy(dayOfWeek, "Thursday");
         break;

      case 5:
         strcpy(dayOfWeek, "Friday");
         break;

      case 6:
         strcpy(dayOfWeek, "Saturday");
         break;

      default:
         printf("Invalid day");
         exit(0);
   }

   switch(local->tm_mon){
      case 0:
         strcpy(month, "January");
         break;

      case 1:
         strcpy(month, "February");
         break;

      case 3:
         strcpy(month, "March");
         break;

      case 4:
         strcpy(month, "April");
         break;

      case 5:
         strcpy(month, "May");
         break;

      case 6:
         strcpy(month, "June");
         break;

      case 7:
         strcpy(month, "July");
         break;

      case 8:
         strcpy(month, "August");
         break;

      case 9:
         strcpy(month, "September");
         break;

      case 10:
         strcpy(month, "October");
         break;

      case 11:
         strcpy(month, "November");
         break;

      case 12:
         strcpy(month, "December");
         break;

      default:
         printf("Invalid month");
         exit(0);
   }

   switch(local->tm_mday) {
      case 1:
      case 21:
      case 31:
         strcpy(day, "st");
         break;

      case 2:
      case 22:
         strcpy(day, "nd");
         break;

      case 3:
      case 23:
         strcpy(day, "rd");
         break;

      default:
         strcpy(day, "th");
         break;
   }

   printf("Today is %s, %s %d%s, %d\n", dayOfWeek, month, local->tm_mday, day, 1900 + local->tm_year);

   int hour = local->tm_hour;
   char ampm[] = "AM";
   if(hour > 12) {
      hour -= 12;
      strcpy(ampm, "PM");
   }

   printf("Current time is %d:%02d%s %s\n", hour, local->tm_min, ampm, local->tm_zone);

   return 0;
}