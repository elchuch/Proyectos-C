#include<iostream>
#include<math.h>
#include<conio.h>     
#include <iomanip>
#define p 7
using namespace std;
void SplineCub(){
	cout<<"\n\n\n\n\t\tMETODO DE SPLINE CUBICO";
	
	int ttt=1,resp,puntos=20,indice,cont=0,cont2=1,t=0,j;
	double vectorD[puntos],fi[puntos],pp[puntos][puntos],producto[puntos][puntos],sumas,px[puntos],py[puntos],pxnuevo,pynuevo,h0[puntos],acum[puntos],acum2[puntos],matriz[puntos][puntos];
	double calcularA[puntos],ptr[puntos],calcularAi[puntos],calcularBi[puntos],calcularC[puntos];
	cout << setprecision(p);
	cout<<"\n\nCuantos puntos(X,Y) desea ingresar:  ";cin>>puntos;
	for(int i=0;i<puntos;i++){
		cout<<"\nx["<<i<<"]:  ";cin>>px[i];
		cout<<"\n\ty["<<i<<"]:  ";cin>>py[i];
		cout<<"\n---------------------";		
		}
		cout<<"\n\n";cout<<"\n\n";
		cout<<"\nLos puntos que usted ingreso: \n\n";
     	cout<<"\ni--\txi--\tyi--\n\n";
		for(int i=0;i<puntos;i++){
		cout<<"\n\n"<<i;
		cout<<"\t"<<px[i];
		cout<<"\t"<<py[i];
		vectorD[i]=py[i];
	}
	cout<<"\n\n";
	cout<<"\n1-modificar toda la tabla,pulse '1' ";
	cout<<"\n2-modificar un punto(x,y) especifico,pulse '2' ";
	cout<<"\n3-no modificar nada,pulse '3':  ";
	cin>>resp;
     switch(resp){
     	case 1:system("cls");SplineCub();break;
     	case 2:do{cout<<"\n Ingresar que punto 'i' que va modificar de la tabla: ";cin>>indice;
     	           cout<<"\n\nEl punto  que usted cambiara  es i["<<indice<<"] :";
     	           cout<<"\nx:"<<px[indice];cout<<"\ty:"<<py[indice];
     	           cout<<"\n";
     	           cout<<"\nIngresar el nuevo punto: ";
     	           cout<<"\n";
     	           cout<<"\nx["<<indice<<"]:  ";cin>>pxnuevo;
		           cout<<"\n\ty["<<indice<<"]:  ";cin>>pynuevo;
     		       cout<<"\nEl nuevo punto(x,y)";
     		        px[indice]=pxnuevo;
     		        py[indice]=pynuevo;
		           cout<<"\t"<<px[indice];
		           cout<<"\t"<<py[indice];
		           cout<<"\n";
				   	cout<<"\nLa tabla mofidicada es";
		           cout<<"\n";
		           cout<<"\ni--\txi--\tyi--\n\n";
		            for(int i=0;i<puntos;i++){
		            cout<<"\n\n"<<i;
	               	cout<<"\t"<<px[i];
		            cout<<"\t"<<py[i];}
		           cout<<"\nDesea modificar otro punto pulse 1,caso contrario culaquier tecla:  ";cin>>resp;
	  }while(resp==1);break;
	 }system("cls");
	    for(int i=0;i<puntos;i++){   //h0=px+1-px
	    	 h0[i]=px[i+1]-px[i];}
	    	 double h0i[puntos];
	    
		
		for(int i=0;i<puntos;i++){   // H0 PARA USAR EN C
	    	h0i[i]=px[i+1]-px[i];
		}	 
	    	  
	    	for(int i=0;i<puntos;i++){//fi
			py[i]=((py[i+1]-py[i])/(px[i+1]-px[i]));}
			 
			
			for(int i=0;i<puntos;i++){
				fi[i]=py[i]; // y+1-y/x+1-x a usar en C
			}
			
			 //for(int i=0;i<puntos;i++){
			 	//cout<<"\n"<<fi[i];
			// }
			
			
		double operacion=0,operacion2=0;
		for(int i=0;i<puntos-2;i++){ //matriz[s]
		operacion=2*(h0[i+1]+h0[i]);
		acum[i]=operacion;
		operacion=0;}
		
       	for(int i=0;i<puntos-2;i++){
       		operacion2=6*(py[i+1]-py[i]);  //vector de matriz s
       		acum2[i]=operacion2;
       			operacion2=0;}
       			
       			for(int i=0;i<puntos-2;i++){
       				for(int j=0;j<ttt;j++){
       					pp[i][j]=acum2[i];
					   }
				   }
				   /*
					for(int i=0;i<puntos-2;i++){
		   		cont=cont+1;//1
		   		    fflush(stdin);
		   		for(int j=0;j<puntos-2;j++){
		   			fflush(stdin);
		   			if(i==j){
		   				matriz[i][j]=acum[i];//4.86
					   }else{ 
					     if(i==i && j==cont){
					     	matriz[i][j]=h0[i+1];//1.63
						 }else{ 
						 	if(i==cont2 && j==cont2-1){
						 		matriz[i][j]=h0[i];
							 }else{
							 	matriz[i][j]=0;//0,0,0
							 	}
						 	
						 }
					   }
					   
				   }
				   
				   cont2=cont2+i;
	} 
	*/
	for(int i=0;i<puntos-1;i++){
        for(int j=0;j<puntos-2;j++){  //Hace que toda la matriz sea igual a 0...
            matriz[i][j]=0;
        }
    }
	 int in;
	
	for(int i=0;i<puntos-1;i++)
    {
            j=0+in;
            matriz[i][j] = h0[i];
            j++;
            matriz[i][j] = acum[i];
            j++;
            matriz[i][j] = h0[i+1];
            in++;
    }               
	
	
	

int nn=puntos-1;//fila
int mm=0;   // colum
double  b[puntos-2][puntos-2];
for (int i=nn-1;i<puntos-2;i++)
for (int j=0;j<puntos-1;j++)

{matriz[i][j]=matriz[i+1][j];}

for (int i=0;i<puntos-2;i++)
for (int j=mm-1;j<puntos-2;j++)

{matriz[i][j]=matriz[i][j+1];}

for (int i=0;i<puntos-2;i++)
for (int j=0;j<puntos-2;j++)

{b[i][j]=matriz[i][j];}

	/*for(int i=0;i<puntos-2;i++){
		   		for(int j=0;j<puntos-2;j++){
		   			cout<<"\t"<<matriz[i][j];
				   }
				   cout<<"\n";
			   }*/
 double mc[puntos-2][puntos-2];
   
    int dim,i,z, h, k;
	dim=puntos-2;
	double ma[dim][dim*2], dif, mult;
	
	//Construccion de una matriz del tipo Matriz = (A | I)
	for (int i=0; i<dim; i++) {
		for (int j=0; j<dim*2; j++) {
			ma[i][j]=0;
		}
	}	
	j=dim;
	for (int i=0; i<dim; i++) {
		ma[i][j]=1;
		j++;
	}
    for (int i=0; i<dim; i++) {
		for (int j=0; j<dim; j++) {
			ma[i][j]=b[i][j];
		}
	}
	
	for (z=0; z<dim; z++) {
		dif=ma[z][z];
		
		for (int h=0; h<dim*2; h++) {
			ma[z][h]=ma[z][h]/dif;
		}
		for (int i=0; i<dim; i++) {
			if (i!=z){
				mult= -ma[i][z];
				for (int j=0; j<dim*2; j++) {
					ma[i][j]=ma[z][j]*mult + ma[i][j];
				}
			}
		}
	}

	for (int i=0; i<puntos-2; i++) {
		k=puntos-2;
		for (int j= 0; j<puntos-2;j++){
			mc[i][j]= ma[i][k];
			k++;
		}
	}
for (int a=0; a<ttt; a++) {
        
        for (int i = 0; i < puntos-2; i++) {
            double sumas = 0;
          
            for (int j = 0; j < puntos-2; j++) {
             
                sumas += mc[i][j] * pp[j][a];
            }
        
            producto[i][a] = sumas;//S final
        }
    }
    
for(int i=0;i<puntos-2;i++){
 	for(int j=0;j<ttt;j++){
 		ptr[i]=producto[i][j];}
}

 for(int i=0;i<puntos;i++){
      if(i==0 || i==puntos-1){
      	calcularA[i]=0;
	  }else{
	  	calcularA[i]=ptr[i-1];
	  }
 		
 }

 double s1[puntos];
 for(int i=0;i<puntos;i++){ // S a usar en C
 	s1[i]=calcularA[i];
 }
 
 // calculo de ai
for(int i=0;i<puntos;i++){
	calcularAi[i]=((calcularA[i+1]-calcularA[i])/(6*h0[i]));
}


for(int i=0;i<puntos;i++){
	calcularBi[i]=(calcularA[i]/2);
}

double tt=0,m=0,w=0;
for(int i=0;i<puntos;i++){

m=((s1[i+1]+(2*s1[i]))/6);
calcularC[i]=(fi[i]-m*h0i[i]);
m=0;

}

  cout<<"\ni--\txi--\tyi--\n\n";
   for(int i=0;i<puntos;i++){
		    cout<<"\n\n"<<i;
	        cout<<"\t"<<px[i];
		    cout<<"\t"<<vectorD[i];}
	cout<<"\n\n\n";
	cout<<"\n";
	int pos=puntos-1;
  double seliminar,aeliminar,beliminar,celiminar,deliminar,puntosx; 
  if(pos>puntos){
  	cout<<"esta fuera del vector";
  	for(int i=0;i<puntos;i++){
  		//cout<<"\n"<<acumY[i];
	  }
  }else{
  	seliminar=s1[pos];
  	aeliminar=calcularAi[pos];
  	beliminar=calcularBi[pos];
  	celiminar=calcularC[pos];
  	deliminar=vectorD[pos];
  	
  	for(int i=0;i<puntos;i++){
  		if(i==pos){
  			while(i<puntos){
  				
  				s1[i]=s1[i+1];
  				calcularAi[i]=calcularAi[i+1];
  				calcularBi[i]=calcularBi[i+1];
  				calcularC[i]=calcularC[i+1];
  				vectorD[i]=vectorD[i+1];
  				
  				
  				i++;
			  }
			  break;
		  }
	  }
	  puntos=puntos-1;
}
	cout<<"\n Si\t\t ai\t\t bi\t\t ci\t\t di\t\t\n";
	for(int i=0;i<puntos;i++){
		cout<<"\n";
		cout<<s1[i];
		cout<<"\t"<<calcularAi[i];
		cout<<"\t"<<calcularBi[i];
		cout<<"\t"<<calcularC[i];
		cout<<"\t"<<vectorD[i];}
		cout<<"\n";
		cout<<"\n";
	for(i=0;i<puntos;i++){
     cout<<"\n"<<px[i]<<"<X<"<<px[i+1];
     cout<<"\nP(x)="<<"  "<<calcularAi[i]<<"    "<<calcularBi[i]<<"    "<<calcularC[i]<<"    "<<vectorD[i];
	 cout<<"\n\n-----------------------------------------------";
	 
	}
cout<<"\n\n";
cout<<"\n\n";
 int respuesta;
cout<<"\nPULSAR '1' PARA INGRESAR OTRA TABLA";
cout<<"\nPULSAR  OTRA TECLA PARA SALIR DEL PROGRAMA\n: ";
cin>>respuesta;
if(respuesta==1){SplineCub();}
        
}    
int main(){
	SplineCub();
	return 0;
}
