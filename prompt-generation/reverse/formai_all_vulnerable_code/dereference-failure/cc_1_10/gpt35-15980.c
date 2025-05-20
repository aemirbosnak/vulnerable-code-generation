//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>

void beautifyHTML(char *filename) {
  FILE *fp, *fp_out;
  char ch;
  int indent = 0;

  fp = fopen(filename, "r");
  fp_out = fopen("output.html", "w");

  if (fp == NULL){
    printf("%s not found.\n", filename);
    return;
  }

  while((ch = fgetc(fp)) != EOF) {
    if(ch == '\n' || ch == ' ') {
      continue;
    }
    if (ch == '<') {
      if (indent > 0) {
        fprintf(fp_out, "\n");
      }
      for(int i = 0; i < indent; i++) {
        fprintf(fp_out, "  ");
      }
      fprintf(fp_out, "%c", ch);
      indent++;
    } else if (ch == '>') {
      fprintf(fp_out, "%c", ch);
      fprintf(fp_out, "\n");
    } else if (ch == '/') {
      indent--;
      fprintf(fp_out,"\n");
      for(int i = 0; i < indent; i++) {
        fprintf(fp_out, "  ");
      }
      fprintf(fp_out, "%c", ch);
    } else {
      fprintf(fp_out, "%c", ch);
    }
  }
  
  fclose(fp);
  fclose(fp_out);
}

int main() {
  beautifyHTML("input.html");
  return 0;
}