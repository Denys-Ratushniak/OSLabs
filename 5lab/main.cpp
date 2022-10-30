#include <bits/stdc++.h>
#include <windows.h>
#include <tchar.h>
//#include "lab5dllheaderv1.h"
using namespace std;
int main()
{
    HMODULE h = LoadLibrary("A:\\T\\3_term\\Operating_Systems\\5labDLLv1\\bin\\Debug\\5labDLLv1.dll");
    if(!h){
        cout << "Could not open the library";
        return 1;
    }
    FARPROC fn = GetProcAddress(h, "runTask");
    if(!fn){
        cout << "Could not locate the function";
        return 2;
    }
    fn();
    //runTask();
    return 0;
}
