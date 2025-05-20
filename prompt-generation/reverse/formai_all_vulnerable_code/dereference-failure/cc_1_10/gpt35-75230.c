//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to beautify HTML code
void beautifyHTML(char* code){
  int i = 0, k = 0;
  char temp[1024];

  while(code[i] != '\0'){
    if(code[i] == '<' && code[i+1] != '/'){ // opening tag
      if(i != 0){
        temp[k] = '\n';
        k++;
      }
      for(int j = 0; j < k; j++){
        printf("  ");
      }
      printf("%c", code[i]);
      temp[k] = code[i];
      k++;
      printf("\n");
      k++;
    }
    else if(code[i] == '<' && code[i+1] == '/'){ // closing tag
      k-=2;
      for(int j = 0; j < k; j++){
        printf("  ");
      }
      printf("%c%c", code[i], code[i+1]);
      temp[k] = code[i];
      temp[k+1] = code[i+1];
      k+=2;
      printf("\n");
      i++;
    }
    else if(code[i] == '>'){ // end of tag
      printf("%c", code[i]);
      temp[k] = code[i];
      k++;
      printf("\n");
    }
    else{
      printf("%c", code[i]);
      temp[k] = code[i];
      k++;
    }
    i++;
  }
}


// main function
int main(){
  char input[1024];
  char* code = NULL;

  printf("Welcome to the HTML Beautifier!\n");
  printf("Enter your HTML code: ");

  fgets(input, sizeof(input), stdin);
  code = (char*)malloc(strlen(input)+1);
  strcpy(code, input);

  beautifyHTML(code);

  free(code);
  return 0;
}