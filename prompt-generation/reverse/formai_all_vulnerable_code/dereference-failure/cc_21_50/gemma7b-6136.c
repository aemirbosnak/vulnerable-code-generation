//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

void text_to_ascii(char *text)
{
  int i = 0;
  int len = strlen(text);
  for (i = 0; i < len; i++)
  {
    switch (text[i])
    {
      case 'a':
      case 'A':
        text[i] = 97;
        break;
      case 'b':
      case 'B':
        text[i] = 98;
        break;
      case 'c':
      case 'C':
        text[i] = 99;
        break;
      case 'd':
      case 'D':
        text[i] = 100;
        break;
      case 'e':
      case 'E':
        text[i] = 101;
        break;
      case 'f':
      case 'F':
        text[i] = 102;
        break;
      case 'g':
      case 'G':
        text[i] = 103;
        break;
      case 'h':
      case 'H':
        text[i] = 104;
        break;
      case 'i':
      case 'I':
        text[i] = 105;
        break;
      case 'j':
      case 'J':
        text[i] = 106;
        break;
      case 'k':
      case 'K':
        text[i] = 107;
        break;
      case 'l':
      case 'L':
        text[i] = 108;
        break;
      case 'm':
      case 'M':
        text[i] = 109;
        break;
      case 'n':
      case 'N':
        text[i] = 110;
        break;
      case 'o':
      case 'O':
        text[i] = 111;
        break;
      case 'p':
      case 'P':
        text[i] = 112;
        break;
      case 'q':
      case 'Q':
        text[i] = 113;
        break;
      case 'r':
      case 'R':
        text[i] = 114;
        break;
      case 's':
      case 'S':
        text[i] = 115;
        break;
      case 't':
      case 'T':
        text[i] = 116;
        break;
      case 'u':
      case 'U':
        text[i] = 117;
        break;
      case 'v':
      case 'V':
        text[i] = 118;
        break;
      case 'w':
      case 'W':
        text[i] = 119;
        break;
      case 'x':
      case 'X':
        text[i] = 120;
        break;
      case 'y':
      case 'Y':
        text[i] = 121;
        break;
      case 'z':
      case 'Z':
        text[i] = 122;
        break;
      default:
        break;
    }
  }
}

int main()
{
  char text[MAX_LEN] = "This is a sample text to convert into ASCII art.";

  text_to_ascii(text);

  printf("%s", text);

  return 0;
}