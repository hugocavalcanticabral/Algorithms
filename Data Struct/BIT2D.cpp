/* *********************** Binary Indexed Tree (BIT) 2D ***********************
 *
 * Memory: O(X * Y), X and Y are the max values of axes.
 * PS: defined under a grid (1, X) x (1, Y)
 * Possible use: Range Sum Query with Updates, (count the frequency of numbers on grid (x1,x2) x (y1,y2), inclusive
*/
#define LSOne(S) (S & (-S)) // bit less significative

const int N = 1030;

class BIT2D {
public:
	int ft[N][N];
	int max_x, max_y;

	// Constructor [ O(X * Y) ]
	BIT2D(int _max_x, int _max_y) : max_x(_max_x), max_y(_max_y) {
		for(int i=0 ; i<max_x+1 ; i++){
			for(int j=0 ; j<max_y+1 ; j++) ft[i][j] = 0;
		}
	}
		
	// Range Sum Query (1, x) X (1, y) [ O(log X * log Y) ]
	int rsq(int x, int y) {
		int sum = 0;
		while(x) {
			int y1 = y;
			while(y1) {
				sum += ft[x][y1];
				y1 -= LSOne(y1);
			}
			x -= LSOne(x);
		}
		return sum;
	}

	// Range Sum Query (x1, x2) X (y1, x2) [ O(log X * log Y) ]
	int rsq(int x1, int y1, int x2, int y2) {
		return rsq(x2, y2) - rsq(x1-1, y2) - rsq(x2, y1-1) + rsq(x1-1, y1-1);
	}

	// Sum the (x, y)-esimo element with v [ O(log X * log Y) ]
	void update(int x, int y, int v) {
		while(x && x <= max_x) {
			int y1 = y;
			while(y1 && y1 <= max_y) {
				ft[x][y1] += v;
				y1 += LSOne(y1);
			}
			x += LSOne(x);
		}
	}
};

