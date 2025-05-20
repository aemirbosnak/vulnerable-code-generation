//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <time.h>

int main() {
  
  time_t currentTime;
  struct tm *timeinfo;
  
  /* Initializing the input variables */
  int year, hours, minutes, seconds, month, day;
  int isDST;
  
  /* Retrieving the current time */
  time(&currentTime);
  
  /* Converting the time to local time */
  timeinfo = localtime(&currentTime);
 
  /* Retrieving the current year */
  year = timeinfo->tm_year + 1900;
  
  printf("Welcome to the Time Travel Simulator\n");
  printf("------------------------------------\n");
  
  /* Providing the user with options to select the date and time to travel to */
  printf("Enter the year to travel to: ");
  scanf("%d",&year);
  
  printf("Enter the month to travel to: ");
  scanf("%d",&month);
  
  printf("Enter the day to travel to: ");
  scanf("%d",&day);
  
  printf("Enter the hours to travel to: ");
  scanf("%d",&hours);
  
  printf("Enter the minutes to travel to: ");
  scanf("%d",&minutes);
  
  printf("Enter the seconds to travel to: ");
  scanf("%d",&seconds);
  
  /* Initializing the variable to store the time difference */
  double timeDiff;
  
  /* Converting the selected time to Unix time */
  time_t inputTime = mktime(&timeinfo);
  
  /* Calculating the time difference */
  timeDiff = difftime(inputTime, currentTime);
  
  /* Setting the system clock to the selected time */
  sleep(timeDiff);
  
  printf("\n\nCongratulations! You have successfully time traveled to %d/%d/%d %d:%d:%d\n",day,month,year,hours,minutes,seconds);
  
  printf("\n\nHope you enjoyed the time travel experience!\n");
  
  return 0;
}