#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define buffersize 2048
int main(int argc, char * argv [])
{
   int pipefd[2];
   char buffer[buffersize];
   
   if(pipe(pipefd)==-1)
   {
     perror("Errore nella creazione della pipe");
     exit(1);
   }

    //Creo il figlio che gestisce pipefd[0]

    if(fork()==0)
    {
       if(read(pipefd[0],buffer,buffersize)==-1) 
       {
          perror("Figlio:Errore nella lettura del messaggio");
     	  exit(1);
       }

       printf("Figlio: ho ricevuto il messaggio: %s\n",buffer);
       sleep(1);
       //Invio il messaggio al padre, per confermare la ricezione del messaggio
       strncpy(buffer,"Non crepi il lupo!", buffersize);
       printf("Figlio: sta inviando il messaggio: %s\n",buffer);
       sleep(1);

       if(write(pipefd[1],buffer,strlen(buffer)+1)==-1)
       {
          perror("Figlio:Errore nell'invio del messaggio al padre");
     	  exit(1);
       }
      
        exit(0);

    }


    //Creo il padre che gestisce pipefd[1]
    else
    {
       //Invio il messaggio al figlio
       
       strncpy(buffer,"In bocca al lupo!",buffersize);
       printf("Padre: sta inviando il messaggio: %s\n",buffer);
       sleep(1);
      if(write(pipefd[1],buffer,buffersize)==-1)
      {
         perror("Padre:Errore nell'invio del messaggio");
     	 exit(1);
      }

      sleep(1);

      if(read(pipefd[0],buffer,buffersize)==-1) 
       {
          perror("Padre:Errore nella lettura del messaggio");
     	  exit(1);
       }
 
      printf("Padre: ho ricevuto il messaggio: %s\n",buffer);

      wait(NULL);

      exit(0);
      
 
    }
 
 
   
}
