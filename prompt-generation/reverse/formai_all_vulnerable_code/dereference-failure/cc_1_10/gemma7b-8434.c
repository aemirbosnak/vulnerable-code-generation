//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define neon_red "\x1b[31m"
#define neon_green "\x1b[32m"
#define neon_blue "\x1b[34m"

void beautify_code(char *code)
{
  char *p = code;
  char *q = code;

  // Indent the first line
  if (*p == '{')
  {
    p++;
    while (isspace(*p))
    {
      *q++ = ' ';
    }
  }

  // Add spacing after commas and colons
  while (p = strchr(p, ','))
  {
    p++;
    while (isspace(*p) || *p == ',')
    {
      *q++ = ' ';
    }
  }

  // Add spacing after opening braces
  while (p = strchr(p, '{'))
  {
    p++;
    while (isspace(*p))
    {
      *q++ = ' ';
    }
  }

  // Highlight the main function
  if (strstr(code, "main()"))
  {
    printf("%s", neon_green);
    printf("MAIN FUNCTION START\n");
    printf("%s", neon_blue);
  }

  // Print the beautified code
  printf("%s", code);

  // Reset the colors
  printf("\x1b[0m");
}

int main()
{
  char code[] = "int main()\n{  printf(\"HELLO, WORLD!\"); }\n";
  beautify_code(code);

  return 0;
}