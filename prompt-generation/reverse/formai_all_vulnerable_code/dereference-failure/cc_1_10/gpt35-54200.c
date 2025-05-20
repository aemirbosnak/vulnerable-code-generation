//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include<stdio.h>
#include<time.h>

int main(){
  time_t current_time;
  int year, month, day, hour, minute, second;
  
  // Start the time travel simulation
  printf("Welcome to the Time Travel Simulator!\n");
  printf("Please enter a year (YYYY): ");
  scanf("%d", &year);
  printf("Please enter a month (MM): ");
  scanf("%d", &month);
  printf("Please enter a day (DD): ");
  scanf("%d", &day);
  printf("Please enter an hour (HH): ");
  scanf("%d", &hour);
  printf("Please enter a minute (MM): ");
  scanf("%d", &minute);
  printf("Please enter a second (SS): ");
  scanf("%d", &second);
  
  // Set the current time to the user-inputted time
  struct tm simulated_time = { 0 };
  simulated_time.tm_year = year - 1900;
  simulated_time.tm_mon = month - 1;
  simulated_time.tm_mday = day;
  simulated_time.tm_hour = hour;
  simulated_time.tm_min = minute;
  simulated_time.tm_sec = second;
  
  // Set the current time
  current_time = mktime(&simulated_time);
  
  // Let the time traveler know their destination time
  printf("\nYour destination time is: %s", asctime(&simulated_time));
  printf("Press any key to start the simulation.\n");
  getchar();
  
  // Start the simulation
  int time_travel_speed;
  printf("\nPlease select a time travel speed (1-10): ");
  scanf("%d", &time_travel_speed);
  
  printf("\nCommencing time travel...\n");
  while (current_time < time(NULL)) {
    time_t diff = time(NULL) - current_time;
    struct tm *diff_time = gmtime(&diff);
    printf("You have traveled %02d:%02d:%02d into the future!\n", diff_time->tm_hour - 1, diff_time->tm_min, diff_time->tm_sec);
    sleep(time_travel_speed);
  }
  
  printf("\nYou have arrived at your destination time!\n");
  printf("Press any key to return to the present.\n");
  getchar();
  
  // Return to the present
  printf("\nReturning to the present...\n");
  while (current_time > time(NULL)) {
    time_t diff = current_time - time(NULL);
    struct tm *diff_time = gmtime(&diff);
    printf("You have traveled %02d:%02d:%02d into the past!\n", diff_time->tm_hour - 1, diff_time->tm_min, diff_time->tm_sec);
    sleep(time_travel_speed);
  }
  
  printf("\nYou have returned to the present time!\n");
  
  return 0;
}