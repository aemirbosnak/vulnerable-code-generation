//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *input = fopen(argv[1], "r");
  if (input == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  FILE *output = fopen(argv[2], "w");
  if (output == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), input) != NULL) {
    for (char *c = buffer; *c != '\0'; c++) {
      switch (*c) {
        case 'a':
          fprintf(output, "  _  _ ___ ___  \n | || ||_ _/ __| \n | || | | | \\__ \\ \n |__||_| |_||___/ \n                   ");
          break;
        case 'b':
          fprintf(output, "  _  __ _ _ __ ___  \n | ||  (_| '_ ` _ \\ \n | || | | | | | | | |\n |_||_| |_|_| |_| |_|\n                     ");
          break;
        case 'c':
          fprintf(output, "  _ ____  \n | | __ ) \n | |  _ \\ \n |_| |_) | \n           ");
          break;
        case 'd':
          fprintf(output, "  _  __ _   \n | ||  (_| |  \n | || | | |   \n |_||_| |_|    \n               ");
          break;
        case 'e':
          fprintf(output, "  _  __ _  _ __ ___  \n | |/ _(_) || '_ ` _ \\ \n | | (_) | || | | | | |\n |_|\___/|_||_| |_| |_|\n                       ");
          break;
        case 'f':
          fprintf(output, "  _  __ _ _   __ _  \n | |/ _(_) | |/ _(_) \n | | (_) | | | (_) |  \n |_|\___/|_|_|\___/   \n                       ");
          break;
        case 'g':
          fprintf(output, "  __ _  _ __ ___   \n / _` || '_ ` _ \\   \n| (_| || | | | | |  \n \__,_||_| |_| |_|   \n                     ");
          break;
        case 'h':
          fprintf(output, "  _  __ _ _ __   \n | |/ _(_) | '_ \  \n | | (_) | | | | \n |_|\___/|_|_| |_| \n                   ");
          break;
        case 'i':
          fprintf(output, "  _  ___           \n | |/ _ \           \n | | (_) |          \n |_|\___/           \n                   ");
          break;
        case 'j':
          fprintf(output, "    _   _  _ __    \n   | | | || '_ \   \n   | |_| || | | |  \n    \__,_||_| |_|   \n                   ");
          break;
        case 'k':
          fprintf(output, "  _  __ _ _ __ ___     \n | |/ _(_) | '_ ` _ \    \n | | (_) | | | | | | |   \n |_|\___/|_|_| |_| |_|    \n                           ");
          break;
        case 'l':
          fprintf(output, "  _  __ _ _ __   ___  \n | |/ _(_) | '_ \ / _ \ \n | | (_) | | | | |  __/ \n |_|\___/|_|_| |_|\___| \n                       ");
          break;
        case 'm':
          fprintf(output, "  _    _ ____  _    _  ___  ___  \n | |  | |  _ \| |  | |/ _ \|_ _| \n | |__| | |_) | |  | | (_) | |   \n |  __  |  __/| |__| |\___/| |   \n |_|  |_|_|   |____/ |____/___|  \n                                  ");
          break;
        case 'n':
          fprintf(output, "  _  __ _ _ __ ___   \n | |/ _(_) | '_ ` _ \  \n | | (_) | | | | | | | \n |_|\___/|_|_| |_| |_|  \n                       ");
          break;
        case 'o':
          fprintf(output, "  _  __ _ _   _  ___   \n | |/ _(_) | | | |/ _ \  \n | | (_) | | | || (_) | \n |_|\___/|_| |_| \___/  \n                       ");
          break;
        case 'p':
          fprintf(output, "  _  __ _  _ __ ___   \n | |/ _(_) || '_ ` _ \  \n | | (_) | || | | | | | \n |_|\___/|_||_| |_| |_|  \n                       ");
          break;
        case 'q':
          fprintf(output, "  __ _  __ _  ___    \n / _` ||  (_)/ _ \   \n| (_| || | | | (_) |  \n \__,_||_| |_|\___/   \n                      ");
          break;
        case 'r':
          fprintf(output, "  _  __ _  _ __ ___  \n | |/ _(_) || '_ ` _ \ \n | | (_) | || | | | | |\n |_|\___/|_||_| |_| |_|\n                       ");
          break;
        case 's':
          fprintf(output, "  _  __ _  _ __ ___   \n | |/ _(_) || '_ ` _ \  \n | | (_) | || | | | | | \n |_|\___/|_||_| |_| |_|  \n                       ");
          break;
        case 't':
          fprintf(output, "  _  __ _ _ __ ___  \n | ||  (_| '_ ` _ \ \n | || | | | | | | | |\n |_||_| |_|_| |_| |_|\n                     ");
          break;
        case 'u':
          fprintf(output, "  _  __ _ _   _    \n | ||  (_| | | | |   \n | || | | | |_| |    \n |_||_| |_|\__, |    \n            __/ |     \n           |___/      ");
          break;
        case 'v':
          fprintf(output, "  _    _ _______  \n | |  | |__   __| \n | |__| |  | |    \n  \____/   |_|     \n                  ");
          break;
        case 'w':
          fprintf(output, "  _  __ _    _ __ ___  \n | ||  (_)/\ / / '_ ` _ \ \n | || | /  V /| | | | | | |\n |_||_| \_/\_/ |_| |_| |_|\n                          ");
          break;
        case 'x':
          fprintf(output, "  __ _  _ __ ___   \n / _` || '_ ` _ \  \n| (_| || | | | | | \n \__,_||_| |_| |_|  \n                   ");
          break;
        case 'y':
          fprintf(output, "  _    _ ____   \n | |  | |  _ \  \n | |__| | |_) | \n  \____/|  __/  \n            |___|  ");
          break;
        case 'z':
          fprintf(output, "  _  __ _  _ __ ___  \n | |/ _(_) || '_ ` _ \ \n | | (_) | || | | | | |\n |_|\___/|_||_| |_| |_|\n                       ");
          break;
        default:
          fprintf(output, " ");
      }
    }
    fprintf(output, "\n");
  }

  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}