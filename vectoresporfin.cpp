#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

void  menu ();
void leer_opcion(int &opt);
void printVector(double myVector[],int size);
void printVector(int myVector[],int size);
void scanVector(int myVector[],int size);
void sumaVector(int vect1[3],int vect2[3],int*ptr);
void restaVector(int vector1[3],int vector2[3],int *ptr);
void ppuntoVector(int myVector[3],int myVector2[3],int size);
void ppuntoVector(int myVector[3],int myVector2[3],int size);
float vectorEscalar (int myVector[],int myV2[],int size);
float norma (int myVector[],int size);
void uno(int vector1[3],int *ptr,double *ptr2);

int main(){
int opt;
float j,k;
char repetir;
int x[3]={0,0,0};
int y[3]={0,0,0};
int z[3]={0,0,0};
int *ptrcm=&x[0];
double q[3]={0.0,0.0,0.0};

int *ptrm=&z[0];
double *ptrq=&q[0];
scanVector(x,3);
scanVector(y,3);
printf("\nVector 1\n");
printVector(x,3);
printf("\nVector 2\n");
printVector(y,3);

do{
    menu ();
    leer_opcion(opt);
switch(opt){
	case 1:
	sumaVector(x,y,ptrm);
    printf("\nsuma Vector 1\n");
    printVector(z,3);
    break;

	case 2:
	restaVector(x,y,ptrm);
    printf("\nresta Vector 1\n");
    printVector(z,3);
    break;

	case 3:
   j=norma(x,3);
   printf("\nnorma Vector%f\n",j);
   break;

 	case 4:
   printf("\nProducto punto");
   ppuntoVector(x,y,3);
    break;

     case 5:
     printf("\nProducto escalar");
     k=vectorEscalar(x,y,3);
     printf("\nproducto escalar con raiz:%f",k);
     break;

 	case 6:
 	printf("\nvector unitario\n");
    uno(x,ptrcm,ptrq);
    break;

   default:
    printf("opcion no valida");
    break;
 }
 printf("\nDesea hacer otra operacion?\n");
 printf("(S)si\n");
 printf("(n)no\n");
 scanf("%c",&opt);
 repetir=getch();
}while((repetir=='S') || (repetir=='s'));
return 0;
}

void menu(){
printf("\n1.suma de los vectores\n");
printf("2.resta de los vectores\n");
printf("3.norma de los vectores\n");
printf("4.producto punto de los vectores\n");
printf("5.producto escalar de los vectores\n");
printf("6.producto unitario de los vectores\n");
}
void leer_opcion(int& opt){
printf("\nintroduce una opcion");
scanf("%d",&opt);
}
void printVector(int myVector[],int size){
for (int i=0; i<size; i++){
printf("vector[%d]: %d\n",i,myVector[i]);
}
}

void scanVector(int myVector[],int size){
    for (int i=0; i<size; i++){
	int valor;
	printf("vector[%d]:\n",i);
	scanf("%d",&valor);
	myVector[i]=valor;
}
}
void printVectorF(double myVector[],int size){
    for (int i=0; i<size; i++){
	printf("vector[%d]: %d\n",i,myVector[i]);
}
}
void sumaVector(int vect1[3], int vect2[3],int *ptr){
	for(int i=0; i<3; i++){
    *(ptr+i)=vect1[i]+vect2[i];
}
}
void restaVector(int vector1[3], int vector2[3],int *ptr){
	for(int i = 0; i<3; i++){
		*(ptr+i)=vector1[i]-vector2[i];
}
}
float norma (int myVector[3],int size){
	float suma=0.0;
	for(int i=0; i<=size; i++){
    suma+=myVector[i]*myVector[i];
}
printf("norma sin raiz%f",suma);
return sqrt(suma);
}
void ppuntoVector (int myVector[3],int myVector2[3],int size){
	 float suma=0.0;
	 for(int i=0; i<=size; i++){
    suma+=myVector[i]*myVector2[i];
}
	printf("\nla suma producto punto:%f",suma);
}
float vectorEscalar (int V[3], int V2[3],int size){
	  float suma=0.0;
	  for(int i=0; i<=size; i++){
      suma+=V[i]*V[i] +V2[i]*V2[i];
}
      printf("\nraiz de %f",suma);
      return sqrt(suma);
}
void uno(int v1[3],int *ptr, double *ptr2){
		float raiz=0.0;
	   for(int i=0; i<3; i++){
        raiz+=v1[i]*v1[i];
}
	float raiz2=sqrt(raiz);
	printf("El vector unitario es:%f\n a la menos uno 1/%f=%f\n",raiz2,raiz2,1/raiz2);
	for(int i=0; i<3; i++){
    *(ptr2+1)=*(ptr+i)*1/raiz2;
    printf("el vector unitario:%d*1/%f",v1[i],1/raiz2);
    printf ("=%f\n",*(ptr2+1));
}
printf("\n");
}
