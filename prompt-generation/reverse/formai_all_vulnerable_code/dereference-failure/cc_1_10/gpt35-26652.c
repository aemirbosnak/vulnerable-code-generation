//FormAI DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  char *description;
  void (*functionPointer)();
} Plugin;

Plugin *new_plugin(char *name, char *description, void (*functionPointer)()) {
  Plugin *plugin = (Plugin*) malloc(sizeof(Plugin));
  plugin->name = name;
  plugin->description = description;
  plugin->functionPointer = functionPointer;
  return plugin;
}

void hello_world() {
  printf("Hello, world!\n");
}

void greet_user() {
  char username[20];
  printf("Please enter your name: ");
  scanf("%s", username);
  printf("Hello, %s!\n", username);
}

void print_menu(Plugin **plugins, int num_plugins) {
  printf("Available Plugins:\n");
  for (int i = 0; i < num_plugins; i++) {
    printf("%d. %s - %s\n", i+1, plugins[i]->name, plugins[i]->description);
  }
  printf("0. Quit\n");
}

int main() {
  Plugin *helloPlugin = new_plugin("Hello World", "Prints 'Hello, world!'", hello_world);
  Plugin *greetingPlugin = new_plugin("Greet User", "Asks user for their name and greets them", greet_user);
  Plugin *plugins[] = {helloPlugin, greetingPlugin};
  int num_plugins = sizeof(plugins)/sizeof(Plugin*);
  int choice = -1;
  while (choice != 0) {
    print_menu(plugins, num_plugins);
    printf("Please choose a plugin (0-%d): ", num_plugins);
    scanf("%d", &choice);
    if (choice >= 1 && choice <= num_plugins) {
      // Run the selected plugin's function
      plugins[choice-1]->functionPointer();
    } else if (choice != 0) {
      printf("Invalid choice. Please try again.\n");
    }
  }
  return 0;
}