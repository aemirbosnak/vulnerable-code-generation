//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void writeToFile(char*);
void logEvent(char*);

int main() {
  char* eventBuffer = (char*)malloc(255 * sizeof(char));
  sprintf(eventBuffer, "System log initiated at %s\n\n", __TIME__);
  writeToFile(eventBuffer);
  
  srand(time(0));
  int randNum;

  for(int i = 0; i < 10; i++) {
    randNum = rand() % 4 + 1;
    switch(randNum) {
      case 1: 
        logEvent("Unauthorized access detected\n"); 
        break;
      case 2: 
        logEvent("System malfunction reported\n"); 
        break;
      case 3: 
        logEvent("Data breach attempted\n"); 
        break;
      case 4: 
        logEvent("Security protocol triggered\n"); 
        break;
    }
  }

  sprintf(eventBuffer, "\nSystem log terminated at %s\n", __TIME__);
  writeToFile(eventBuffer);
  free(eventBuffer);
  return 0;
}

void writeToFile(char* eventBuffer) {
  FILE* fPtr;
  fPtr = fopen("system_log.txt", "a");

  if(fPtr == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  fputs(eventBuffer, fPtr);
  fclose(fPtr);
}

void logEvent(char* event) {
  char* eventBuffer = (char*)malloc(255 * sizeof(char));
  sprintf(eventBuffer, "[%s] %s\n", __TIME__, event);
  writeToFile(eventBuffer);
  free(eventBuffer);
}