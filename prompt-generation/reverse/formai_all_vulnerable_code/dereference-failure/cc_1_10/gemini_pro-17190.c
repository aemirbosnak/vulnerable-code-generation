//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: decentralized
#include <assert.h>
#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_URL_SIZE 1024
#define MAX_SANITIZED_URL_SIZE 2048

#define CHILD_PROCESS_SUCCESS 0
#define INVALID_CHILD_PROCESS_PID -1
#define UNABLE_TO_FORK_ERROR -1

static bool is_valid_url(const char *url) {
  CURL *curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "Error initializing libcurl.\n");
    return false;
  }

  curl_easy_setopt(curl, CURLOPT_URL, url);

  CURLcode res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  return res == CURLE_OK ? true : false;
}

static char *sanitize_url(const char *url) {
  pid_t pid = fork();
  if (pid == INVALID_CHILD_PROCESS_PID) {
    perror("Error in fork");
    return NULL;
  } else if (pid == CHILD_PROCESS_SUCCESS) {
    execl("/usr/bin/host", "/usr/bin/host", url, NULL);
    exit(EXIT_FAILURE);  // If execl succeeds, this line is never reached
  }

  // Parent process continues here
  int status;
  wait(&status);

  char sanitized_url[MAX_SANITIZED_URL_SIZE];
  if (WEXITSTATUS(status) == CHILD_PROCESS_SUCCESS) {
    const char *sanitized_url_start = strstr(url, "has address ");
    if (sanitized_url_start != NULL) {
      const char *sanitized_url_end = strchr(sanitized_url_start, '\n');
      if (sanitized_url_end != NULL) {
        int len = sanitized_url_end - sanitized_url_start;
        assert(len < MAX_SANITIZED_URL_SIZE);
        strncpy(sanitized_url, sanitized_url_start, len);
        sanitized_url[len] = '\0';
        return strdup(sanitized_url);
      }
    }
  }

  // If sanitization fails, return NULL
  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s url\n", argv[0]);
    return EXIT_FAILURE;
  }

  const char *url = argv[1];
  if (!is_valid_url(url)) {
    fprintf(stderr, "%s is not a valid URL.\n", url);
    return EXIT_FAILURE;
  }

  char *sanitized_url = sanitize_url(url);
  if (sanitized_url != NULL) {
    printf("%s\n", sanitized_url);
    free(sanitized_url);
  } else {
    fprintf(stderr, "Error sanitizing %s.\n", url);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}