/*
	BI PARTIDE MARCHING 
	COMPLEXIDADE: O(E*V)
	
	BASTA PREENCHER O VECTOR 'ADJ' E O 'N' (N = NUMERO DE VERTICES DO CONJUNTO A) E CHAMAR O BPM(), ELE RETORNARÁ O NUMERO DE MATCHINGS
	E OS MATCHES ESTARÃO NO VETOR 'PAR', QUE SIGNIFICARÁ QUE O I-ESIMO TERMO DO CONJUNTO 'B' FEZ PAR COM O ELEMTENTO 'PAR[I]' NO         		CONJUNTO 'A'
	
	ALGORITMO CONTA COM VERTICES DE 0 -> N-1, MODIFICAR SE FOR O CASO
*/

const int maxn = 40;		//NUMERO MAXIMO DE VERTICES DO MAIOR CONJUNTO ('A' OU 'B')

bool visitados[maxn];		//AQUI É PARA A FUNÇÃO SABER QUEM JÁ ESTÁ FORMANDO UM PAR
int par[maxn];				//AQUI FICARÁ MARCADO QUEM DO CONJUNTO 'A' FEZ PAR COM O I-ESIMO DO CONJUNTO 'B', ENTÃO AQUI FICA A CONSULTA 								  DOS MATCHINGS
vector <int> adj[maxn];		//ADJACENCIA DO CONJUNTO 'A'
int pares;					//QUANTIDADE DE MATCHINGS
int n;						//QUANTIDADE DE VERTICES DO CONJUNTO A

bool dfs(int pos) {
	for(int i=0 ; i<sz(adj[pos]) ; i++) {
		if(visitados[adj[pos][i]])continue;
		
		if(par[adj[pos][i]]!=-1) {
			visitados[adj[pos][i]] = true;
			if(dfs(par[adj[pos][i]])) {	//A ARESTA JÁ ESTAVA COM MATCH, POREM EU CONSIGO MELHORAR SE AQUI DER TRUE
				par[adj[pos][i]] = pos;
				
				return true;
			}
		}
		else {	//ARESTA NÃO ESTAVA VISITADA AINDA, ENTÃO FORMO UM MATCH
			par[adj[pos][i]] = pos;
			
			return true;
		}
	}
	
	return false;
}
	
int BPM() {
	pares=0;
	memset(par, -1, sizeof par);
	
	for(int i=0; i<n ; ++i)	{//PARA CADA VERTICE EU TENTO FAZER O SEU MATCHING	//SE 'ZERO' NÃO FOR O VERTICE INICIAL MODIFICAR AQUI*****
		memset(visitados, 0, sizeof visitados);
		if(dfs(i))pares++;
	}
	
	return pares;
}
