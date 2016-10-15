#include <stdlib.h>
#include<stdio.h>
#include<conio.h> 
#include<time.h>
#include<string.h>


struct personne
{ 
       char Name[20] ;
       char Surname[20];
        int Score ;
};

struct carte   //les cases de la matrice à mémoriser sont de type carte
{ int val ;
  int tr ; //trouver ou pas trouver
};

struct table  //les cases de la matrice console sont de type table
{ int  val    ;
  char s [10]  ;
  char tr[10]  ;
} ;


//identification du joueur
void identification(personne *p )
{ 
     printf("->Name:\n");
    scanf("%s",& p->Name);
    printf("->Surname:\n");
    scanf("%s",& p->Surname);
    system("cls");
    p->Score = 0;
}


//affichage du menu
void menu(personne *p) 
{
     char mode ;

   do {
             do {
             
			 printf("\n              >Press \t1: Start\n                     \t2: How To Play\n                \t3: Quit\n"); 
             scanf("%c",&mode);
                    if( !(mode <= '3' && mode >= '1')  ) { system("cls") ; printf("    \n\n\t\t\t ==========  NOT VALIDED choice  ==========  \n\n    ") ;}
               
			   } while ( !(mode <= '3' && mode >= '1') ) ;
        
		if ( mode == '1')
           { identification( p ) ;
             printf("                             > GET READY ! \n");
           }
       else if(mode == '2')
             { system("cls") ;
             printf("***************************************************************************");
             printf("\n\n");
			 printf ("\t> A matrix of pairs will be shown on the screen.\n"); 
             printf("\t> You have to memorise all the pairs.\n");
             printf("\t> In each try, You loose a shot.\n");
             printf("\t> You have 20 shots.\n");
             printf("\t> If the number of shots is zero you will lose the game.\n");
             printf("\t> You can press '99' for help.\n");
             printf("\t> Each second for help means that you are going to lose one shot.\n");
             printf("\t> Your score is how much shots left at the end of the game.\n");
             printf("\n\n");
              printf("                       HAVE FUN!             \n\n");
			  printf("**************************************************************************");
			  printf("\n\n");
			  }
              
       else if (mode =='3')
             exit(0);
             
     } while ( mode=='2' );
}




//remplissage de la matrice M dont l'utilisateur doit mémoiriser , elle est constitée des paire des nombre {1,2,3,4,5,6,7,8}
void remplissage (carte **M ) 
{    int i ,j , x ;
     int T[8]= {0,0,0,0,0,0,0,0} ;
 srand( time(NULL));
     i=0 ;
  do {
        j=0;
              do
               {
                  
                  M[i][j].tr = 0 ;
                         do{
                             x = (rand()%8)+1  ;
	                       }while(T[x-1]==2);
	              T[x-1]=T[x-1]+1  	 ;
                  M[i][j].val = x  ;
                  j++;
               }while (j<4 );
       
	   i++;
    }while(i<4);
 
}
 
 
 
 //fonction qui affiche la matrice M dont le joueur doit mémoriser
 void affichage (carte **M)
    { int i, j ;

	  for (i=0 ;i<4 ;i++) 
	    {  
	      
	      
	      printf("-----------------------------------------------------------------\n") ;
	      printf("|\t \t|\t \t|\t \t|\t \t|\n");
	      printf("|") ;
  	  
               for (j=0 ; j<4 ; j++) 
	          {
       
                printf ("\t%d\t|" , M[i][j].val   ) ;
              }
         printf("\n");
         printf("|\t \t|\t \t|\t \t|\t \t|\n");
       }
      
	     printf("-----------------------------------------------------------------\n") ;
   } 
   
   
   
   
   //fonction attendre
      void attendre(float temps)
{
	clock_t arrive=clock()+(temps*CLOCKS_PER_SEC) ;
	while (clock()<arrive);
}



// remplissage de la matrice console M1
 void remplissage ( struct table **M1 ) 
{  int i ,j ;

   for (i=0 ; i<4 ; i++)
   {      for(j=0 ;j<4 ; j++) 
          { M1[i][j].val = 10*i +j ;
               
             strcpy(M1[i][j].s , "     " ) ;  
              strcpy(M1[i][j].tr , "         " ) ;;
           
          }
   }
      
}  

