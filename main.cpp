#include<stdio.h>
#include<string.h>

int main (){    
unsigned m=8;     
    
char Unirverso[8];

Unirverso[0]='a';
Unirverso[1]='b';
Unirverso[2]='c';
Unirverso[3]='d';
Unirverso[4]='e';
Unirverso[5]='f';
Unirverso[6]='g';
Unirverso[7]='h';

char cadA[8],cadB[8];
unsigned int cA[8]={0,0,0,0,0,0,0,0}; //a
unsigned int cB[8]={0,0,0,0,0,0,0,0}; //b
unsigned int aub[8]; //los que estan en ambos sin repetir 
unsigned int anb[8]; //solo los que estan en ambos
unsigned int amb[8]; //lo de a pero no b
unsigned int ac[8]; //not de a

printf("Conjunto A ");
scanf("%s",&cadA); 
printf("Conjunto B ");
scanf("%s",&cadB);
int con=0,con2=0;
while(cadA[con]!='\0'){
  if(cadA[0]=='-'){
      for(int y=0;y<8;y++){
      
      cadA[y]=0;
      }
      
  }  
  else{
  
    if(cadA[con]==Unirverso[0]){
      cA[0]=1;
      con++;  
        }
    else if(cadA[con]==Unirverso[1]){
    cA[1]=1;
    con++;
    }  
  
    else if(cadA[con]==Unirverso[2]){
    cA[2]=1;
    con++;
    }  
    else if(cadA[con]==Unirverso[3]){
    cA[3]=1;
    con++;
    }      
  
    else if(cadA[con]==Unirverso[4]){
    cA[4]=1;
    con++;
    }  
    else if(cadA[con]==Unirverso[5]){
    cA[5]=1;
    con++;
      }  
  
    else if(cadA[con]==Unirverso[6]){
    cA[6]=1;
    con++;
    }  

    else if(cadA[con]==Unirverso[7]){
    cA[7]=1;
    con++;
    }
  
 } 

}
while(cadB[con2]!='\0'){
    
    if(cadB[0]=='-'){
     for(int y=0;y<8;y++){
      
      cadB[y]=0;
      }
     
    }
    else{
    
    if(cadB[con2]==Unirverso[0]){
    cB[0]=1;
  con2++;  
  }
  else if(cadB[con2]==Unirverso[1]){
    cB[1]=1;
  con2++;
  }  
  else if(cadB[con2]==Unirverso[2]){
    cB[2]=1;
  con2++;
  }  
  else if(cadB[con2]==Unirverso[3]){
    cB[3]=1;
  con2++;
  }   
  else if(cadB[con2]==Unirverso[4]){
    cB[4]=1;
  con2++;
  }  
  else if(cadB[con2]==Unirverso[5]){
    cB[5]=1;
  con2++;
  }  
  else if(cadB[con2]==Unirverso[6]){
    cB[6]=1;
  con2++;
  }  
  else if(cadB[con2]==Unirverso[7]){
    cB[7]=1;
  con2++;
  }
    
    } 
        
    
    
}
for(int i=0;i<m;i++){
    aub[i]=cA[i]|cB[i];
}
for(int i=0;i<m;i++){
    anb[i]=cA[i]&cB[i];
}
for(int i=0;i<m;i++){
    amb[i]=cA[i]&(!cB[i]);
}
for(int i=0;i<m;i++){
    ac[i]=!cA[i];
}

        printf("\n");
    if(aub[0]==1){
        printf("%c",Unirverso[0]);
    }
    if(aub[1]==1){
        printf("%c",Unirverso[1]);
    }
    if(aub[2]==1){
        printf("%c",Unirverso[2]);
        }
    if(aub[3]==1){
       printf("%c",Unirverso[3]);
    }    
     if(aub[4]==1){
        printf("%c",Unirverso[4]);
    }
    if(aub[5]==1){
        printf("%c",Unirverso[5]);
    }
    if(aub[6]==1){
        printf("%c",Unirverso[6]);  
    }
    if(aub[7]==1){
        printf("%c",Unirverso[7]);
     }
    if(aub[0]==0 && aub[1]==0 && aub[2]==0 && aub[3]==0 && aub[4]==0 && aub[5]==0 && aub[6]==0 && aub[7]==0){
          printf("-");
      }
      
     printf("\n");
    if(anb[0]==1){
        printf("%c",Unirverso[0]);
    }
    if(anb[1]==1){
        printf("%c",Unirverso[1]);
    }
     if(anb[2]==1){
        printf("%c",Unirverso[2]);
    }
    if(anb[3]==1){
        printf("%c",Unirverso[3]);
    }
     if(anb[4]==1){
        printf("%c",Unirverso[4]);
    }
     if(anb[5]==1){
        printf("%c",Unirverso[5]);
    }
    if(anb[6]==1){
        printf("%c",Unirverso[6]);
    }
    if(anb[7]==1){
        printf("%c",Unirverso[7]);
        }
    
     if(anb[0]==0 && anb[1]==0 && anb[2]==0 && anb[3]==0 && anb[4]==0 && anb[5]==0 && anb[6]==0 && anb[7]==0){
          printf("-");
      }
      
     printf("\n");
    if(amb[0]==1){
        printf("%c",Unirverso[0]);
    }
    if(amb[1]==1){
        printf("%c",Unirverso[1]);
    }
     if(amb[2]==1){
        printf("%c",Unirverso[2]);
    }
    if(amb[3]==1){
        printf("%c",Unirverso[3]);
    }
     if(amb[4]==1){
        printf("%c",Unirverso[4]);
    }
     if(amb[5]==1){
        printf("%c",Unirverso[5]);
    }
    if(amb[6]==1){
        printf("%c",Unirverso[6]);
    }
    if(amb[7]==1){
        printf("%c",Unirverso[7]);
        }
    if(amb[0]==0 && amb[1]==0 && amb[2]==0 && amb[3]==0 && amb[4]==0 && amb[5]==0 && amb[6]==0 && amb[7]==0){
          printf("-");
      }
      
      printf("\n");
    if(ac[0]==1){
        printf("%c",Unirverso[0]);
    }
    if(ac[1]==1){
        printf("%c",Unirverso[1]);
    }
     if(ac[2]==1){
        printf("%c",Unirverso[2]);
    }
    if(ac[3]==1){
        printf("%c",Unirverso[3]);
    }
     if(ac[4]==1){
        printf("%c",Unirverso[4]);
    }
     if(ac[5]==1){
        printf("%c",Unirverso[5]);
    }
    if(ac[6]==1){
        printf("%c",Unirverso[6]);
    }
    if(ac[7]==1){
        printf("%c",Unirverso[7]);
        }

    if(ac[0]==0 && ac[1]==0 && ac[2]==0 && ac[3]==0 && ac[4]==0 && ac[5]==0 && ac[6]==0 && ac[7]==0){
          printf("-");
      }
   return 0;
   
 }