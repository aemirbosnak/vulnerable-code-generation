//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <string.h>

void beautify(char **str)
{
  int i = 0, j = 0, k = 0, maxLen = 0, indent = 0;
  char tempStr[1024] = "";

  // Calculate maximum length of the string
  for (i = 0; str[i] != '\0'; i++)
  {
    maxLen++;
  }

  // Allocate memory for the beautified string
  *str = (char *)malloc(maxLen * sizeof(char) + 1);

  // Indent the first line
  tempStr[0] = ' ';
  tempStr[1] = '\t';

  // Iterate over the original string
  for (i = 0; str[i] != '\0'; i++)
  {
    // Check if the current line is the first line or a new line
    if (str[i] == '\n')
    {
      indent++;
      tempStr[k++] = '\n';
      tempStr[k++] = ' ';
      tempStr[k++] = ' ';
    }
    else
    {
      // Indent subsequent lines
      tempStr[k++] = ' ';
      tempStr[k++] = ' ';
    }

    // Copy the character from the original string
    tempStr[k++] = str[i];
  }

  // Copy the beautified string to the original string
  strcpy(*str, tempStr);

  // Free the temporary memory
  free(tempStr);
}

int main()
{
  char *str = "This is a string.\nIt has multiple lines.\n";

  beautify(&str);

  printf("%s", str);

  return 0;
}