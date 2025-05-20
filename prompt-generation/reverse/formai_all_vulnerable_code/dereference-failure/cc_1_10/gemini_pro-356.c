//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: artistic
// A kaleidoscope of code, a symphony of bits,
// Where democracy's voice whispers and transmits.
// Each ballot a brushstroke, painting the canvas,
// A tapestry of choices, where futures amass.

#include <stdio.h>
#include <stdlib.h>

// The candidates, each with a vibrant hue,
// Their policies, a spectrum for voters to pursue.
typedef struct candidate {
  char *name;
  int votes;
} candidate;

// The ballot box, where secrets reside,
// A vessel of aspirations, where dreams abide.
typedef struct ballotbox {
  candidate *candidates;
  int num_candidates;
} ballotbox;

// The artistry begins, a brushstroke of code,
// A dance of algorithms, where decisions unfold.
int vote(ballotbox *box, char *candidate_name) {
  for (int i = 0; i < box->num_candidates; i++) {
    if (strcmp(box->candidates[i].name, candidate_name) == 0) {
      box->candidates[i].votes++;
      return 1;
    }
  }
  return 0;
}

// The results, a crescendo of numbers,
// A symphony of preferences, where the victor thunders.
void count_votes(ballotbox *box) {
  printf("The electoral tapestry, vibrant and grand,\n");
  for (int i = 0; i < box->num_candidates; i++) {
    printf("%s: %d votes\n", box->candidates[i].name, box->candidates[i].votes);
  }
}

// A blank canvas awaits, ready for the strokes,
// A new election, where dreams and hopes invoke.
ballotbox *create_ballotbox(candidate *candidates, int num_candidates) {
  ballotbox *box = malloc(sizeof(ballotbox));
  box->candidates = candidates;
  box->num_candidates = num_candidates;
  return box;
}

// A masterpiece complete, the verdict is cast,
// A reflection of the will, where futures are amassed.
int main() {
  // The candidates, each a vibrant shade,
  candidate candidates[] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Carol", 0},
    {"Dave", 0}
  };

  // The ballot box, a vessel of dreams,
  ballotbox *box = create_ballotbox(candidates, 4);

  // Votes dance in, shaping the electoral scene,
  vote(box, "Alice");
  vote(box, "Bob");
  vote(box, "Carol");
  vote(box, "Dave");
  vote(box, "Alice");

  // The votes counted, a symphony of numbers,
  count_votes(box);

  return 0;
}