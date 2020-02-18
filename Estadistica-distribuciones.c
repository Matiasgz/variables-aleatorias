#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//	PROTOTIPOS:
int FACTORIAL(int);
int COMBINACION(int, int);
float BI_N(int, int, float);
float BI(int n, int k, float p);
void BINOMIAL_N();
void GEOMETRICA();
void HIPERGEOMETRICA();
void BINOMIAL();

int main()
{
	
	
	char SI_NO[2], SI_NO2[2];	
	printf("\n\n\t\t PROGRAMA ESTADISTICA: VARIABLES ALEATORIAS DISCRETAS");	
	printf("\n\n\n\t %cSe busca cantidad de %cxitos?  ",168,130);	
	gets(SI_NO);
	
	if(strcmp(SI_NO,"SI") == 0 || strcmp(SI_NO,"Si") == 0 || strcmp(SI_NO,"si") == 0 || strcmp(SI_NO,"sI") == 0 )
	{
		printf("\n\t %cLos elementos estan tomados de a grupos?  ",168);
		fflush(stdin); gets(SI_NO2); system("cls");
		
		if(strcmp(SI_NO2,"SI") == 0 || strcmp(SI_NO2,"Si") == 0 || strcmp(SI_NO2,"si") == 0 || strcmp(SI_NO2,"sI") == 0 )
			// ACA VA LA FUNC HIPERGEOMETRICA
			HIPERGEOMETRICA();
		else
			// Y ACA VA LA BINOMIAL */
			BINOMIAL();
	}
	else
	{
		printf("\n\t %cSe busca m%cs de un %cxito?  ",168,160,130);
		fflush(stdin); gets(SI_NO2); system("cls");
		if(strcmp(SI_NO2,"SI") == 0 || strcmp(SI_NO2,"Si") == 0 || strcmp(SI_NO2,"si") == 0 || strcmp(SI_NO2,"sI") == 0 )
			BINOMIAL_N();
		else
			GEOMETRICA();
	}	
	
	return 0;
}



int FACTORIAL(int X)
{
	int R=1;	
	while(X > 1){
		R= R * X; 
		X--;
	}
	return R;
}

int COMBINACION(int M, int N)
{
	int R= FACTORIAL(M) / (FACTORIAL(N) * (FACTORIAL(M-N))); 
	return R;
}

void BINOMIAL_N()
{
	int n, k;
	float p;
	printf("\n\n\t\t DISTRIBUCION BINOMIAL NEGATIVA \n\n");
	printf("\n\t Ingrese n (cant. pruebas): ");
	scanf("%d", &n);
	printf("\n\t Ingrese k (exitos buscados): ");
	scanf("%d", &k);
	printf("\n\t Ingrese p (probabilidad): ");
	scanf("%f", &p);
	
	printf("\n\n   La probabilidad de que en %d pruebas se logren los %d %cxitos, es de: %.2f \n\n",n ,k ,130 ,BI_N(n, k, p));
}

float BI_N(int n, int k, float p)
{	
	float PROB = COMBINACION(n-1, k-1) * pow(p, k) * pow((1-p), n-k);	
	return PROB;
}

void GEOMETRICA()
{
	int n;
	float p;
	printf("\n\n\t\t DISTRIBUCION GEOM%cTRICA \n\n",144);
	printf("\n\t Ingrese n (cant. pruebas): ");
	scanf("%d", &n);
	printf("\n\t Ingrese p (probabilidad): ");
	scanf("%f", &p);
	
	float PROB= pow(1-p, n-1);
	printf("\n\n   La probabilidad de en %d pruebas se de el %cxito, es de: %.2f \n\n",n , 130, PROB);
	
}

void BINOMIAL()
{
	int n, k;
	float p;
	printf("\n\n\t\t DISTRIBUCION BINOMIAL \n\n");
	printf("\n\t Ingrese n (cant. pruebas): ");
	scanf("%d", &n);
	printf("\n\t Ingrese k (exitos buscados): ");
	scanf("%d", &k);
	printf("\n\t Ingrese p (probabilidad): ");
	scanf("%f", &p);
	
	printf("\n\n   La probabilidad de que en %d pruebas se logren los %d %cxitos, es de: %.2f \n\n",n ,k ,130 ,BI(n, k, p));
}

float BI(int n, int k, float p)
{	float q = ( 1 - p);

	float PROB = COMBINACION(n, p) * pow(p, k) * pow((q), n-k);	
	return PROB;
}


void HIPERGEOMETRICA()
{
	int n;
	float p;
	int N;
	int k;
	int x;
	
	
	printf("\n\n\t\t DISTRIBUCION HIPERGEOM%cTRICA \n\n",144);
	printf("\n\t Ingrese N (cantidad TOTAL de elementos): ");
	scanf("%d", &N);
	
	printf("\n\t Ingrese K (cant. TOTAL de exitos): ");
	scanf("%d", &k);
	
	printf("\n\t Ingrese n (cant. de elementos de la muestra): ");
	scanf("%d", &n);
	
	printf("\n\t Ingrese X (cant.de exitos de ma muestra): ");
	scanf("%f", &x);
	
	
	float PROB= ( COMBINACION(k,x) * COMBINACION((N-k), (n-x)) ) / COMBINACION (N,n) ;
	
	
	
	
	printf("\n\n   La probabilidad de en %d pruebas se de el %cxito, es de: %.2f \n\n",n , 130, PROB);
}

