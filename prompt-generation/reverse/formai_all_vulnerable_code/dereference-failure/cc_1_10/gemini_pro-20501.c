//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
  CURL *curl;
  char *url;
  char *output;
  int status;
} CurlState;

static void curl_init(CurlState *state) {
  state->curl = curl_easy_init();
  state->url = NULL;
  state->output = NULL;
  state->status = 0;
}

static void curl_cleanup(CurlState *state) {
  if (state->curl) curl_easy_cleanup(state->curl);
  if (state->url) free(state->url);
  if (state->output) free(state->output);
}

static int curl_set_url(CurlState *state, const char *url) {
  if (state->url) free(state->url);
  state->url = strdup(url);
  return (state->url != NULL);
}

static int curl_perform(CurlState *state) {
  state->status = curl_easy_perform(state->curl);
  return (state->status == CURLE_OK);
}

static size_t curl_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
  CurlState *state = (CurlState *)userdata;
  char *temp = realloc(state->output, state->output ? strlen(state->output) + size * nmemb + 1 : size * nmemb + 1);
  if (!temp) return 0;
  state->output = temp;
  memcpy(state->output + (state->output ? strlen(state->output) : 0), ptr, size * nmemb);
  state->output[strlen(state->output) + (state->output ? strlen(state->output) : 0)] = '\0';
  return size * nmemb;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  CurlState state;
  curl_init(&state);
  curl_set_url(&state, argv[1]);
  curl_easy_setopt(state.curl, CURLOPT_WRITEFUNCTION, curl_callback);
  curl_easy_setopt(state.curl, CURLOPT_WRITEDATA, &state);
  curl_easy_setopt(state.curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(state.curl, CURLOPT_MAXREDIRS, 5L);
  if (!curl_perform(&state)) {
    fprintf(stderr, "Error performing curl: %s\n", curl_easy_strerror(state.status));
    curl_cleanup(&state);
    return EXIT_FAILURE;
  }

  printf("Status: %d\n", state.status);
  printf("Output:\n%s\n", state.output);

  curl_cleanup(&state);
  return EXIT_SUCCESS;
}