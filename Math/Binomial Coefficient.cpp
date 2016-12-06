const int MAX=2600;

long long matriz[MAX][MAX];
long long MOD=1e9+7;

for(int i=0 ; i< MAX ; ++i) {
	matriz[i][0]=matriz[i][i]=1LL;

	for(int j=1 ; j<i ; ++j) {
		matriz[i][j]=(matriz[i-1][j-1]+matriz[i-1][j])%MOD;
	}
}
