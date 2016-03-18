const int INF = 0x3F3F3F3F;

typedef pair<int, int> bezout;

bezout find_bezout(int a, int b) {
    if (b == 0) return bezout(1, 0);

    bezout u = find_bezout(b, a % b);

    return bezout(u.second, u.first - (a/b) * u.second);
}

//Find x and y such as ax + by == c. (x, y) is a particular solution for the problem.
//The others solutions looks like: (x + bk, y - ak), for all integer k, positive or negative.
//Return (INF, INF) if doesnt have solution

int gcd(int a, int b){ return (a%b==0 ? b : gcd(b, a%b));}

bezout solve_linear_diophantine(int a, int b, int c) {
    int d = gcd(a, b);

    if ( c % d ) return bezout(INF, INF);

    int new_c = c / d;
    bezout asw = find_bezout( a / d, b / d );
    asw.first *= new_c; asw.second *= new_c;

    return asw;
}
