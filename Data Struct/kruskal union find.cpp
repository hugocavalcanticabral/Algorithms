//Kruskal using Union_Find
const int MAX = 10010;
 
//class implementing Union Find Data Structure with Path Compression
struct Union_Find {
	int id[MAX], sz[MAX];
	Union_Find(int n){ //class constructor
		for (int i = 0; i < n; ++i) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	int root(int i) {
		while(i != id[i]) {
			id[i] = id[id[i]]; //path Compression
			i = id[i];
		}
		return i;
	}
	int find(int p, int q) { return root(p)==root(q); }
	
	void unite(int p, int q) {
		int i = root(p);
		int j = root(q);
		 
		if(sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}
		else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}
};

vector< pair<int, pair<int, int>> > graph;
int n, e;	//vertices e arestas
long long int T;	//caminho total minimo
 
void Kruskal_MST() {
	Union_Find UF(n);
	int u, v;
	 
	for (int i = 0; i < e; ++i) {
		u = graph[i].second.first;
		v = graph[i].second.second;
		if( !UF.find(u, v) ) {
			// printf("uniting %d and %d\n",u,v );
			UF.unite(u, v);
			T += graph[i].first;
		}
	}
}
