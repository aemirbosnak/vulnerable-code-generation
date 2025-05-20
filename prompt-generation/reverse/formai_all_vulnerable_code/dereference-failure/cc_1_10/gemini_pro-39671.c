//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
// In a realm beyond the void, where dreams and reality intertwine, an ethereal system emerges to guard against the unseen.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A tapestry of variables, woven with surreal threads.
int anomaly_score;
int threshold;
char *suspicious_pattern;
char *normal_pattern;
unsigned int random_seed;

// An algorithm from the depths of the subconscious, detecting anomalies like a sixth sense.
int detect_anomaly(unsigned int seed, char *pattern) {
  random_seed = seed;
  srand(random_seed);
  anomaly_score = 0;
  for (int i = 0; i < strlen(pattern); i++) {
    if (pattern[i] != '0' && pattern[i] != '1') {
      return -1;  // Pattern contains invalid characters.
    }
    int random_bit = rand() % 2;
    if (pattern[i] != '0' + random_bit) {
      anomaly_score++;
    }
  }
  return anomaly_score;
}

// A never-ending vigil, scanning the ethereal realm for intrusions.
void surveillance_loop(char *normal_pattern, int threshold) {
  while (1) {
    // Time warps and reality flickers.
    time_t t = time(NULL);
    random_seed = t % 1000000000;  // Seed the random number generator with a touch of chaos.

    // A new pattern emerges from the depths, its true nature yet unknown.
    suspicious_pattern = (char *) malloc(strlen(normal_pattern) + 1);
    for (int i = 0; i < strlen(normal_pattern); i++) {
      suspicious_pattern[i] = '0' + (rand() % 2);
    }

    // The algorithm whispers its secrets, revealing the anomaly score.
    anomaly_score = detect_anomaly(random_seed, suspicious_pattern);
    free(suspicious_pattern);

    // The threshold, a line in the sand separating normalcy from the uncanny.
    if (anomaly_score > threshold) {
      printf("**INTRUSION DETECTED**\n");
      printf("Anomaly score: %d\n", anomaly_score);
      printf("Pattern: %s\n", suspicious_pattern);
      printf("Random seed: %u\n", random_seed);
    }
    sleep(1);  // A moment's respite in the eternal watch.
  }
}

// The tapestry of dreams and reality is woven anew, the intrusion detection system ever vigilant.
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <normal_pattern> <threshold>\n", argv[0]);
    return 1;
  }
  normal_pattern = argv[1];
  threshold = atoi(argv[2]);
  surveillance_loop(normal_pattern, threshold);
  return 0;
}