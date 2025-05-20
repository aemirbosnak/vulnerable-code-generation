//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a dynamic menu
void print_menu(int level, char* menu[][5]) {
  if (level == 0) {
    printf("Welcome to the Dynamic Menu!\n");
    return;
  }

  // Print the menu header
  printf("Level %d: ", level);

  // Print the menu items
  for (int i = 0; i < 5; i++) {
    if (menu[level][i] != NULL) {
      printf("%s", menu[level][i]);
      if (strcmp(menu[level][i], "Exit") != 0) {
        // Recursively print the sub-menu
        print_menu(level - 1, menu[level][i + 1]);
      }
    }
  }
}

// Function to select a menu item
int select_item(int level, char* menu[][5]) {
  int choice;

  // Print the menu and wait for user input
  print_menu(level, menu);
  printf("Enter your choice (1-%d): ", level);
  scanf("%d", &choice);

  // Return the selected item
  return choice;
}

int main() {
  // Define the menu
  char* menu[5][5] = {
    {"File", "New", "Open", "Save", "Exit"},
    {"Edit", "Undo", "Redo", "Cut", "Copy", "Paste"},
    {"View", "Full Screen", "Normal", "Hide", "Show"},
    {"Tools", "Calculator", "Converter", "Password", "Settings"},
    {"Help", "About", "Documentation", "Feedback", "Support"}
  };

  // Recursively print the menu
  print_menu(5, menu);

  // Select a menu item
  int choice = select_item(5, menu);

  // Handle the user's selection
  switch (choice) {
    case 1:
      printf("You selected File > New.\n");
      break;
    case 2:
      printf("You selected Edit > Undo.\n");
      break;
    case 3:
      printf("You selected View > Full Screen.\n");
      break;
    case 4:
      printf("You selected Tools > Calculator.\n");
      break;
    case 5:
      printf("You selected Help > About.\n");
      break;
    default:
      printf("Invalid choice.\n");
      break;
  }

  return 0;
}