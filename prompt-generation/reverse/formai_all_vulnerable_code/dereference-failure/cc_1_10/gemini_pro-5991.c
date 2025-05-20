//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
// In the realm of yore, where knights and maidens roam,
// A code we craft, t'optimize and to gloam.

#include <stdio.h> // For valiant prints, we summon thee
#include <stdlib.h> // For valiant malloc, we decree

// A castle's keep, where data dwells so grand,
// With sentinels to guard, throughout the land.
typedef struct Castle {
  int numKnights; // The valiant knights, so fierce and bold
  int numArchers; // The archers keen, with arrows gold
  int numPeasants; // The peasants toil, the keep to hold
} Castle, *pCastle;

// A noble squire, to serve the lord with might,
// And optimize the keep, by day and night.
pCastle OptimizeKeep(pCastle keep) {
  // First, we trim the knights, if they be too stout,
  keep->numKnights = keep->numKnights > 10 ? 10 : keep->numKnights;
  // Then, archers keen, we number ten or less,
  keep->numArchers = keep->numArchers > 10 ? 10 : keep->numArchers;
  // And peasants fair, we limit to a score,
  keep->numPeasants = keep->numPeasants > 20 ? 20 : keep->numPeasants;
  // Thus, optimized, the keep shall stand secure,
  // A testament to wisdom, swift and sure.
  return keep;
}

// A monarch wise, to rule with gentle hand,
// And test the keep, with trials he has planned.
int main() {
  // A keep, so grand, we conjure with a spell,
  pCastle keep = malloc(sizeof(Castle));
  keep->numKnights = 15; // Knights aplenty, at their lord's command
  keep->numArchers = 12; // Archers sharp, with arrows keen in hand
  keep->numPeasants = 25; // Peasants loyal, tending to the land

  // The squire, so skilled, we call upon his might,
  // To optimize the keep, by day and night.
  pCastle optimized = OptimizeKeep(keep);
  // And now, the keep, optimized and strong,
  // Ready to withstand the trials that throng.

  // We print the numbers, with eloquence and grace,
  printf("Knights: %d, Archers: %d, Peasants: %d,\n",
         optimized->numKnights, optimized->numArchers, optimized->numPeasants);
  // A testament to code, both swift and bold,
  // A keep optimized, a tale to be told.

  // When all is done, we free the keep so grand,
  // And bid it farewell, with heart and hand.
  free(keep);
  return 0; // Thus, ends our tale, with honor bright,
  // A code optimized, a realm of light.
}