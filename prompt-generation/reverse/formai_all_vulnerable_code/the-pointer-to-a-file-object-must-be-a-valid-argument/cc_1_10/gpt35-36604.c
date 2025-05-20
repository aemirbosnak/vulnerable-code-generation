//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char street[50];
  char city[50];
  char state[50];
} Location;

typedef struct {
  Location start_location;
  Location end_location;
  float distance;
} Route;

void print_location(Location location) {
  printf("%s, %s, %s", location.street, location.city, location.state);
}

void print_route(Route route) {
  printf("Start Location: ");
  print_location(route.start_location);
  printf("\nEnd Location: ");
  print_location(route.end_location);
  printf("\nDistance: %.2f miles\n", route.distance);
}

Route get_route() {
  Route route;
  printf("Enter Start Location:\n");
  printf("Street: ");
  fgets(route.start_location.street, 50, stdin);
  printf("City: ");
  fgets(route.start_location.city, 50, stdin);
  printf("State: ");
  fgets(route.start_location.state, 50, stdin);
  printf("\nEnter End Location:\n");
  printf("Street: ");
  fgets(route.end_location.street, 50, stdin);
  printf("City: ");
  fgets(route.end_location.city, 50, stdin);
  printf("State: ");
  fgets(route.end_location.state, 50, stdin);
  printf("Enter Distance: ");
  scanf("%f", &route.distance);
  return route;
}

void save_route(Route route) {
  FILE* file = fopen("routes.txt", "a");
  fprintf(file, "%s,%s,%s,%s,%s,%s,%f\n", 
    route.start_location.street, route.start_location.city, route.start_location.state,
    route.end_location.street, route.end_location.city, route.end_location.state,
    route.distance);
  fclose(file);
}

Route* retrieve_routes(int* count) {
  FILE* file = fopen("routes.txt", "r");
  Route* routes = malloc(sizeof(Route));
  char buffer[200];
  while (fgets(buffer, 200, file)) {
    Route route;
    char* street1 = strtok(buffer, ",");
    char* city1 = strtok(NULL, ",");
    char* state1 = strtok(NULL, ",");
    char* street2 = strtok(NULL, ",");
    char* city2 = strtok(NULL, ",");
    char* state2 = strtok(NULL, ",");
    char* distance_str = strtok(NULL, ",");
    strcpy(route.start_location.street, street1);
    strcpy(route.start_location.city, city1);
    strcpy(route.start_location.state, state1);
    strcpy(route.end_location.street, street2);
    strcpy(route.end_location.city, city2);
    strcpy(route.end_location.state, state2);
    route.distance = atof(distance_str);
    routes = realloc(routes, sizeof(Route) * (*count + 1));
    routes[*count] = route;
    (*count)++;
  }
  fclose(file);
  return routes;
}

void print_menu() {
  printf("\nGPS Navigation Simulation\n");
  printf("1) Add Route\n");
  printf("2) List All Routes\n");
  printf("3) Find Route\n");
  printf("4) Exit\n");
  printf("Enter Selection: ");
}

int main() {
  int choice = 0;
  while (choice != 4) {
    print_menu();
    scanf("%d", &choice);
    getchar(); // Gets rid of newline character
    switch (choice) {
      case 1: {
        Route route = get_route();
        save_route(route);
        printf("Route Saved!\n");
        break;
      }
      case 2: {
        int count = 0;
        Route* routes = retrieve_routes(&count);
        for (int i = 0; i < count; i++) {
          printf("%d) ", i + 1);
          print_route(routes[i]);
        }
        free(routes);
        break;
      }
      case 3: {
        int count = 0;
        Route* routes = retrieve_routes(&count);
        printf("Enter Start Location:\n");
        printf("Street: ");
        char street[50];
        fgets(street, 50, stdin);
        printf("City: ");
        char city[50];
        fgets(city, 50, stdin);
        printf("State: ");
        char state[50];
        fgets(state, 50, stdin);
        Location start_location = {street, city, state};
        printf("\nEnter End Location:\n");
        printf("Street: ");
        fgets(street, 50, stdin);
        printf("City: ");
        fgets(city, 50, stdin);
        printf("State: ");
        fgets(state, 50, stdin);
        Location end_location = {street, city, state};
        int found = 0;
        for (int i = 0; i < count; i++) {
          if (strcmp(routes[i].start_location.street, start_location.street) == 0 &&
              strcmp(routes[i].start_location.city, start_location.city) == 0 &&
              strcmp(routes[i].start_location.state, start_location.state) == 0 &&
              strcmp(routes[i].end_location.street, end_location.street) == 0 &&
              strcmp(routes[i].end_location.city, end_location.city) == 0 &&
              strcmp(routes[i].end_location.state, end_location.state) == 0) {
            printf("\nRoute Found!\n");
            print_route(routes[i]);
            found = 1;
            break;
          }
        }
        if (!found) {
          printf("\nRoute Not Found.\n");
        }
        free(routes);
        break;
      }
      case 4: {
        printf("Exiting Program...\n");
        break;
      }
      default: {
        printf("Invalid Selection. Try Again.\n");
        break;
      }
    }
  }
  return 0;
}