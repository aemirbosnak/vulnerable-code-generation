//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// The Enchanting File Backup System (EFBS) conjures up a mystical realm where your precious files are shielded from the perils of time and mishaps.

// Function Prototypes:
void backupFile(const char *filename, const char *backupDirectory);
void createBackupDirectory(const char *backupDirectory);
time_t getBackupTimestamp(const char *filename);
char *getTimestampString(time_t timestamp);
int fileExists(const char *filename);

// The main function, where the magic begins:
int main() {
  // Let's backup a precious file, like a love letter you've been writing for a lifetime.
  const char *filename = "MyHeartfeltLoveLetter.txt";

  // The backup directory, a haven where your treasures are safely tucked away.
  const char *backupDirectory = "SanctuaryOfBackups";

  // Create the backup directory if it doesn't exist, like a fortress guarding your secrets.
  createBackupDirectory(backupDirectory);

  // Check if the love letter exists, just like confirming the existence of your heart's desire.
  if (fileExists(filename)) {
    backupFile(filename, backupDirectory);
    printf("Your love letter is now safely ensconced in the Sanctuary of Backups.\n");
  } else {
    printf("No love letter found. Time to write one and pour your heart into it!\n");
  }

  return 0;
}

// Function to backup a file, like casting a protective spell over your cherished memories.
void backupFile(const char *filename, const char *backupDirectory) {
  // Determine the last time the love letter was modified, like recalling the moment your heart skipped a beat.
  time_t timestamp = getBackupTimestamp(filename);

  // Convert the timestamp into a string, like capturing the essence of a memory in words.
  char *timestampString = getTimestampString(timestamp);

  // Construct the backup file's path, like building a secret vault within the Sanctuary of Backups.
  char backupFilepath[256];
  snprintf(backupFilepath, sizeof(backupFilepath), "%s/%s_%s.bak", backupDirectory, filename, timestampString);

  // Open the original file, like opening a treasure chest filled with your heart's most precious words.
  FILE *originalFile = fopen(filename, "r");

  // Create the backup file, like crafting a magical scroll to preserve your heartfelt expressions.
  FILE *backupFile = fopen(backupFilepath, "w");

  // Copy the contents of the love letter into the backup file, like transferring the essence of your heart.
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), originalFile)) {
    fputs(buffer, backupFile);
  }

  // Close both files, sealing the secrets within their confines.
  fclose(originalFile);
  fclose(backupFile);

  // Free the timestamp string, breaking the enchantment that held its form.
  free(timestampString);
}

// Function to create a backup directory, like summoning a fortress to safeguard your treasures.
void createBackupDirectory(const char *backupDirectory) {
  // Check if the backup directory already exists, like confirming the presence of a hidden sanctuary.
  int directoryExists = fileExists(backupDirectory);

  // If the directory doesn't exist, conjure it into existence!
  if (!directoryExists) {
    if (mkdir(backupDirectory, 0755) == -1) {
      perror("Failed to create backup directory.");
      exit(EXIT_FAILURE);
    }
    printf("Sanctuary of Backups created. Your treasures will be well-guarded here.\n");
  } else {
    printf("Sanctuary of Backups already exists. Rest assured, your treasures are safe.\n");
  }
}

// Function to retrieve the last modified timestamp of a file, like capturing a moment in time.
time_t getBackupTimestamp(const char *filename) {
  struct stat fileInfo;

  // Attempt to retrieve the file's information, like unlocking secrets from a time capsule.
  if (stat(filename, &fileInfo) == -1) {
    perror("Failed to get file information.");
    exit(EXIT_FAILURE);
  }

  // Extract the timestamp, like unsealing a message from the past.
  time_t timestamp = fileInfo.st_mtime;

  return timestamp;
}

// Function to convert a timestamp into a string, like transforming a moment into a tale.
char *getTimestampString(time_t timestamp) {
  // Allocate memory for the timestamp string, like preparing a canvas for a masterpiece.
  char *timestampString = malloc(32);

  // Convert the timestamp to a string, like etching a moment into the annals of time.
  strftime(timestampString, 32, "%Y-%m-%d_%H-%M-%S", localtime(&timestamp));

  return timestampString;
}

// Function to check if a file exists, like verifying the presence of a hidden treasure.
int fileExists(const char *filename) {
  // Attempt to open the file, like trying to unlock a secret door.
  FILE *file = fopen(filename, "r");

  // If the file opened successfully, it exists!
  if (file) {
    fclose(file);
    return 1;
  } else {
    return 0;
  }
}