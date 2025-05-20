//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Here be the funny part!
typedef struct {
  char *name;
  char *value;
} Clown;

typedef struct {
  Clown *clowns;
  int num_clowns;
} Circus;

// Let's create a new circus!
Circus *create_circus() {
  Circus *circus = malloc(sizeof(Circus));
  circus->clowns = NULL;
  circus->num_clowns = 0;
  return circus;
}

// Now, let's add a clown to our circus!
void add_clown(Circus *circus, Clown *clown) {
  if (circus->num_clowns == 0) {
    circus->clowns = malloc(sizeof(Clown));
  } else {
    circus->clowns = realloc(circus->clowns, (circus->num_clowns + 1) * sizeof(Clown));
  }
  circus->clowns[circus->num_clowns] = *clown;
  circus->num_clowns++;
}

// Time to say goodbye to our funny friends!
void free_circus(Circus *circus) {
  for (int i = 0; i < circus->num_clowns; i++) {
    free(circus->clowns[i].name);
    free(circus->clowns[i].value);
  }
  free(circus->clowns);
  free(circus);
}

// The grand finale: parsing a JSON string into our circus!
Circus *parse_json(char *json) {
  Circus *circus = create_circus();
  int i = 0;
  while (json[i]) {
    Clown clown;
    clown.name = malloc(sizeof(char) * 100);
    clown.value = malloc(sizeof(char) * 100);
    int name_index = 0;
    int value_index = 0;
    while (json[i] != ':' && json[i] != '\0') {
      clown.name[name_index++] = json[i++];
    }
    i++; // Skip the colon
    while (json[i] != ',' && json[i] != '}' && json[i] != '\0') {
      clown.value[value_index++] = json[i++];
    }
    clown.name[name_index] = '\0';
    clown.value[value_index] = '\0';
    add_clown(circus, &clown);
    i++; // Skip the comma or closing brace
  }
  return circus;
}

// Let's show off our circus!
void print_circus(Circus *circus) {
  for (int i = 0; i < circus->num_clowns; i++) {
    printf("%s: %s\n", circus->clowns[i].name, circus->clowns[i].value);
  }
}

int main() {
  char *json = "{\"name\": \"Bozo\", \"age\": \"25\"}";
  Circus *circus = parse_json(json);
  print_circus(circus);
  free_circus(circus);
  return 0;
}