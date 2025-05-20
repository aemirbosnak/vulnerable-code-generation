//Gemma-7B DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_LANES 3
#define MAX_TIME 10

typedef struct TrafficLight {
  int current_state;
  int next_state;
  int timer;
  struct TrafficLight* adjacent_lights;
} TrafficLight;

TrafficLight* create_traffic_light(int lane) {
  TrafficLight* light = malloc(sizeof(TrafficLight));
  light->current_state = lane;
  light->next_state = (lane + 1) % NUM_LANES;
  light->timer = 0;
  light->adjacent_lights = NULL;
  return light;
}

void add_adjacent_light(TrafficLight* light, TrafficLight* adjacent_light) {
  light->adjacent_lights = adjacent_light;
}

void control_traffic_lights() {
  TrafficLight* red_light = create_traffic_light(0);
  TrafficLight* yellow_light = create_traffic_light(1);
  TrafficLight* green_light = create_traffic_light(2);

  add_adjacent_light(red_light, yellow_light);
  add_adjacent_light(yellow_light, green_light);
  add_adjacent_light(green_light, red_light);

  for (int time = 0; time < MAX_TIME; time++) {
    switch (red_light->current_state) {
      case 0:
        red_light->current_state = 1;
        yellow_light->current_state = 2;
        break;
      case 1:
        red_light->current_state = 2;
        green_light->current_state = 0;
        break;
      case 2:
        red_light->current_state = 0;
        green_light->current_state = 1;
        break;
    }

    red_light->timer++;
    if (red_light->timer == MAX_TIME) {
      red_light->timer = 0;
    }

    sleep(1);
  }
}

int main() {
  control_traffic_lights();
  return 0;
}