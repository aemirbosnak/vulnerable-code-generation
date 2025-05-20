//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store each question
typedef struct Question {
  char question[256];
  char options[4][64];
  int correct_option;
} Question;

// Array of questions
Question questions[] = {
  {
    "What is the capital of India?",
    {
      "New Delhi",
      "Mumbai",
      "Kolkata",
      "Chennai"
    },
    0
  },
  {
    "Who is the Prime Minister of India?",
    {
      "Narendra Modi",
      "Rahul Gandhi",
      "Sonia Gandhi",
      "Manmohan Singh"
    },
    0
  },
  {
    "What is the currency of India?",
    {
      "Rupee",
      "Dollar",
      "Euro",
      "Pound"
    },
    0
  }
};

// Function to display the questions and options
void display_questions(Question *questions, int num_questions) {
  for (int i = 0; i < num_questions; i++) {
    printf("Q%d: %s\n", i + 1, questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("  %d. %s\n", j + 1, questions[i].options[j]);
    }
  }
}

// Function to get user input
int get_user_input(int num_questions) {
  int *answers = malloc(sizeof(int) * num_questions);

  for (int i = 0; i < num_questions; i++) {
    printf("Enter your answer for Q%d: ", i + 1);
    scanf("%d", &answers[i]);
  }

  return answers;
}

// Function to check user answers
int check_user_answers(int *user_answers, Question *questions, int num_questions) {
  int score = 0;

  for (int i = 0; i < num_questions; i++) {
    if (user_answers[i] == questions[i].correct_option) {
      score++;
    }
  }

  return score;
}

// Main function
int main() {
  int num_questions = sizeof(questions) / sizeof(Question);

  display_questions(questions, num_questions);

  int *user_answers = get_user_input(num_questions);

  int score = check_user_answers(user_answers, questions, num_questions);

  printf("Your score is %d\n", score);

  return 0;
}