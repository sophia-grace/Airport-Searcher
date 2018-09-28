
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "List.h"

int compInt(const void *a, const void *b);
int main(void) {
   srand(time(NULL));

   List *L;

   L = newList();
   //1.  Created an empty list...
   printf("\n1. Created an empty list...\n");
   if (empty(L))
	printf("The list is empty.\n");
   print(L);

   // 2. Populate list with random#s
   printf("\n2. Populate list with random#s\n");
   for (int i=0; i < 10; i++) {
      int *nn = malloc(sizeof(int));
      *nn = rand()%100;
      add(L, nn);
   }
   print(L);

   if (empty(L))
	printf("The list is empty.\n");
   else
	printf("The list is not empty.\n");

   // 3. Clearing the list of its contents
   printf("\n3. Clearing the list of its contents\n");
   clear(L);
   if (empty(L))
	printf("The list is empty.\n");
   else
	printf("The list is not empty.\n");
   print(L);

   // 4. Repopulating the list with 10 #'s
   printf("\n4. Repopulating the list with 10 #'s\n");
   for (int i=0; i < 10; i++) {
      int *nn = malloc(sizeof(int));
      *nn = rand()%100;
      add(L, nn);
   }
   print(L);

   // 5. Testing get()...get element at a random index
   printf("\n5. Testing get()...get element at a random index\n");
   int i = rand()%size(L);
   printf("L[%d] = ", i);
   int *r = get(L, i);
   printf("%d\n", *r);

   // 6 Testing set - -99
   printf("\n6. Testing set\n");
   i = rand()%size(L);
   printf("L[%d] = ", i);
   int *j = malloc(sizeof(int));
   *j = 99;
   r = malloc(sizeof(int));
   r = (int *) set(L, i, j);
   printf("%d\n", *r);
   print(L);

   // 7/ testing contains(-99)
   printf("\n7. testing contains(99)\n");
   int *item = malloc(sizeof(int));
   *item = 99;
   int *result = (int *)contains(L, item, compInt);
   if (result)
	printf("The list contains %d.\n", *result);
   else
	printf("The list does not contain %d.\n", *item);

   printf("Contains a random element?\n");
   *item = rand()%100;
   result = (int *)contains(L, item, compInt);
   if (result)
	printf("The list contains %d.\n", *result);
   else
	printf("The list does not contain %d.\n", *item);

   // 8. Removing elements from start of list
   printf("\n8. Removing elements from start of list\n");
   int s = size(L);
   for (int x = 0; x < s/2; x++) {
      printf("removing from start of list = ");
      r = removeItem(L, 0);
      printf("%d\n", *r);
      print(L);
   }
   print(L);
   
   // 9. Removing elements from end of list
   s = size(L); 
   for (int x=0; x < s/2; x++) {
      printf("Removing from end of list = ", i, s);
      r = removeItem(L, size(L)-1);
      printf("%d\n", *r);
      print(L);
   }

   // 10. Repopulating the list with 10 #'s
   printf("\n10. Repopulating the list with 10 #'s\n");
   for (int i=0; i < 10; i++) {
      int *nn = malloc(sizeof(int));
      *nn = rand()%100;
      add(L, nn);
   }
   print(L);

   // 11. Removing some elements in the middle of the list
   printf("11. Removing l[3] from middle of list = ");
   r = removeItem(L, 3);
   printf("%d\n", *r);
   print(L);
   printf("11. Removing l[6] from middle of list = ");
   r = removeItem(L, 6);
   printf("%d\n", *r);
   print(L);

   // 12. Add an item at index
   printf("12. Add an item 89 at index - 3\n");
   i = 3;
   r = malloc(sizeof(int));
   *r = 89;
   addAt(L, i, r);
   print(L);
   printf("12. Add an item 89 at index - 6\n");
   i = 6;
   r = malloc(sizeof(int));
   *r = 90;
   addAt(L, i, r);
   print(L);
   printf("12. Add an item 91 at index - 0\n");
   i = 0;
   r = malloc(sizeof(int));
   *r = 91;
   addAt(L, i, r);
   print(L);
   printf("12. Add an item 92 at index - end\n");
   i = size(L);
   r = malloc(sizeof(int));
   *r = 92;
   addAt(L, i, r);
   print(L);

   // 13. Clear the contents!
   printf("13. Clear the contents!\n");
   clear(L);
   print(L);
 
   printf("14. Add an item 93 at index - 0\n");
   r = malloc(sizeof(int));
   i = 0; *r = 93;
   addAt(L, i, r);
   print(L);
   printf("14. Add an item 94 at index - 0\n");
   r = malloc(sizeof(int));
   i = 0; *r = 94;
   addAt(L, i, r);
   print(L);
   
   // 15. Test the iterator
   printf("15. Test the iterator\n");
   struct ListIterator *iter = newIterator(L);
   while (hasNext(iter)) {
      int *n = next(iter);
      printf("%d ", *n);
   }
   clearIterator(iter);
   printf("\n");
   
   // 15. Repopulating the list with 10 #'s
   printf("\n10. Repopulating the list with 10 #'s\n");
   for (int i=0; i < 10; i++) {
      int *nn = malloc(sizeof(int));
      *nn = rand()%100;
      add(L, nn);
   }
   print(L);
   printf("15. Test the iterator\n");
   iter = newIterator(L);
   while (hasNext(iter)) {
      int *n = next(iter);
      printf("%d ", *n);
   }
   clearIterator(iter);
   printf("\n");

   return(0);
} // main()

int compInt(const void *a, const void *b) {
   // Tests to see if objects *a and *b are equal. Returns 1 if, 0 o/w
   int *x = (int *) a;
   int *y = (int *) b;
   return (*x == *y);
} // compInt()
