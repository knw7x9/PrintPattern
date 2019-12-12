/* Katherine Wilsdon
 * No IDE, using Atom / Cygwin
 * Compiler flag: -o 
 * Windows
 * September 19, 2019
 * Description: Prints a pattern of dashes followed by asterisks in an ascending
 * order shape for a number. The user can enter a number as command line argument
 * or the program will prompt the user for a number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* PrintPattern(int,int);

int main(int argc, char** argv) {
  int inputNum;

  // When a command line argument is entered, set the input number
  if(argv[1] != NULL && atoi(argv[1]) != 0) {
    inputNum = atoi(argv[1]);
  } // If there is no command line argument, prompt the user for a number and set the input number
  else {
  printf("To print a pattern, enter a nonnegative integer: \n");
  // Assign user input to inputNum
  scanf("%d", &inputNum);
  }
  // Print the pattern
  for (int i = 1; i <= inputNum; ++i) {
    char* pattern = PrintPattern(inputNum, i);
    printf("%s\n", pattern);
  }
  return 0;
}
/*
 * Prints a pattern of a certain length containing a given number of asterisks
 * preceded by dashes.
 */
char* PrintPattern(int length, int asteriskNum) {
  // Allocate the size of the char array on the heap
  char* pattern = malloc(sizeof(char)*(length + 1));
  int dashLength = length - asteriskNum;
  // Add dashes to char array
  for (int i = 0; i < dashLength; ++i) {
    pattern[i] = '-';
  }
  // Add asterisks to char array
  for (int i = dashLength; i < length; ++i) {
    pattern[i] = '*';
  }
  // End string with null terminator
  pattern[length] = '\0';
  return pattern;
}
