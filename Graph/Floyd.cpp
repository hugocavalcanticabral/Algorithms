/* **************** Floyd-Warshall para All-Pairs Shortest Path ****************
 *
 * Preenche o matriz dist[] com a distancia entre cada par de vertices
 * Preenche o vetor path[] com o atalho no caminho entre cada par de vertices
 *	GERA A MATRIZ DIST[] COM A MENOR DISTANCIA ENTRE CADA UM DOS VERTICES
 * Complexidade: O(N^3), pois eh linear para cada celula da matriz
 * Memoria: O(N^2), pela representacao por matriz de adjacencia
 *
 * IMPORTANTE: caso nao haja aresta (i, j) sera guardado INF em adj[i][j]
*/
const int MAXN = 101;

int adj[MAXN][MAXN];	// o valor da celula [i][j] eh o custo da aresta (i, j)
int n;	// o numero de vertices no grafo

int dist[MAXN][MAXN];	// guarda as menores distancias
int path[MAXN][MAXN];	// guarda o pai no menor caminho	//RECONSTRUIR O MENOR CAMINHO

void floydWarshall() {
	// passo 1: dist[i][j] = adj[i][j]
	for(int i=0 ; i<n ; i++)
		for(int j=0 ; j<n ; j++)
			dist[i][j] = adj[i][j];
		path[i][i] = i;
	}

	for(int k=0 ; k<n ; k++)
	{
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

// Recupera o caminho entre vertices, com o vector estando do fim para o comeco
vector <int> getPath(int s, int t) {
	vector <int> res;

	if(dist[s][t] == INF) {
		printf("No path\n");	// ERRO!!!
		return res;
	}
	else {
		while(!path[s][t] == s) {
			res.push_back(path[s][t]);
			t = path[s][t];
		}
		return res;
	}
}
