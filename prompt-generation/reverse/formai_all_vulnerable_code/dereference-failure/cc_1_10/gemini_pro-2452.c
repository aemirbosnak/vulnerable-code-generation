//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 7

struct color_code {
  char code[MAX_COLOR_CODE_LENGTH + 1];
  int red;
  int green;
  int blue;
};

struct color_code_table {
  struct color_code codes[256];
};

static const struct color_code_table color_code_table = {
  {
    { "000000", 0, 0, 0 },
    { "000080", 0, 0, 128 },
    { "0000ff", 0, 0, 255 },
    { "008000", 0, 128, 0 },
    { "008080", 0, 128, 128 },
    { "0080ff", 0, 128, 255 },
    { "00ff00", 0, 255, 0 },
    { "00ff80", 0, 255, 128 },
    { "00ffff", 0, 255, 255 },
    { "800000", 128, 0, 0 },
    { "800080", 128, 0, 128 },
    { "8000ff", 128, 0, 255 },
    { "808000", 128, 128, 0 },
    { "808080", 128, 128, 128 },
    { "8080ff", 128, 128, 255 },
    { "80ff00", 128, 255, 0 },
    { "80ff80", 128, 255, 128 },
    { "80ffff", 128, 255, 255 },
    { "ff0000", 255, 0, 0 },
    { "ff0080", 255, 0, 128 },
    { "ff00ff", 255, 0, 255 },
    { "ff8000", 255, 128, 0 },
    { "ff8080", 255, 128, 128 },
    { "ff80ff", 255, 128, 255 },
    { "ffff00", 255, 255, 0 },
    { "ffff80", 255, 255, 128 },
    { "ffffff", 255, 255, 255 }
  }
};

static int hex_to_int(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else {
    return -1;
  }
}

static int parse_color_code(const char *code, struct color_code *color_code) {
  int i;

  if (strlen(code) != MAX_COLOR_CODE_LENGTH) {
    return -1;
  }

  for (i = 0; i < MAX_COLOR_CODE_LENGTH; i++) {
    int v = hex_to_int(code[i]);
    if (v == -1) {
      return -1;
    }
    color_code->code[i] = code[i];
    if (i % 2 == 0) {
      color_code->red = (color_code->red << 4) | v;
    } else {
      color_code->green = (color_code->green << 4) | v;
    }
  }

  color_code->blue = color_code->green;

  return 0;
}

static int find_color_code(const char *code, struct color_code *color_code) {
  int i;

  for (i = 0; i < 256; i++) {
    if (strcmp(code, color_code_table.codes[i].code) == 0) {
      *color_code = color_code_table.codes[i];
      return 0;
    }
  }

  return -1;
}

static void print_color_code(const struct color_code *color_code) {
  printf("Color code: %s\n", color_code->code);
  printf("Red: %d\n", color_code->red);
  printf("Green: %d\n", color_code->green);
  printf("Blue: %d\n", color_code->blue);
}

int main(int argc, char **argv) {
  struct color_code color_code;
  int i;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <color_code>\n", argv[0]);
    return 1;
  }

  if (parse_color_code(argv[1], &color_code) != 0) {
    fprintf(stderr, "Invalid color code: %s\n", argv[1]);
    return 1;
  }

  if (find_color_code(color_code.code, &color_code) != 0) {
    fprintf(stderr, "Unknown color code: %s\n", color_code.code);
    return 1;
  }

  print_color_code(&color_code);

  return 0;
}