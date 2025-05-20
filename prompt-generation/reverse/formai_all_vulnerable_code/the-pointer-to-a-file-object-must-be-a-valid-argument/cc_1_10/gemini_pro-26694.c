//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: paranoid
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 199309L
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <err.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <syslog.h>

static int
rdint(char *s, int *r)
{
	int v;
	char *e;

	if (s == NULL || *s == '\0') {
		return -1;
	}

	errno = 0;
	v = strtol(s, &e, 10);
	if (*e != '\0' || errno != 0) {
		return -1;
	}

	*r = v;
	return 0;
}

static int
process_record(char *record)
{
	char *t, *e, *groups, *users;
	int fd, i = 0, fg = 0, fu = 0;

	if (strchr(record, ' ') == NULL) {
		return -1;
	}

	t = strtok(record, " ");
	e = t + strlen(t);
	groups = alloca(strlen(e) + 1);
	memcpy(groups, e, strlen(e) + 1);

	t = strtok(record, NULL);
	e = t + strlen(t);
	users = alloca(strlen(e) + 1);
	memcpy(users, e, strlen(e) + 1);

	fd = open("/etc/passwd", O_RDONLY);
	if (fd >= 0) {
		struct passwd *pw;

		while ((pw = getpwent()) != NULL) {
			if (strcmp(pw->pw_name, users) != 0) {
				continue;
			}

			fu = pw->pw_uid;
			while ((t = strtok(NULL, " ")) != NULL) {
				struct group *gr;

				gr = getgrnam(t);
				if (gr == NULL) {
					continue;
				}

				fg = gr->gr_gid;
				i++;
			}
			break;
		}

		endpwent();
	}

	if (fd >= 0) {
		close(fd);
	}

	if (i == 0 || fu == 0 || fg == 0) {
		return -1;
	}

	return 0;
}

static int
process_log(void)
{
	char buf[4096], *s;
	int fd;

	fd = open("/var/log/auth.log", O_RDONLY);
	if (fd >= 0) {
		ssize_t n;

		while ((n = read(fd, buf, sizeof(buf))) > 0) {
			char *t;

			t = buf;
			while((s = strtok(t, "\n")) != NULL) {
				process_record(s);
				t = NULL;
			}
		}

		close(fd);
		return 0;
	}

	return -1;
}

int
main(int argc, char **argv)
{
	int i = 0, n = 0;
	FILE *f;
	char *s, fname[1024];
	struct timeval tv;
	struct tm lt;
	time_t t;
	pid_t p;
	uid_t u;
	gid_t g;
	struct stat sbuf;

	if (!(argc > 1)) {
		errx(1, "No dice file specified.\n");
	}

	if (stat(argv[1], &sbuf) >= 0) {
		if (sbuf.st_size == 0) {
			errx(1, "Dice file '%s' has zero length.\n", argv[1]);
		}
	}

	if ((f = fopen(argv[1], "r")) == NULL) {
		err(1, "Cannot open dice file '%s'.\n", argv[1]);
	}

	p = getpid();
	u = getuid();
	g = getgid();

	while ((s = fgets(fname, sizeof(fname), f)) != NULL) {
		int v = 0;
		s[strcspn(s, "\n")] = '\0';

		if(rdint(s, &v) != 0) {
			fclose(f);
			errx(1, "Cannot read dice file '%s'.\n", argv[1]);
		}

		if (sbuf.st_nlink > 1) {
			syslog(LOG_NOTICE, "File '%s' has %lld links.\n", fname, (long long int)sbuf.st_nlink);
		}

		if (sbuf.st_mode & S_IWOTH) {
			syslog(LOG_NOTICE, "File '%s' is writable by other users.\n", fname);
		}

		if (process_log() >= 0) {
			syslog(LOG_NOTICE, "Process %d modified file '%s'.\n", p, fname);
		}

		if (u == 0 && g == 0) {
			if (strcmp(fname, "/etc/passwd") == 0) {
				syslog(LOG_NOTICE, "Process %d modified file '%s'.\n", p, fname);
			}
		}

		if (u != sbuf.st_uid) {
			syslog(LOG_NOTICE, "File '%s' is not owned by user %d.\n", fname, u);
		}

		if (g != sbuf.st_gid) {
			syslog(LOG_NOTICE, "File '%s' is not owned by group %d.\n", fname, g);
		}

		if (sbuf.st_mtime > 7*24*60*60) {
			gettimeofday(&tv, NULL);
			t = tv.tv_sec;
			localtime_r(&t, &lt);
			strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &lt);
			syslog(LOG_NOTICE, "File '%s' has not been modified since %s.\n", fname, s);
		}

		i += v;
		n++;
	}

	fclose(f);
	printf("%f\n", (double)i / n);
	return 0;
}