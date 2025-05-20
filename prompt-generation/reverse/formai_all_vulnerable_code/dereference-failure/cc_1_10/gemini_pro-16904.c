//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
  [0] = 0,  // "a"
  [1] = 1,  // "able"
  [2] = -1, // "about"
  [3] = 1,  // "above"
  [4] = -1, // "after"
  [5] = 1,  // "again"
  [6] = -1, // "against"
  [7] = 1,  // "all"
  [8] = -1, // "almost"
  [9] = 1,  // "alone"
  [10] = -1, // "along"
  [11] = 1, // "already"
  [12] = -1, // "also"
  [13] = 1, // "although"
  [14] = -1, // "always"
  [15] = 1, // "among"
  [16] = -1, // "an"
  [17] = 1, // "and"
  [18] = -1, // "another"
  [19] = 1, // "any"
  [20] = -1, // "anybody"
  [21] = 1, // "anyone"
  [22] = -1, // "anything"
  [23] = 1, // "anyway"
  [24] = -1, // "anywhere"
  [25] = 1, // "are"
  [26] = -1, // "aren't"
  [27] = 1, // "around"
  [28] = -1, // "as"
  [29] = 1, // "at"
  [30] = -1, // "away"
  [31] = 1, // "back"
  [32] = -1, // "bad"
  [33] = 1, // "be"
  [34] = -1, // "because"
  [35] = 1, // "been"
  [36] = -1, // "before"
  [37] = 1, // "being"
  [38] = -1, // "below"
  [39] = 1, // "beside"
  [40] = -1, // "best"
  [41] = 1, // "better"
  [42] = -1, // "between"
  [43] = 1, // "big"
  [44] = -1, // "both"
  [45] = 1, // "but"
  [46] = -1, // "by"
  [47] = 1, // "can"
  [48] = -1, // "cannot"
  [49] = 1, // "case"
  [50] = -1, // "certain"
  [51] = 1, // "certainly"
  [52] = -1, // "clear"
  [53] = 1, // "clearly"
  [54] = -1, // "come"
  [55] = 1, // "could"
  [56] = -1, // "couldn't"
  [57] = 1, // "did"
  [58] = -1, // "didn't"
  [59] = 1, // "different"
  [60] = -1, // "directly"
  [61] = 1, // "do"
  [62] = -1, // "does"
  [63] = 1, // "doesn't"
  [64] = -1, // "done"
  [65] = 1, // "down"
  [66] = -1, // "downward"
  [67] = 1, // "during"
  [68] = -1, // "each"
  [69] = 1, // "early"
  [70] = -1, // "either"
  [71] = 1, // "else"
  [72] = -1, // "elsewhere"
  [73] = 1, // "enough"
  [74] = -1, // "especially"
  [75] = 1, // "even"
  [76] = -1, // "ever"
  [77] = 1, // "every"
  [78] = -1, // "everybody"
  [79] = 1, // "everyone"
  [80] = -1, // "everything"
  [81] = 1, // "everywhere"
  [82] = -1, // "except"
  [83] = 1, // "far"
  [84] = -1, // "fast"
  [85] = 1, // "feel"
  [86] = -1, // "felt"
  [87] = 1, // "few"
  [88] = -1, // "final"
  [89] = 1, // "finally"
  [90] = -1, // "fine"
  [91] = 1, // "for"
  [92] = -1, // "forever"
  [93] = 1, // "forward"
  [94] = -1, // "four"
  [95] = 1, // "from"
  [96] = -1, // "front"
  [97] = 1, // "full"
  [98] = -1, // "fully"
  [99] = 1, // "further"
};

// Tokenize the input string into an array of words
char** tokenize(char* input) {
  char** tokens = malloc(sizeof(char*) * 100);
  int token_count = 0;

  char* token = strtok(input, " ");
  while (token != NULL) {
    tokens[token_count] = token;
    token = strtok(NULL, " ");
    token_count++;
  }

  return tokens;
}

// Compute the sentiment score for a given input string
int sentiment_analysis(char* input) {
  char** tokens = tokenize(input);

  int sentiment_score = 0;
  for (int i = 0; i < 100; i++) {
    if (tokens[i] != NULL) {
      sentiment_score += SENTIMENT_SCORES[i];
    }
  }

  free(tokens);
  return sentiment_score;
}

int main() {
  char* input = "I am feeling good today";
  int sentiment_score = sentiment_analysis(input);
  printf("Sentiment score: %d\n", sentiment_score);

  return 0;
}