//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_ANSWER_LEN 2

typedef struct element {
  int atomic_no;
  char symbol[3];
  char name[MAX_NAME_LEN];
  int group;
  char period[3];
} Element;

void populate_elements(Element *elements, int size) {
  FILE *fp;
  fp = fopen("periodic_table.txt", "r");

  if (fp == NULL) {
    printf("Error opening file");
    exit(1);
  }

  int i = 0;
  char line[100];

  while (fgets(line, sizeof(line), fp)) {
    sscanf(line, "%d,%[^,],%[^,],%d,%s", &elements[i].atomic_no, 
           elements[i].symbol, elements[i].name,
           &elements[i].group, elements[i].period);
    i++;
  }

  fclose(fp);
}

void shuffle_array(int *array, int size) {
  int temp, random;

  for (int i = size - 1; i > 0; i--) {
    random = rand() % (i + 1);
    temp = array[i];
    array[i] = array[random];
    array[random] = temp;
  }
}

void quiz(Element *elements, int size, int num_questions) {
  int score = 0;
  int *question_index = malloc(num_questions * sizeof(int));

  for (int i = 0; i < num_questions; i++) {
    question_index[i] = i;
  }
  
  shuffle_array(question_index, num_questions);

  printf("Welcome to the Periodic Table Quiz!\n\n");
  printf("You will be asked %d questions.\n\n", num_questions);

  for (int i = 0; i < num_questions; i++) {
    Element current_element = elements[question_index[i]];

    printf("Question %d:\n", i + 1);
    printf("What is the symbol for %s?\n", current_element.name);

    char answer[MAX_ANSWER_LEN];
    scanf("%s", answer);

    if (strcmp(answer, current_element.symbol) == 0) {
      printf("Correct!\n\n");
      score++;
    } else {
      printf("Incorrect. The correct answer was %s.\n\n",
             current_element.symbol);
    }
  }

  printf("Quiz complete! You got %d out of %d questions correct!\n",
         score, num_questions);
  free(question_index);
}

int main() {
  srand(time(0));
  int num_questions = 10;
  int size = 118; // number of elements in periodic table

  Element *elements = malloc(size * sizeof(Element));
  populate_elements(elements, size);

  quiz(elements, size, num_questions);

  free(elements);
  return 0;
}