void chaine (char ch[30])
{ int i ,j ;
  	for(i=0;i<=10;i++)
	{   system("cls");
	    for(j=0;j<=i;j++) { printf("\n");}
	    for(j=0;j<=i;j++) { printf("  ");}
		printf("%s",ch);
		attendre(0.3);
	}
	
}


//affichage de la matrice console M1
void affichage (table **M1)
    { int i, j ;

	  for (i=0 ;i<4 ;i++) 
	  {  
	                  printf("------------------------------------------------------------------\n") ;
	                  printf("|");
					 
					 
					  for (j=0 ; j<4 ; j++) 
	              {
                   printf ("\t%s|" , M1[i][j].tr  ) ;
                  }
  	                   printf("\n") ;
					   printf("|")  ;
                  
			if (i==0) 
			     {for (j=0 ; j<4 ; j++) 
	              {
                   printf ("\t(0%d)\t |" , M1[i][j].val   ) ;
				  }
				      
				      printf("\n") ;
				      printf("|")  ;
		     	}
			else{
				   for (j=0 ; j<4 ; j++) 
	              {
                   printf ("\t(%d)\t |" , M1[i][j].val   ) ;
				  }
				      
				      printf("\n") ;
				      printf("|")  ;
			    }
                    
					  for (j=0 ; j<4 ; j++) 
	              {
                   printf ("\t%s\t |" , M1[i][j].s  ) ;
                  }
  	                   printf("\n") ;
					   
	 }
      
	  printf("------------------------------------------------------------------\n") ;
	  printf("               >PRESS (99) FOR HELP \n") ;
	  
   } 
   
   
   int verif (int x ,carte **M , table **M1)
   { int v ,i ,j ;
      v=0 ;
      i=0; 
      do {
      	 j=0;
            do {
                 if(M[i][j].tr==0 && M1[i][j].val == x) v=1 ;  
                 j++;
                
               }while (j<=3 && v==0);
            i++;   
         }while(i<=3 && v==0  ) ;
         
         return(v) ;
   }
   
   
   int verif1 (carte **M)
   { int i, j, v ;
     v=1;
	 for(i=0;i<=3;i++)
	 { for(j=0;j<=3;j++) {if(M[i][j].tr==0) v=0;
	 }
	 }
       
    printf("c bn") ;
   	return(v);
   }
   
   
   void help (carte **M , table **M1 ,int *nbc)
   { int s , i ;
    
   	printf("\n\n\n");
    printf("           *** ATTENTION ***\n\n");
    printf("          > One Second ---> (-) One Shot \n\n\n");
           do{
               printf("          >  Shoose Time\n\n\n");
               scanf("%d", &s);
               if (*nbc<=s) printf("No More Shots Left ") ;
             }while (*nbc <=s) ;
    attendre(2);
   	printf("          >  You Will Lose %d Shots \n\n\n",s);
   	printf("                     *** TOP ***\n\n\n  ");
   	attendre(2);
   	 affichage (M) ;
   	 printf("\n\n");
   	   for(i=1;i<=s;i++) 
       { printf("   >%d\t" ,i); attendre(1) ;}
   	 system("cls") ;
   	 affichage(M1) ;
   	*nbc =*nbc -s+1 ;
   	
   	printf("%d",*nbc);
   }
   
   void find (carte **M ,table **M1 , int x , int y)
   { int x1 , x2 , y1 , y2 ;
     x1=x%10;  x2=x/10;
	  y1=y%10;  y2=y/10;
     M1[x2][x1].val=M[x2][x1].val ; M1[y2][y1].val=M[y2][y1].val ;
	    strcpy(M1[x2][x1].tr , " Found   " ) ;  
        strcpy(M1[y2][y1].tr , " Found   " ) ;
        M[y2][y1].tr =1 ;
        M[x2][x1].tr =1 ;
        
	    affichage (M1) ;
   }
   
   int verif_find (carte **M,int x, int y)
   {int v,x1 , x2 , y1 , y2 ;
     v=0;
     x1=x%10;  x2=x/10;
	  y1=y%10;  y2=y/10;
	  if (M[x2][x1].val== M[y2][y1].val) v=1 ;
	  return(v);
   }
   
   
   void seen(carte **M , table **M1 ,int x ,int y)
   { int x1 , x2 , y1 , y2 ;
     x1=x%10;  x2=x/10;
	  y1=y%10;  y2=y/10;
   	
   	printf("Box Number (%d):%d\nBox Number (%d):%d\n", x,M[x2][x1].val,y , M[y2][y1].val ) ;
           attendre(4) ;
           system("cls");
           strcpy(M1[x2][x1].s , " Seen " ) ;  
           strcpy(M1[y2][y1].s , " Seen  " ) ;
           affichage (M1) ;
   }
   
   void result ( personne p)
   { 
     char ch1[40] ="**  G  A  M  E    O  V  E  R   **" ;
     char ch2[40] ="**  Y  O  U    W  I  N  **" ;
      
    
   	 
	 if(p.Score==0)  { system("cls") ;
                      attendre(2) ;
                      chaine(ch1) ;
                printf("\n\n\n\n\n\n\n\n\n");
                printf("******************************************************************************\n\n");
                printf("           >  Name: %s \n\n" ,p.Name) ;
                printf("           >  Surname: %s \n\n" ,p.Surname) ;
                printf("           >  Score: %d \n\n" , p.Score) ;
                printf("******************************************************************************\n");
			     }
     if(p.Score>0)   
              { system("cls") ;
                 attendre(2) ;
                chaine(ch2) ;
                printf("\n\n\n\n\n\n\n\n\n");
                printf("*******************************************************************************\n\n");
                printf("           >  Name: %s \n\n" ,p.Name) ;
                printf("           >  Surname: %s \n\n" ,p.Surname) ;
                printf("           >  Score: %d \n\n" ,p.Score) ;
                printf("*******************************************************************************\n");
              } 
   }
   
   int jeu(carte **M, table **M1)
   
   { int vx,vy,s,i,nbc,x,y,coup;
    int fin_matrice = 0 ; 
   i=0;
   nbc=20;
   do{
    printf("   \nFIND PAIRS\n\n") ;
         do{
          printf("Enter First Box:\n");
          scanf ("%d" , &x) ;
          vx=verif(x , M , M1) ;
          if (x==99) vx=1 ;
           } while ( vx == 0 ) ;
        
		do{
          printf("Enter Second Box:\n");
          scanf("%d" , &y) ;
          vy=verif(y , M , M1);
          if (y==99) vy=1 ;
          } while( vy  == 0 || x==y);
     
	 system("cls");
     
         if(x==99 || y==99)                          { help (M,M1,&nbc) ;} 
   
         else if(verif_find(M,x,y) == 1)      {  find(M , M1 , x ,y) ;}
     
         else                                         { seen(M,M1,x,y);}
    i++;
    nbc=nbc-1 ;
    printf("        >You Still Have %d Shots\n\n\n " , nbc) ;
    
	fin_matrice=verif1(M) ;
   
   } while(nbc>0 && fin_matrice==0);
   
    return(nbc)  ;       
              
}
   




int main()
{ 
 int i, j ,nbc ;
carte **M;
table **M1;
struct personne p ;
    
	menu (&p);
	attendre(1);
    
	M=(carte**)malloc(4*sizeof(carte*)) ;
 
 for(i=0;i<4;i++)
 { M[i]=(carte*)malloc(4*sizeof(carte));
 } 
  
  remplissage (M) ;
  
  printf("You Have 10 Seconds To Memorise Matrix\n") ;
  attendre(3) ;
 
  printf("\n\n\n") ;
  printf("                      ******  TOP !!  ***** \n\n\n") ;
  attendre(1);
  
  affichage(M) ;
  printf("\n") ;
   for(i=1;i<11;i++) 
   { printf("   >%d\t" ,i);attendre(1) ; } 
   system("cls");
  
  M1=(table**)malloc(4*sizeof(table*)) ;
 for(i=0;i<4;i++)
 { M1[i]=(table*)malloc(4*sizeof(table));
 } 
  
   remplissage (M1) ;
   attendre(2) ;
   	affichage (M1) ;
  
  
  p.Score=jeu(M,M1);
	
	result (p) ;
 
  
 
    getch();

} 
