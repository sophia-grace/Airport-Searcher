//   File:          search.c
//   Purpose:       Creates a database of Airports, searchable by
//                  airport code, from code.txt. Airports are stored
//                  in a linked list.
//   Author:        Sophia Trump
//   Date:          18 April 2018


//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "List.h"

#define MAX_INPUT 3
#define MAX_YN 1


//declarations
void readData(char *file, List *airports, int *n);
int more(void);


int main(int argc, char *argv[]) {
  List *airportList;
  airportList = newList();

  char input[MAX_INPUT + 1];
  int found;                                    //index of the matching airport
  int nA = 0;


  //variables used for the write up
  Airport nonUsExample;
  int nonUsCount = 0;
  int largestName;

  //CHECK COMMAND LINE ARGS
  if(argc != 2) {  //must have program name and txt file
    printf("Cannot proceed: Missing file name.\n");
    exit(EXIT_FAILURE);
  }

  //INITIALIZE AIRPORT OBJECTS
  readData(argv[1], airportList, &nA);
  printf("done. [%d airports!]\n", nA); //print the number of airports read

  //SEARCH
  do {
    printf("\n");

    //get code from user
    printf("Enter the three-letter code for an airport: ");
    scanf("%s", input);

    if(strlen(input) > 3) {  //check that airport code length is 3
      printf("Invalid airport code.\nGoodbye!\n");
      exit(EXIT_FAILURE);
    }

    //search for code and output result
    Airport *found;
    found = queryAirport(airportList, input);
    if(found == NULL) {
      printf("Unsuccessful: %s is not a known airport.\n", input);
    }
    else { //found points to an airport
      printf("Success: ");
      show(*found); //dereference found to print the airport
    }
  } while(more());

  printf("\nThis was a database of %d airports.\n", size(airportList));
  printf("Goodbye!\n");
  printf("\n");

  return 0;
} //main()


int more() {
  char yn[MAX_YN + 1];                           //contains Y/N input from user

  //check if user would like to continue
  while(1) {
    printf("Would you like to search again (Y/N)? ");
    scanf("%s", yn);
    if((strcmp(yn, "Y") == 0) || (strcmp(yn, "y") == 0)) {
      return 1;
    }
    else if((strcmp(yn, "N") == 0) || (strcmp(yn, "n") == 0)) {
      return 0;
    }
    else {
      printf("Invalid input. Please try again.\n");
    }
  }
} // more()


void readData(char *file, List *airports, int *n) {
  FILE *fp;

  int i = 0;          //# of airports read

  fp = fopen(file, "r");
  if(fp == NULL) {
    printf("Unable to open file: %s\n", file);
    exit(EXIT_FAILURE);
  }
  printf("Able to open file: %s\n", file);

  printf("Reading data...");

  char line[80];
  fgets(line, sizeof(line), fp); //ignore first line
  while((fgets(line, sizeof(line), fp)) != NULL) {

    int l = strlen(line);
    line[l - 1] = '\0'; //append null char
    Airport *a = malloc(sizeof(Airport));

    a = parse(line);

    add(airports, a); //add newly parsed Airport to the list

    i++;
  }

  *n = i; //set the number of airports read to i
  fclose(fp);
} //readData()
