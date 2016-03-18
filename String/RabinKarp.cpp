struct RabinKarp {

   string pat;  
   long long patHash;  // hash of pat
   int M;
   long long Q;
   int R = 256;
   long long RM;

   RabinKarp(string pat) {
      this.pat = pat;
      M = pat.size();
      Q = 1e9+7;
      RM = 1;
      for (int i = 1; i <= M-1; i++) RM = (R * RM) % Q; // R^(M-1)%Q
      
      patHash = hash(pat, M);
   }

   long long hash(string key, int M) {
      long long h = 0;
      for (int j = 0; j < M; j++) h = (R * h + key[j]) % Q;
      return h;
   }

   int search(string txt) {
      int N = txt.size();
      long long txtHash = hash(txt, M);
      if (patHash == txtHash && check(txt, 0)) return 0; // find
          
      for (int i = 1; i <= N - M; i++) {
         txtHash = (txtHash + Q - RM*txt[i-1] % Q) % Q;
         txtHash = (txtHash * R + txt[i+M-1]) % Q;
         if (patHash == txtHash)
            if (check(txt, i)) return i; // find
      }
      return N; // didnt find
   }

   bool check(string txt, int i) { //O(N)
      return true; // Monte Carlo
   } 
   /*bool check(string txt, int i) { //O(N*M)
      for (int j = 0; j < M; j++) 
         if (pat[j] != txt[i + j]) 
            return false; 
      return true;
   }*/
};
