//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TEMPS 5

struct TemperatureData {
  int temp;
  int hour;
  int minute;
  int day;
  int month;
  int year;
};

void printTemperatures(struct TemperatureData tempData[]) {
  printf("TEMPERATURES:\n");
  printf("---------------------------------------------------------\n");
  printf("|  ID  |  Temp(C)  |  Hour  |  Minute  |  Date(mm/dd/yy)  |\n");
  printf("---------------------------------------------------------\n");
  for (int i = 0; i < NUM_TEMPS; i++) {
    printf("|  %d   |    %03d    |   %02d   |    %02d    |       %02d/%02d/%02d     |\n", i, tempData[i].temp, tempData[i].hour, tempData[i].minute, tempData[i].month, tempData[i].day, tempData[i].year);
  }
  printf("---------------------------------------------------------\n");
}

void displayMenu() {
  printf("\n\nCOMMANDS:\n");
  printf("------------------------------------------------------------\n");
  printf("|  Command  |                Action                       |\n");
  printf("------------------------------------------------------------\n");
  printf("|     A     | Add a temperature measurement to the database |\n");
  printf("|     V     | View all temperature measurements             |\n");
  printf("|     Q     | Quit program                                  |\n");
  printf("------------------------------------------------------------\n");
  printf("Enter a command (A/V/Q): ");
}

int main() {
  struct TemperatureData tempData[NUM_TEMPS] = {0};

  int currentTempIndex = 0;

  printf("Welcome to the C Temperature Monitor\n\n");

  while (1) {
    displayMenu();

    char command;
    scanf(" %c", &command);

    if (command == 'Q' || command == 'q') {
      printf("Exiting program...\n");
      break;
    } else if (command == 'A' || command == 'a') {
      int temp;
      printf("Enter temperature (in Celsius): ");
      scanf("%d", &temp);
      tempData[currentTempIndex].temp = temp;

      time_t now;
      struct tm *tm;

      now = time(0);
      tm = localtime(&now);

      tempData[currentTempIndex].hour = tm->tm_hour;
      tempData[currentTempIndex].minute = tm->tm_min;
      tempData[currentTempIndex].day = tm->tm_mday;
      tempData[currentTempIndex].month = tm->tm_mon + 1;
      tempData[currentTempIndex].year = tm->tm_year + 1900;

      printf("Temperature added to database!\n");
      currentTempIndex = (currentTempIndex + 1) % NUM_TEMPS;
    } else if (command == 'V' || command == 'v') {
      printTemperatures(tempData);
    } else {
      printf("Invalid command! Try again.\n\n");
    }
  }

  return 0;
}