//FormAI DATASET v1.0 Category: Browser Plugin ; Style: accurate
// Unique C Browser Plugin Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Declare global variables
int numClicks = 0;
bool isActivated = false;

// Define the plugin structure
struct Plugin {
   char *name;
   char *description;
   bool (*activate)(void);
   void (*deactivate)(void);
   void (*click)(void);
};

// Define the activate method for the plugin
bool activatePlugin(void) {
   if (!isActivated) {
      isActivated = true;
      printf("Plugin activated!\n");
   } else {
      printf("Plugin already activated!\n");
   }
   return isActivated;
}

// Define the deactivate method for the plugin
void deactivatePlugin(void) {
   if (isActivated) {
      isActivated = false;
      printf("Plugin deactivated!\n");
   } else {
      printf("Plugin already deactivated!\n");
   }
}

// Define the click method for the plugin
void clickPlugin(void) {
   if (isActivated) {
      numClicks++;
      printf("Plugin clicked %d times!\n", numClicks);
   } else {
      printf("Plugin not activated, cannot be clicked!\n");
   }
}

// Define the main function
int main(void) {
   // Initialize the plugin structure
   struct Plugin myPlugin;
   myPlugin.name = "My Plugin";
   myPlugin.description = "A simple browser plugin";
   myPlugin.activate = activatePlugin;
   myPlugin.deactivate = deactivatePlugin;
   myPlugin.click = clickPlugin;

   // Test the plugin
   assert(myPlugin.activate() == true);
   assert(myPlugin.activate() == false);
   myPlugin.click();
   assert(numClicks == 0);
   myPlugin.activate();
   myPlugin.click();
   assert(numClicks == 1);
   myPlugin.click();
   assert(numClicks == 2);
   myPlugin.deactivate();
   myPlugin.click();
   assert(numClicks == 2);

   return 0;
}