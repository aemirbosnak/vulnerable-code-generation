//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

typedef struct Unit {
  char name[20];
  double value;
  struct Unit* next;
} Unit;

Unit* unit_add(Unit* head, char* name, double value) {
  Unit* new_unit = malloc(sizeof(Unit));
  strcpy(new_unit->name, name);
  new_unit->value = value;
  new_unit->next = NULL;

  if (head == NULL) {
    head = new_unit;
  } else {
    head->next = new_unit;
  }

  return head;
}

double unit_convert(Unit* head, char* target_unit, double value) {
  Unit* current_unit = head;
  double conversion_factor = 1.0;

  while (current_unit) {
    if (strcmp(current_unit->name, target_unit) == 0) {
      conversion_factor = current_unit->value;
      break;
    }

    current_unit = current_unit->next;
  }

  return value * conversion_factor;
}

int main() {
  Unit* units = NULL;
  units = unit_add(units, "meter", 1.0);
  units = unit_add(units, "centimeter", 100.0);
  units = unit_add(units, "decimeter", 10.0);
  units = unit_add(units, "mile", 1609.0);

  double distance = unit_convert(units, "meter", 10.0);
  printf("%f meters are equal to %f miles.\n", distance, distance * 0.000621371);

  return 0;
}