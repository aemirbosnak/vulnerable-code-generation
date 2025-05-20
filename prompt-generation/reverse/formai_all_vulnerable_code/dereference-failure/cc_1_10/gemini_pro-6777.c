//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A canvas is an array of characters for the output
typedef char canvas[256][256];

// A brush writes a string into a canvas
typedef void (*brush)(canvas, char *);

// The following brushes draw different shapes
void draw_line(canvas c, char *line) {
  int x1, y1, x2, y2;
  sscanf(line, "line %d %d %d %d", &x1, &y1, &x2, &y2);
  for (int x = x1; x <= x2; x++) {
    c[y1][x] = c[y2][x] = '#';
  }
  for (int y = y1; y <= y2; y++) {
    c[y][x1] = c[y][x2] = '#';
  }
}

void draw_circle(canvas c, char *circle) {
  int x0, y0, r;
  sscanf(circle, "circle %d %d %d", &x0, &y0, &r);
  for (int x = x0 - r; x <= x0 + r; x++) {
    for (int y = y0 - r; y <= y0 + r; y++) {
      if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r) {
        c[y][x] = '#';
      }
    }
  }
}

void draw_rectangle(canvas c, char *rectangle) {
  int x1, y1, x2, y2;
  sscanf(rectangle, "rectangle %d %d %d %d", &x1, &y1, &x2, &y2);
  for (int x = x1; x <= x2; x++) {
    c[y1][x] = c[y2][x] = '#';
  }
  for (int y = y1; y <= y2; y++) {
    c[y][x1] = c[y][x2] = '#';
  }
}

// The following function reads a file and returns its content
char *read_file(char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    return NULL;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *content = malloc(fsize + 1);
  fread(content, 1, fsize, f);
  fclose(f);
  content[fsize] = '\0';
  return content;
}

// The following function processes a command
void process_command(canvas c, char *command) {
  char *brush_name = strtok(command, " ");
  if (strcmp(brush_name, "line") == 0) {
    draw_line(c, command);
  } else if (strcmp(brush_name, "circle") == 0) {
    draw_circle(c, command);
  } else if (strcmp(brush_name, "rectangle") == 0) {
    draw_rectangle(c, command);
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s [filename]\n", argv[0]);
    return EXIT_FAILURE;
  }
  char *content = read_file(argv[1]);
  if (content == NULL) {
    printf("Error: could not read file %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  canvas c;
  memset(c, ' ', sizeof(c));
  char *command = strtok(content, "\n");
  while (command != NULL) {
    process_command(c, command);
    command = strtok(NULL, "\n");
  }
  for (int y = 0; y < 256; y++) {
    for (int x = 0; x < 256; x++) {
      printf("%c", c[y][x]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}