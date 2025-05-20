//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <string.h>

// Helper function to check if a character is alphanumeric or not
int isAlphanumeric(char c) {
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

// Helper function to check if a character is a whitespace or not
int isWhitespace(char c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

// Sanitizes a given URL by removing unwanted characters and ensuring proper formatting
void sanitizeUrl(char* url) {
  // Declare variables
  int n = strlen(url);
  int i = 0;
  int j = 0;
  int isProtocolPresent = 0;
  int isDomainPresent = 0;
  int isPathPresent = 0;
  char domainBuffer[256];
  int domainIndex = 0;

  // Remove leading and trailing whitespace
  while (isWhitespace(url[i])) {
    i++;
  }
  while (isWhitespace(url[n-1])) {
    n--;
  }
  url[n] = '\0';

  // Check if protocol is present
  if (n > 7 && strncmp(url, "http://", 7) == 0) {
    i += 7;
    isProtocolPresent = 1;
  } else if (n > 8 && strncmp(url, "https://", 8) == 0) {
    i += 8;
    isProtocolPresent = 1;
  }

  // Copy domain name and remove unwanted characters
  while (i < n) {
    if (url[i] == '/') {
      isPathPresent = 1;
      break;
    } else if (isAlphanumeric(url[i]) || url[i] == '.') {
      domainBuffer[domainIndex++] = url[i];
      isDomainPresent = 1;
    }
    i++;
  }
  domainBuffer[domainIndex] = '\0';

  // Reformat URL
  j = 0;
  if (isProtocolPresent) {
    url[j++] = 'h';
    url[j++] = 't';
    url[j++] = 't';
    url[j++] = 'p';
    url[j++] = 's';
    url[j++] = ':';
    url[j++] = '/';
    url[j++] = '/';
  }
  url[j++] = 'w';
  url[j++] = 'w';
  url[j++] = 'w';
  url[j++] = '.';
  strncpy(url+j, domainBuffer, strlen(domainBuffer));
  j += strlen(domainBuffer);
  if (isPathPresent) {
    url[j++] = '/';
    url[j++] = 'p';
    url[j++] = 'a';
    url[j++] = 't';
    url[j++] = 'h';
  }
  url[j] = '\0'; 
}

int main() {
  // Test the URL sanitizer
  char url1[] = " goo gle.com/ path";
  char url2[] = "http://  example.com   /";
  char url3[] = "https://www.##my##-bad-domain.com////some///path//";
  char url4[] = "https://www.good-domain.com";
  sanitizeUrl(url1);
  sanitizeUrl(url2);
  sanitizeUrl(url3);
  sanitizeUrl(url4);
  printf("Sanitized URL 1: %s\n", url1);
  printf("Sanitized URL 2: %s\n", url2);
  printf("Sanitized URL 3: %s\n", url3);
  printf("Sanitized URL 4: %s\n", url4);
  return 0;
}