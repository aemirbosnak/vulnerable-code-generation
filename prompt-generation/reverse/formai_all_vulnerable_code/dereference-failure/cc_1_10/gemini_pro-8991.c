//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a URL
#define MAX_URL_LENGTH 2048

// Define the list of allowed characters in a URL
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_~";

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(MAX_URL_LENGTH);

  // Initialize the sanitized URL to the empty string
  strcpy(sanitized_url, "");

  // Loop through each character in the URL
  for (int i = 0; i < strlen(url); i++) {
    // If the character is allowed, add it to the sanitized URL
    if (strchr(allowed_chars, url[i]) != NULL) {
      strncat(sanitized_url, &url[i], 1);
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

// Function to play a multiplayer game
void play_game(char *player1_url, char *player2_url) {
  // Sanitize the player URLs
  char *sanitized_player1_url = sanitize_url(player1_url);
  char *sanitized_player2_url = sanitize_url(player2_url);

  // Print the sanitized player URLs
  printf("Player 1 URL: %s\n", sanitized_player1_url);
  printf("Player 2 URL: %s\n", sanitized_player2_url);

  // Free the memory allocated for the sanitized URLs
  free(sanitized_player1_url);
  free(sanitized_player2_url);
}

// Main function
int main() {
  // Get the player URLs from the user
  char player1_url[MAX_URL_LENGTH];
  char player2_url[MAX_URL_LENGTH];
  printf("Enter Player 1 URL: ");
  scanf("%s", player1_url);
  printf("Enter Player 2 URL: ");
  scanf("%s", player2_url);

  // Play the game
  play_game(player1_url, player2_url);

  return 0;
}