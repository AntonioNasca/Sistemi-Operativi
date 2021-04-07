#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char* argv[])
{
     int file,n;
     char buffer[100]="Testo molto lungo dentro il buffer";
      
     if(argc<2)
     {printf("Sintassi: <filesorgente>\n"); exit(1);}

     if((file=open(argv[1],O_RDONLY))==-1)
     {	 
         perror(argv[1]); 
	 exit(1);
     }

     if((n=read(file,buffer,100-1))==-1)
     {
         perror(argv[1]);
         exit(1);
     }

      buffer[n]='\0';

     printf("Ho letto la frase:\n%s ",buffer);


     close(file);
 
}
