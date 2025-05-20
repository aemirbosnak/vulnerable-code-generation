//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_STACK 1000

// Node structure for key-value pair
struct node{
  char key[50];
  char value[200];
};

// Stack structure used for nested JSON parsing
struct stack{
  int top;
  int size;
  char* arr[MAX_STACK];
};

// Function to check if a string is a number or not
int is_number(char* str){
  int len = strlen(str);
  for(int i=0;i<len;i++){
    if(!isdigit(str[i])){
      return 0;
    }
  }
  return 1;
}

// Function to create a new node
struct node* create_node(char* str1, char* str2){
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  strcpy(new_node->key, str1);
  strcpy(new_node->value, str2);
  return new_node;
}

// Function to trim leading and trailing whitespaces from a string
char *trim(char *str)
{
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

// Function to push an element onto stack
void push(struct stack* st, char* str){
  if(st->top == st->size-1){
    printf("Stack overflow!\n");
    return;
  }
  st->top++;
  st->arr[st->top] = (char*) malloc(sizeof(char)*50);
  strcpy(st->arr[st->top], str);
}

// Function to pop an element from stack
char* pop(struct stack* st){
  if(st->top == -1){
    printf("Stack underflow!\n");
    return NULL;
  }
  char* str = st->arr[st->top];
  st->top--;
  return str;
}

// Main function to parse JSON string
void parse_json(char* str, struct node* root){
  int i=1, root_flag = 1;
  int len = strlen(str);
  int is_value=0, is_object=0, is_array=0;
  int obj_count=0, arr_count=0;
  struct stack* st = (struct stack*) malloc(sizeof(struct stack));
  st->top = -1;
  st->size = MAX_STACK;
  while(i<len-1){
    char* key = (char*) malloc(sizeof(char)*50);
    char* value = (char*) malloc(sizeof(char)*200);
    char* curr_char = (char*) malloc(sizeof(char)*2);
    if(is_value){
      if(str[i] == '\"'){
        strcpy(value, "");
        i++;
        while(str[i] != '\"'){
          strcpy(curr_char, "");
          strncat(curr_char, &str[i], 1);
          strcat(value, curr_char);
          i++;
        }
        is_value=0;
      }
      else if(str[i] == '-' || isdigit(str[i])){
        strcpy(value, "");
        while(str[i] != ',' && str[i] != '}' && str[i] != ']'){
          strcpy(curr_char, "");
          strncat(curr_char, &str[i], 1);
          strcat(value, curr_char);
          i++;
        }
        is_value=0;
      }
      else if(str[i] == 't'){
        strcpy(value, "true");
        i+=3;
        is_value=0;
      }
      else if(str[i] == 'f'){
        strcpy(value, "false");
        i+=4;
        is_value=0;
      }
      else if(str[i] == 'n'){
        strcpy(value, "null");
        i+=3;
        is_value=0;
      }
    }
    else if(is_object){
      if(str[i] == '{'){
        obj_count++;
        push(st, "{");
      }
      else if(str[i] == '\"'){
        strcpy(key, "");
        i++;
        while(str[i] != '\"'){
          strcpy(curr_char, "");
          strncat(curr_char, &str[i], 1);
          strcat(key, curr_char);
          i++;
        }
      }
      else if(str[i] == ':'){
        is_value=1;
      }
      else if(str[i] == ','){
        root_flag=0;
      }
      else if(str[i] == '}'){
        obj_count--;
        while(strcmp(st->arr[st->top], "{") != 0){
          pop(st);
        }
        pop(st);
        if(obj_count == 0){
          is_object=0;
        }
      }
    }
    else if(is_array){
      if(str[i] == '['){
        arr_count++;
        push(st, "[");
      }
      else if(str[i] == ']'){
        arr_count--;
        while(strcmp(st->arr[st->top], "[") != 0){
          pop(st);
        }
        pop(st);
        if(arr_count == 0){
          is_array=0;
        }
      }
    }
    else{
      if(str[i] == '{'){
        is_object=1;
        root_flag=1;
        push(st, "{");
        if(root_flag){
          strcpy(root->key, "");
          strcpy(root->value, "");
          root_flag=0;
        }
        else{
          struct node* new_node = create_node("", "");
          strcpy(value, "");
          strcat(value, "{");
          push(st, "{");
          i++;
          parse_json(str+i, new_node);
          i+=strlen(new_node->value)+2;
          strcat(value, new_node->value);
          strcat(value, "}");
          strcpy(new_node->value, value);
          new_node->key[strlen(new_node->key)-1] = '\0';
          strcpy(key, new_node->key);
          strcpy(value, new_node->value);
          free(new_node);
        }
      }
      else if(str[i] == '['){
        is_array=1;
        root_flag=1;
        push(st, "[");
        if(root_flag){
          strcpy(root->key, "");
          strcpy(root->value, "");
          root_flag=0;
        }
        else{
          struct node* new_node = create_node("", "");
          strcpy(value, "");
          strcat(value, "[");
          push(st, "[");
          i++;
          parse_json(str+i, new_node);
          i+=strlen(new_node->value)+2;
          strcat(value, new_node->value);
          strcat(value, "]");
          strcpy(new_node->value, value);
          new_node->key[strlen(new_node->key)-1] = '\0';
          strcpy(key, new_node->key);
          strcpy(value, new_node->value);
          free(new_node);
        }
      }
      else if(str[i] == '\"'){
        strcpy(key, "");
        i++;
        while(str[i] != '\"'){
          strcpy(curr_char, "");
          strncat(curr_char, &str[i], 1);
          strcat(key, curr_char);
          i++;
        }
      }
      else if(str[i] == ':'){
        is_value=1;
      }
      else if(str[i] == ','){
        root->key[strlen(root->key)-1] = '\0';
        root->value[strlen(root->value)-1] = '\0';
        struct node* new_node = create_node(trim(root->key), trim(root->value));
        strcpy(key, "");
        strcpy(value, "");
        root_flag=0;
      }
      else if(str[i] == '}'){
        root->key[strlen(root->key)-1] = '\0';
        root->value[strlen(root->value)-1] = '\0';
        struct node* new_node = create_node(trim(root->key), trim(root->value));
        root_flag=1;
        root->key[0] = '\0';
        root->value[0] = '\0';
      }
    }
    i++;
    free(key);
    free(value);
    free(curr_char);
  }
}

int main(){
  char* json_string = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
  struct node* root = create_node("", "");
  parse_json(json_string, root);
  printf("Key: %s, Value: %s\n", root->key, root->value);
  return 0;
}