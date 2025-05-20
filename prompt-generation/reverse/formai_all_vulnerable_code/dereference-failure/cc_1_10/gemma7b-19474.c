//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the module for student information
void student_info(char *name, int roll_no, float marks)
{
  printf("Name: %s\n", name);
  printf("Roll No: %d\n", roll_no);
  printf("Marks: %.2f\n", marks);
}

// Define the module for question paper
void question_paper(int num_questions, char **questions)
{
  for (int i = 0; i < num_questions; i++)
  {
    printf("%d. %s\n", i + 1, questions[i]);
  }
}

// Define the module for student answer
void student_answer(char **answers)
{
  for (int i = 0; i < 10; i++)
  {
    printf("Answer for Question %d: %s\n", i + 1, answers[i]);
  }
}

int main()
{
  char name[20];
  int roll_no;
  float marks;

  // Get student information
  printf("Enter your name: ");
  scanf("%s", name);

  printf("Enter your roll number: ");
  scanf("%d", &roll_no);

  printf("Enter your marks: ");
  scanf("%f", &marks);

  // Display student information
  student_info(name, roll_no, marks);

  int num_questions = 10;
  char **questions = (char **)malloc(num_questions * sizeof(char *));

  // Create question paper
  questions[0] = "What is the meaning of the word 'entrepreneur'?";
  questions[1] = "Explain the concept of polymorphism in OOP.";
  questions[2] = "Define the term 'software engineering'.";
  // ... Add more questions

  // Display question paper
  question_paper(num_questions, questions);

  char **answers = (char **)malloc(num_questions * sizeof(char *));

  // Get student answer
  printf("Enter your answers for each question: ");
  for (int i = 0; i < num_questions; i++)
  {
    answers[i] = malloc(200);
    scanf("%s", answers[i]);
  }

  // Display student answer
  student_answer(answers);

  return 0;
}