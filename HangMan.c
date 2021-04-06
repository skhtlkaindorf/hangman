#include <stdio.h>
#include <string.h>


void print(int counter, char *ch) {
      printf("%d: %s - length: %d\n",counter, ch , strlen(ch));
}


int main(){

   FILE *fp;
   char buff[255];

   int counter = 0;

   fp = fopen("dictionary.txt", "r");
   while (fgets(buff, 255, (FILE*)fp) != NULL)
   {
      counter++;
      buff[strlen(buff) - 1] = '\0';
      print(counter, buff);
   }

   printf("Total lines: %d", counter);

   fclose(fp);
}