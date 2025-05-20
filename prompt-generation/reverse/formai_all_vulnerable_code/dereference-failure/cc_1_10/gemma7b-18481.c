//Gemma-7B DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sys_admin(char *username, char *action) {
  FILE *fp;
  char buff[1024];

  fp = fopen("/etc/passwd", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }

  while (fgets(buff, 1024, fp) != NULL) {
    char *user = strchr(buff, ":") + 1;
    if (strcmp(user, username) == 0) {
      if (strcmp(action, "modify") == 0) {
        printf("Enter new password:");
        scanf("%s", buff);
        fp = fopen("/etc/passwd", "w");
        fprintf(fp, "%s:%s:%s\n", user, buff, "x");
        fclose(fp);
      } else if (strcmp(action, "delete") == 0) {
        fp = fopen("/etc/passwd", "w");
        char *line = strstr(buff, user);
        line = strchr(line, "\n");
        line = NULL;
        fprintf(fp, "%s\n", line);
        fclose(fp);
      }
    }
  }

  fclose(fp);
}

int main() {
  char username[256];
  char action[256];

  printf("Enter username:");
  scanf("%s", username);

  printf("Enter action (modify/delete):");
  scanf("%s", action);

  sys_admin(username, action);

  return 0;
}