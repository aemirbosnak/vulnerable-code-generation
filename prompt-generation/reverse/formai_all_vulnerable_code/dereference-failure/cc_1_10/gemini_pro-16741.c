//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

struct town {
  char *name;
  struct town *next;
  struct road *roads;
};

struct road {
  struct town *town1;
  struct town *town2;
  int distance;
  struct road *next;
};

struct network {
  struct town *towns;
  struct road *roads;
};

struct network *network_new() {
  struct network *network = malloc(sizeof(struct network));
  network->towns = NULL;
  network->roads = NULL;
  return network;
}

void network_free(struct network *network) {
  struct town *town = network->towns;
  while (town != NULL) {
    struct town *next = town->next;
    free(town->name);
    free(town);
    town = next;
  }
  struct road *road = network->roads;
  while (road != NULL) {
    struct road *next = road->next;
    free(road);
    road = next;
  }
  free(network);
}

struct town *town_new(char *name) {
  struct town *town = malloc(sizeof(struct town));
  town->name = strdup(name);
  town->next = NULL;
  town->roads = NULL;
  return town;
}

void town_free(struct town *town) {
  free(town->name);
  free(town);
}

struct road *road_new(struct town *town1, struct town *town2, int distance) {
  struct road *road = malloc(sizeof(struct road));
  road->town1 = town1;
  road->town2 = town2;
  road->distance = distance;
  road->next = NULL;
  return road;
}

void road_free(struct road *road) {
  free(road);
}

void network_add_town(struct network *network, struct town *town) {
  if (network->towns == NULL) {
    network->towns = town;
  } else {
    struct town *last_town = network->towns;
    while (last_town->next != NULL) {
      last_town = last_town->next;
    }
    last_town->next = town;
  }
}

void network_add_road(struct network *network, struct road *road) {
  if (network->roads == NULL) {
    network->roads = road;
  } else {
    struct road *last_road = network->roads;
    while (last_road->next != NULL) {
      last_road = last_road->next;
    }
    last_road->next = road;
  }
}

void network_print(struct network *network) {
  struct town *town = network->towns;
  while (town != NULL) {
    printf("%s\n", town->name);
    struct road *road = town->roads;
    while (road != NULL) {
      printf("  %s (%d miles)\n", road->town2->name, road->distance);
      road = road->next;
    }
    town = town->next;
  }
}

int main() {
  struct network *network = network_new();

  struct town *town1 = town_new("London");
  struct town *town2 = town_new("Paris");
  struct town *town3 = town_new("Rome");
  struct town *town4 = town_new("Madrid");
  struct town *town5 = town_new("Lisbon");

  network_add_town(network, town1);
  network_add_town(network, town2);
  network_add_town(network, town3);
  network_add_town(network, town4);
  network_add_town(network, town5);

  struct road *road1 = road_new(town1, town2, 200);
  struct road *road2 = road_new(town1, town3, 300);
  struct road *road3 = road_new(town1, town4, 400);
  struct road *road4 = road_new(town1, town5, 500);
  struct road *road5 = road_new(town2, town3, 200);
  struct road *road6 = road_new(town2, town4, 300);
  struct road *road7 = road_new(town2, town5, 400);
  struct road *road8 = road_new(town3, town4, 200);
  struct road *road9 = road_new(town3, town5, 300);
  struct road *road10 = road_new(town4, town5, 200);

  network_add_road(network, road1);
  network_add_road(network, road2);
  network_add_road(network, road3);
  network_add_road(network, road4);
  network_add_road(network, road5);
  network_add_road(network, road6);
  network_add_road(network, road7);
  network_add_road(network, road8);
  network_add_road(network, road9);
  network_add_road(network, road10);

  network_print(network);

  network_free(network);

  return 0;
}