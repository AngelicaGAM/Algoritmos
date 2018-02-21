/* 
 * File:   BitStuffing.cpp
 * Author: angelica
 *
 * Created on 19 de febrero de 2018, 10:28 PM
 */

#include <cstdlib>
#include<string.h>
#include<stdio.h>
#include <math.h>

int main() {
        
        char Hec[50];
        int c=0,n,p=2 ,tam;
	char str[50];
   //Bandera
	str[0]='0';
        str[1]='1';
        str[2]='1';
        str[3]='1';
        str[4]='1';
        str[5]='1';
        str[6]='1';
        str[7]='0';
        
        
        printf("Tamaño de tu mensaje   ");
        scanf("%d",&tam);
        
        for(int q=8;q<8+tam;q++){
            
        printf("Ingresa tu mensaje Bit[%d]:   ",q);
 	scanf("%s",&str[q]);   
        
        }
       
        
	for (int i=8;i<strlen(str);i++) {
            int ban=0;
		for (int j=i;j<=(i+5);j++) {
			if(str[j]=='1') {
				ban++;
			}
		}
		
		if(ban==6) {
		  int nl=strlen(str)+2;
		   for (;nl>=(i+5);nl--)
                        {
			str[nl]=str[nl-1];
			}
			str[i+5]='0';
			i=i+7;
		}
	}
        //Bandera
        n=strlen(str);
        str[n+1]='0';
        str[n+2]='1';
        str[n+3]='1';
        str[n+4]='1';
        str[n+5]='1';
        str[n+6]='1';
        str[n+7]='1';
        str[n+8]='0';
        str[n+9]='x';
        
        printf("\nMensaje: ");
        for(int u=0;u<=n+10;u++){
            printf(" %c",str[u]);
        }
        printf("\n");
       
        
       for( int y=c ; y <= 10 ;y++ ){
             if(c>p){
                 c=10;
             }
            
        if (str[c]== 'x' || str[c+1]== 'x' || str[c+2]== 'x' || str[c+3]=='x') { 
            if (str[c]== 'x')    
            {
                //fin
                c=10;
            
            }
            else if(str[c+1]=='x'){
                str[c+1]='0';
                str[c+2]='0';
                str[c+3]='0';
            c=c-4;
            }
            else if(str[c+2]=='x'){
                str[c+2]='0';
                str[c+3]='0';
                c=c-4;
            
            }
            else if(str[c+3]=='x'){
                str[c+3]='0';
            c=c-4;
            }
        
        }
        
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='0'; 
            p=p+1;
        c=c+4; 
        }
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='1'; 
        p=p+1;  
        c=c+4;
        }
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='2'; 
            p=p+1;
            c=c+4;
         }
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 1) { 
            Hec[p]='3'; 
            p=p+1;
        c=c+4;    
        }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='4'; 
            p=p+1;
        c=c+4;
        }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='5'; 
            p=p+1;
        c=c+4;
        }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='6'; 
            p=p+1;
        c=c+4;    
            }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 1) { 
            Hec[p]='7'; 
            p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='8'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='9'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='A'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 1) { 
            Hec[p]='B'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='C'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='D'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='E'; 
        p=p+1;
        c=c+4;
        }
        
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 1) { 
        Hec[p]='F'; 
        p=p+1;
        c=c+4;
        }
        
        }
        
        int q;
        q=strlen(Hec);
        printf("\nHex: ");
       
        for(int u=0;u<=q;u++){
            printf("%c",Hec[u]);
        }
        
       
}
        
       
     /*  int mul=strlen(str);
       int base=0, suma=0;
      
       
      printf("\nMult: %d",mul);
       
       for(int y=0;y<=mul;y++){
           
           if(str[y]=='1'){
               
               mul=mul-1;
               base=pow(2,mul);

               suma=base+suma;
               
           }
           else
               mul=mul-1;
       
       }
       printf("BASE %d",base);
       printf("%d",suma);
      
      */
         
        

        


/*        
         for( int y=c ; y <= 10 ;y++ ){
             if(c>p){
                 c=10;
             }
            
        if (str[c]== 'x' || str[c+1]== 'x' || str[c+2]== 'x' || str[c+3]=='x') { 
            if (str[c]== 'x')    
            {
                //fin
                c=10;
            
            }
            else if(str[c+1]=='x'){
                str[c+1]='0';
                str[c+2]='0';
                str[c+3]='0';
            c=c-4;
            }
            else if(str[c+2]=='x'){
                str[c+2]='0';
                str[c+3]='0';
                c=c-4;
            
            }
            else if(str[c+3]=='x'){
                str[c+3]='0';
            c=c-4;
            }
        
        }
        
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='0'; 
            p=p+1;
        c=c+4; 
        }
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='1'; 
        p=p+1;  
        c=c+4;
        }
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='2'; 
            p=p+1;
            c=c+4;
         }
        else if (str[c]== 0 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 1) { 
            Hec[p]='3'; 
            p=p+1;
        c=c+4;    
        }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='4'; 
            p=p+1;
        c=c+4;
        }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='5'; 
            p=p+1;
        c=c+4;
        }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='6'; 
            p=p+1;
        c=c+4;    
            }
        else if (str[c]== 0 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 1) { 
            Hec[p]='7'; 
            p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='8'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='9'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='A'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 0 && str[c+2]== 1 && str[c+3]== 1) { 
            Hec[p]='B'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 0) { 
            Hec[p]='C'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 0 && str[c+3]== 1) { 
            Hec[p]='D'; 
        p=p+1;
        c=c+4;
        }
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 0) { 
            Hec[p]='E'; 
        p=p+1;
        c=c+4;
        }
        
        else if (str[c]== 1 && str[c+1]== 1 && str[c+2]== 1 && str[c+3]== 1) { 
        Hec[p]='F'; 
        p=p+1;
        c=c+4;
        }
        
        
        }
        */
        