//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main(void) {
   time_t t;
   struct tm *timeinfo;
   char year_entered[100];
   int year, current_year, j;

   /* Get the current year */
   t = time(NULL);
   timeinfo = localtime(&t);
   current_year = timeinfo->tm_year + 1900;

   /* Get the desired year from user */
   printf("Enter a year (two or four digits): ");
   fgets(year_entered, sizeof(year_entered), stdin);
   sscanf(year_entered, "%d", &year);

   /* Check if entered year is within range */
   if (year < 0 || year > 9999) {
      printf("Invalid year entered.\n");
      return 0;
   }
   if (year < 100) {
      year += 1900;
   }

   /* Print year info */
   printf("\nEntered Year: %d\nCurrent Year: %d\n\n", year, current_year);

   /* Travel through time! */
   printf("Traveling through time...");
   for (j = current_year; j < year; j++) {
      printf("%d\n", j);
   }
   for (j = current_year; j > year; j--) {
      printf("%d\n", j);
   }

   if (year == current_year) {
      printf("You are already in the current year!\n");
   } else if (year > current_year) {
      printf("You have traveled to the future and ended up in the year %d.\n", year);
   } else {
      printf("You have traveled to the past and ended up in the year %d.\n", year);
   }

   return 0;
}