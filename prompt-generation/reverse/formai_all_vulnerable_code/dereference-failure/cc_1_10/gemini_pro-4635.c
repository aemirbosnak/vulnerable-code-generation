//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum States {
  Typing,
  Measuring,
  Outputting
};

struct Test {
  char *text;
  int length;
  int start;
  int end;
  int errors;
  int correct;
  int start_time;
  int end_time;
  int elapsed_time;
};

struct Test* makeTest(char *text) {
  struct Test *test = malloc(sizeof(struct Test));
  test->text = text;
  test->length = strlen(text);
  test->start = 0;
  test->end = test->length;
  test->errors = 0;
  test->correct = 0;
  test->start_time = time(NULL);
  test->end_time = 0;
  test->elapsed_time = 0;
  return test;
}

void displayTest(struct Test *test) {
  printf("==========================================");
  printf("\nTest Text: %s", test->text);
  printf("\nLength: %d", test->length);
  printf("\nStart Time: %d", test->start_time);
  printf("\nEnd Time: %d", test->end_time);
  printf("\nElapsed Time: %d", test->elapsed_time);
  printf("\nErrors: %d", test->errors);
  printf("\nCorrect: %d", test->correct);
  printf("\n==========================================");
}

void startTest(struct Test *test) {
  test->start_time = time(NULL);
}

void endTest(struct Test *test) {
  test->end_time = time(NULL);
  test->elapsed_time = test->end_time - test->start_time;
}

int calculateErrors(struct Test *test) {
  int i;
  for (i = 0; i < test->length; i++) {
    if (test->text[i] != test->text[i]) {
      test->errors++;
    }
  }
  return test->errors;
}

int calculateCorrect(struct Test *test) {
  int i;
  for (i = 0; i < test->length; i++) {
    if (test->text[i] == test->text[i]) {
      test->correct++;
    }
  }
  return test->correct;
}

int main() {
  struct Test *test = makeTest("Hello World!");
  startTest(test);
  endTest(test);
  calculateErrors(test);
  calculateCorrect(test);
  displayTest(test);
  return 0;
}