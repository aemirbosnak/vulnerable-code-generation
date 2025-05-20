//FormAI DATASET v1.0 Category: Date and time ; Style: enthusiastic
// Welcome to the exciting world of C Date and Time!

#include <stdio.h>
#include <time.h>

int main() {

  // Let's start by getting the current time using the time() function
  time_t t = time(NULL);

  // Now let's convert that time into a more readable format
  char time_str[128];
  strftime(time_str, sizeof(time_str), "%c", localtime(&t));

  // And let's print it out to the user
  printf("The current time is: %s\n", time_str);

  // Let's also get some information about the user's timezone
  struct tm *lt = localtime(&t);
  char tz_str[128];
  strftime(tz_str, sizeof(tz_str), "%Z", lt);
  int tz_offset = lt->tm_gmtoff / 3600;

  // And let's print that out as well
  printf("Your timezone is %s (GMT%s%d)\n", tz_str, tz_offset >= 0 ? "+" : "-", abs(tz_offset));

  // Now let's ask for the user's birthday so we can calculate their age
  int birth_year, birth_month, birth_day;
  printf("\nWhat year were you born? ");
  scanf("%d", &birth_year);
  printf("What month were you born (1-12)? ");
  scanf("%d", &birth_month);
  printf("What day of the month were you born? ");
  scanf("%d", &birth_day);

  // Let's calculate their age based on the current date
  struct tm bday = {0};
  bday.tm_year = birth_year - 1900; // tm_year is 1900 less than the actual year
  bday.tm_mon = birth_month - 1; // tm_mon is 0-based
  bday.tm_mday = birth_day;
  time_t bday_time = mktime(&bday);
  double age_in_seconds = difftime(t, bday_time);
  int age_in_years = (int)(age_in_seconds / (60 * 60 * 24 * 365.25));

  // And let's print out their age to the user
  printf("\nYou are %d years old!\n", age_in_years);

  // And there you have it! A fun little program that tells you the time, your timezone, and how old you are!
  return 0;
}