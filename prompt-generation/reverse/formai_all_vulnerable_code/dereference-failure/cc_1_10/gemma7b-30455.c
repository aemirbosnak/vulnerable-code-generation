//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *str)
{
  int i = 0, j = 0, k = 0, l = 0, flag = 0;
  char temp[1024], ch, prev = '\0';

  while (str[i] != '\0')
  {
    switch (str[i])
    {
      case '(':
      case ')':
      case '{':
      case '}':
      case '[':
      case ']':
        flag = 1;
        break;
      default:
        flag = 0;
    }

    if (flag && prev == ' ')
    {
      temp[k++] = ' ';
    }

    temp[k++] = str[i];

    prev = str[i];

    i++;
  }

  strcpy(str, temp);

  free(temp);
}

int main()
{
  char str[] = "((a))";

  beautify(str);

  printf("%s\n", str);

  return 0;
}