//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
  char *text;
  int len;
  int correct;
  int incorrect;
} Test;

Test *createTest(char *text) {
  Test *test = malloc(sizeof(Test));
  test->text = text;
  test->len = strlen(text);
  test->correct = 0;
  test->incorrect = 0;
  return test;
}

void freeTest(Test *test) {
  free(test->text);
  free(test);
}

void printTest(Test *test) {
  printf("Text: %s\n", test->text);
  printf("Length: %d\n", test->len);
  printf("Correct: %d\n", test->correct);
  printf("Incorrect: %d\n", test->incorrect);
}

void runTest(Test *test) {
  char input[test->len + 1];
  printf("Enter the text: ");
  scanf("%s", input);

  for (int i = 0; i < test->len; i++) {
    if (input[i] == test->text[i]) {
      test->correct++;
    } else {
      test->incorrect++;
    }
  }
}

int main() {
  srand(time(NULL));

  char *texts[] = {
    "The quick brown fox jumps over the lazy dog",
    "The rain in Spain falls mainly on the plain",
    "Now is the time for all good men to come to the aid of their country",
    "Four score and seven years ago our fathers brought forth on this continent a new nation",
    "We the People of the United States, in Order to form a more perfect Union",
  };

  int numTests = sizeof(texts) / sizeof(char *);

  Test **tests = malloc(sizeof(Test *) * numTests);
  for (int i = 0; i < numTests; i++) {
    tests[i] = createTest(texts[i]);
  }

  for (int i = 0; i < numTests; i++) {
    runTest(tests[i]);
    printTest(tests[i]);
    freeTest(tests[i]);
  }

  free(tests);

  return 0;
}