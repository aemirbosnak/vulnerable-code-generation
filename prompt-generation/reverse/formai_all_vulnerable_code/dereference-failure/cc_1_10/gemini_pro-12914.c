//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: futuristic
// Welcome to the Stellar JSON Parser, traveler!
// Prepare for a journey through the cosmic realm of data!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cosmic token types
enum TokenTypes {
  TO_NULL = 0,
  TO_LBRACE,
  TO_RBRACE,
  TO_LBRACKET,
  TO_RBRACKET,
  TO_COLON,
  TO_COMMA,
  TO_STRING,
  TO_NUMBER,
  TO_BOOL
};

// Declare the interstellar crew of parser functions
int parseJSON(char *json);
int parseValue(char **json);
int parseObject(char **json);
int parseArray(char **json);
int parseString(char **json);
int parseNumber(char **json);
int parseBool(char **json);

// Initialize the cosmic ship
int main(int argc, char *argv[]) {
  // Check for valid input
  if (argc != 2) {
    printf("Usage: JSONParser <JSON_FILE>\n");
    return 1;
  }

  // Load the JSON file into a cosmic buffer
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: Could not open file %s\n", argv[1]);
    return 1;
  }
  fseek(fp, 0, SEEK_END);
  size_t fileLength = ftell(fp);
  rewind(fp);
  char *json = malloc(fileLength + 1);
  fread(json, fileLength, 1, fp);
  fclose(fp);

  // Initiate the JSON parsing journey
  int parseStatus = parseJSON(json);

  // Report the mission outcome
  if (parseStatus == 0) {
    printf("Mission successful! JSON parsed successfully.\n");
  } else {
    printf("Mission failed! JSON parsing failed.\n");
  }

  // Release the cosmic resources
  free(json);
  return 0;
}

// Parse the entire JSON galaxy
int parseJSON(char *json) {
  char *start = json;
  int status = parseValue(&start);
  return status;
}

// Parse a single cosmic value
int parseValue(char **json) {
  // Skip any whitespace
  char *start = *json;
  while (*start && *start <= ' ') start++;

  // Determine the value type
  switch (*start) {
    case '{':
      return parseObject(json);
    case '[':
      return parseArray(json);
    case '"':
      return parseString(json);
    case '-':
    case '0' ... '9':
      return parseNumber(json);
    case 't':
    case 'f':
      return parseBool(json);
    case 0:
      return TO_NULL;
    default:
      return -1;
  }
}

// Parse a cosmic object
int parseObject(char **json) {
  char *start = *json + 1;
  while (*start && *start != '}') start++;
  if (*start == 0) return -1;
  *json = start + 1;
  return TO_LBRACE;
}

// Parse a cosmic array
int parseArray(char **json) {
  char *start = *json + 1;
  while (*start && *start != ']') start++;
  if (*start == 0) return -1;
  *json = start + 1;
  return TO_LBRACKET;
}

// Parse a cosmic string
int parseString(char **json) {
  char *start = *json + 1;
  while (*start && *start != '"') start++;
  if (*start == 0) return -1;
  *json = start + 1;
  return TO_STRING;
}

// Parse a cosmic number
int parseNumber(char **json) {
  char *start = *json;
  while (*start && (*start == '.' || (*start >= '0' && *start <= '9'))) start++;
  if (*start != 0) return -1;
  *json = start;
  return TO_NUMBER;
}

// Parse a cosmic boolean
int parseBool(char **json) {
  char *start = *json;
  if (!strncmp(start, "true", 4)) {
    *json = start + 4;
    return TO_BOOL;
  } else if (!strncmp(start, "false", 5)) {
    *json = start + 5;
    return TO_BOOL;
  } else {
    return -1;
  }
}