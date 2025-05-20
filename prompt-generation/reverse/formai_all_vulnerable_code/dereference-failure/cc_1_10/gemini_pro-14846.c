//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

// Function to escape special characters in a URL
char *escape_url(const char *url) {
  char *escaped_url = malloc(strlen(url) * 3 + 1); // Allocate enough space for the escaped URL
  char *p = escaped_url;
  while (*url) {
    switch (*url) {
      case ' ':  *p++ = '%'; *p++ = '2';  *p++ = '0'; break;
      case '\'': *p++ = '%'; *p++ = '2';  *p++ = '7'; break;
      case '"':  *p++ = '%'; *p++ = '2';  *p++ = '2'; break;
      case '<':  *p++ = '%'; *p++ = '3';  *p++ = 'C'; break;
      case '>':  *p++ = '%'; *p++ = '3';  *p++ = 'E'; break;
      case '&':  *p++ = '%'; *p++ = '2';  *p++ = '6'; break;
      case '%':  *p++ = '%'; *p++ = '2';  *p++ = '5'; break;
      case '+':  *p++ = '%'; *p++ = '2';  *p++ = 'B'; break;
      case '#':  *p++ = '%'; *p++ = '2';  *p++ = '3'; break;
      case '?':  *p++ = '%'; *p++ = '3';  *p++ = 'F'; break;
      case ';':  *p++ = '%'; *p++ = '3';  *p++ = 'B'; break;
      case '/':  *p++ = '%'; *p++ = '2';  *p++ = 'F'; break;
      case ':':  *p++ = '%'; *p++ = '3';  *p++ = 'A'; break;
      case '@':  *p++ = '%'; *p++ = '4';  *p++ = '0'; break;
      case '=':  *p++ = '%'; *p++ = '3';  *p++ = 'D'; break;
      case ',':  *p++ = '%'; *p++ = '2';  *p++ = 'C'; break;
      default:   *p++ = *url;
    }
    url++;
  }
  *p = '\0';
  return escaped_url;
}

// Function to unescape special characters in a URL
char *unescape_url(const char *url) {
  char *unescaped_url = malloc(strlen(url) + 1); // Allocate enough space for the unescaped URL
  char *p = unescaped_url;
  while (*url) {
    if (*url == '%' && *(url + 1) && *(url + 2)) {
      char hex[3] = {*(url + 1), *(url + 2), '\0'};
      int code = strtol(hex, NULL, 16);
      *p++ = (char)code;
      url += 3;
    } else {
      *p++ = *url++;
    }
  }
  *p = '\0';
  return unescaped_url;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  char *escaped_url = escape_url(argv[1]);
  printf("Escaped URL: %s\n", escaped_url);

  char *unescaped_url = unescape_url(escaped_url);
  printf("Unescaped URL: %s\n", unescaped_url);

  free(escaped_url);
  free(unescaped_url);

  return 0;
}