//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUMBER 1000

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
    return new_unit;
  }

  head->next = new_unit;
  return head;
}

double convert_units(Unit* head, char* target_unit, double value) {
  Unit* current_unit = head;
  double conversion_factor = 1.0;

  while (current_unit) {
    if (strcmp(current_unit->name, target_unit) == 0) {
      conversion_factor = current_unit->value;
    } else if (strcmp(current_unit->name, "base") == 0) {
      conversion_factor = 1.0;
    } else {
      conversion_factor *= current_unit->value;
    }

    current_unit = current_unit->next;
  }

  return value * conversion_factor;
}

int main() {
  Unit* units = NULL;
  units = unit_add(units, "meter", 1.0);
  units = unit_add(units, "decimeter", 10.0);
  units = unit_add(units, "kilometer", 1000.0);
  units = unit_add(units, "base", 1.0);

  double converted_value = convert_units(units, "decimeter", 15.0);

  printf("%f decimeters are equal to %f meters\n", 15.0, converted_value);

  return 0;
}