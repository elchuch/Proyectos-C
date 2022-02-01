#include<iostream>     
#include<stdio.h>      
#include<math.h>    
#include<conio.h>     
#include <iomanip>
#define FILAS_B  2
#define COLUMNAS_B 1
#define FILAS_A 2
#define COLUMNAS_A 2
#define filas_B  3
#define columna_B 1
#define filas_A 3
#define columna_A 3
#define Presi 10 
using namespace std;
char op;
void f1(){
	int ii=0;
	double Xaux,Yaux;
	double x,y,FX1,FX2,producto[FILAS_B][COLUMNAS_B];
	double M[FILAS_A][COLUMNAS_A ],det,aux,a00,a01,a10,a11,MFX[FILAS_B][COLUMNAS_B ];
	double tolerancia,itera;
	 printf("\n\nSistema de ecuaciones 1");
	 printf("\n************");
	cout << setprecision(Presi); 
	cout<<"\nIngresar punto x:  ";cin>>x;
	cout<<"\nIngresar punto y:  ";cin>>y;
	cout<<"\nIngresar numero maximo de iteraciones: ";cin>>itera;
	cout<<"\nIngresar tolerancia:  ";cin>>tolerancia;
	cout<<"\n";	cout<<"\n";	cout<<"\n";
        do{
        
        ii=ii+1;
        printf("\nITERACION [%i]\n",ii-1);
        fflush(stdin);
        a00=(2*x)+y;
        a01=x;
        a10=3*(y*y);
        a11=1+(6*x*y);
        FX1=(x*x)+(x*y)-10;
        FX2=y+3*(x*y*y)-50;
        /////////////////
        MFX[0][0]=FX1;
        MFX[1][0]=FX2;
        det=a00*a11-a10*a01;
        M[0][0]=a11/det;
        M[0][1]=(-a01)/det;
        M[1][0]=(-a10)/det;
        M[1][1]=a00/det;
        cout<<"x: "<<x<<"\n";
        cout<<"y: "<<y<<"\n";
        printf("\n");
       
        printf("JACOBIANA\n");
        for(int i=0;i<FILAS_A;i++)
		{
			for(int j=0;j<COLUMNAS_A;j++){
				M[i][j];
				cout<<M[i][j]<<"\t";//Hasta aqui la Jacobiana esta calculada
			}
			cout<<"\n";
		}
	
		
	      printf("\n");
		 printf("F(x)\n");
		for(int i=0;i<FILAS_B;i++){
			for(int j=0;j<COLUMNAS_B;j++){
				MFX[i][j];
				cout<<MFX[i][j]<<"\t";
			}
			cout<<"\n";
		}
		
///////////		//////////////////////////////////////////////////////////////////7
		 for (int a = 0; a < COLUMNAS_B; a++) {
        
        for (int i = 0; i < FILAS_A; i++) {
            double suma = 0;
          
            for (int j = 0; j < COLUMNAS_A; j++) {
             
                suma += M[i][j] * MFX[j][a];
            }
        
            producto[i][a] = suma;
        }
    }

    printf("\n");
    printf("F(x)*J(x)-1\n");
    for (int i = 0; i < FILAS_B; i++) {
        for (int j = 0; j < COLUMNAS_B; j++) {
            cout<<producto[i][j]<<"\t";
        }
        printf("\n");
    }
       //calculamos la resta
    Xaux=x-producto[0][0];
    Yaux=y-producto[1][0];
    x=0;
    y=0;
    x=Xaux;
    y=Yaux;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
		}while(ii<itera);
		printf("\nUsted quiere ingresar otro punto(digite la letra 's',caso contrario pulse otra tecla): ");scanf("%c",&op);
		if(op=='s' || op=='S'){
			system("cls");
			 f1();
		}
}
void f2(){
		int ii=0;
	double Xaux,Yaux;
	double x,y,FX1,FX2,producto[FILAS_B][COLUMNAS_B];
	double M[FILAS_A][COLUMNAS_A ],det,aux,a00,a01,a10,a11,MFX[FILAS_B][COLUMNAS_B ];
	double tolerancia,itera;
	 printf("\n\nSistema de ecuaciones  2");
	 printf("\n************");
	cout << setprecision(Presi); 
	cout<<"\nIngresar punto x:  ";cin>>x;
	cout<<"\nIngresar punto y:  ";cin>>y;
	cout<<"\nIngresar numero maximo de iteraciones: ";cin>>itera;
	cout<<"\nIngresar tolerancia:  ";cin>>tolerancia;
	cout<<"\n";	cout<<"\n";	cout<<"\n";
        do{
       
        ii=ii+1;
        printf("\nITERACION [%i]\n",ii-1);
        fflush(stdin);
        a00=2*x;
        a01=2*y;
        a10=-exp(x);
        a11=-2;
        FX1=(x*x)+(y*y)-9;
        FX2=-exp(x)-(2*y)-3;
        /////////////////
        MFX[0][0]=FX1;
        MFX[1][0]=FX2;
        det=a00*a11-a10*a01;
        M[0][0]=a11/det;
        M[0][1]=(-a01)/det;
        M[1][0]=(-a10)/det;
        M[1][1]=a00/det;
        cout<<"x: "<<x<<"\n";
        cout<<"y: "<<y<<"\n";
        printf("\n");
        
        printf("JACOBIANA\n");
        for(int i=0;i<FILAS_A;i++)
		{
			for(int j=0;j<COLUMNAS_A;j++){
				M[i][j];
				cout<<M[i][j]<<"\t";//Hasta aqui la Jacobiana esta calculada
			}
			cout<<"\n";
		}
	
		
	   printf("\n");
		 printf("F(x)\n");
		for(int i=0;i<FILAS_B;i++){
			for(int j=0;j<COLUMNAS_B;j++){
				MFX[i][j];
				cout<<MFX[i][j]<<"\t";
			}
			cout<<"\n";
		}
		
///////////		//////////////////////////////////////////////////////////////////7
		 for (int a = 0; a < COLUMNAS_B; a++) {
        
        for (int i = 0; i < FILAS_A; i++) {
            double suma = 0;
          
            for (int j = 0; j < COLUMNAS_A; j++) {
             
                suma += M[i][j] * MFX[j][a];
            }
        
            producto[i][a] = suma;
        }
    }

    printf("\n");
    printf("F(x)*J(x)-1\n");
    for (int i = 0; i < FILAS_B; i++) {
        for (int j = 0; j < COLUMNAS_B; j++) {
            cout<<producto[i][j]<<"\t";
        }
        printf("\n");
    }
    Xaux=x-producto[0][0];
    Yaux=y-producto[1][0];
    x=0;
    y=0;
    x=Xaux;
    y=Yaux;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
		}while(ii<itera);
		printf("\nUsted quiere ingresar otro punto(digite la letra 's',caso contrario pulse otra tecla): ");scanf("%c",&op);
		if(op=='s' || op=='S'){
			system("cls");
			 f2();
		}
}
void f3(){
	int ii=0;
	double Adj[filas_A][columna_A];
	double Xaux,Yaux,Zaux;
	double x,y,z,FX1,FX2,FX3,producto[filas_B][columna_B];
	double M[filas_A][columna_A ],det,aux,a00,a01,a02,a10,a11,a12,a20,a21,a22,MFX[filas_B][columna_B ];
	double tolerancia,itera;
	 printf("\n\nSistema de ecuaciones  3");
	 printf("\n************");
	cout << setprecision(Presi); 
	cout<<"\nIngresar punto x:  ";cin>>x;
	cout<<"\nIngresar punto y:  ";cin>>y;
	cout<<"\nIngresar punto z:   ";cin>>z;
	cout<<"\nIngresar numero maximo de iteraciones: ";cin>>itera;
	cout<<"\nIngresar tolerancia:  ";cin>>tolerancia;
	cout<<"\n";	cout<<"\n";	cout<<"\n";
        do{
       
        ii=ii+1;
        printf("\nITERACION [%i]\n",ii-1);
        fflush(stdin);
        a00=4*x-4;
        a01=2*y;
        a02=(6*z)+6;
        a10=2*x;
        a11=(2*y)-2;
        a12=4*z;
        a20=(6*x)-12;
        a21=2*y;
        a22=-6*z;
        FX1=(2*x*x)-(4*x)+(y*y)+(3*z*z)+(6*z)+2;
        FX2=(x*x)+(y*y)-(2*y)+(2*z*z)-5;
        FX3=(3*x*x)-(12*x)+(y*y)-(3*z*z)+8;
        /////////////////
        MFX[0][0]=FX1;
        MFX[1][0]=FX2;
        MFX[2][0]=FX3;
        det=a00*(a11*a22-a21*a12)-a01*(a10*a22-a20*a12)+a02*(a10*a21-a20*a11);
        M[0][0]=a00;
        M[0][1]=a01;
        M[0][2]=a02;
        M[1][0]=a10;
        M[1][1]=a11;
        M[1][2]=a12;
        M[2][0]=a20;
        M[2][1]=a21;
        M[2][2]=a22;
        
      
		//Calculo de la matriz adjunta
                        Adj[0][0]=(M[1][1]*M[2][2])-(M[2][1]*M[1][2]);
                        Adj[0][1]=((M[1][0]*M[2][2])-(M[2][0]*M[1][2]))*(-1);
                        Adj[0][2]=(M[1][0]*M[2][1])-(M[2][0]*M[1][1]);
                        Adj[1][0]=((M[0][1]*M[2][2])-(M[2][1]*M[0][2]))*(-1);
                        Adj[1][1]=(M[0][0]*M[2][2])-(M[2][0]*M[0][2]);
                        Adj[1][2]=((M[0][0]*M[2][1])-(M[2][0]*M[0][1]))*(-1);
                        Adj[2][0]=(M[0][1]*M[1][2])-(M[1][1]*M[0][2]);
                        Adj[2][1]=((M[0][0]*M[1][2])-(M[1][0]*M[0][2]))*(-1);
                        Adj[2][2]=(M[0][0]*M[1][1])-(M[1][0]*M[0][1]);
        cout<<"x: "<<x<<"\n";
        cout<<"y: "<<y<<"\n";
        cout<<"z: "<<z<<"\n";
        printf("\n");
        
        printf("JACOBIANA\n");
        for(int i=0;i<filas_A;i++)
		{
			for(int j=0;j<columna_A;j++){
				
				M[i][j]=(1/det)*Adj[j][i];
				
				cout<<M[i][j]<<"\t";//Hasta aqui la Jacobiana esta calculada
			}
			cout<<"\n";
		}
	
		
	   printf("\n");
		 printf("F(x)\n");
		for(int i=0;i<filas_B;i++){
			for(int j=0;j<columna_B;j++){
				MFX[i][j];
				cout<<MFX[i][j]<<"\t";
			}
			cout<<"\n";
		}
		
///////////		//////////////////////////////////////////////////////////////////7
		 for (int a = 0; a < columna_B; a++) {
        
        for (int i = 0; i < filas_A; i++) {
            double suma = 0;
          
            for (int j = 0; j < columna_A; j++) {
             
                suma += M[i][j] * MFX[j][a];
            }
        
            producto[i][a] = suma;
        }
    }

    printf("\n");
    printf("F(x)*J(x)-1\n");
    for (int i = 0; i < filas_B; i++) {
        for (int j = 0; j < columna_B; j++) {
            cout<<producto[i][j]<<"\t";
        }
        printf("\n");
    }
       //calculamos la resta
    Xaux=x-producto[0][0];
    Yaux=y-producto[1][0];
    Zaux=z-producto[2][0];
    x=0;
    y=0;
    z=0;
    x=Xaux;
    y=Yaux;
    z=Zaux;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
		}while(ii<itera);
		
		printf("\nUsted quiere ingresar otro punto(digite la letra 's',caso contrario pulse otra tecla): ");scanf("%c",&op);
		if(op=='s' || op=='S'){
			system("cls");
			 f3();
		}

}
void f4(){
	int ii=0;
	double Adj[filas_A][columna_A];
	double Xaux,Yaux,Zaux;
	double x,y,z,FX1,FX2,FX3,producto[filas_B][columna_B];
	double M[filas_A][columna_A ],det,aux,a00,a01,a02,a10,a11,a12,a20,a21,a22,MFX[filas_B][columna_B ];
	double tolerancia,itera;
	 printf("\n\nSistema de ecuaciones  3");
	 printf("\n************");
	cout << setprecision(Presi); 
	cout<<"\nIngresar punto x:  ";cin>>x;
	cout<<"\nIngresar punto y:  ";cin>>y;
	cout<<"\nIngresar punto z:   ";cin>>z;
	cout<<"\nIngresar numero maximo de iteraciones: ";cin>>itera;
	cout<<"\nIngresar tolerancia:  ";cin>>tolerancia;
	cout<<"\n";	cout<<"\n";	cout<<"\n";
        do{
       
        ii=ii+1;
        printf("\nITERACION [%i]\n",ii-1);
        fflush(stdin);
        a00=2*x;
        a01=2*y;
        a02=0;
        a10=(2*x)-1;
        a11=-12;
        a12=0;
        a20=(6*x)-12;
        a21=2*y;
        a22=-6*z;
        FX1=(x*x)-4*x+(y*y);
        FX2=(x*x)-x-(12*y)+1;
        FX3=(3*x*x)-(12*x)+(y*y)-(3*z*z)+8;
        /////////////////
        MFX[0][0]=FX1;
        MFX[1][0]=FX2;
        MFX[2][0]=FX3;
        det=a00*(a11*a22-a21*a12)-a01*(a10*a22-a20*a12)+a02*(a10*a21-a20*a11);
        M[0][0]=a00;
        M[0][1]=a01;
        M[0][2]=a02;
        M[1][0]=a10;
        M[1][1]=a11;
        M[1][2]=a12;
        M[2][0]=a20;
        M[2][1]=a21;
        M[2][2]=a22;
        
      
		//Calculo de la matriz adjunta
                        Adj[0][0]=(M[1][1]*M[2][2])-(M[2][1]*M[1][2]);
                        Adj[0][1]=((M[1][0]*M[2][2])-(M[2][0]*M[1][2]))*(-1);
                        Adj[0][2]=(M[1][0]*M[2][1])-(M[2][0]*M[1][1]);
                        Adj[1][0]=((M[0][1]*M[2][2])-(M[2][1]*M[0][2]))*(-1);
                        Adj[1][1]=(M[0][0]*M[2][2])-(M[2][0]*M[0][2]);
                        Adj[1][2]=((M[0][0]*M[2][1])-(M[2][0]*M[0][1]))*(-1);
                        Adj[2][0]=(M[0][1]*M[1][2])-(M[1][1]*M[0][2]);
                        Adj[2][1]=((M[0][0]*M[1][2])-(M[1][0]*M[0][2]))*(-1);
                        Adj[2][2]=(M[0][0]*M[1][1])-(M[1][0]*M[0][1]);
        cout<<"x: "<<x<<"\n";
        cout<<"y: "<<y<<"\n";
        cout<<"z: "<<z<<"\n";
        printf("\n");
        
        printf("JACOBIANA\n");
        for(int i=0;i<filas_A;i++)
		{
			for(int j=0;j<columna_A;j++){
				
				M[i][j]=(1/det)*Adj[j][i];
				
				cout<<M[i][j]<<"\t";//Hasta aqui la Jacobiana esta calculada
			}
			cout<<"\n";
		}
	
		
	   printf("\n");
		 printf("F(x)\n");
		for(int i=0;i<filas_B;i++){
			for(int j=0;j<columna_B;j++){
				MFX[i][j];
				cout<<MFX[i][j]<<"\t";
			}
			cout<<"\n";
		}
		
///////////		//////////////////////////////////////////////////////////////////7
		 for (int a = 0; a < columna_B; a++) {
        
        for (int i = 0; i < filas_A; i++) {
            double suma = 0;
          
            for (int j = 0; j < columna_A; j++) {
             
                suma += M[i][j] * MFX[j][a];
            }
        
            producto[i][a] = suma;
        }
    }

    printf("\n");
    printf("F(x)*J(x)-1\n");
    for (int i = 0; i < filas_B; i++) {
        for (int j = 0; j < columna_B; j++) {
            cout<<producto[i][j]<<"\t";
        }
        printf("\n");
    }
       //calculamos la resta
    Xaux=x-producto[0][0];
    Yaux=y-producto[1][0];
    Zaux=z-producto[2][0];
    x=0;
    y=0;
    z=0;
    x=Xaux;
    y=Yaux;
    z=Zaux;
    
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
		}while(ii<itera);
		
		printf("\nUsted quiere ingresar otro punto(digite la letra 's',caso contrario pulse otra tecla): ");scanf("%c",&op);
		if(op=='s' || op=='S'){
			system("cls");
			 f4();
		}
	
	
}
int main(){
	int caso1,casoglobal;
	char r1,reGlobal;
	 cout<<"\n\t\t\tINTEGRANTES";
	cout<<"\nGonzalez Andradre Ethan Allan";
	cout<<"\n\tVega Vazquez Jose De Jesus";
	cout<<"\n\t\tRomero Cervantes Adriel";
	cout<<"\n\t\t\tPimentel Mendez Juan Ricardo";
	cout<<"\n\n\n\n";
	do{
	cout<<"\n\n";
	cout<<"\n\tINTRUCCIONES";
	cout<<"\n\t\t\tPara usar el metodo 3 y 4 ,primero ingresar la tabla,pulsando 2";
	cout<<"\n\n";
	 cout<<"\n1-Sistema de ecuaciones No Lineales";
	 cout<<"\n2 Ingresar tabla para usarla en el Metodo Spline y DifDividida";
     cout<<"\n\t\t3- Metodo de Diferencia Divididas";
     cout<<"\n\t\t4-Metodo Spline Cubico";
     cout<<"\n5-Diferenciacion e Integracion(usan la misma tabla)";
     cout<<"\nPulsa el numero del metodo que deseas utilizar,RECUERDA LAS INSTRUCCIONES:  ";cin>>casoglobal;
	 switch(casoglobal){
	 	 case 1:system("cls"); do{
	cout<<"\n\tSistema de ecuaciones 1";printf("\n x^2+xy-10");printf("\ny+3xy^2-50");printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	cout<<"\n\tSistema de ecuaciones 2";printf("\n x^2+y^2-9");printf("\n-e^(x)-2y-3)");printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	cout<<"\n\tSistema de ecuaciones 3";printf("\n 2x^2-4x+y^2+3^z+6z+2");printf("\nx^2+y^2-2y+2z^2-5");printf("\n3x^2-12x+y^2-3z^2+8");printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	cout<<"\n\tSistema de ecuaciones 4";printf("\n x^2-4x+y^2");printf("\nx^2-x-12y+1");printf("\n3x^2-12x+y^2-3z^2+8");printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	printf("\nIngresar que sistema de ecuaciones desea resolver: ");
	scanf("%i",&caso1);
	switch(caso1){
		case 1:	f1();break;
		case 2:f2();break;
		case 3: f3();break;
		case 4:f4();break;
		}
			cout<<"\nDesea regresar al menu de Sistema de Ecuaciones No lineales: ";
			cout<<"\n(si es asi digite la letra 's' ,caso contrario cualquier otra)";
			cin>>r1;
			system("cls");
	}while(r1!='n');break;

	 }
	
	 	
		
	        cout<<"\nDesea regresar al Menu principal: ";cin>>reGlobal;
			cout<<"\n(si es asi digite la letra 's' ,caso contrario cualquier otra)";
			cin>>reGlobal;	
	}while(reGlobal!='n');
     
	 


	
	
	return 0;
}
