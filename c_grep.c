#include <stdio.h>
#include <stdbool.h>


bool isThisCharInThisWord(int, char *, int);
bool isEndOfFile(int);
bool isANewLine(int);
void printTheLineNumber(long);


int main() {


  int   thisLetter         = 0;
  long  lineNumber         = 1L;
  char* findThisWord       = "main";
  int   findThisWordLength = 4;
  int   lengthOfMatch      = 0;


  while ( !isEndOfFile(thisLetter) ) {


    thisLetter = getchar();


    if (isEndOfFile(thisLetter)) { break; }
    if (isANewLine(thisLetter))  { lineNumber++; }


    while (isThisCharInThisWord(thisLetter, findThisWord, findThisWordLength)) {

      lengthOfMatch++;

      thisLetter = getchar();

      if (isEndOfFile(thisLetter)) { break; }
    }

    if (lengthOfMatch == findThisWordLength) { printTheLineNumber(lineNumber); printf("%s\n", findThisWord); }

    lengthOfMatch = 0;
  }

  return 0;
}



bool isEndOfFile(int c) {
  return c == EOF;
}



bool isANewLine(int c) {
  return c == '\n';
}



bool isThisCharInThisWord(int c, char * word, int wordLength) {
 
  for (int letter = 0; letter < wordLength; letter++) {

    int tempc = word[letter];

    if (c == tempc) { return true; } 
  }

  return false;
}



void printTheLineNumber(long lineNumber) {
  printf("%ld: ", lineNumber);
}
