//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
// TeX meets Unix: a file backup system in the style of Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

// Say \bye to a file.
void bye(const char *file) {
  if (remove(file) != 0) {
    perror("remove");
    exit(1);
  }
}

// Give a file a Latin name.
char *latin(const char *file) {
  char *result = malloc(strlen(file) + 7);
  if (result == NULL) {
    perror("malloc");
    exit(1);
  }
  sprintf(result, "%s.latin", file);
  return result;
}

// Encode a file in Latin-1.
void encode(const char *file) {
  char *latin_file = latin(file);
  FILE *in = fopen(file, "rb");
  FILE *out = fopen(latin_file, "wb");
  if (in == NULL || out == NULL) {
    perror("fopen");
    exit(1);
  }
  int c;
  while ((c = fgetc(in)) != EOF) {
    if (c < 0x80) {
      fputc(c, out);
    } else {
      fputc('?', out);
    }
  }
  fclose(in);
  fclose(out);
  free(latin_file);
}

// Decode a file from Latin-1.
void decode(const char *file) {
  char *latin_file = latin(file);
  FILE *in = fopen(latin_file, "rb");
  FILE *out = fopen(file, "wb");
  if (in == NULL || out == NULL) {
    perror("fopen");
    exit(1);
  }
  int c;
  while ((c = fgetc(in)) != EOF) {
    if (c != '?') {
      fputc(c, out);
    }
  }
  fclose(in);
  fclose(out);
  bye(latin_file);
}

// Backup a file to a timestamped name.
void backup(const char *file) {
  char timestamp[16];
  time_t t = time(NULL);
  strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", localtime(&t));
  char *backup_file = malloc(strlen(file) + strlen(timestamp) + 2);
  if (backup_file == NULL) {
    perror("malloc");
    exit(1);
  }
  sprintf(backup_file, "%s.%s", file, timestamp);
  if (rename(file, backup_file) != 0) {
    perror("rename");
    exit(1);
  }
  free(backup_file);
}

// Restore a file from a timestamped name.
void restore(const char *file) {
  struct stat st;
  if (stat(file, &st) != 0) {
    perror("stat");
    exit(1);
  }
  if (!S_ISREG(st.st_mode)) {
    fprintf(stderr, "%s: not a regular file\n", file);
    exit(1);
  }
  if (rename(file, file) != 0) {
    perror("rename");
    exit(1);
  }
}

// List files with timestamped names.
void list() {
  system("ls -ltr | grep '^[0-9]'");
}

// Clean up old backups.
void clean() {
  system("find . -type f -name '*.??????' -mtime +7 -exec rm {} \;");
}

// Usage: goodbye [file]
int main(int argc, char **argv) {
  if (argc == 1) {
    bye("bye");
  } else if (argc == 2) {
    if (strcmp(argv[1], "encode") == 0) {
      encode(argv[2]);
    } else if (strcmp(argv[1], "decode") == 0) {
      decode(argv[2]);
    } else if (strcmp(argv[1], "backup") == 0) {
      backup(argv[2]);
    } else if (strcmp(argv[1], "restore") == 0) {
      restore(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
      list();
    } else if (strcmp(argv[1], "clean") == 0) {
      clean();
    } else {
      fprintf(stderr, "Usage: goodbye [encode|decode|backup|restore|list|clean] [file]\n");
      exit(1);
    }
  } else {
    fprintf(stderr, "Usage: goodbye [encode|decode|backup|restore|list|clean] [file]\n");
    exit(1);
  }
  return 0;
}