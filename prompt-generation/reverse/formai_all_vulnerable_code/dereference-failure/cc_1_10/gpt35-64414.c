//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

typedef struct element{
  char type;
  int value;
  struct element *next;
} Element;

typedef struct node{
  char name[20];
  Element *elements;
  struct node *next;
} Node;

void add_element(char type, int value, Node *node){
  Element *new_element = (Element*) malloc(sizeof(Element));
  new_element->type = type;
  new_element->value = value;
  new_element->next = node->elements;
  node->elements = new_element;
}

void print_elements(Element *element){
  if(element == NULL) return;
  
  if(element->type == 'R') printf("Resistance%10d\n", element->value);
  if(element->type == 'C') printf("Capacitance%10d\n", element->value);
  if(element->type == 'I') printf("Current Source%5d\n", element->value);
  if(element->type == 'V') printf("Voltage Source%5d\n", element->value);

  print_elements(element->next);
}

void print_nodes(Node *node){
  printf("\n%s has the following elements:\n", node->name);
  print_elements(node->elements);
}

int main(){
  Node *ground = (Node*) malloc(sizeof(Node));
  Node *node1 = (Node*) malloc(sizeof(Node));
  Node *node2 = (Node*) malloc(sizeof(Node));

  sprintf(ground->name, "Ground");
  sprintf(node1->name, "Node 1");
  sprintf(node2->name, "Node 2");

  add_element('V', 10, node1);
  add_element('R', 100, node1);
  add_element('C', 50, node1);

  add_element('R', 50, node2);
  add_element('I', 20, node2);

  print_nodes(ground);
  print_nodes(node1);
  print_nodes(node2);

  return 0;
}