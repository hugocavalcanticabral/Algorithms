/*
	Struct to find prefix or words in a dictionary
	
	PS: if you look for sufix just invert the words
	PS: can be done in O(L), just using array instead of map
	
	insert: O(L*log(L)) 'L' is the size of the word (PS: for each word), in a dictionary O(N*L*log(L))
	query:  O(L*log(L))
	
	Memory: O(N), N  is the sum of all characters stored
	
	IMPORTANT: para imprimir as palavras da Trie em ordem lexicográfica, é necessário apenas realizar uma DFS
*/

struct trie {
	bool finish;
	map <char, trie> child;
};

void insert(trie &T, string &s, int i) {
	if(i>=s.size())T.finish=true;
	else insert(T.child[s[i]], s, i+1);
}

void query(trie T, string &s, int i) {
	if(i>=s.size())return T.finish;
	else {
		if(T.child.find(s[i])==T.child.end())return false;
		else return query(T.child[s[i]], s, i+1);
	}
}
