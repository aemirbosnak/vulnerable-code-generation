//GEMINI-pro DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

// Define the path to the log file
#define LOG_FILE "/var/log/jester.log"

// Define the maximum length of a command
#define MAX_COMMAND_LENGTH 256

// Define the maximum number of arguments to a command
#define MAX_ARGS 32

// Define the maximum length of a line in the log file
#define MAX_LOG_LINE 1024

// Define the maximum number of lines in the log file
#define MAX_LOG_LINES 100

// Define the maximum number of days to keep log files
#define MAX_LOG_DAYS 7

// Define the time format for the log file
#define TIME_FORMAT "%Y-%m-%d %H:%M:%S"

// Declare the global variables
int log_fd;
int log_lines;
int log_days;

// Declare the functions
void open_log(void);
void close_log(void);
void write_log(const char *line);
void rotate_logs(void);
void execute_command(const char *command);
void help(void);

int main(int argc, char *argv[])
{
  // Open the log file
  open_log();

  // Parse the command-line arguments
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      help();
      return 0;
    }
    else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--days") == 0)
    {
      if (i + 1 < argc)
      {
        log_days = atoi(argv[i + 1]);
      }
      else
      {
        fprintf(stderr, "Error: no days specified\n");
        return 1;
      }
    }
    else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0)
    {
      if (i + 1 < argc)
      {
        log_lines = atoi(argv[i + 1]);
      }
      else
      {
        fprintf(stderr, "Error: no lines specified\n");
        return 1;
      }
    }
    else
    {
      // Execute the command
      execute_command(argv[i]);
    }
  }

  // Close the log file
  close_log();

  return 0;
}

void open_log(void)
{
  // Open the log file
  log_fd = open(LOG_FILE, O_WRONLY | O_APPEND | O_CREAT, 0644);
  if (log_fd < 0)
  {
    perror("open");
    exit(1);
  }

  // Get the current number of lines in the log file
  log_lines = 0;
  char line[MAX_LOG_LINE];
  while (fgets(line, MAX_LOG_LINE, log_fd))
  {
    log_lines++;
  }

  // Get the current number of days since the log file was last rotated
  log_days = 0;
  struct stat statbuf;
  if (stat(LOG_FILE, &statbuf) < 0)
  {
    perror("stat");
    exit(1);
  }
  time_t now = time(NULL);
  time_t last_rotated = statbuf.st_mtime;
  log_days = (int)(difftime(now, last_rotated) / (60 * 60 * 24));

  // Rotate the log files if necessary
  rotate_logs();
}

void close_log(void)
{
  // Close the log file
  close(log_fd);
}

void write_log(const char *line)
{
  // Write the line to the log file
  write(log_fd, line, strlen(line));

  // Increment the number of lines in the log file
  log_lines++;

  // Rotate the log files if necessary
  rotate_logs();
}

void rotate_logs(void)
{
  // If the number of lines in the log file exceeds the maximum, rotate the logs
  if (log_lines > MAX_LOG_LINES)
  {
    // Close the current log file
    close_log();

    // Rename the old log files
    for (int i = MAX_LOG_DAYS - 1; i > 0; i--)
    {
      char old_log_file[256];
      snprintf(old_log_file, 256, "%s.%d", LOG_FILE, i);
      char new_log_file[256];
      snprintf(new_log_file, 256, "%s.%d", LOG_FILE, i + 1);
      rename(old_log_file, new_log_file);
    }

    // Open a new log file
    open_log();
  }

  // If the number of days since the log file was last rotated exceeds the maximum, rotate the logs
  if (log_days > MAX_LOG_DAYS)
  {
    // Close the current log file
    close_log();

    // Delete the oldest log file
    char oldest_log_file[256];
    snprintf(oldest_log_file, 256, "%s.%d", LOG_FILE, MAX_LOG_DAYS);
    unlink(oldest_log_file);

    // Rename the old log files
    for (int i = MAX_LOG_DAYS - 1; i > 0; i--)
    {
      char old_log_file[256];
      snprintf(old_log_file, 256, "%s.%d", LOG_FILE, i);
      char new_log_file[256];
      snprintf(new_log_file, 256, "%s.%d", LOG_FILE, i + 1);
      rename(old_log_file, new_log_file);
    }

    // Open a new log file
    open_log();
  }
}

void execute_command(const char *command)
{
  // Parse the command
  char *args[MAX_ARGS];
  int argc = 0;
  char *token = strtok(command, " ");
  while (token != NULL && argc < MAX_ARGS)
  {
    args[argc++] = token;
    token = strtok(NULL, " ");
  }

  // Create a child process
  pid_t pid = fork();
  if (pid < 0)
  {
    perror("fork");
    exit(1);
  }

  // In the child process, execute the command
  if (pid == 0)
  {
    execvp(args[0], args);
    perror("execvp");
    exit(1);
  }

  // In the parent process, wait for the child process to exit
  int status;
  waitpid(pid, &status, 0);

  // Write the command to the log file
  char line[MAX_LOG_LINE];
  snprintf(line, MAX_LOG_LINE, "%s %s", command, (status == 0) ? "succeeded" : "failed");
  write_log(line);
}

void help(void)
{
  printf("Usage: jester [options] <command>\n");
  printf("Options:\n");
  printf("  -h, --help            Display this help message\n");
  printf("  -d, --days <days>      Keep log files for the specified number of days\n");
  printf("  -l, --lines <lines>    Keep the specified number of lines in the log file\n");
}