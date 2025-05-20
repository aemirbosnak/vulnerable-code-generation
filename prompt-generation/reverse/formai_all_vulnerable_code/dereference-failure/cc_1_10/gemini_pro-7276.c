//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_SIZE 256
#define MAX_URL_SIZE 256

typedef enum {
  SPAM,
  NOT_SPAM
} SpamStatus;

const char *SPAM_KEYWORDS[] = {
  "free",
  "money",
  "lottery",
  "offer",
  "discount",
  "click",
  "subscribe"
};

const char *SPAM_URLS[] = {
  "bit.ly/",
  "goo.gl/",
  "tinyurl.com/",
  "ow.ly/",
  "t.co/",
  "buff.ly/",
  "rb.gy/"
};

int check_email_for_spam(const char *email) {
  for (int i = 0; i < sizeof(SPAM_KEYWORDS) / sizeof(char *); i++) {
    if (strstr(email, SPAM_KEYWORDS[i])) {
      return SPAM;
    }
  }
  return NOT_SPAM;
}

int check_url_for_spam(const char *url) {
  for (int i = 0; i < sizeof(SPAM_URLS) / sizeof(char *); i++) {
    if (strstr(url, SPAM_URLS[i])) {
      return SPAM;
    }
  }
  return NOT_SPAM;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <email address or URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *input = argv[1];
  
  // Check if the input is an email address or a URL.
  if (strchr(input, '@')) {
    // Check the email address for spam.
    SpamStatus status = check_email_for_spam(input);
    if (status == SPAM) {
      printf("The email address '%s' is spam.\n", input);
    } else {
      printf("The email address '%s' is not spam.\n", input);
    }
  } else {
    // Check the URL for spam.
    SpamStatus status = check_url_for_spam(input);
    if (status == SPAM) {
      printf("The URL '%s' is spam.\n", input);
    } else {
      printf("The URL '%s' is not spam.\n", input);
    }
  }

  return EXIT_SUCCESS;
}