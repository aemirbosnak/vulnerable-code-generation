//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
// C program for GPS Navigation Simulation

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

struct Position {
  double latitude;
  double longitude;
};

struct Waypoint {
  char name[50];
  struct Position position;
};

struct Route {
  char name[50];
  int num_waypoints;
  struct Waypoint* waypoint_list;
};

double GreatCircleDistance(struct Position pos1, struct Position pos2){
  // Calculates the great circle distance between two points on Earth
  // Uses the haversine formula
  double lat1 = pos1.latitude * PI / 180;
  double lon1 = pos1.longitude * PI / 180;
  double lat2 = pos2.latitude * PI / 180;
  double lon2 = pos2.longitude * PI / 180;
  double dlat = lat2 - lat1;
  double dlon = lon2 - lon1;
  double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double d = 6371 * c;
  return d;
}

int FindNearestWaypoint(struct Position position, struct Route route){
  // Finds the index of the nearest waypoint in the route to the given position
  int nearest_index = 0;
  double min_distance = GreatCircleDistance(position, route.waypoint_list[0].position);
  for(int i = 1; i < route.num_waypoints; i++){
    double distance = GreatCircleDistance(position, route.waypoint_list[i].position);
    if(distance < min_distance){
      min_distance = distance;
      nearest_index = i;
    }
  }
  return nearest_index;
}

int main(){
  // Test code
  struct Position current_pos = {37.7749, -122.4194}; // San Francisco
  struct Waypoint wp1 = {"Golden Gate Bridge", {37.8199, -122.4783}};
  struct Waypoint wp2 = {"Alcatraz Island", {37.8267, -122.4233}};
  struct Route route1 = {"San Francisco Landmarks", 2, &wp1};
  route1.waypoint_list[1] = wp2;
  int nearest_index = FindNearestWaypoint(current_pos, route1);
  printf("Nearest waypoint: %s\n", route1.waypoint_list[nearest_index].name);
  return 0;
}