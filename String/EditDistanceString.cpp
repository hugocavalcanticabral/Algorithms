/* ******************************* Edit Distance *******************************
 *
 * Calcula qual o menor número de operações para transformar uma string inicial
 * em uma final, podendo inserir, remover ou alterar letras
 *
 * Complexidade: O(N * M), em que N e M são os tamanhos das strings
*/
const int N = 81;
int pd[N][N];
string a, b;

int go(int i1, int i2) {	// calcula a melhor forma
	if(pd[i1][i2] != -1) return pd[i1][i2];
	if(i1 == a.length()) return pd[i1][i2] = b.length()-i2;
	if(i2 == b.length()) return pd[i1][i2] = a.length()-i1;
	
	if(a[i1] == b[i2]) return pd[i1][i2] = go(i1+1, i2+1);
	int del = 1+go(i1+1, i2), ins = 1+go(i1, i2+1), cha = 1+go(i1+1, i2+1);
	return pd[i1][i2] = min(del, min(ins, cha));
}

void fill(int i1, int i2, int cnt, int idx) {	// Recupera a solução
	if(i1 == a.length()) {	// chegou no fim da primeira, insere o que falta
		for(int i=i2 ; i<b.length() ; i++)
			printf("%d Insert %d,%c\n", cnt+i-i2, idx+i-i2+1, b[i]);
		return ;
	}
	if(i2 == b.length()) {	// chegou no fim da segunda, remove o que sobra
		for(int i=i1 ; i<a.length() ; i++)
			printf("%d Delete %d\n", cnt+i-i1, idx+1);
		return ;
	}
	if(a[i1] == b[i2]) fill(i1+1, i2+1, cnt, idx+1);
	else {
		int del = 1+pd[i1+1][i2], ins = 1+pd[i1][i2+1], cha = 1+pd[i1+1][i2+1];
		int menor = min(del, min(ins, cha));
		if(del == menor) {
			printf("%d Delete %d\n", cnt++, idx+1);
			fill(i1+1, i2, cnt, idx);
		}
		else if(ins == menor) {
			printf("%d Insert %d,%c\n", cnt++, idx+1, b[i2]);
			fill(i1, i2+1, cnt, idx+1);
		}
		else {
			printf("%d Replace %d,%c\n", cnt++, idx+1, b[i2]);
			fill(i1+1, i2+1, cnt, idx+1);
		}
	}
}

void solve() {
	memset(pd, -1, sizeof pd);
	printf("%d\n", go(0, 0));
	fill(0, 0, 1, 0);
}
