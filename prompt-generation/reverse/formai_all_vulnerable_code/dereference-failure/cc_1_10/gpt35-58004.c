//FormAI DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char *inputFile, char *outputFile)
{
  FILE *input, *output;
  char buffer[1001], prev_char='\0', curr_char='\0';
  int indentation = 0;

  // open input file for reading
  input = fopen(inputFile, "r");
  if (!input)
  {
      printf("Unable to open input file!\n");
      exit(1);
  }

  // open output file for writing
  output = fopen(outputFile, "w");
  if (!output)
  {
      printf("Unable to open output file!\n");
      exit(1);
  }

  // read each character from input file and beautify it
  while (fgets(buffer, 1000, input))
  {
    for (int i = 0; i < strlen(buffer); i++)
    {
      curr_char = buffer[i];

      // if opening tag is found, increase indentation and write tag with proper indentation
      if (prev_char == '<' && curr_char != '/')
      {
        fprintf(output, "\n%*s%c", indentation, "", '<');
        indentation += 2;
      }

      fprintf(output, "%c", curr_char);

      // if closing tag is found, decrease indentation and write tag with proper indentation
      if (prev_char == '/' && curr_char == '>')
      {
        indentation -= 2;
        fprintf(output, "\n%*s%c%c", indentation, "", '<', '/');
      }

      prev_char = curr_char;
    }
  }

  // close input and output files
  fclose(input);
  fclose(output);

  printf("Successfully beautified HTML and saved to file %s!\n", outputFile);
}

int main()
{
  char inputFile[] = "input.html";
  char outputFile[] = "output.html";

  beautifyHTML(inputFile, outputFile);

  return 0;
}