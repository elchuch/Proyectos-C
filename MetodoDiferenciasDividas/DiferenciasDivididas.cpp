#include<iostream>
#include<math.h>
#include<conio.h>     
#include <iomanip>
#define p 9
using namespace std;
void DiferenciasDivididas(){
	double resta;
		char r;
	int conti=0;
	double v0;
	double valor=1;
	int cont11=0;
	int cont22=0;
	double suma=0;
	int posi=0;
	int grad;
	int puntos,xx;
	char resp;
	double pInic;
	int cont=0,t=0;
	int i=0;
	double puntoX,puntoY;
	cout << setprecision(p);
	cout<<"\n\tDIFERENCIAS DIVIDIDAS ";
	cout<<"\n*******************************";
	cout<<"\nIngresar puntos (x,y)"<<endl;
	cout<<"\nCuantos puntos desea ingresar: ";cin>>puntos;
	double x[puntos],y[puntos],yy[puntos],V[puntos-1];
	int cont2=puntos;
	//int acum=puntos-1;
	double acumY[puntos];
	for(int i=0;i<puntos;i++){
		cout<<"\nIngrese el punto [x]"<<i<<": ";cin>>x[i];
		cout<<"\nIngrese el punto [y]"<<i<<": ";cin>>y[i];
		  conti++;
         if(conti==1){
         	v0=y[i];
		 }
	
		}
	cout<<"\nIngresar el punto X que desea interpolar: ";cin>>pInic;
	system("cls");
	cout<<"\nLa tabla inicial es : \n\n";
	cout<<"\ni--\txi--\tFxi--\n\n";//cout<<"\n\txi\n\n--";
	for(int i=0;i<puntos;i++){
		cout<<"\n\n"<<i;
		cout<<"\t"<<x[i];
		cout<<"\t"<<y[i];
		} //cout<<"\n"<<v0;
	
	
	cout<<"\n"<<"\nPunto a interpolar x: "<<pInic;
	for(int i=0;i<puntos;i++){
		
		if(pInic<x[i]){
			cout<<"\nEl punto se encuentra entre este intervalo x0: "<<x[0]<< "; x1:"<<x[i];
		
		}
		else{
			cout<<"\nEse punto no se encuentra en el intervalo";
		}
	}
	
	for(int i=0;i<puntos-1;i++){
		resta=pInic-x[i];
		V[i]=resta;
	}
	
    cout<<"\n";	
	cout<<"\nSon correctos los datos o desea cambiarlos(pulse 's' caso contrario cualquier tecla): ";cin>>resp;
	if(resp=='s'){
		DiferenciasDivididas();}
		
	 	for(int j=1;j<=puntos-1;j++){
			
			for(int i=0;i<puntos;i++){
				
				
				cont++;
				if(cont<cont2){
				yy[i]=(y[i+1]-y[i])/(x[i+j]-x[i]);
			     cout<<"\n"<<yy[i];
			    y[i]=yy[i];
			    }
			    posi++;
			    if(posi==1){
			    	acumY[j]=y[i];
				}
				
				
			}
	
		    cont=0;
		    cont2--;
		    posi=0;
		    
		    cout<<"\t\t\t\t\t\n"; 
			//cout<<"\";cout<<"\n";
		    
	
    }
    /*cout<<"\nAcum";
    
    for(int i=0;i<puntos;i++){
    cout<<"\n"<<acumY[i];}*/
  fflush(stdin);
  int pos=0;
  double eliminar; 
  if(pos>puntos){
  	cout<<"esta fuera del vector";
  	for(int i=0;i<puntos;i++){
  		cout<<"\n"<<acumY[i];
	  }
  }else{
  	eliminar=acumY[pos];
  	for(int i=0;i<puntos;i++){
  		if(i==pos){
  			while(i<puntos){
  				acumY[i]=acumY[i+1];
  				i++;
			  }
			  break;
		  }
	  }
	  puntos=puntos-1;
	
	  /*for(int i=0;i<puntos;i++){
	  	cout<<"\n"<<acumY[i];
	  }*/
  }


    
    	cout<<"\nIngresar el  grad(P(x)) de tu polinomio: ";cin>>grad;
    //cout<<"\nIngresar los valores de la tabla para construir tu polinomio: ";
    /*for(int i=0;i<grad;i++){
    	fflush(stdin);
    	cout<<"\nvalor i0: ";cin>>acumY[i];
    	}*/
    /*for(int i=0;i<grad;i++){
    	cout<<"\n"<<acumY[i];
	}*/
	   
	  for(int i=0; i<grad;i++){
		    cont22++;// cont22=1,2
		  	cont11=0;
		    valor=1;
		for(int j=0;j<grad;j++){
			
			valor=valor*V[j];// 1*(2.5-1.73)
			cont11++;// cont11=1
			if(cont11==cont22){//
				suma=suma+valor*acumY[i];//1*(2.5-1.73)*f0
				
			}
		}
	
	} 
	
	suma=suma+v0;
	cout<<"\n";
	cout<<"\nEl resultado es de [P"<<pInic<<"]=  "<<suma; 
	suma=0;
	cout<<"\n";
    cout<<"\nDesea ingresar nuevos datos,pulse 's',caso contrario cualquier tecla: ";cin>>r;
    if(r=='s'){
    	DiferenciasDivididas();
	}
	
}
int main(){
	DiferenciasDivididas();
	return 0;
}
