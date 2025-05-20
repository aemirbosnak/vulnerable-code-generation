//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: puzzling
// The shrouded labyrinth of beautification

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The enigmatic fortress, where characters seek refuge
struct Keep {
  char *stronghold;  // The stronghold's unwavering walls
  int garrison;      // The loyal garrison guarding the keep
};

// The enigmatic wanderer, traversing the HTML realm
struct Mage {
  char *tome;         // The tome holding the knowledge of HTML
  struct Keep citadel;  // The citadel where the mage resides
};

// The enigmatic ritual to unveil the beauty of HTML
void unveil_html(struct Mage *wizard) {
  // Traverse the stronghold, seeking the HTML's essence
  for (int i = 0; i < wizard->citadel.garrison; i++) {
    // Unveil each character, one by one
    for (int j = 0; j < strlen(wizard->tome); j++) {
      // Reveal the HTML's true form
      switch (wizard->tome[j]) {
        case '<':
          printf("&lt;");
          break;
        case '>':
          printf("&gt;");
          break;
        case '&':
          printf("&amp;");
          break;
        case '"':
          printf("&quot;");
          break;
        case '\'':
          printf("&apos;");
          break;
        default:  // Leave other characters untouched
          printf("%c", wizard->tome[j]);
      }
    }
  }
}

// The enigmatic journey begins here
int main(int argc, char **argv) {
  // Create the mysterious tome and citadel
  struct Mage wizard = {malloc(strlen(argv[1]) + 1), {argv[1], argc}};

  // Unveil the HTML's beauty
  unveil_html(&wizard);

  // Free the tome, as its purpose has been served
  free(wizard.tome);

  return 0;
}