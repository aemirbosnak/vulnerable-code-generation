//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_URL_LENGTH 1024

char* sanitize_url(char* input_url) {
  // Define regular expression for matching legal URLs
  regex_t regex;
  int status = regcomp(&regex, "^https?://[A-Za-z0-9.-]+(:[0-9]+)?(/.*)?$", 0);
  if (status != 0) {
    fprintf(stderr, "Error compiling regular expression\n");
    return NULL;
  }

  // Allocate memory for sanitized URL
  char* sanitized_url = (char*) malloc(sizeof(char) * MAX_URL_LENGTH);

  // Remove any leading or trailing whitespace
  char* trimmed_url = strtok(input_url, " \t\n");
  if (trimmed_url == NULL) {
    fprintf(stderr, "Error: empty URL\n");
    return NULL;
  }

  // Remove any illegal characters or suspicious patterns
  char* legal_url = strpbrk(trimmed_url, " \t\n<>'\"\\");
  if (legal_url == NULL) {
    strcpy(sanitized_url, trimmed_url);
  } else {
    snprintf(sanitized_url, MAX_URL_LENGTH, "http://%s", legal_url);
  }

  // Normalize the URL by removing any redundant parts
  char* prefix = "https://";
  char* www_prefix = "www.";
  char* normalized_url = strstr(sanitized_url, prefix);
  if (normalized_url == NULL) {
    normalized_url = sanitized_url;
  } else {
    normalized_url += strlen(prefix);
  }
  char* www_url = strstr(normalized_url, www_prefix);
  if (www_url != NULL) {
    memmove(normalized_url, www_url + strlen(www_prefix), strlen(www_url) - strlen(www_prefix) + 1);
  }

  // Confirm that the resulting URL is valid and well-formed
  status = regexec(&regex, normalized_url, 0, NULL, 0);
  if (status != 0) {
    fprintf(stderr, "Error: invalid or unsafe URL\n");
    free(sanitized_url);
    return NULL;
  }

  // Return the sanitized URL
  return sanitized_url;
}

int main() {
  // Prompt the user to enter a URL
  printf("Enter a URL to sanitize:\n");
  char input_url[MAX_URL_LENGTH];
  fgets(input_url, MAX_URL_LENGTH, stdin);

  // Sanitize the URL and check for errors
  char* sanitized_url = sanitize_url(input_url);
  if (sanitized_url == NULL) {
    printf("Error sanitizing URL\n");
    return 1;
  }

  // Use the sanitized URL as input for subsequent operations
  printf("Sanitized URL: %s\n", sanitized_url);
  free(sanitized_url);
  return 0;
}