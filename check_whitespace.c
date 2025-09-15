#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Strips spaces from both the front and back of a string,
 * leaving any internal spaces alone.
 */
char *strip(char const *str) {
  int size = (int)strlen(str);

  // This counts the number of leading and trailing spaces
  // so we can figure out how big the result array should be.
  int num_spaces = 0;
  int first_non_space = 0;
  while (first_non_space < size && str[first_non_space] == ' ') {
    ++num_spaces;
    ++first_non_space;
  }

  int last_non_space = size-1;
  while (last_non_space >= 0 && str[last_non_space] == ' ') {
    ++num_spaces;
    --last_non_space;
  }

  // If num_spaces >= size then that means that the string
  // consisted of nothing but spaces, so we'll return the
  // empty string.
 if (num_spaces >= size) {
    char *empty = (char *)calloc(1, sizeof(char)); 
    return empty; 
  }

  // Allocate a slot for all the "saved" characters
  // plus one extra for the null terminator.
  int out_len = (last_non_space - first_non_space + 1);
  char *result = (char *)calloc((size_t)out_len + 1, sizeof(char)); 

  // Copy in the "saved" characters.
  int i;
  for (i = first_non_space; i <= last_non_space; ++i) {
    result[i-first_non_space] = str[i];
  }
  // Place the null terminator at the end of the result string.
  result[out_len] = '\0';
  return result;
}

/*
 * Return true (1) if the given string is "clean", i.e., has
 * no spaces at the front or the back of the string.
 */
int is_clean(char const *str) {
  // We check if it's clean by calling strip and seeing if the
  // result is the same as the original string.
  char *cleaned = strip(str);
  // strcmp compares two strings, returning a negative value if
  // the first is less than the second (in alphabetical order),
  // 0 if they're equal, and a positive value if the first is
  // greater than the second.
  int ok = (strcmp(str, cleaned) == 0); 
  free(cleaned);
  return ok ? 1 : 0;
}
