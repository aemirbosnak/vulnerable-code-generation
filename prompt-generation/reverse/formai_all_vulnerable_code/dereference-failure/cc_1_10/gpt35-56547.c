//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: statistical
/*
This program demonstrates the basics of building a JSON parser.
It starts by reading a JSON string from stdin, then parsing it 
to extract its keys and values, and finally printing the key-value pairs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 1024
#define MAX_OBJECT_SIZE 1024

typedef enum { NONE, OBJECT, ARRAY } JsonType;

typedef struct {
  JsonType type;
  char* key;
  char* value;
} JsonElement;

void parseJson(char *jsonStr);
void parseJsonObject(char *jsonStr, int *i, char *key, int keyLen);
void parseJsonArray(char *jsonStr, int *i);
void parseJsonString(char *jsonStr, int *i, char *str, int strSize);
void parseJsonNumber(char *jsonStr, int *i, char *str, int strSize);
void skipWhitespace(char *jsonStr, int *i);

int main() {
  char jsonStr[MAX_OBJECT_SIZE];
  fgets(jsonStr, MAX_OBJECT_SIZE, stdin);
  parseJson(jsonStr);
  return 0;
}

void parseJson(char *jsonStr) {
  int i = 0;
  skipWhitespace(jsonStr, &i);

  if (jsonStr[i] == '{') {
    i++;
    parseJsonObject(jsonStr, &i, "", 0);
  }
  else if (jsonStr[i] == '[') {
    i++;
    parseJsonArray(jsonStr, &i);
  }
}

void parseJsonObject(char *jsonStr, int *i, char *key, int keyLen) {
  JsonElement elements[MAX_OBJECT_SIZE];
  int numElements = 0;

  skipWhitespace(jsonStr, i);

  while (jsonStr[*i] != '}') {
    char currKey[MAX_KEY_SIZE];
    parseJsonString(jsonStr, i, currKey, MAX_KEY_SIZE);
    skipWhitespace(jsonStr, i);
    if (jsonStr[*i] != ':') {
      fprintf(stderr, "Invalid JSON: expected ':'\n");
      exit(1);
    }
    (*i)++;
    skipWhitespace(jsonStr, i);

    char currValue[MAX_VALUE_SIZE];
    parseJsonString(jsonStr, i, currValue, MAX_VALUE_SIZE);

    JsonElement newElement = {
      .type = NONE,
      .key = strdup(currKey),
      .value = strdup(currValue)
    };

    elements[numElements++] = newElement;

    skipWhitespace(jsonStr, i);
    if (jsonStr[*i] == ',') {
      (*i)++;
      skipWhitespace(jsonStr, i);
    }
    else if (jsonStr[*i] != '}') {
      fprintf(stderr, "Invalid JSON: expected ',' or '}'\n");
      exit(1);
    }
  }

  printf("{\n");
  int j;
  for (j = 0; j < numElements; j++) {
    printf("  \"%s\": %s", elements[j].key, elements[j].value);
    if (j < numElements - 1) {
      printf(",");
    }
    printf("\n");
    free(elements[j].key);
    free(elements[j].value);
  }
  printf("}\n");
}

void parseJsonArray(char *jsonStr, int *i) {
  JsonElement elements[MAX_OBJECT_SIZE];
  int numElements = 0;

  skipWhitespace(jsonStr, i);

  while (jsonStr[*i] != ']') {
    char currValue[MAX_VALUE_SIZE];
    parseJsonString(jsonStr, i, currValue, MAX_VALUE_SIZE);

    JsonElement newElement = {
      .type = NONE,
      .key = NULL,
      .value = strdup(currValue)
    };

    elements[numElements++] = newElement;

    skipWhitespace(jsonStr, i);
    if (jsonStr[*i] == ',') {
      (*i)++;
      skipWhitespace(jsonStr, i);
    }
    else if (jsonStr[*i] != ']') {
      fprintf(stderr, "Invalid JSON: expected ',' or ']'\n");
      exit(1);
    }
  }

  printf("[\n");
  int j;
  for (j = 0; j < numElements; j++) {
    printf("  %s", elements[j].value);
    if (j < numElements - 1) {
      printf(",");
    }
    printf("\n");
    free(elements[j].value);
  }
  printf("]\n");
}

void parseJsonString(char *jsonStr, int *i, char *str, int strSize) {
  if (jsonStr[*i] != '\"') {
    fprintf(stderr, "Invalid JSON: expected '\"'\n");
    exit(1);
  }
  (*i)++;
  int strIndex = 0;
  while (jsonStr[*i] != '\"' && strIndex < strSize - 1) {
    if (jsonStr[*i] == '\\') {
      (*i)++;
      // handle escape characters
      switch (jsonStr[*i]) {
        case '\"':
          str[strIndex++] = '\"';
          break;
        case '\\':
          str[strIndex++] = '\\';
          break;
        case '/':
          str[strIndex++] = '/';
          break;
        case 'b':
          str[strIndex++] = '\b';
          break;
        case 'f':
          str[strIndex++] = '\f';
          break;
        case 'n':
          str[strIndex++] = '\n';
          break;
        case 'r':
          str[strIndex++] = '\r';
          break;
        case 't':
          str[strIndex++] = '\t';
          break;
        default:
          fprintf(stderr, "Invalid JSON: invalid escape sequence\n");
          exit(1);
      }
    }
    else {
      str[strIndex++] = jsonStr[*i];
    }
    (*i)++;
  }
  (*i)++;
  str[strIndex] = '\0';
}

void parseJsonNumber(char *jsonStr, int *i, char *str, int strSize) {
  // TODO
}

void skipWhitespace(char *jsonStr, int *i) {
  while (jsonStr[*i] == ' ' || jsonStr[*i] == '\t' || jsonStr[*i] == '\n' || jsonStr[*i] == '\r') {
    (*i)++;
  }
}