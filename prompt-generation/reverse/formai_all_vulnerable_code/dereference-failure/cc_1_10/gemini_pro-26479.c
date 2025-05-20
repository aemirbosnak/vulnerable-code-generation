//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100
#define NUM_THREADS 4

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point start, end;
} PathfindingRequest;

typedef struct {
  PathfindingRequest request;
  Point* path;
  int path_length;
} PathfindingResult;

pthread_mutex_t mutex;
int num_completed_threads = 0;
PathfindingResult* results[NUM_THREADS];

void* pathfinding_thread(void* arg) {
  PathfindingRequest* request = (PathfindingRequest*)arg;
  Point* path = malloc(sizeof(Point) * MAP_WIDTH * MAP_HEIGHT);
  int path_length = 0;

  // Perform pathfinding here

  PathfindingResult* result = malloc(sizeof(PathfindingResult));
  result->request = *request;
  result->path = path;
  result->path_length = path_length;

  pthread_mutex_lock(&mutex);
  results[num_completed_threads++] = result;
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  pthread_t threads[NUM_THREADS];
  PathfindingRequest requests[NUM_THREADS];

  // Initialize pathfinding requests

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, pathfinding_thread, &requests[i]);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Process pathfinding results

  for (int i = 0; i < NUM_THREADS; i++) {
    PathfindingResult* result = results[i];
    printf("Path from (%d, %d) to (%d, %d):\n", result->request.start.x, result->request.start.y, result->request.end.x, result->request.end.y);
    for (int j = 0; j < result->path_length; j++) {
      printf("(%d, %d)\n", result->path[j].x, result->path[j].y);
    }
    free(result->path);
    free(result);
  }

  return 0;
}