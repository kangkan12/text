// Emplementation of APRIORI ALgorithm

#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
int **Candidate, **T_table, **Frequent, No_of_T = 0, **temp1,**temp2;

// Frequent Itemset generate Fucntion*************************************
 int Generate_Frequent (int min_Sup, int k) {    
    int row = 0, i = 0, j = 0, c = 0, count = 0, F_row = 1, F_column = 1, column = 0, d = 0;
    Frequent = (int **)malloc(F_row * sizeof(int *));
    Frequent[F_row-1] = (int *)malloc(F_column * sizeof(int ));
    Frequent[F_row-1][F_column-1] = '&';
 while(Candidate[i][j] != '&')
 { 
  while (T_table[row][column] != '&') 
    {
    while (Candidate[i][j] != '#')
     {
     while (T_table[row][column] != '#') 
      {
      if (Candidate[i][j] == T_table[row][column]) 
       c++;
       column++;      
      }
     column = 0;
     if(c >= 1)
     {
     d++;
     }
     c = 0;
     j++;
    }
    if(d >= j)
    count ++;
   d = 0;
    column  = 0;
    j = 0;
    row++;
  }
  row = 0;
  j = 0;  
 if (count >= min_Sup) 
 {
  while(Candidate[i][j] != '#') 
   {
    Frequent[F_row-1][F_column-1] = Candidate[i][j];
    Frequent [F_row-1] = realloc( Frequent[F_row-1],++F_column * sizeof(int));
    Frequent[F_row-1][F_column-1] = '#';
    j++;
   }
   F_column = 1;
          Frequent = realloc(Frequent, ++F_row * sizeof(int *));
          Frequent[F_row-1] = (int *)malloc(F_column* sizeof(int ));
          Frequent[F_row-1][F_column-1] = '&';
 }
 i++;
 j = 0;
 count  = 0;
 }
 printf("\n\nFrequent %d_Itemsets = ",k);
 printf(" { ");
 for(i=0; i<F_row-1; i++)
  {
   j = 0;
  printf(" (");
  while(Frequent[i][j] != '#')
  {
   printf("%d,", Frequent[i][j]);
   j++;
  }
   printf("), ");
 }
 printf(" }");
F_row--;
return F_row;

}

//Candidate genarate function*******************************************************
void Generate_Candidate_itemSet ( int f_row, int k) {

 int row = 0, i, j,l, p, s, check = 0, col = 0, temp = 0, m =1 ;
  l = 1;
  p = f_row - l;
  s = p;  
  row = 0;
 int  column = 0, flag = 0,n_row = 1, c = 1, R_count = 0;
    Candidate = (int **)malloc(n_row * sizeof(int *));
    Candidate[n_row-1] = (int *)malloc(c * sizeof(int ));
    Candidate[n_row-1][c-1] = '&';

 if(Frequent[0][1] == '#')
  {
   j = 0;
 
   while(Frequent[row+1][0] != '&')
    {
     for(;n_row<p+1;j++)
     {
      Candidate[n_row-1][c-1] = Frequent[row][0];
      Candidate[n_row-1]= realloc(Candidate[n_row-1],++c * sizeof(int));
      Candidate[n_row-1][c-1] = Frequent[j+1][0]; 
      Candidate[n_row-1] = realloc(Candidate[n_row-1],++c * sizeof(int));
      Candidate[n_row-1][c-1] = '#'; 
      Candidate = realloc(Candidate,++n_row * sizeof(int *));
      c = 1;
      Candidate [n_row-1] = (int *)malloc(c * sizeof(int));
      Candidate[n_row-1][c-1] = '&';   
      R_count++;
     }
   row++;
   l++;
   p = f_row-l+p;
   j = row;
   } 
 }

else {
 c = 1;
 j = 0;
 i = 0;
 row = 1;

 while(Frequent[i][0] != '&')
 { 
  while(Frequent[row][0] != '&')
  {  
    while( Frequent[i][c-1] == Frequent[row][c-1])
   {
   
     if(Frequent[row][c+1] == '#' )
        {
        if (Frequent[i][c] != Frequent[row][c])
         {
          p = 1;
         
          while(Frequent[i][p-1] != '#')
          {
           Candidate[n_row-1][p-1] = Frequent[i][p-1];
           Candidate[n_row-1]= realloc(Candidate[n_row-1],++p * sizeof(int ));
         
          }
         Candidate[n_row-1][p-1] = Frequent[row][p-2];
         Candidate[n_row-1] = realloc(Candidate[n_row-1],++p * sizeof(int ));
         Candidate[n_row-1][p-1] = '#';   
         p = 1;
         Candidate = realloc(Candidate,++n_row * sizeof(int *));
         Candidate[n_row-1] = (int *)malloc(c * sizeof(int ));
         Candidate[n_row-1][p-1] = '&';
          R_count++;
         
         }
        } c++;
    
      
      }
      c = 1;
      row = row + 1;
     }
     
    i++;
    row = i+1;
    }
 
   }
/*printf("\n\nCandidate %d_ItemSets = ",k);
for(i = 0; i<R_count; i++)
{
printf(" (");
for(j = 0; j <  k; j++ ){
printf("%d,", Candidate[i][j]);
}
printf("), ");
}*/
}

