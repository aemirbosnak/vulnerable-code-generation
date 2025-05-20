//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Create a struct to store the questions and answers
typedef struct {
  char question[100];
  char answer[100];
} Question;

// Create an array of questions
Question questions[] = {
  {"What is the capital of France?", "Paris"},
  {"What is the largest country in the world?", "Russia"},
  {"What is the highest mountain in the world?", "Mount Everest"},
  {"What is the most popular programming language?", "Python"},
  {"What is the name of the operating system used by Apple computers?", "macOS"}
};

// Create a function to print the questions and answers
void printQuestions() {
  // Loop through the array of questions
  for (int i = 0; i < 5; i++) {
    // Print the question
    printf("%s\n", questions[i].question);

    // Print the answer
    printf("  %s\n", questions[i].answer);
  }
}

// Create a function to get the user's answers
void getAnswers(char answers[]) {
  // Loop through the array of questions
  for (int i = 0; i < 5; i++) {
    // Get the user's answer
    printf("What is your answer to question %d? ", i + 1);
    scanf("%s", answers[i]);
  }
}

// Create a function to check the user's answers
int checkAnswers(char answers[]) {
  // Loop through the array of questions
  int correct = 0;
  for (int i = 0; i < 5; i++) {
    // Check if the user's answer is correct
    if (strcmp(answers[i], questions[i].answer) == 0) {
      correct++;
    }
  }

  // Return the number of correct answers
  return correct;
}

// Create a function to print the results
void printResults(int correct) {
  // Print the number of correct answers
  printf("You got %d out of 5 questions correct!\n", correct);

  // Print a message based on the number of correct answers
  if (correct == 5) {
    printf("Congratulations! You're a genius!\n");
  } else if (correct >= 3) {
    printf("Good job! You're on the right track.\n");
  } else {
    printf("Don't worry, you can do better next time.\n");
  }
}

// Main function
int main() {
  // Print the questions and answers
  printQuestions();

  // Get the user's answers
  char answers[5];
  getAnswers(answers);

  // Check the user's answers
  int correct = checkAnswers(answers);

  // Print the results
  printResults(correct);

  return 0;
}