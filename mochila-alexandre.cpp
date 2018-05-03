#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

using namespace std;

int MochilaDinamica(int n, int M, int pesos[], int valores[])
{
    int G[n+1][M+1];
    int i, j;

   for (i=0;i<= n;i++)  {
       for (j=0;j<=M;j++)   {
           if (i==0||j==0) {
               G[i][j] = 0;
           }
           else if (pesos[i-1]<=j) {
                 G[i][j] = max(G[i-1][j],valores[i-1] + G[i-1][j-pesos[i-1]]);
           }
           else {
                 G[i][j] = G[i-1][j];
           }
       }
   }
return G[n][M];
}

int main(void)
{
    int M;
    int n;

    int ord[100000];
    string file;
    cout << "Digite o nome do arquivo a ser ordenado: ";
    cin >> file;
    ifstream in(file);
    char numero[10];
    int fim = 0;
    while(!in.eof()){
        in >> numero;
        ord[fim] = atoi(numero);
        fim++;
    }
    n = ord[0];
    M = ord[1];

	int pesos[n];
    int valores[n];
    int j =0;
	for (int i=2; i < 2*n+2; i = i+2)
	{
		pesos[j] = ord[i];
		//cout << "pesos: " << pesos[j] << endl;
		valores[j] = ord[i+1];
		//cout << "valores: " << valores[j] <<endl;
		j++;
	}

    cout << "Valor: " <<  MochilaDinamica(n,M,pesos,valores) << endl;
    return 0;
}
