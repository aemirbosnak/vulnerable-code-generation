//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  system("clear");
  srand(time(NULL));
  int vote_id = rand() % 100000;
  char username[20];
  printf("Enter your username: ");
  scanf("%s", username);

  FILE *fp = fopen("votes.txt", "a");
  fprintf(fp, "%s, %d\n", username, vote_id);
  fclose(fp);

  char vote_choice[20];
  printf("Enter your vote choice: ");
  scanf("%s", vote_choice);

  fp = fopen("votes.txt", "r");
  char line[1024];
  int i = 0;
  while (fgets(line, 1024, fp) != NULL) {
    char *username_p = strstr(line, username);
    char *vote_choice_p = strstr(line, vote_choice);
    if (username_p && vote_choice_p) {
      i++;
    }
  }
  fclose(fp);

  if (i > 1) {
    printf("Error: You have already voted.");
  } else {
    fp = fopen("candidates.txt", "r");
    char candidate_name[20];
    int candidate_id = 0;
    while (fscanf(fp, "%s, %d\n", candidate_name, &candidate_id) != EOF) {
      if (strcmp(candidate_name, vote_choice) == 0) {
        candidate_id++;
      }
    }
    fclose(fp);

    fp = fopen("votes.txt", "a");
    fprintf(fp, "%s, %d\n", username, candidate_id);
    fclose(fp);

    printf("Thank you for voting! Your vote has been cast.");
  }

  return 0;
}