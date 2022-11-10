#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector< vector<ll> > matrix;

void solve(int sx, int sy, int step, int type, int num);
void* MyThreadFunction(void *lpParam);
void print(matrix &a);
void print(matrix &a, ofstream &output);
void read(matrix &a, ifstream &input);
void calc_points();
void runtask();
