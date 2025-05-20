//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAN_SIZE 10

struct PersonalFinancePlan {
  char name[20];
  int age;
  double income;
  double expenses;
  double savings;
  double investments;
  struct PersonalFinancePlan *next;
};

void createPersonalFinancePlan(struct PersonalFinancePlan **head) {
  *head = malloc(sizeof(struct PersonalFinancePlan));
  (*head)->name[0] = '\0';
  (*head)->age = 0;
  (*head)->income = 0.0;
  (*head)->expenses = 0.0;
  (*head)->savings = 0.0;
  (*head)->investments = 0.0;
  (*head)->next = NULL;
}

void addPersonalFinancePlan(struct PersonalFinancePlan **head, char *name, int age, double income, double expenses, double savings, double investments) {
  struct PersonalFinancePlan *newPlan = malloc(sizeof(struct PersonalFinancePlan));
  newPlan->name[0] = '\0';
  strcpy(newPlan->name, name);
  newPlan->age = age;
  newPlan->income = income;
  newPlan->expenses = expenses;
  newPlan->savings = savings;
  newPlan->investments = investments;
  newPlan->next = NULL;

  if (*head == NULL) {
    *head = newPlan;
  } else {
    (*head)->next = newPlan;
  }
}

int main() {
  struct PersonalFinancePlan *head = NULL;

  createPersonalFinancePlan(&head);
  addPersonalFinancePlan(&head, "John Doe", 25, 50000.0, 2000.0, 10000.0, 20000.0);
  addPersonalFinancePlan(&head, "Jane Doe", 30, 60000.0, 3000.0, 15000.0, 30000.0);

  struct PersonalFinancePlan *currentPlan = head;
  while (currentPlan) {
    printf("Name: %s\n", currentPlan->name);
    printf("Age: %d\n", currentPlan->age);
    printf("Income: %.2lf\n", currentPlan->income);
    printf("Expenses: %.2lf\n", currentPlan->expenses);
    printf("Savings: %.2lf\n", currentPlan->savings);
    printf("Investments: %.2lf\n", currentPlan->investments);
    printf("\n");
    currentPlan = currentPlan->next;
  }

  return 0;
}