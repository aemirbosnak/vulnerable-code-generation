//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.01
struct point {
  double lat;
  double lon;
};

struct route {
  int num_points;
  struct point *points;
};

struct gps {
  struct point current;
  struct route *route;
};

struct gps *gps_init(struct route *route) {
  struct gps *gps = malloc(sizeof(struct gps));
  gps->route = route;
  gps->current = route->points[0];
  return gps;
}

void gps_update(struct gps *gps, double lat, double lon) {
  gps->current.lat = lat;
  gps->current.lon = lon;
}

double gps_distance_to_destination(struct gps *gps) {
  int n = gps->route->num_points - 1;
  double lat1 = gps->current.lat;
  double lon1 = gps->current.lon;
  double lat2 = gps->route->points[n].lat;
  double lon2 = gps->route->points[n].lon;

  double dlat = lat2 - lat1;
  double dlon = lon2 - lon1;

  double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));

  return EARTH_RADIUS * c;
}

void gps_free(struct gps *gps) {
  free(gps->route->points);
  free(gps->route);
  free(gps);
}

int main() {
  // Define a route
  struct point points[] = {
    {37.7749, -122.4194},
    {37.7633, -122.4259},
    {37.7702, -122.4229},
    {37.7659, -122.4162},
  };

  struct route route = {
    4,
    points
  };

  // Initialize a GPS device
  struct gps *gps = gps_init(&route);

  // Update the GPS device with some initial coordinates
  gps_update(gps, 37.7702, -122.4229);

  // Print the distance to the destination
  printf("Distance to destination: %f km\n", gps_distance_to_destination(gps));

  // Free the GPS device
  gps_free(gps);

  return 0;
}