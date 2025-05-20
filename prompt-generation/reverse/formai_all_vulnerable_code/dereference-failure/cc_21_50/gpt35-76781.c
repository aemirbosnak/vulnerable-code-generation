//FormAI DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h> // for detecting arrow key presses
#include <unistd.h>

#define MAX_LINE_LEN 80 // set max characters per line for display purposes

int main(int argc, char **argv) {

  // check if command-line argument provided for ebook file
  if (argc < 2) {
    printf("Error: no ebook file provided.\n");
    return 1;
  }

  // open ebook file and read in contents
  FILE *f = fopen(argv[1], "r");
  if (!f) {
    printf("Error: could not open ebook file.\n");
    return 1;
  }
  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *contents = malloc(size + 1);
  fread(contents, 1, size, f);
  contents[size] = '\0';
  fclose(f);

  // set up terminal to detect arrow key presses
  struct termios orig, new;
  tcgetattr(STDIN_FILENO, &orig);
  new = orig;
  new.c_lflag &= ~(ICANON|ECHO); // disable canonical mode and echo
  tcsetattr(STDIN_FILENO, TCSANOW, &new);

  // set up variables for scrolling and display
  char *ptr = contents; // current position in text
  int rows = 0; // current row number
  while (*ptr++) {
    if (*ptr == '\n') rows++; // increment row number each time a newline character is encountered
  }
  ptr = contents; // reset position in text to start
  int max_rows = (rows > 20) ? 20 : rows; // set max number of rows displayed on screen
  int top_row = 0; // index of top row being displayed on screen

  // display initial portion of text
  int i;
  for (i = 0; i < max_rows; i++) {
    printf("%.*s\n", MAX_LINE_LEN, ptr);
    while (*ptr++ != '\n'); // increment pointer to start of next line
  }

  // detect arrow key presses and scroll through text accordingly
  char c;
  while ((c = getchar())) {
    switch (c) {
      case 27: // arrow key detected
        getchar(); // skip [
        switch (getchar()) {
          case 65: // up arrow key
            if (top_row > 0) {
              top_row--;
              ptr = contents;
              for (i = 0; i < top_row; i++) {
                while (*ptr++ != '\n'); // increment pointer to start of next line
              }
              system("clear"); // clear terminal window before redisplaying text
              for (i = 0; i < max_rows; i++) {
                printf("%.*s\n", MAX_LINE_LEN, ptr);
                while (*ptr++ != '\n'); // increment pointer to start of next line
              }
            }
            break;
          case 66: // down arrow key
            if (top_row < rows - max_rows) {
              top_row++;
              ptr = contents;
              for (i = 0; i < top_row; i++) {
                while (*ptr++ != '\n'); // increment pointer to start of next line
              }
              system("clear"); // clear terminal window before redisplaying text
              for (i = 0; i < max_rows; i++) {
                printf("%.*s\n", MAX_LINE_LEN, ptr);
                while (*ptr++ != '\n'); // increment pointer to start of next line
              }
            }
            break;
          default: // ignore other arrow keys
            break;
        }
        break;
      case 'q': // quit program on 'q' key press
        free(contents);
        tcsetattr(STDIN_FILENO, TCSANOW, &orig); // restore terminal settings
        return 0;
      default: // ignore other key presses
        break;
    }
  }
}