#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

//Comando <sorgentedacopiare> <destinazionefilecopiato>
int main(int argc, char *argv[])
{
     int file1, file2, sizefile, result;
     char buffer[1024];


     if(argc<3)
     {
        printf("Devi riscrivere il comando, sintassi: %s <sorgentedacopiare> <destinazionefilecopiato>\n ", argv[0]);
	exit(1);
     }
     
     //Apro file1 con solo permessi di lettura
     if((file1=open(argv[1],O_RDONLY))==-1)
     {
       perror(argv[1]);
	exit(1);
     }
 
      //Apro file2 con  permessi di scrittura,creazione e troncamento
     if((file2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC),0600)==-1)
     {
        perror(argv[2]);
        exit(1);  
     }
     
     //Copiare i dati
     
     do
     {
        //Leggo al massimo 1024 byte
        if((sizefile=read(file1,buffer,1024))==-1)
        {
           perror(argv[1]);
	   exit(1);
        }

        //Leggo al massimo 1024 byte
        if((result=write(file2,buffer,sizefile))==-1)
        {
           perror(argv[2]);
	   exit(1);
        }

     }

    while(sizefile==1024);

    close(file1);
    close(file2);

}