//Prune function***************************************************
int Prune() {

}

//main function***************************************************
int main ()
{
    int i, j, t = 0, row = 1, column = 1, F_row;
    T_table = (int **)malloc(row * sizeof(int *));
    T_table[row-1] = (int *)malloc(sizeof(int) * column);
    printf ("\n\n\t******   Apriori ALgoRithM EmpleMenTation  *****");
    printf ("\n\n\t       Please Enter the items and $ to stop\n");
    char ch; 
    while((ch = getchar()) != '$') {
        if( ch != '\n') {
            t = ch - '0';
             
            T_table[row-1] = realloc( T_table[row-1],++column * sizeof(int) );
            T_table[row-1][column-2] = t; 
        } 
        else if (ch == '\n') {
             No_of_T ++;
             T_table[row-1][column-1] = '#';
             column = 1;
             T_table = realloc(T_table, ++row * sizeof(int *));
             T_table[row-1] = (int *)malloc(sizeof(int) * column);
             T_table[row-1][column-1] = '&';
        }
        
    }
    printf ("\n  Number of transection is %d\n", No_of_T);  
    printf ("\n  The transections are :\n");
    for (i = 0; i < No_of_T; i++) {
          j=0;
          printf("\n  TID %d   ",(i+1));
          while (T_table[i][j] != '#') {
            printf("%d ",T_table[i][j]);
            j++;
          }
          printf("\n");   
    }
    int  N = 1, M = 0, l, flag = 0, k = 1;
   
    Candidate = (int **)malloc(N * sizeof(int *));
    Candidate[N-1] = (int *)malloc(k * sizeof(int));
    Candidate[N-1][k-1]= '&';
    for (i = 0; i < No_of_T; i++) {
         j=0;
         while (T_table[i][j] != '#') {
            for(l = 0; l < N  ; l++) {
                if(T_table[i][j] == Candidate[l][k-1]) {
                   flag = 0;
                   M = 1;
                   }
                   else
                   flag = 1;
            }
            if (flag == 1 && M != 1) {
               Candidate[N-1][k-1] = T_table[i][j];
               Candidate[N-1] = realloc(Candidate[N-1],++k * sizeof(int ));
               Candidate[N-1][k-1]= '#';
               k =1;
               Candidate = realloc(Candidate,++N * sizeof(int *));
               Candidate[N-1] = (int *)malloc(	k * sizeof(int));
               Candidate[N-1][k-1]= '&';
               flag = 0;
            }
            M = 0;
          j++;     
         }       
     }
     int min_Sup;
    printf ("\n  Please Enter the minimum Support value number:  ");
    scanf ("%d",&min_Sup);
    
      N=N-1; 
  // Candidate set is arrange in ascending order
  int swap;
  for (i = 0; i < N; i++) {
    
       for(j = i+1; j< N;j++) {
       if( Candidate[i][0] >Candidate[j][0] ) {
         swap = Candidate[i][0];
         Candidate[i][0] = Candidate[j][0];
         Candidate[j][0] = swap;
         }
        }    
     
       }


    /*printf ("\n  The One Candidate itemSets are: ");
    for (i = 0; i < N; i++) {
      printf(" (");
       for(j = 0; j< 1;j++) {
        printf("%d,",Candidate[i][j]);
         }    
      printf(") ");
       }*/
       
k = 1;
F_row = Generate_Frequent (min_Sup,k);
k++;
while(F_row > 1){
   Generate_Candidate_itemSet (F_row,k) ;
   F_row = Generate_Frequent (min_Sup,k);
   k++;
  }
} 
