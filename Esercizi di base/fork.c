#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
int main()
{
    int pid1,pid2,pid3,exitstatus;
   

    printf("Inizio\n");
    
   sleep(2);
   pid1=fork();

   //Figlio 1 
   if(pid1==0)
   {
      sleep(2);
      printf("----------------\n");
      printf("Sono il figlio con il pid %d\n",pid1);
      printf("----------------\n");
      printf("Adesso faccio la tabellina del 5\n");
     

      for(int i=0;i<11;i++)
      printf("5x%d=%d\n",i,5*i);

      
      exit(0);
   }
   
   sleep(5);
   pid2=fork();

   //Figlio 1 
   if(pid2==0)
   {
      sleep(2);
      printf("----------------\n");
      printf("Sono il figlio con il pid %d\n",pid2);
      printf("----------------\n");
      printf("Adesso faccio la tabellina del 7\n");
     

      for(int i=0;i<11;i++)
      printf("7x%d=%d\n",i,7*i);

      
      exit(0);
   }



   //Padre del figlio 1 e figlio 2
   else
   {
     printf("----------------\n");
     printf("Sono il padre con il pid %d\n",pid1);

     
     printf("Mio figlio 1 ha finito\n");
     sleep(2);
     waitpid(pid1, NULL, 0);
     printf("----------------\n");

   
     printf("Mio figlio 2 ha finito\n");
     sleep(2);
     waitpid(pid2, NULL, 0);
     
     printf("----------------\n");

     printf("Sono il padre con il pid %d adesso tocca a me\n",pid1);
     printf("Adesso faccio la tabellina del 6\n");
     printf("----------------\n");
     sleep(2);

      for(int i=0;i<11;i++)
      printf("6x%d=%d\n",i,6*i);

     printf("Sono il padre con il pid %d e mio padre e' con il ppid %d\n",pid1,getppid());
     

   }


  
    
    
  
}
