//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_AGE 128
#define AI_NAME "HAL 9000"

enum gender {
  MALE,
  FEMALE,
  OTHER,
};

struct human {
  char *name;
  int age;
  int height; // in centimeters
  float weight; // in kilograms
  enum gender gender;
  struct human *mother;
  struct human *father;
};

// Initialize a human struct with provided parameters.
struct human *new_human(const char *name, int age, int height, float weight,
                       enum gender gender, struct human *mother,
                       struct human *father) {
  struct human *h = (struct human *)malloc(sizeof(struct human));
  h->name = name;
  h->age = age;
  h->height = height;
  h->weight = weight;
  h->gender = gender;
  h->mother = mother;
  h->father = father;
  return h;
}

// Destroy a human struct and release its memory.
void destroy_human(struct human *h) {
  free(h->name);
  free(h);
}

// Simulates the passage of one year and increases the age of the human.
void age_human(struct human *h) {
  h->age++;
}

// Calculates the life expectancy based on the human's age and gender.
int life_expectancy(struct human *h) {
  int expectancy = 0;
  if (h->gender == MALE) {
    expectancy = 69;
    expectancy -= (h->age - 50) / 4;
    if (h->height > 185) expectancy += 2;
    if (h->weight < 60) expectancy += 1;
  } else if (h->gender == MALE) {
    expectancy = 75;
    expectancy -= (h->age - 50) / 4;
    if (h->height > 170) expectancy += 2;
    if (h->weight < 50) expectancy += 1;
  } else {
    expectancy = 70;
    expectancy -= (h->age - 50) / 4;
    if (h->height > 165) expectancy += 2;
    if (h->weight < 55) expectancy += 1;
  }
  return expectancy;
}

int main() {
  // Initialize the AI chatbot.
  printf("Welcome to the AI chatbot. My name is %s.\n", AI_NAME);

  // Create a human and set their initial attributes.
  struct human *h = new_human("John Doe", 30, 180, 80, MALE, NULL, NULL);

  // Start the conversation.
  while (1) {
    // Get the user's input.
    char input[1024];
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Process the user's input and generate a response.
    char response[1024];
    if (sscanf(input, "age %d", &h->age) == 1) {
      sprintf(response, "Your age is now %d.\n", h->age);
    } else if (sscanf(input, "height %d", &h->height) == 1) {
      sprintf(response, "Your height is now %d cm.\n", h->height);
    } else if (sscanf(input, "weight %f", &h->weight) == 1) {
      sprintf(response, "Your weight is now %.2f kg.\n", h->weight);
    } else if (sscanf(input, "gender %d", (int *)&h->gender) == 1) {
      sprintf(response, "Your gender is now %s.\n",
              h->gender == MALE ? "male" : h->gender == FEMALE ? "female"
                                                           : "other");
    } else if (sscanf(input, "expectancy") == 1) {
      int expectancy = life_expectancy(h);
      sprintf(response, "Your life expectancy is %d years.\n", expectancy);
    } else if (sscanf(input, "age %d", &h->age) == 1) {
      sprintf(response, "Your age is now %d.\n", h->age);
    } else if (strcmp(input, "exit") == 0) {
      sprintf(response, "Goodbye.\n");
      break;
    } else {
      sprintf(response,
              "I'm sorry, I didn't understand your input.\nValid commands are: "
              "age, height, weight, gender, expectancy, exit.\n");
    }

    // Print the response to the user.
    printf("%s", response);
  }

  // Destroy the human struct and exit the program.
  destroy_human(h);
  return 0;
}