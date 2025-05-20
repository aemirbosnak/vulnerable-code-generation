//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 2048

void sanitize_url(char *url)
{
  char *temp_url1 = strdup(url);
  char *temp_url2 = strdup(url);
  char *token = strtok(temp_url1, " ");

  // Check if the input URL is valid
  if (token == NULL || strncmp(token, "https://", 8) != 0)
  {
    printf("Invalid URL");
    return;
  }

  // Remove whitespace characters from URL
  int i, j;
  for (i = 0, j = 0; i < strlen(temp_url2); i++)
  {
    if (temp_url2[i] != ' ')
      url[j++] = temp_url2[i];
  }
  url[j] = '\0';

  // Convert URL to lowercase
  for (i = 0; i < strlen(url); i++)
  {
    url[i] = tolower(url[i]);
  }

  // Remove query parameters from URL
  char *qmark = strchr(url, '?');
  if (qmark != NULL)
  {
    *qmark = '\0';
  }

  // Remove the last slash if it exists
  if (url[strlen(url) - 1] == '/')
  {
    url[strlen(url) - 1] = '\0';
  }

  // Remove any double-slashes
  char *slash = strstr(url, "//");
  if (slash != NULL)
  {
    strcpy(slash, slash + 1);
  }
}

int main()
{
  char url[MAX_URL_LENGTH];

  printf("Enter URL to sanitize: ");
  fgets(url, MAX_URL_LENGTH, stdin);

  // Remove newline character from input string
  url[strcspn(url, "\n")] = '\0';

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}