//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum score for the exam
#define MAX_SCORE 100

// Define the passing score for the exam
#define PASSING_SCORE 50

// Define the data structure for a question
typedef struct {
  char *question;
  char **answers;
  int num_answers;
  int correct_answer;
} Question;

// Define an array of questions
Question questions[] = {
  {
    "What is the capital of the United States?",
    (char *[]) {"New York City", "Los Angeles", "Washington, D.C.", "Chicago"},
    4,
    2
  },
  {
    "Who was the first president of the United States?",
    (char *[]) {"George Washington", "Abraham Lincoln", "Thomas Jefferson", "John Adams"},
    4,
    0
  },
  {
    "What is the largest ocean in the world?",
    (char *[]) {"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"},
    4,
    1
  },
  {
    "What is the highest mountain in the world?",
    (char *[]) {"Mount Everest", "K2", "Kangchenjunga", "Lhotse"},
    4,
    0
  },
  {
    "What is the longest river in the world?",
    (char *[]) {"Nile River", "Amazon River", "Yangtze River", "Mississippi River"},
    4,
    0
  },
  {
    "What is the population of the world?",
    (char *[]) {"7 billion", "8 billion", "9 billion", "10 billion"},
    4,
    1
  },
  {
    "What is the name of the current president of the United States?",
    (char *[]) {"Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush"},
    4,
    0
  },
  {
    "What is the name of the current prime minister of the United Kingdom?",
    (char *[]) {"Boris Johnson", "Theresa May", "David Cameron", "Gordon Brown"},
    4,
    0
  },
  {
    "What is the name of the current president of France?",
    (char *[]) {"Emmanuel Macron", "François Hollande", "Nicolas Sarkozy", "Jacques Chirac"},
    4,
    0
  },
  {
    "What is the name of the current chancellor of Germany?",
    (char *[]) {"Olaf Scholz", "Angela Merkel", "Gerhard Schröder", "Helmut Kohl"},
    4,
    0
  }
};

// Function to generate a random number between min and max
int random_range(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to shuffle an array of strings
void shuffle_array(char **array, int size) {
  for (int i = 0; i < size; i++) {
    int j = random_range(i, size - 1);
    char *temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

// Function to print a question and its answers
void print_question(Question question) {
  printf("%s\n", question.question);
  for (int i = 0; i < question.num_answers; i++) {
    printf("%d. %s\n", i + 1, question.answers[i]);
  }
}

// Function to get the user's answer to a question
int get_answer() {
  int answer;
  scanf("%d", &answer);
  return answer;
}

// Function to check if an answer is correct
int is_correct_answer(Question question, int answer) {
  return answer == question.correct_answer;
}

// Function to calculate the user's score
int calculate_score(int num_correct_answers) {
  return (num_correct_answers * MAX_SCORE) / NUM_QUESTIONS;
}

// Function to print the user's score
void print_score(int score) {
  printf("Your score is %d%%\n", score);
}

// Function to determine if the user passed the exam
int passed_exam(int score) {
  return score >= PASSING_SCORE;
}

// Function to print the pass/fail message
void print_pass_fail(int passed) {
  if (passed) {
    printf("Congratulations! You passed the exam.\n");
  } else {
    printf("Sorry, you failed the exam.\n");
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Shuffle the questions
  shuffle_array(questions, NUM_QUESTIONS);

  // Get the user's answers to the questions
  int num_correct_answers = 0;
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    print_question(questions[i]);
    int answer = get_answer();
    if (is_correct_answer(questions[i], answer)) {
      num_correct_answers++;
    }
  }

  // Calculate the user's score
  int score = calculate_score(num_correct_answers);

  // Print the user's score
  print_score(score);

  // Determine if the user passed the exam
  int passed = passed_exam(score);

  // Print the pass/fail message
  print_pass_fail(passed);

  return 0;
}