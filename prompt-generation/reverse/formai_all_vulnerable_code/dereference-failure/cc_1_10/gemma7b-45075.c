//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define SERVER_PORT 8080

char **g_data = NULL;
int g_data_size = 0;

void update_data() {
  FILE *fp = fopen("/proc/meminfo", "r");
  if (fp) {
    char line[1024];
    fgets(line, sizeof(line), fp);
    fclose(fp);

    char **words = NULL;
    int num_words = 0;
    char *p = line;
    while (p) {
      char *word = strchr(p, ' ');
      if (word) {
        words = realloc(words, (num_words + 1) * sizeof(char *));
        words[num_words++] = strdup(p);
        p = word + 1;
      } else {
        words = realloc(words, (num_words + 1) * sizeof(char *));
        words[num_words++] = strdup(p);
        p = NULL;
      }
    }

    if (g_data) {
      free(g_data);
    }
    g_data = words;
    g_data_size = num_words;
  }
}

int main() {
  update_data();

  for (int i = 0; i < g_data_size; i++) {
    printf("%s\n", g_data[i]);
  }

  sleep(1);
  return 0;
}