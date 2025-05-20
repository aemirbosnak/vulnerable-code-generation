//Gemma-7B DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_LANES 10

typedef struct TrafficLight {
  int current_state;
  int num_lanes;
  struct TrafficLight **next_light;
} TrafficLight;

TrafficLight *create_traffic_light(int num_lanes) {
  TrafficLight *light = malloc(sizeof(TrafficLight));
  light->current_state = 0;
  light->num_lanes = num_lanes;
  light->next_light = NULL;
  return light;
}

void advance_traffic_light(TrafficLight *light) {
  light->current_state = (light->current_state + 1) % light->num_lanes;
}

void print_traffic_light(TrafficLight *light) {
  switch (light->current_state) {
    case 0:
      printf("Red");
      break;
    case 1:
      printf("Yellow");
      break;
    case 2:
      printf("Green");
      break;
  }
  printf("\n");
}

int main() {
  TrafficLight *north_light = create_traffic_light(3);
  TrafficLight *south_light = create_traffic_light(2);
  TrafficLight *east_light = create_traffic_light(4);
  TrafficLight *west_light = create_traffic_light(5);

  north_light->next_light = south_light;
  south_light->next_light = east_light;
  east_light->next_light = west_light;
  west_light->next_light = north_light;

  for (int i = 0; i < 10; i++) {
    advance_traffic_light(north_light);
    print_traffic_light(north_light);
  }

  return 0;
}