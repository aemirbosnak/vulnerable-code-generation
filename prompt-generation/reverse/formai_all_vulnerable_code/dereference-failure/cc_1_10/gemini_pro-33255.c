//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Cloud {
  float x;
  float y;
  float z;
  float size;
};

struct Wind {
  float x;
  float y;
  float z;
  float speed;
};

struct Rain {
  float x;
  float y;
  float z;
  float size;
  float speed;
};

struct Snow {
  float x;
  float y;
  float z;
  float size;
  float speed;
};

struct Weather {
  struct Cloud *clouds;
  int num_clouds;
  struct Wind *winds;
  int num_winds;
  struct Rain *rains;
  int num_rains;
  struct Snow *snows;
  int num_snows;
};

struct Weather *create_weather(int num_clouds, int num_winds, int num_rains, int num_snows) {
  struct Weather *weather = malloc(sizeof(struct Weather));
  weather->clouds = malloc(sizeof(struct Cloud) * num_clouds);
  weather->num_clouds = num_clouds;
  weather->winds = malloc(sizeof(struct Wind) * num_winds);
  weather->num_winds = num_winds;
  weather->rains = malloc(sizeof(struct Rain) * num_rains);
  weather->num_rains = num_rains;
  weather->snows = malloc(sizeof(struct Snow) * num_snows);
  weather->num_snows = num_snows;
  return weather;
}

void destroy_weather(struct Weather *weather) {
  free(weather->clouds);
  free(weather->winds);
  free(weather->rains);
  free(weather->snows);
  free(weather);
}

void update_weather(struct Weather *weather) {
  for (int i = 0; i < weather->num_clouds; i++) {
    weather->clouds[i].x += weather->winds[i].x * weather->winds[i].speed;
    weather->clouds[i].y += weather->winds[i].y * weather->winds[i].speed;
    weather->clouds[i].z += weather->winds[i].z * weather->winds[i].speed;
  }

  for (int i = 0; i < weather->num_rains; i++) {
    weather->rains[i].x += weather->winds[i].x * weather->winds[i].speed;
    weather->rains[i].y += weather->winds[i].y * weather->winds[i].speed;
    weather->rains[i].z += weather->winds[i].z * weather->winds[i].speed;
  }

  for (int i = 0; i < weather->num_snows; i++) {
    weather->snows[i].x += weather->winds[i].x * weather->winds[i].speed;
    weather->snows[i].y += weather->winds[i].y * weather->winds[i].speed;
    weather->snows[i].z += weather->winds[i].z * weather->winds[i].speed;
  }
}

void render_weather(struct Weather *weather) {
  for (int i = 0; i < weather->num_clouds; i++) {
    printf("Cloud %d: x=%f, y=%f, z=%f, size=%f\n", i, weather->clouds[i].x, weather->clouds[i].y, weather->clouds[i].z, weather->clouds[i].size);
  }

  for (int i = 0; i < weather->num_rains; i++) {
    printf("Rain %d: x=%f, y=%f, z=%f, size=%f, speed=%f\n", i, weather->rains[i].x, weather->rains[i].y, weather->rains[i].z, weather->rains[i].size, weather->rains[i].speed);
  }

  for (int i = 0; i < weather->num_snows; i++) {
    printf("Snow %d: x=%f, y=%f, z=%f, size=%f, speed=%f\n", i, weather->snows[i].x, weather->snows[i].y, weather->snows[i].z, weather->snows[i].size, weather->snows[i].speed);
  }
}

int main() {
  srand(time(NULL));

  struct Weather *weather = create_weather(100, 100, 100, 100);

  for (int i = 0; i < weather->num_clouds; i++) {
    weather->clouds[i].x = rand() % 1000;
    weather->clouds[i].y = rand() % 1000;
    weather->clouds[i].z = rand() % 1000;
    weather->clouds[i].size = rand() % 100;
  }

  for (int i = 0; i < weather->num_winds; i++) {
    weather->winds[i].x = rand() % 100;
    weather->winds[i].y = rand() % 100;
    weather->winds[i].z = rand() % 100;
    weather->winds[i].speed = rand() % 100;
  }

  for (int i = 0; i < weather->num_rains; i++) {
    weather->rains[i].x = rand() % 1000;
    weather->rains[i].y = rand() % 1000;
    weather->rains[i].z = rand() % 1000;
    weather->rains[i].size = rand() % 100;
    weather->rains[i].speed = rand() % 100;
  }

  for (int i = 0; i < weather->num_snows; i++) {
    weather->snows[i].x = rand() % 1000;
    weather->snows[i].y = rand() % 1000;
    weather->snows[i].z = rand() % 1000;
    weather->snows[i].size = rand() % 100;
    weather->snows[i].speed = rand() % 100;
  }

  while (1) {
    update_weather(weather);
    render_weather(weather);
  }

  destroy_weather(weather);

  return 0;
}