#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


#define buffersize 2048

/*Questo programma prende i dati dal file sorgente e li copia sul file di destinazione, 
poi tramite il comando execv utilizzo il comando cat per visualizzare cosa c'è all'interno del file di destinazione. */
int main(int argc, char * argv [])
{
    
    int file1,file2,size,result;
    char buffer[buffersize];
    
    

    if(argc<4)
    {
       printf("Sintassi: <sorgente> <destinazione> <comando>\n");
    }

    if((file1=open(argv[1],O_RDONLY))==-1)
    {
      perror("Errore sull'apertura del file sorgente");
      exit(1);
    }

    if((file2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0700))==-1)
    {
      perror("Errore sull'apertura del file di destinazione");
      exit(1);
    }

    do
    {
       if((size=read(file1,buffer,buffersize))==-1)
    	{
      	  perror("Errore sulla lettura file sorgente");
      	  exit(1);
    	}

        if((result=write(file2,buffer,size))==-1)
    	{
      	  perror("Errore sulla scrittura file di destinazione");
      	  exit(1);
    	}

    }
  
    while(size==buffersize);

     printf("Sto eseguendo il comando %s sul file %s\n",argv[3],argv[2]);
    
     execvp(argv[3],argv);

    

    close(file1);
    close(file2);



}
