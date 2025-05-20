//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* compress(char* data) {
  int len = strlen(data);
  char last_char = data[0];
  int count = 1;
  char* result = malloc(len * sizeof(char));
  int result_index = 0;
  
  for (int i = 1; i < len; i++) {
    if (data[i] == last_char && count < 255) {
      count++;
    } else {
      result[result_index] = last_char;
      result[result_index + 1] = count;
      result_index += 2;
      last_char = data[i];
      count = 1;
    }
  }
  
  result[result_index] = last_char;
  result[result_index + 1] = count;
  
  return result;
}

void multiplayer_compress(char* data[], int num_players) {
  char* compressed_data[num_players];
  int sizes[num_players];
  
  for (int i = 0; i < num_players; i++) {
    char* player_data = data[i];
    char* compressed = compress(player_data);
    int size = strlen(compressed);
    
    compressed_data[i] = compressed;
    sizes[i] = size;
  }
  
  // send compressed_data and sizes to all players
  
  for (int i = 0; i < num_players; i++) {
    int size = sizes[i];
    char* compressed = compressed_data[i];
    
    printf("Player %d compressed data: %s\n", i, compressed);
    printf("Player %d compressed size: %d\n", i, size);
  }
}

int main() {
  char* data[] = {"AAAABBBCCDAA", "ABCCDEDFGGG", "AAABBCDDEEFF"};
  int num_players = sizeof(data) / sizeof(char*);
  
  multiplayer_compress(data, num_players);
  
  return 0;
}