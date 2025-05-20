//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main() {
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer,80,"Current date and time: %x %I:%M:%S %p", info);
   printf("Formatted date & time : %s\n", buffer );
   
   int hours = info->tm_hour;
   int minutes = info->tm_min;
   int seconds = info->tm_sec;
   int year = 1900 + info->tm_year;
   int month = 1 + info->tm_mon;
   int day = info->tm_mday;

   printf("\n");

   printf("Today's date is: %d/%d/%d\n", month, day, year);
   printf("The current time is: %d:%d:%d\n", hours, minutes, seconds);

   // Find out the day of the week
   switch(info->tm_wday) {
      case 0 :
         printf("Today is Sunday");
         break;
      case 1 :
         printf("Today is Monday");
         break;
      case 2 :
         printf("Today is Tuesday");
         break;
      case 3 :
         printf("Today is Wednesday");
         break;
      case 4 :
         printf("Today is Thursday");
         break;
      case 5 :
         printf("Today is Friday");
         break;
      case 6 :
         printf("Today is Saturday");
         break;
   }

   printf("\n");

   return 0;
}