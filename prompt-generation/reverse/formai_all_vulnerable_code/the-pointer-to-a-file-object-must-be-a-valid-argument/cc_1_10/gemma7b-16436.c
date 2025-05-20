//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMeta {
  char *name;
  char *value;
} CMeta;

CMeta **extract_c_metadata(FILE *fp)
{
  CMeta **meta_list = NULL;
  char buffer[MAX_BUFFER_SIZE];
  char *line = NULL;
  int line_num = 0;

  while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL)
  {
    line = strchr(buffer, ':');
    if (line)
    {
      char *name = strdup(buffer);
      char *value = strdup(line + 1);
      CMeta *meta = malloc(sizeof(CMeta));
      meta->name = name;
      meta->value = value;
      meta_list = realloc(meta_list, (line_num + 1) * sizeof(CMeta));
      meta_list[line_num++] = meta;
    }
  }

  return meta_list;
}

int main()
{
  FILE *fp = fopen("example.c", "r");
  CMeta **meta_list = extract_c_metadata(fp);

  for (int i = 0; meta_list[i] != NULL; i++)
  {
    printf("%s: %s\n", meta_list[i]->name, meta_list[i]->value);
  }

  fclose(fp);

  return 0;
}