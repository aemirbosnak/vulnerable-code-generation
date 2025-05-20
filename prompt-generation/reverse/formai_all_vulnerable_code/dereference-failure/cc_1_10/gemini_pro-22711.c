//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ 1024
#define MAXTAGS 100

typedef struct {
  char *name;
  char *value;
} tag_t;

typedef struct {
  tag_t tags[MAXTAGS];
  int num_tags;
} xml_t;

xml_t *
parse_xml(char *buf)
{
  xml_t *xml;
  char *p, *q;
  int i;

  xml = malloc(sizeof(xml_t));
  if (xml == NULL)
    return NULL;

  xml->num_tags = 0;

  p = buf;
  while (*p != '\0') {
    if (*p == '<') {
      q = strchr(p, '>');
      if (q == NULL)
        break;

      tag_t *tag = &xml->tags[xml->num_tags++];
      tag->name = malloc(q - p + 1);
      if (tag->name == NULL)
        return NULL;
      strncpy(tag->name, p + 1, q - p - 1);
      tag->name[q - p - 1] = '\0';

      p = q + 1;
      if (*p == '/') {
        p++;
        continue;
      }

      i = 0;
      while (*p != '\0' && *p != '>' && i < BUFSZ - 1) {
        if (*p == '=') {
          q = strchr(p, '"');
          if (q == NULL)
            break;

          tag->value = malloc(q - p + 1);
          if (tag->value == NULL)
            return NULL;
          strncpy(tag->value, p + 1, q - p - 1);
          tag->value[q - p - 1] = '\0';

          p = q + 1;
          continue;
        }

        p++;
        i++;
      }
    } else {
      p++;
    }
  }

  return xml;
}

void
print_xml(xml_t *xml)
{
  int i;

  for (i = 0; i < xml->num_tags; i++) {
    printf("<%s", xml->tags[i].name);
    if (xml->tags[i].value != NULL)
      printf(" %s=\"%s\"", xml->tags[i].name, xml->tags[i].value);
    printf(">");
  }

  printf("\n");
}

int
main(int argc, char *argv[])
{
  char buf[BUFSZ];
  xml_t *xml;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <xml file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  while (fgets(buf, BUFSZ, fp) != NULL) {
    xml = parse_xml(buf);
    if (xml == NULL) {
      perror("parse_xml");
      return EXIT_FAILURE;
    }

    print_xml(xml);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}