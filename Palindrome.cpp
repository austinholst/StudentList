#include <iostream>
#include <string.h>
using namespace std;

/*
 *Name: Austin Holst
 *Date: 09 - 19 - 2017
 *Code: You input a word or multiple words and it tells you if It's a
 *palindrome
 */


int main() {
  

  //initializing char arrays                                           
  char start[81];
  char nospace[81];

  int counter = 0;

  cout << "Type something to see if it's a palindrome!" << endl;
  cin.get(start, 81);//Reads str 80  characters + terminating character
     
  for(int i = 0; i < 81; i++) {
    if(start[i] != ' ' && ispunct(start[i]) != true) {
      nospace[counter] = start[i];
      counter++;
    }
  }

  strcpy(start, nospace);//copies nospace into start so they are the same  
  
  //turns everything into lower case                                      
  for(int i = 0; i < 81; i++) {
    nospace[i] = tolower(nospace[i]);
    start[i] = tolower(start[i]);
  }

  int counter2 = strlen(nospace);
  int length = strlen(nospace);

  //Start at the end of the string and put all of the characters in a new string
  //going backwards                                                             
  char reverse[81];
  for(int i = 0; i < length +  1; i++) {
    reverse[i] = nospace[counter2 - 1];
    counter2--;
  }

  //comapre reverse and start array and see if they are the same                
  if(strcmp(reverse, start) == 0 ) {
    cout << "That is a palindrome!" << endl;
  }
  else {
    cout <<  "That is not a palindrome" << endl;
    }
  return 0;
}
