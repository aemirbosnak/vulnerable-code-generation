//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char *name;
  int votes;
} Candidate;

Candidate *candidates;
int num_candidates;

void add_candidate(int id, char *name) {
  candidates = realloc(candidates, (num_candidates + 1) * sizeof(Candidate));
  candidates[num_candidates].id = id;
  candidates[num_candidates].name = strdup(name);
  candidates[num_candidates].votes = 0;
  num_candidates++;
}

void remove_candidate(int id) {
  int i;
  for (i = 0; i < num_candidates; i++) {
    if (candidates[i].id == id) {
      free(candidates[i].name);
      for (; i < num_candidates - 1; i++) {
        candidates[i] = candidates[i + 1];
      }
      num_candidates--;
      break;
    }
  }
}

void vote(int id) {
  int i;
  for (i = 0; i < num_candidates; i++) {
    if (candidates[i].id == id) {
      candidates[i].votes++;
      break;
    }
  }
}

void print_results() {
  int i;
  for (i = 0; i < num_candidates; i++) {
    printf("%d. %s: %d votes\n", candidates[i].id, candidates[i].name,
           candidates[i].votes);
  }
}

int main() {
  int choice;
  int id;
  char name[100];

  while (1) {
    printf("1. Add candidate\n");
    printf("2. Remove candidate\n");
    printf("3. Vote\n");
    printf("4. Print results\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter candidate ID: ");
        scanf("%d", &id);
        printf("Enter candidate name: ");
        scanf("%s", name);
        add_candidate(id, name);
        break;
      case 2:
        printf("Enter candidate ID to remove: ");
        scanf("%d", &id);
        remove_candidate(id);
        break;
      case 3:
        printf("Enter candidate ID to vote for: ");
        scanf("%d", &id);
        vote(id);
        break;
      case 4:
        print_results();
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}