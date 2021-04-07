#include <stdio.h>
#include <stdlib.h>
#include  <fcntl.h>

//CREA DUE FILE DI TESTO UNO PIPPO E IL SECONDO TOPOLINO
int main()
{
   int file1,file2;
    
   if((file1=creat("pippo.txt",0600))==-1)
   {
      printf("Errore nella chiamata del creat per pippo.txt\n");
      exit(1);
   }

   if((file2=creat("topolino.txt",0700))==-1)
   {
      printf("Errore nella chiamata del creat per topolino.txt\n");
      exit(1);
   }


    printf("File creati, tutto okay\n");
}
   

