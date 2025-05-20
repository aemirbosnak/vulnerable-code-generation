//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUTES 10
#define MAX_LOCATIONS 100

typedef struct {
  int id;
  char name[50];
  float latitude;
  float longitude;
} Location;

typedef struct {
  int id;
  char name[50];
  Location *locations[MAX_LOCATIONS];
  int num_locations;
} Route;

void print_location(Location *location) {
  printf("%d. %s (%f, %f)\n", location->id, location->name, location->latitude, location->longitude);
}

void print_route(Route *route) {
  printf("%d. %s\n", route->id, route->name);
  for (int i = 0; i < route->num_locations; i++) {
    print_location(route->locations[i]);
  }
}

void print_routes(Route **routes, int num_routes) {
  for (int i = 0; i < num_routes; i++) {
    print_route(routes[i]);
    printf("--------------------\n");
  }
}

Location *create_location(int id, char *name, float latitude, float longitude) {
  Location *location = malloc(sizeof(Location));
  location->id = id;
  strcpy(location->name, name);
  location->latitude = latitude;
  location->longitude = longitude;
  return location;
}

Route *create_route(int id, char *name) {
  Route *route = malloc(sizeof(Route));
  route->id = id;
  strcpy(route->name, name);
  route->num_locations = 0;
  return route;
}

void add_location_to_route(Route *route, Location *location) {
  route->locations[route->num_locations] = location;
  route->num_locations++;
}

int main() {
  Location *location1 = create_location(1, "Start", 37.773972, -122.431297);
  Location *location2 = create_location(2, "A", 37.771828, -122.420413);
  Location *location3 = create_location(3, "B", 37.777539, -122.411079);
  Location *location4 = create_location(4, "C", 37.780331, -122.415567);

  Route *route1 = create_route(1, "Route 1");
  add_location_to_route(route1, location1);
  add_location_to_route(route1, location2);

  Route *route2 = create_route(2, "Route 2");
  add_location_to_route(route2, location1);
  add_location_to_route(route2, location3);
  
  Route *route3 = create_route(3, "Route 3");
  add_location_to_route(route3, location1);
  add_location_to_route(route3, location4);

  Route *routes[MAX_ROUTES] = {route1, route2, route3};
  int num_routes = 3;

  print_routes(routes, num_routes);

  return 0;
}