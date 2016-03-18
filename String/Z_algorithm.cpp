/*
	Find all occurrences of a string A in another string B	

	Given two strings A and B, just make a string S = A + B, and call z_algo, for find all occurrence of A in B	

	If z[i]>=A.size() then there are a occurrence of string A in B on that position ( i-A.size(), because the first A.size() positions belongs to A)
	
	EX: A=ABA, B=CABAMAIABOABABAA	,	S=ABACABAMAIABOABACAA
				    					Z=0010301010200501011
*/

const int MAXN=200000;

int z[MAXN];

void z_algo(string &s) {
	memset(z, 0, sizeof z);
	int L = 0, R = 0;
	for (int i = 1; i < s.size() ; i++)  {
		if (i > R)  {
			L = R = i;
			while (R < s.size() && s[R-L] == s[R]) R++;
			z[i] = R-L; R--;
		} 
		else  {
			int k = i-L;
			if (z[k] < R-i+1) z[i] = z[k];
			else  {
				L = i;
				while (R < s.size() && s[R-L] == s[R]) R++;
				z[i] = R-L; R--;
			}
		}
	}
}
