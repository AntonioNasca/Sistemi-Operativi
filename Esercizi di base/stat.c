#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define buffsize 2046
#define MODE 0660
int main(int argc, char * argv [])
{
    int file1,file2,size,result,status;
    struct stat statbuf; //Utilizzo questo intero per determinare da dove devo copiare
    char buffer[buffsize];
    const char * type;
    mode_t modes; 

    if(argc<3)
    {
       printf("Sintassi <sorgente> <destinazione>");
       exit(1);
    }

    //Raccolgo informazioni su file o directory
    if (lstat(argv[1], &statbuf) == -1) {
        perror(argv[1]);
        exit(1);
    }

    //Vedo se è una directory
    modes=statbuf.st_mode;
    if ((modes & S_IFMT) == S_IFDIR)
    {
      printf("IL file e' una directory\n");
    } 

    else
    {
      printf("IL file non e' una directory\n"); 
    }  

    

    //Apro il file
    if((file1=open(argv[1], O_RDONLY))==-1)
    {
       perror("Errore per l'apertura del file");
       exit(1);
    }

 

    //Apro il file di destinazione oppure lo creo se non c'è
    if((file2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,MODE))==-1)
    {
      perror("Errore nella creazione del file di destinazione");
      exit(1);

    }

  
    
   
     //Adesso scrivo sul file
    do
       {

           if((size=read(file1,buffer,buffsize))==-1)
   	  {
      	    perror("Errore sulla lettura del file sorgente");
     	    exit(1);
    	  } 
       
           
         
    	  if((result=write(file2,buffer,size))==-1)
   	 {
      	    perror("Errore sulla creazioen del file di destinazione");
     	    exit(1);
    	 }
 
       
       }  while(size==buffsize);
   


    printf("Ho finito\n");
    close(file1);
    close(file2);
    

   
}
