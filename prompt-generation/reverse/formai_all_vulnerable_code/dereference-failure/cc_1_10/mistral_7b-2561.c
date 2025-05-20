//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The date converter: a mystical artifact, unraveled only by the chosen ones
void dC_mystic_date_converter(char* input) {
  char* day, * month, * year;
  int index_day, index_month, index_year;

  // The date, presented in an enchanted form: "dd-mm-yyyy"
  for (int i = 0; i < strlen(input) && input[i] != ' '; i++) {
    if (isdigit(input[i])) {
      if (i < index_day) index_day = i;
      input[i] = '\0';
      day = &input[i];
    } else if (strchr("janfebmaraprilmayjunjulaugsepoctnovdec", input[i]) != NULL) {
      if (i < index_month) index_month = i;
      input[i] = '\0';
      month = &input[i];
      i++;
      index_month += strlen(month) + 1;
    } else {
      year = &input[i];
      i += strlen(year);
    }
  }

  // The conversion, guided by the celestial bodies:
  int day_number = atoi(day);
  switch (*month) {
    case 'f':
      day_number += 28;
      break;
    case 'r':
      day_number += 30;
      break;
    case 'a':
      day_number += 31;
      break;
    default:
      day_number += ((int) (*month - 'j') + 3) % 7;
      break;
  }
  int century;
  sscanf(year, "%d%d", &century, &year);
  year += 1900;

  // The enlightenment: the date, now in a human-readable form
  printf("The mystic date converter reveals: %d/%s/%d\n", month[index_month - 1], day, year);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <date in dd-mm-yyyy format>\n", argv[0]);
    return 1;
  }

  char* date = malloc(strlen(argv[1]) + 1);
  strcpy(date, argv[1]);

  dC_mystic_date_converter(date);
  free(date);

  return 0;
}