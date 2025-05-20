//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point start;
  Point end;
} Destination;

typedef struct {
  int num_destinations;
  Destination *destinations;
} Input;

typedef struct {
  int num_routes;
  Destination **routes;
} Output;

Input *parse_input(char *input_file) {
  FILE *file = fopen(input_file, "r");
  if (file == NULL) {
    perror("Error opening input file");
    return NULL;
  }

  int num_destinations;
  fscanf(file, "%d", &num_destinations);

  Input *input = malloc(sizeof(Input));
  input->num_destinations = num_destinations;
  input->destinations = malloc(sizeof(Destination) * num_destinations);

  for (int i = 0; i < num_destinations; i++) {
    fscanf(file, "%d %d %d %d", &input->destinations[i].start.x, &input->destinations[i].start.y,
            &input->destinations[i].end.x, &input->destinations[i].end.y);
  }

  fclose(file);
  return input;
}

Output *solve(Input *input) {
  Output *output = malloc(sizeof(Output));
  output->num_routes = input->num_destinations;
  output->routes = malloc(sizeof(Destination *) * input->num_destinations);

  for (int i = 0; i < input->num_destinations; i++) {
    output->routes[i] = &input->destinations[i];
  }

  return output;
}

void print_output(Output *output, char *output_file) {
  FILE *file = fopen(output_file, "w");
  if (file == NULL) {
    perror("Error opening output file");
    return;
  }

  fprintf(file, "%d\n", output->num_routes);
  for (int i = 0; i < output->num_routes; i++) {
    fprintf(file, "%d %d %d %d\n", output->routes[i]->start.x, output->routes[i]->start.y,
            output->routes[i]->end.x, output->routes[i]->end.y);
  }

  fclose(file);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  Input *input = parse_input(argv[1]);
  if (input == NULL) {
    return EXIT_FAILURE;
  }

  Output *output = solve(input);
  print_output(output, argv[2]);

  free(input->destinations);
  free(input);
  free(output->routes);
  free(output);

  return EXIT_SUCCESS;
}