#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

void imprimir_menu ();
void scanVector(int*ptr, int size);
void leer_opcion(int &opt);
void printMatrix(int*ptr,int size1, int size2);
void printMatrix(int arr[3][3]);
void sumaMatrix(int*ptrH, int*ptr2a, int*prtC, int z);
void restaMatrix(int*ptrH, int*ptr2a,int*prtC, int z);
void multMatrix(int*ptrH, int*ptr2,int*ptr,  int &L);
void Fac(int*ptr, int*ptrH, int t, int c, int &x, int &acm);

int main(){
int opt, x=3;
float r,w;
char repetir;

int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int b[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int c[3][3]={{0,0,0},{0,0,0},{0,0,0}};

int *ptrC=&c[0][0];;
int *ptr2a=&a[0][0];
int *ptrH=&b[0][0];
	printf("\nVector 1\n");
	scanVector(ptr2a,3);
    printf("\nVector 2\n");
    scanVector(ptrH,3);

 printf("\nMatriz 1\n");
 printMatrix(ptr2a,3,3);
 printf("\nMatriz 2\n");
 printMatrix(ptrH,3,3);
 do{
    imprimir_menu ();
    leer_opcion(opt);
switch(opt){
	case 1:
	printf("\n matrix suma\n");
    sumaMatrix(ptrC, ptrH, ptr2a,3);
    break;

 	case 2:
     printf("\n matrix resta\n");
     restaMatrix(ptrC, ptrH, ptr2a,3);
    break;

	case 3:
    printf("\nmatrix multiplicada\n");
    multMatrix(ptr2a, ptrH, ptrC,x);
     break;

    default:printf("\n opcion no valida.");
    break;
}
printf("\n\nDesea hacer otra operacion? \n");
printf("(S) si\n");
printf("(N) no\n");
scanf("%c", &opt);
repetir=getch();
}while((repetir=='S')||(repetir=='s'));
return 0;
}
void scanVector(int*ptr,int size){
	int valor;
	int i=0;
    for(i=0; i<size; i++){
    int j=0;
	for(j=0; j<size; j++){
	printf("[%d][%d]:\n",i,j);
	scanf("%d",&valor);
   *(ptr+j+(i*size))=valor;
}
}
}
void printMatrix(int *ptr,int size1, int size2){
    int i=0;
	for(i=0; i<size1; i++){
    int j=0;
    for(j=0; j<size2 ; j++){
    printf("%d ",*(ptr+j+(i*size1)));
}
    printf("\n");
}
}
void printMatrix(int arr[3][3]){
    int i=0;
	for(i=0; i<3; i++){
    int j=0;
    for(j=0; j<3; j++){
    printf("%d ",arr[i][j]);
}
    printf("\n");
}
}
void sumaMatrix(int*ptr, int*ptrH, int*ptr2, int L){
int suma=0;
    int i=0;
	for(i=0; i<L; i++){
    int j=0;
    for(j=0; j<L; j++){
     *(ptr+j+(i*L))=*(ptr2+j+(i*L))+*(ptrH+j+(i*L));
    printf("%d ",*(ptr+j+(i*L)));
}
    printf("\n");
}
}
void restaMatrix(int*ptr,int*ptrH, int*ptr2, int L){
int suma=0;
    int i=0;
	for(i=0; i<L; i++){
    int j=0;
    for(int j=0; j<L; j++){
    *(ptr+j+(i*L))=*(ptr2+j+(i*L))-*(ptrH+j+(i*L));
    printf("%d  ",*(ptr+j+(i*L)));
}
    printf("\n");
}
}
void multMatrix(int *ptr2, int *ptrH, int *ptr, int &L){
   int v=0;
   int i=0;
   for(i=0; i<L; i++){
   int j=0;
   for(j=0; j<L;j++){
    Fac(ptr2,ptrH,i,j,L,v);
    *(ptr+j+(i*L))=v;
    printf("%d",*(ptr+j+(i*L)));
}
    printf("\n");
}
}
void Fac(int *ptr2, int *ptrH, int t, int c, int &x, int &acm){
	acm=0 ;
	int i=0;
	for(i=0; i<x; i++){
    acm+=(*(ptr2+i+(t*x)))*(*(ptrH+c+(i*x)));
}
}
void imprimir_menu(){
 printf("\n1.-suma de las matrices\n\n");
 printf("2.-resta de las matrices\n\n");
 printf("3.-multiplicacion de las matrices\n\n");
}
void leer_opcion(int& opt){
printf("\nIntroduce una opcion\n");
scanf("%d",&opt);
}
