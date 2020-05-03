#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//need to name executable as lower or upper
void changeCase(int argc, char *argv[]){
  int c = 0;
    if(0 == strcmp(argv[0], "./lower")){
      printf("Exercise - 7.1\n");
      while(EOF != (c = getchar())){
          putchar(tolower(c));}
    } 
    else if(0 == strcmp(argv[0], "./upper")){
      printf("Exercise - 7.1\n");
      while(EOF != (c = getchar())){
        putchar(toupper(c));}
    }
    else printf("Name of executable is neither lower or upper.\n");
}

FILE *openFile(char *s){
  FILE *f;
  if ((f = fopen(s,"r"))==NULL){
    printf("Can't open file \n");
    exit(2);
  }
  return f;
}

#define BUFFSIZE 1000

void compareFiles(int argc, char *argv[]){
  FILE *fin1, *fin2;
  char buf1[BUFFSIZE], buf2[BUFFSIZE];
  int i = 0;

  fin1 = openFile(argv[1]);
  fin2 = openFile(argv[2]);

  while((fgets(buf1, BUFFSIZE, fin1) != NULL) 
      &&(fgets(buf2, BUFFSIZE, fin2) != NULL)){
        if(strcmp (buf1, buf2) != 0){
            printf( "Left line %d: %s\nRight line %d: %s\n", i, buf1, i, buf2);
        }
      i++;
  }

  fclose(fin1);
  fclose(fin2);
}

void printFiles(int argc, char *argv[]){
  int pg = 1;
  char c;
 
  for(int i = 1; i < argc; i++){
    printf("%s page%d\n\n", argv[i], pg);
    FILE *fin = openFile(argv[i]);
      
    while ((c = fgetc(fin)) != EOF) { 
      printf("%c", c); 
    }   
   
    printf("\n\n");
    ++pg;
    fclose(fin);
  }
}

int main(int argc, char *argv[]){
  
  changeCase(argc, argv);
  if(argc == 3){
    printf("Exercise - 7.6\n");
    compareFiles(argc, argv);
  }
  else if(argc > 1){
    printf("Exercise - 7.8\n");
    printFiles(argc, argv);
  }
  else{
    printf("No files given\n");
    exit(1);
  }
  return 0;
}
