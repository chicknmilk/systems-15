#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char *line);

int main() {
  char line[128] = "ls -a -l";
  char **args = parse_args(line);

  int i;

  execvp(args[0], args);

  return 0;
}

char ** parse_args(char *line) {
  char **args = calloc(5, sizeof(char *)); // at most 5 pointers to strings
  args[0] = line; // first argument has same address as line
  int i;
  for (int i = 1; i < 5; i++) { // skips first
    if (strsep(&line, " ") != NULL) args[i] = line;
  }
  return args;
}