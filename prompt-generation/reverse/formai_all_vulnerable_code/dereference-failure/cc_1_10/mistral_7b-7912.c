//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
 char name[20];
 char symbol[3];
 int atomic_number;
 int group_number;
 int period;
 int shells;
} Element;

int main() {
 srand(time(NULL));
 int num_elements = 118;
 Element *elements = malloc(num_elements * sizeof(Element));

 for (int i = 0; i < num_elements; i++) {
 strcpy(elements[i].name, "ElementName");
 strcpy(elements[i].symbol, "Symb");
 elements[i].atomic_number = i + 1;
 elements[i].group_number = rand() % 18 + 1;
 elements[i].period = rand() % 7 + 1;
 elements[i].shells = rand() % 7 + 1;
 }

 int num_questions = 10;
 int num_correct = 0;

 for (int q = 0; q < num_questions; q++) {
 int i = rand() % num_elements;
 int j = rand() % num_elements;

 printf("Question %d:\n", q + 1);
 printf("Which element has atomic number %d and is in period %d?\n", elements[i].atomic_number, elements[i].period);
 printf("A) %s\n", elements[j].name);
 printf("B) %s\n", elements[i].name);
 printf("C) %s\n", elements[rand() % num_elements].name);
 printf("D) %s\n", elements[rand() % num_elements].name);

 char answer;
 scanf("%c", &answer);

 if (answer == 'A' && elements[i].group_number == elements[j].group_number) {
 num_correct++;
 }
 }

 printf("You got %d out of %d correct.\n", num_correct, num_questions);
 free(elements);
 return 0;
}