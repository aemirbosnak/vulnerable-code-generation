//FormAI DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h> // to include standard input/output functions
#include <stdlib.h> // to include standard library functions
#include <string.h> // to include string handling functions

// defining the maximum number of questions and options
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

// function to print a humorous message
void funnyMessage() {
  printf("\nYou are now entering the mysterious world of online exams. Brace yourself, it's going to be a bumpy ride!\n");
}

// function to print a question and options
void printQuestion(char question[], char options[][MAX_OPTIONS]) {
  printf("%s\n", question);
  for(int i = 0; i < MAX_OPTIONS; i++) {
    printf("%d. %s\n", i+1, options[i]);
  }
}

int main() {
  // declaring variables
  int score = 0;
  char answer[MAX_OPTIONS];
  char questions[MAX_QUESTIONS][100] = { "What is the capital of France?", "What is the meaning of life?", "Why did the chicken cross the road?", "What came first, the chicken or the egg?", "Why do we park in a driveway and drive in a parkway?", "Why do round pizzas come in square boxes?", "Why do they call it a drive-through if you have to stop?", "What is the airspeed velocity of an unladen swallow?", "Why do we say 'heads up' when we should duck?", "Why do they sterilize needles for lethal injections?" };
  char answers[MAX_QUESTIONS][MAX_OPTIONS] = { "Paris", "42", "To get to the other side", "The egg", "Who knows?", "Because they haven't invented round boxes yet", "Because 'stop-and-go-through' doesn't have the same ring to it", "African or European?", "Good question", "Safety first!" };

  funnyMessage(); // calling the function to print a funny message

  // loop through all the questions
  for(int i = 0; i < MAX_QUESTIONS; i++) {
    char options[MAX_OPTIONS][MAX_OPTIONS] = { "A", "B", "C", "D" }; // declaring the options for each question
    printQuestion(questions[i], options); // calling the function to print the question and options
    printf("Enter your answer: ");
    scanf("%s", answer);

    // checking if the answer is correct
    if(strcmp(answer, answers[i]) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Wrong!\n");
    }
  }

  // printing the final score
  printf("Your final score is %d/%d\n", score, MAX_QUESTIONS);

  return 0; // ending the program
}