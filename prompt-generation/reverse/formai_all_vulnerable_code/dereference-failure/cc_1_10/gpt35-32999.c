//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int isLeapYear(int year) {
  if(year % 400 == 0) {
    return 1;
  } else if(year % 4 == 0 && year % 100 != 0) {
    return 1;
  } else {
    return 0;
  }
}

int getDaysInMonth(int month, int year) {
  switch(month) {
    case 2:
      if(isLeapYear(year)) {
        return 29;
      } else {
        return 28;
      }
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      return 31;
  }
}

void convertDate(char *date) {
  char *day, *month, *year, *suffix;
  int d, m, y;

  day = strtok(date, " ");
  month = strtok(NULL, " ");
  year = strtok(NULL, " ");
  suffix = strtok(NULL, " ");

  d = atoi(day);
  y = atoi(year);

  if(suffix != NULL && (*suffix == 'B' || *suffix == 'b')) {
    y = (y - 543);
  }

  for(int i = 1; i <= 12; i++) {
    if(strcmp(months[i], month) == 0) {
      m = i;
      break;
    }
  }

  int daysInMonth = getDaysInMonth(m, y);

  if(d > daysInMonth) {
    printf("Invalid date\n");
  } else {
    printf("%d/%d/%d\n", d, m, y);
  }
}

int main() {
  char date[20];
  printf("Enter a date (dd mmm yyyy [B.E.]): ");
  fgets(date, sizeof(date), stdin);
  convertDate(date);
  return 0;
}