//FormAI DATASET v1.0 Category: Calculator ; Style: single-threaded
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

typedef enum{
  NUMBER,
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  POWER,
  MODULO,
  LEFT_PAREN,
  RIGHT_PAREN,
  END
} Token;

int pos = 0;
char *input;

void skip_whitespace(){
  while(input[pos] == ' ' || input[pos] == '\t'){
    pos++;
  }
}

double parse_number(){
  double num = 0;
  double fraction = 0;
  double div = 10;
  int decimal_point = 0;
  while(isdigit(input[pos]) || input[pos] == '.'){
    if(input[pos] == '.')
      decimal_point = 1;
    else if(!decimal_point){
      num *= 10;
      num += input[pos] - '0';
    }
    else{
      fraction += (input[pos] - '0') / div;
      div *= 10;
    }
    pos++;
  }
  return num + fraction;
}

Token get_next_token(){
  skip_whitespace();
  switch(input[pos]){
    case '+': pos++; return PLUS;
    case '-': pos++; return MINUS;
    case '*': pos++; return MULTIPLY;
    case '/': pos++; return DIVIDE;
    case '^': pos++; return POWER;
    case '%': pos++; return MODULO;
    case '(': pos++; return LEFT_PAREN;
    case ')': pos++; return RIGHT_PAREN;
    case '\0': return END;
    default: return NUMBER;
  }
}

double expr();

double factor(){
  Token token = get_next_token();
  double result = 0;
  switch(token){
    case NUMBER:
      result = parse_number();
      break;
    case PLUS:
      result = factor();
      break;
    case MINUS:
      result = -factor();
      break;
    case LEFT_PAREN:
      result = expr();
      get_next_token();
      break;
    default:
      printf("Error: expected number, left paren, or minus sign\n");
      break;
  }
  return result;
}

double power(){
  double left = factor();
  Token token = get_next_token();
  double right = 0;
  switch(token){
    case POWER:
      right = power();
      return pow(left, right);
    default:
      pos--;
      return left;
  }
}

double modulo(){
  double left = power();
  Token token = get_next_token();
  double right = 0;
  switch(token){
    case MODULO:
      right = modulo();
      return fmod(left, right);
    default:
      pos--;
      return left;
  }
}

double term(){
  double left = modulo();
  Token token = get_next_token();
  double right = 0;
  while(token == MULTIPLY || token == DIVIDE){
    switch(token){
      case MULTIPLY:
        right = modulo();
        left *= right;
        break;
      case DIVIDE:
        right = modulo();
        left /= right;
        break;
      default:
        break;
    }
    token = get_next_token();
  }
  pos--;
  return left;
}

double expr(){
  double left = term();
  Token token = get_next_token();
  double right = 0;
  while(token == PLUS || token == MINUS){
    switch(token){
      case PLUS:
        right = term();
        left += right;
        break;
      case MINUS:
        right = term();
        left -= right;
        break;
      default:
        break;
    }
    token = get_next_token();
  }
  pos--;
  return left;
}

void main(){
  input = malloc(256);
  printf("Enter calculation: ");
  scanf("%[^\n]", input);
  double result = expr();
  printf("%f\n", result);
}