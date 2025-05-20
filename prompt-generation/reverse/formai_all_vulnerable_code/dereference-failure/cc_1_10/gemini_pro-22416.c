//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to sanitize a URL
char *sanitize_url(char *url) {
  int len = strlen(url);
  char *sanitized_url = malloc(len + 1);
  int i, j;
  for (i = 0, j = 0; i < len; i++) {
    switch (url[i]) {
    case ' ':
      sanitized_url[j++] = '+';
      break;
    case '&':
      sanitized_url[j++] = '&';
      sanitized_url[j++] = 'a';
      sanitized_url[j++] = 'm';
      sanitized_url[j++] = 'p';
      sanitized_url[j++] = ';';
      break;
    case '\'':
      sanitized_url[j++] = '%';
      sanitized_url[j++] = '2';
      sanitized_url[j++] = '7';
      break;
    case '\"':
      sanitized_url[j++] = '%';
      sanitized_url[j++] = '2';
      sanitized_url[j++] = '2';
      break;
    case '<':
      sanitized_url[j++] = '%';
      sanitized_url[j++] = '3';
      sanitized_url[j++] = 'C';
      break;
    case '>':
      sanitized_url[j++] = '%';
      sanitized_url[j++] = '3';
      sanitized_url[j++] = 'E';
      break;
    case '#':
      sanitized_url[j++] = '%';
      sanitized_url[j++] = '2';
      sanitized_url[j++] = '3';
      break;
    default:
      sanitized_url[j++] = url[i];
    }
  }
  sanitized_url[j] = '\0';
  return sanitized_url;
}

// Driver code
int main() {
  char url[] = "www.example.com/path/to/file?query=string&other=value#fragment";
  char *sanitized_url = sanitize_url(url);
  printf("Sanitized URL: %s\n", sanitized_url);
  free(sanitized_url);
  return 0;
}