//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

int main(){
  char input[MAX_LENGTH];
  int length, i, j, count=0;

  printf("Enter a C program: ");
  fgets(input,MAX_LENGTH,stdin);

  length=strlen(input);

  //Dynamically allocating memory for array of strings
  char **code_lines = (char **)malloc(length * sizeof(char *));
  for(i = 0; i < length; i++){
    code_lines[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
  }

  //Parsing the input C program by counting '{', '}' and ';'
  for(i=0;i<length;i++){
    if(input[i]=='{'){
      count++;
    }
    else if(input[i]=='}'){
      count--;
    }
    else if(input[i]==';'){
      j++;
    }
    else{
      code_lines[j][i]=input[i];
    }
  }

  //Printing the parsed code
  printf("\nParsed Code:\n\n");
  for(i=0;i<j;i++){
    printf("%s;\n",code_lines[i]);
  }
  printf("\n");

  //Freeing the allocated memory
  for(i = 0; i < length; i++){
    free(code_lines[i]);
  }
  free(code_lines);

  return 0;
}