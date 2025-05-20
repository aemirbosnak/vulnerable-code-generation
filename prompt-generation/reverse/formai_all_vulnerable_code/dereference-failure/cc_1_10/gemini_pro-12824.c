//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_POINTS 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_LENGTH 20

typedef struct {
  char category[MAX_CATEGORY_LENGTH];
  int frequency;
} DataPoint;

typedef struct {
  DataPoint data_points[MAX_DATA_POINTS];
  int num_data_points;
  int num_categories;
} Data;

Data *create_data() {
  Data *data = malloc(sizeof(Data));
  data->num_data_points = 0;
  data->num_categories = 0;
  return data;
}

void add_data_point(Data *data, char *category, int frequency) {
  if (data->num_data_points >= MAX_DATA_POINTS) {
    return;
  }

  int i;
  for (i = 0; i < data->num_data_points; i++) {
    if (strcmp(data->data_points[i].category, category) == 0) {
      data->data_points[i].frequency += frequency;
      return;
    }
  }

  if (data->num_categories >= MAX_CATEGORIES) {
    return;
  }

  strcpy(data->data_points[data->num_data_points].category, category);
  data->data_points[data->num_data_points].frequency = frequency;
  data->num_data_points++;
  data->num_categories++;
}

void print_data(Data *data) {
  int i;
  for (i = 0; i < data->num_data_points; i++) {
    printf("%s: %d\n", data->data_points[i].category, data->data_points[i].frequency);
  }
}

int main() {
  Data *data = create_data();

  add_data_point(data, "Category 1", 10);
  add_data_point(data, "Category 2", 20);
  add_data_point(data, "Category 3", 30);
  add_data_point(data, "Category 4", 40);
  add_data_point(data, "Category 5", 50);

  print_data(data);

  return 0;
}