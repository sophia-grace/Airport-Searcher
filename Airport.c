//   File:          Airport.c
//   Purpose:       The Airport's functionalities.
//   Author:        Sophia Trump
//   Date:          18 April 2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Airport.h"


// print Airport object
void show(Airport a) {
   printf("%s - %s, %s, %s (%s).\n",a.code,a.name,a.city,a.state,a.country);
} // show()


//set up the members of airport from readData() call
//then return the initialized airport object to store in data member
Airport *parse(char *str) {
  Airport * result = malloc(sizeof(Airport));
  char *token;

  token = strtok(str, ",");
  result -> code = malloc((strlen(token) * sizeof(char)) + 1);
  strcpy(result->code, token);

  token = strtok(NULL, ",");
  result -> name = malloc((strlen(token) * sizeof(char)) + 1);
  strcpy(result->name, token);

  token = strtok(NULL, ",");
  result -> city = malloc((strlen(token) * sizeof(char)) + 1);
  strcpy(result->city, token);

  token = strtok(NULL, ",");
  result -> state = malloc((strlen(token) * sizeof(char)) + 1);
  strcpy(result->state, token);

  token = strtok(NULL, ",");
  result -> country = malloc((strlen(token) * sizeof(char)) + 1);
  strcpy(result->country, token);

  return result;
} //parse()


//compare Airport code with user input code
//called from contains function in List.c
int compareAirport(const void * a, const void * b) {
  Airport * airport = (void *)(a);
  char * code = (char *)(b);
  return (strcmp(code, airport->code) == 0);
}
