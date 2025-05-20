//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the periodic table as a 2D array of strings
const char *periodic_table[][18] = {
  {"H", "He"},
  {"Li", "Be", "B", "C", "N", "O", "F", "Ne"},
  {"Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar"},
  {"K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr"},
  {"Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"},
  {"Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn"},
  {"Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lw", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"}
};

// Define the number of rows and columns in the periodic table
const int num_rows = 7;
const int num_cols = 18;

// Define the maximum length of a element symbol
const int max_symbol_length = 2;

// Define the input buffer size
const int input_buffer_size = 256;

// Define the number of questions to ask
const int num_questions = 10;

// Define the function to get a random number between two numbers
int get_random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Define the function to get a random element from the periodic table
const char *get_random_element() {
  int row = get_random_number(0, num_rows - 1);
  int col = get_random_number(0, num_cols - 1);
  return periodic_table[row][col];
}

// Define the function to ask a question
void ask_question(const char *element) {
  printf("What is the symbol for the element %s?\n", element);
}

// Define the function to get the user's answer
char *get_user_answer() {
  char *buffer = malloc(input_buffer_size);
  fgets(buffer, input_buffer_size, stdin);
  buffer[strcspn(buffer, "\n")] = 0; // Remove the newline character
  return buffer;
}

// Define the function to check if the user's answer is correct
int is_correct_answer(const char *element, const char *answer) {
  return strcmp(element, answer) == 0;
}

// Define the main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Ask the user questions
  for (int i = 0; i < num_questions; i++) {
    const char *element = get_random_element();
    ask_question(element);
    char *answer = get_user_answer();
    if (is_correct_answer(element, answer)) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The correct answer is %s.\n", element);
    }
    free(answer);
  }

  return 0;
}