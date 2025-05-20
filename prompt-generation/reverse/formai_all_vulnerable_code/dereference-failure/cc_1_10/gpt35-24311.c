//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(const char* inputFilename, const char* outputFilename) {
  FILE * inputFile, * outputFile;
  inputFile = fopen(inputFilename,"r");
  outputFile = fopen(outputFilename,"w");

  if(inputFile == NULL) {
    printf("Cannot open input file.");
    exit(1);
  }
  if(outputFile == NULL) {
    printf("Cannot open output file.");
    exit(1);
  }

  char c;
  int indent = 0;
  int newLinePending = 0;
  while((c = fgetc(inputFile)) != EOF) {
    if(newLinePending && c != ' ') {
      fputc('\n', outputFile);
      newLinePending = 0;
    }
    if(c == '<') {
      if(newLinePending) {
        fputc('\n', outputFile);
        newLinePending = 0;
      }
      fputc(c, outputFile);
      if(fgetc(inputFile) != '/') {
        indent++;
      }
      ungetc(c, inputFile);

    } else if(c == '/') {
      if(newLinePending) {
        fputc('\n', outputFile);
        newLinePending = 0;
      }
      indent--;
      fputc(c, outputFile);
    } else if(c == '>') {
      fputc(c, outputFile);
      if(fgetc(inputFile) != '<') {
        indent--;
        newLinePending = 1;
      }
      ungetc(c, inputFile);
    } else {
      if(newLinePending) {
        fputc('\n', outputFile);
        newLinePending = 0;
      }
      fputc(c, outputFile);
    }
    if(c == '\n') {
      for(int i=0;i<indent;i++) {
        fputc('\t',outputFile);
      }
    }
  }

  fclose(inputFile);
  fclose(outputFile);
}

void main() {
  beautifyHTML("input.html", "output.html");
}