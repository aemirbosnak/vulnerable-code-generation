//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 100

/* function to check for valid number */
int is_number(char *str){
  int i;
  if(str[0]=='-'|| str[0]=='+')i=1;
  else i=0;
  while(str[i]){
    if(!isdigit(str[i])){
      return 0;
    }
    i++;
  }
  return 1;
}

/* function to evaluate expression */
int evaluate(char *expr){
  char *tokens[MAX_LEN];
  char *token;
  int token_count=0;
  int result=0;
  int temp=0;
  token=strtok(expr," ");

  while(token!=NULL){
    tokens[token_count]=token;
    token_count++;
    token=strtok(NULL," ");
  }

  for(int i=0;i<token_count;i++){
    if(is_number(tokens[i])){
      temp=atoi(tokens[i]);
    }
    else{
      switch(tokens[i][0]){
        case '+':
          result+=temp;
          break;
        case '-':
          result-=temp;
          break;
        case '*':
          temp*=atoi(tokens[i+1]);
          i++;
          break;
        case '/':
          temp/=atoi(tokens[i+1]);
          i++;
          break;
        default:
          printf("Invalid Operator");
          return 0;
      }
    }
  }
  result+=temp;
  return result;
}

int main(){
  char *expr="5 + 3 * 2 - 4 / 2";
  printf("Result : %d\n",evaluate(expr));
  return 0;
}