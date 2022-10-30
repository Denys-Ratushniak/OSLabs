#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long mod = 1e9+7;
ll n,m,k,max_number;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);srand(clock());
    cin >> n >> m >> max_number;max_number++;
    vector< ll > random(max(n, m));
    for(int i = 0; i < random.size(); ++i) random[i] = i;
    vector< vector<ll> > a(n, vector<ll>(m,0));
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            //random_shuffle(random.begin(),random.end());
            a[i][j] = (rand() * random[abs(i-j)] + rand() + rand() + rand()) % max_number;
            //a[i][j] = i + j + 5;
        }
    }
    string out_version = to_string(n) + "_" + to_string(m) + "_" + to_string(max_number-1) + "_out.txt";
    string in_version = to_string(n) + "_" + to_string(m) + "_" + to_string(max_number-1) + "_in.txt";
    string result_path = "A:\\T\\3 term\\Operating Systems\\3lab\\results_right\\" + out_version;
    string test_path = "A:\\T\\3 term\\Operating Systems\\3lab\\tests\\" + in_version;
    ofstream in(test_path);ofstream out(result_path);
    in << n << " " << m  << " " << max_number-1 << "\n\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            in << a[i][j] << " ";
        in << "\n";
    }
    in << "\n";
    ll diag_cnt = 2 * n + 2 * m - 2;
    vector<pair<ll,ll>> diag(diag_cnt);
    vector< pair< pair<ll,ll>, pair<ll,ll> > > points_for_diag(diag_cnt);
    ll x1 = 0;ll y1 = 0;ll x2 = 0;ll y2 = 0;
    for(int i = 0; i < diag_cnt/2; ++i){
        points_for_diag[i] = {{x1, y1}, {x2, y2}};
        if(x1 == n - 1) y1++;
        else x1++;

        if(y2 == m - 1) x2++;
        else y2++;
    }
    x1 = 0;y1 = m-1;x2 = 0;y2 = m-1;
    for(int i = diag_cnt/2; i < diag_cnt; ++i){
        points_for_diag[i] = {{x1, y1}, {x2, y2}};
        if(y1 == 0) x1++;
        else y1--;
        if(x2 == n - 1) y2--;
        else x2++;
    }
    //for(int i = 0; i < diag_cnt; ++i) cout << points_for_diag[i].first.first << " " << points_for_diag[i].first.second << " " << points_for_diag[i].second.first << " " << points_for_diag[i].second.second << "\n";
    ll add = n + 2*m - 2;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            diag[i+j].first += a[i][j];
            diag[i+j].second ++;
            diag[i-j+add].first += a[i][j];
            diag[i-j+add].second ++;
        }
    }
    ll ans = 0;
    for(int i = 1 ; i < diag.size(); ++i) if(diag[i].first * diag[ans].second > diag[i].second * diag[ans].first) ans = i;
    long double result = (long double)diag[ans].first / (long double)diag[ans].second;
    out << ans << " ";
    out << fixed << setprecision(5) << result << "\n";
    out << points_for_diag[ans].first.first+1 << " " << points_for_diag[ans].first.second+1 << " " << points_for_diag[ans].second.first+1 << " " << points_for_diag[ans].second.second+1 << "\n";
    return 0;
}
