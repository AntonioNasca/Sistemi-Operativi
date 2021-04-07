#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


#define buffsize 2046
int main(int argc, char * argv[])
{
    struct stat sb;
    int file1,file2;
    char *buffer1,*buffer2;
    


   if(argc<3)
    {
       printf("sintassi:./mmap <file_sorgente> <file_destinazione>\n");
       exit(1);
    }

   
   //Apro il file
   if((file1=open(argv[1],O_RDONLY))==-1)
   {
      perror("Errore nell'apertura del file sorgente");
      exit(1);
   }

   //Apro il file
   if((file2=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,(sb.st_mode &0700)))==-1)
   {
      perror("Errore nell'apertura del file di destinazione");
      exit(1);
   }


   //Controllo informazioni sul file
   if(fstat(file1,&sb)==-1)
   {
     perror("Errore sulla lettura delle informazioni");
     exit(1);
   }

   //Guardo se è un file
   if(!S_ISREG(sb.st_mode))
   {
     perror("Errore questo non e' un file");
     exit(1);
   }

   //Ridimensiono il fiel di output
   if(ftruncate(file2,sb.st_size)==-1)
   {
     perror("Errore sulla troncatura del file destinazione");
     exit(1);
   }

   //Mappare il file sorgente
   if((buffer1=(char*)mmap(NULL,sb.st_size,PROT_READ, MAP_SHARED, file1,0))==MAP_FAILED)
   {
     perror("Errore sulla mappatura in memoria del file sorgente");
     exit(1);
   }

   //Mappare il file sorgente
   if((buffer2=(char*)mmap(NULL,sb.st_size,PROT_WRITE, MAP_SHARED, file2,0))==MAP_FAILED)
   {
     perror("Errore sulla mappatura in memoria del file di destinazione");
     exit(1);
   }

   //Chiudo il file
   if(close(file1)==-1)
   {
     perror("Errore sulla chiusura del file");
     exit(1);
   }


   printf("Inseriro' questo contenuto sul file di output '%s':\n",argv[2]);

   //visualizzo i dati sulla  memoria mappata 
   for(int i=0;i<sb.st_size;i++)
   putchar(buffer1[i]);

   //Vado ad inserire
   if(memcpy(buffer2,buffer1,sb.st_size));
   {
     perror("Copiato con");
     printf("Benissimo utilizzare il comando cat su '%s':\n",argv[2]);

     exit(1);
   }

  

 

   
   munmap(buffer1,sb.st_size);
   munmap(buffer2,sb.st_size);


   close(file1);
   close(file2);
   
   
   

   

   

   


   
  
}

