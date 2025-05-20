//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

typedef struct IntrusionDetectionSystem {
  char* str;
  int length;
  struct IntrusionDetectionSystem* next;
} IntrusionDetectionSystem;

IntrusionDetectionSystem* createIntrusionDetectionSystem(char* str, int length) {
  IntrusionDetectionSystem* system = malloc(sizeof(IntrusionDetectionSystem));
  system->str = malloc(sizeof(char) * MAX_STRING_LENGTH);
  system->length = length;
  system->next = NULL;

  strcpy(system->str, str);

  return system;
}

void addIntrusionDetectionSystem(IntrusionDetectionSystem* system, char* str, int length) {
  IntrusionDetectionSystem* newSystem = createIntrusionDetectionSystem(str, length);

  if (system) {
    newSystem->next = system;
  }

  system = newSystem;
}

void scanForIntrusion(IntrusionDetectionSystem* system) {
  for (IntrusionDetectionSystem* currentSystem = system; currentSystem; currentSystem = currentSystem->next) {
    for (int i = 0; i < currentSystem->length; i++) {
      if (currentSystem->str[i] >= 'a' && currentSystem->str[i] <= 'z') {
        printf("Potential intrusion detected at character %c in string %s\n", currentSystem->str[i], currentSystem->str);
      }
    }
  }
}

int main() {
  IntrusionDetectionSystem* system = NULL;

  addIntrusionDetectionSystem(system, "Hello, world!", 13);
  addIntrusionDetectionSystem(system, "This is a secret message.", 21);
  addIntrusionDetectionSystem(system, "Attack me!", 6);

  scanForIntrusion(system);

  return 0;
}