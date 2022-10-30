#include <tchar.h>
#include <windows.h>
using namespace std;

#ifdef LAB5DLLHEADERV1_EXPORTS
#define LAB5DLLHEADERV1__API __declspec(dllexport)
#else
#define LAB5DLLHEADERV1_API __declspec(dllimport)
#endif

extern "C" LAB5DLLHEADERV1_API void runTask();

extern "C" LAB5DLLHEADERV1_API void calc_points();

extern "C" LAB5DLLHEADERV1_API void read(vector< vector<long long> > &a, ifstream &input);

extern "C" LAB5DLLHEADERV1_API void print(vector< vector<long long> > &a, ofstream &output);

extern "C" LAB5DLLHEADERV1_API DWORD WINAPI MyThreadFunction(LPVOID lpParam);

extern "C" LAB5DLLHEADERV1_API void solve(int sx, int sy, int step, int type, int num);
