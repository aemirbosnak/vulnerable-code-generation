//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// A bucket represents a range of values.
struct Bucket {
  int start;  // The starting value of the range.
  int end;    // The ending value of the range.
  int count;  // The number of elements in the range.
  int *data;  // The data in the range.
};

// Create a bucket.
struct Bucket *createBucket(int start, int end) {
  struct Bucket *bucket = malloc(sizeof(struct Bucket));
  bucket->start = start;
  bucket->end = end;
  bucket->count = 0;
  bucket->data = NULL;
  return bucket;
}

// Insert an element into a bucket.
void insertIntoBucket(struct Bucket *bucket, int value) {
  if (bucket->count == 0) {
    bucket->data = malloc(sizeof(int));
  } else {
    bucket->data = realloc(bucket->data, (bucket->count + 1) * sizeof(int));
  }
  bucket->data[bucket->count++] = value;
}

// Sort the elements in a bucket.
void sortBucket(struct Bucket *bucket) {
  for (int i = 0; i < bucket->count - 1; i++) {
    for (int j = i + 1; j < bucket->count; j++) {
      if (bucket->data[i] > bucket->data[j]) {
        int temp = bucket->data[i];
        bucket->data[i] = bucket->data[j];
        bucket->data[j] = temp;
      }
    }
  }
}

// Create an array of buckets.
struct Bucket **createBuckets(int min, int max, int numBuckets) {
  struct Bucket **buckets = malloc(numBuckets * sizeof(struct Bucket *));
  for (int i = 0; i < numBuckets; i++) {
    buckets[i] = createBucket(min + (i * (max - min) / numBuckets),
                               min + ((i + 1) * (max - min) / numBuckets) - 1);
  }
  return buckets;
}

// Insert elements into buckets.
void insertIntoBuckets(struct Bucket **buckets, int *data, int size, int numBuckets) {
  for (int i = 0; i < size; i++) {
    int bucketIndex = (data[i] - buckets[0]->start) * numBuckets / (buckets[numBuckets - 1]->end - buckets[0]->start);
    insertIntoBucket(buckets[bucketIndex], data[i]);
  }
}

// Sort the elements in the buckets.
void sortBuckets(struct Bucket **buckets, int numBuckets) {
  for (int i = 0; i < numBuckets; i++) {
    sortBucket(buckets[i]);
  }
}

// Merge the sorted buckets into a single array.
int *mergeBuckets(struct Bucket **buckets, int numBuckets) {
  int size = 0;
  for (int i = 0; i < numBuckets; i++) {
    size += buckets[i]->count;
  }
  int *sortedData = malloc(size * sizeof(int));
  int index = 0;
  for (int i = 0; i < numBuckets; i++) {
    for (int j = 0; j < buckets[i]->count; j++) {
      sortedData[index++] = buckets[i]->data[j];
    }
  }
  return sortedData;
}

// Free the memory allocated for the buckets.
void freeBuckets(struct Bucket **buckets, int numBuckets) {
  for (int i = 0; i < numBuckets; i++) {
    free(buckets[i]->data);
    free(buckets[i]);
  }
  free(buckets);
}

// Print the sorted array.
void printSortedArray(int *data, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

int main() {
  // Get the input data.
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  int *data = malloc(size * sizeof(int));
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &data[i]);
  }

  // Find the minimum and maximum values in the array.
  int min = data[0], max = data[0];
  for (int i = 1; i < size; i++) {
    if (data[i] < min) {
      min = data[i];
    }
    if (data[i] > max) {
      max = data[i];
    }
  }

  // Create an array of buckets.
  int numBuckets = 10;
  struct Bucket **buckets = createBuckets(min, max, numBuckets);

  // Insert elements into buckets.
  insertIntoBuckets(buckets, data, size, numBuckets);

  // Sort the elements in the buckets.
  sortBuckets(buckets, numBuckets);

  // Merge the sorted buckets into a single array.
  int *sortedData = mergeBuckets(buckets, numBuckets);

  // Free the memory allocated for the buckets.
  freeBuckets(buckets, numBuckets);

  // Print the sorted array.
  printf("Sorted array: ");
  printSortedArray(sortedData, size);

  // Free the memory allocated for the sorted array.
  free(sortedData);

  return 0;
}