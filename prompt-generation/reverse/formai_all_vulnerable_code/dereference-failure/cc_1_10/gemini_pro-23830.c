//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the GPS data structure
typedef struct {
  double latitude;
  double longitude;
  double altitude;
  double speed;
  double heading;
} GPSData;

// Define the car data structure
typedef struct {
  double x;
  double y;
  double angle;
  double speed;
} CarData;

// Define the map data structure
typedef struct {
  int width;
  int height;
  int **data;
} MapData;

// Create a new GPS data object
GPSData *new_gps_data() {
  GPSData *gps_data = malloc(sizeof(GPSData));
  gps_data->latitude = 0.0;
  gps_data->longitude = 0.0;
  gps_data->altitude = 0.0;
  gps_data->speed = 0.0;
  gps_data->heading = 0.0;
  return gps_data;
}

// Create a new car data object
CarData *new_car_data() {
  CarData *car_data = malloc(sizeof(CarData));
  car_data->x = 0.0;
  car_data->y = 0.0;
  car_data->angle = 0.0;
  car_data->speed = 0.0;
  return car_data;
}

// Create a new map data object
MapData *new_map_data(int width, int height) {
  MapData *map_data = malloc(sizeof(MapData));
  map_data->width = width;
  map_data->height = height;
  map_data->data = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    map_data->data[i] = malloc(sizeof(int) * width);
  }
  return map_data;
}

// Free the GPS data object
void free_gps_data(GPSData *gps_data) {
  free(gps_data);
}

// Free the car data object
void free_car_data(CarData *car_data) {
  free(car_data);
}

// Free the map data object
void free_map_data(MapData *map_data) {
  for (int i = 0; i < map_data->height; i++) {
    free(map_data->data[i]);
  }
  free(map_data->data);
  free(map_data);
}

// Update the GPS data
void update_gps_data(GPSData *gps_data, double latitude, double longitude, double altitude,
                     double speed, double heading) {
  gps_data->latitude = latitude;
  gps_data->longitude = longitude;
  gps_data->altitude = altitude;
  gps_data->speed = speed;
  gps_data->heading = heading;
}

// Update the car data
void update_car_data(CarData *car_data, double x, double y, double angle, double speed) {
  car_data->x = x;
  car_data->y = y;
  car_data->angle = angle;
  car_data->speed = speed;
}

// Update the map data
void update_map_data(MapData *map_data, int x, int y, int value) {
  map_data->data[y][x] = value;
}

// Draw the map
void draw_map(MapData *map_data) {
  for (int y = 0; y < map_data->height; y++) {
    for (int x = 0; x < map_data->width; x++) {
      printf("%d", map_data->data[y][x]);
    }
    printf("\n");
  }
}

// Draw the car
void draw_car(CarData *car_data) {
  printf("Car: (%.2f, %.2f, %.2f, %.2f)\n", car_data->x, car_data->y, car_data->angle, car_data->speed);
}

// Main function
int main() {
  // Create the GPS data object
  GPSData *gps_data = new_gps_data();

  // Create the car data object
  CarData *car_data = new_car_data();

  // Create the map data object
  MapData *map_data = new_map_data(100, 100);

  // Update the GPS data
  update_gps_data(gps_data, 37.785834, -122.406417, 0.0, 0.0, 0.0);

  // Update the car data
  update_car_data(car_data, 0.0, 0.0, 0.0, 0.0);

  // Update the map data
  update_map_data(map_data, 0, 0, 1);

  // Draw the map
  draw_map(map_data);

  // Draw the car
  draw_car(car_data);

  // Free the GPS data object
  free_gps_data(gps_data);

  // Free the car data object
  free_car_data(car_data);

  // Free the map data object
  free_map_data(map_data);

  return 0;
}