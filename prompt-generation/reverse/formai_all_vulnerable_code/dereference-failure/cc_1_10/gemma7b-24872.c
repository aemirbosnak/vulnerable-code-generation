//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERIOD 11
#define GROUP 17

typedef struct Element {
  char name[20];
  int atomicNumber;
  int massNumber;
  char symbol[2];
  char state;
  struct Element *next;
} Element;

Element *head = NULL;

void insertElement(char *name, int atomicNumber, int massNumber, char symbol, char state)
{
  Element *newElement = (Element *)malloc(sizeof(Element));
  strcpy(newElement->name, name);
  newElement->atomicNumber = atomicNumber;
  newElement->massNumber = massNumber;
  strcpy(newElement->symbol, symbol);
  newElement->state = state;
  newElement->next = NULL;

  if (head == NULL)
  {
    head = newElement;
  }
  else
  {
    Element *current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newElement;
  }
}

void printTable()
{
  Element *current = head;
  printf("<table>\n");
  printf("<thead>\n");
  printf("<tr>\n");
  printf("<th>Name</th>\n");
  printf("<th>Atomic Number</th>\n");
  printf("<th>Mass Number</th>\n");
  printf("<th>Symbol</th>\n");
  printf("<th>State</th>\n");
  printf("</tr>\n");
  printf("</thead>\n");
  printf("<tbody>\n");
  while (current)
  {
    printf("<tr>\n");
    printf("<td>%s</td>\n", current->name);
    printf("<td>%d</td>\n", current->atomicNumber);
    printf("<td>%d</td>\n", current->massNumber);
    printf("<td>%s</td>\n", current->symbol);
    printf("<td>%c</td>\n", current->state);
    printf("</tr>\n");
    current = current->next;
  }
  printf("</tbody>\n");
  printf("</table>\n");
}

int main()
{
  insertElement("Hydrogen", 1, 1, "H", 'G');
  insertElement("Helium", 2, 4, "He", 'G');
  insertElement("Lithium", 3, 6, "Li", 'S');
  insertElement("Sodium", 11, 23, "Na", 'S');
  insertElement("Potassium", 19, 39, "K", 'S');

  printTable();

  return 0;
}