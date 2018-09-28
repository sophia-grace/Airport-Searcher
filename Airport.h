//   File:          Airport.h
//   Purpose:       The header file for Airports.
//   Author:        Sophia Trump
//   Date:          18 April 2018


typedef struct {
  char *code;
  char *name;
  char *city;
  char *state;
  char *country;
} Airport;


//print Airport object
void show(Airport a);
//parse code into Airport object and return pointer to Airport
Airport *parse(char *code);
//compare Airport code with user input code
//called from contains function in List.c
int compareAirport(const void *item1, const void *item2);
