//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Question {
  char question[MAX];
  int answer;
  struct Question* next;
} Question;

void shuffle(Question** head) {
  for (int i = 0; i < MAX; i++) {
    Question* ptr1 = (*head)->next;
    Question* ptr2 = rand() % MAX;

    char temp[MAX];
    strcpy(temp, ptr1->question);
    strcpy(ptr1->question, ptr2->question);
    strcpy(ptr2->question, temp);

    int temp_ans = ptr1->answer;
    ptr1->answer = ptr2->answer;
    ptr2->answer = temp_ans;
  }
}

int main() {
  Question* head = (Question*)malloc(sizeof(Question));
  head->question[0] = 'Q';
  head->question[1] = 'W';
  head->question[2] = 'E';
  head->answer = 1;
  head->next = NULL;

  Question* second = (Question*)malloc(sizeof(Question));
  second->question[0] = 'R';
  second->question[1] = 'T';
  second->question[2] = 'Y';
  second->answer = 2;
  second->next = NULL;

  Question* third = (Question*)malloc(sizeof(Question));
  third->question[0] = 'A';
  third->question[1] = 'S';
  third->question[2] = 'D';
  third->answer = 3;
  third->next = NULL;

  head->next = second;
  second->next = third;

  shuffle(&head);

  for (Question* current = head; current; current = current->next) {
    printf("%s\n", current->question);
    printf("Answer: %d\n", current->answer);
  }

  return 0;
}