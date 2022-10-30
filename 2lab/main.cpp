#include <bits/stdc++.h>
#include <windows.h>
#include <windowsx.h>
#include "commdlg.h"
#include <conio.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
using namespace std;

void suspend(DWORD processId)
{
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    Thread32First(hThreadSnapshot, &threadEntry);

    do
    {
        if (threadEntry.th32OwnerProcessID == processId)
        {
            HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
                threadEntry.th32ThreadID);

            SuspendThread(hThread);
            CloseHandle(hThread);
        }
    } while (Thread32Next(hThreadSnapshot, &threadEntry));

    CloseHandle(hThreadSnapshot);
}
void resume(DWORD processId){
    HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

    THREADENTRY32 threadEntry;
    threadEntry.dwSize = sizeof(THREADENTRY32);

    Thread32First(hThreadSnapshot, &threadEntry);

    do
    {
        if (threadEntry.th32OwnerProcessID == processId)
        {
            HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
                threadEntry.th32ThreadID);

            ResumeThread(hThread);
            CloseHandle(hThread);
        }
    } while (Thread32Next(hThreadSnapshot, &threadEntry));

    CloseHandle(hThreadSnapshot);
}
int main()
{
    ios_base::sync_with_stdio(0);
    SetConsoleOutputCP(1251);

    PROCESS_INFORMATION pi ;
    STARTUPINFO si ;
    ZeroMemory(&si, sizeof(si)) ;
    si.cb = sizeof( si ) ;
    printf( "Press any key to start programm\n" );
    getch();

    OPENFILENAME file;
    char file_name[256];
    ZeroMemory(&file, sizeof(OPENFILENAME));
    file.lStructSize = sizeof(OPENFILENAME);
    file.lpstrFile = file_name;
    file.nMaxFile = 256;
    GetOpenFileName(&file);

    string path = file.lpstrFile;

    for(int i = path.size()-1; i >= 0 && path[i]!='\\'; i--){
        path.pop_back();
    }
    path.pop_back();
    getch();
    string command;
    command += '"';
    command += "c:\\program files\\winrar\\rar.exe";
    command += '"';
    command += " a -r A:\\RAR.rar ";
    command += path;
    //cout << command << "\n";
    CreateProcess( NULL , &command[0], NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi) ;

    DWORD archive_id = pi.dwProcessId;
    HANDLE archive_handle= pi.hProcess;
    cout << "ID " << archive_id << "\n";
    int a,b;
    a = GetPriorityClass(archive_handle); cout << "PriorityClass = " << a << "\n";
    SetPriorityClass(archive_handle, BELOW_NORMAL_PRIORITY_CLASS);

    getch();
    suspend(archive_id);
    cout << "Now thread is paused, input 0 to kill it, the other number will resume itn";
    cin >> b;
    a = GetPriorityClass(archive_handle); cout << "PriorityClass = " << a << "\n";
    SetPriorityClass(archive_handle, HIGH_PRIORITY_CLASS);
    a = GetPriorityClass(archive_handle); cout << "PriorityClass = " << a << "\n";
    if(b) resume(archive_id);
    else {
        TerminateProcess(archive_handle, 0);
        return 0;
    }

    return 0;
}
