#include<stdio.h>
#include<stdlib.h>

#define n 6

void exibir(int dist[][n], int matriz[][n])
{
    int linha, coluna;
	
	printf("Matriz de Entrada:\n");
    for(linha = 0 ; linha < n ; linha++)
    {
        for(coluna = 0 ; coluna < n ; coluna++)
        {
        	 printf("%d ", matriz[linha][coluna]);
		}
        printf("\n");
    }
    printf("\n");
    printf("Matriz de Saida:\n");
    for(linha = 0 ; linha < n ; linha++)
    {
        for(coluna = 0 ; coluna < n ; coluna++)
        {
        	 printf("%d ", dist[linha][coluna]);
		}
        printf("\n");
    }

}

void algoritmo_warshall(int dist[][n])
{
	int i = 0, j = 0, k = 0, d;
	
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			if(dist[i][j] > 1)
			{
				dist[i][j] = 1;
			} 
		}
	}
	
	for (k = 0; k < n; k++) 
	{
        for (i = 0; i < n; i++) 
		{
            for (j = 0; j < n; j++) 
			{
                if (dist[i][j] == 0)
                {
                	dist[i][j] = dist[i][k] * dist[k][j];
				}
            }
        }
    }
}

int main()
{
	int matriz[n][n] = {{0,1,1,0,0,0},
					    {1,0,0,1,0,0},
						{0,0,0,0,0,0},
						{0,1,2,1,0,1},
						{0,0,1,1,0,1},
						{0,0,0,1,0,0}};
	int dist[n][n];
	int i = 0, j = 0;
	
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			dist[i][j] = matriz[i][j];
		}
	}
	
	algoritmo_warshall(dist);
	exibir(dist, matriz);
	
	return 0;
}
