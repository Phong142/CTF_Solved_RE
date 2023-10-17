#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <WinUser.h>
#include <conio.h>
#include <time.h>
#include <TlHelp32.h>
#include <iostream>
#include <shlobj_core.h>
#include <string>
#include <winternl.h>
#include <typeinfo>
#include "ReadResource.h"
#define HIDE_FUNCTION
#define _DWORD unsigned __int32
#define _WORD unsigned __int16
#define _BYTE unsigned __int8
#define FLG_HEAP_ENABLE_TAIL_CHECK   0x10
#define FLG_HEAP_ENABLE_FREE_CHECK   0x20
#define FLG_HEAP_VALIDATE_PARAMETERS 0x40
#define NT_GLOBAL_FLAG_DEBUGGED (FLG_HEAP_ENABLE_TAIL_CHECK | FLG_HEAP_ENABLE_FREE_CHECK | FLG_HEAP_VALIDATE_PARAMETERS)

using namespace std;

_DWORD index_array[] = { 9, 18, 15, 3, 4, 23, 6, 7, 8, 22, 10, 11, 33, 13, 14, 27, 16, 37, 17, 19, 20, 21, 5, 34, 24, 25, 26, 2, 12, 29, 30, 31, 32, 28, 0, 35, 36, 1 };
_DWORD program_case[] = { 6, 1, 7, 1, 3, 2, 4, 3, 6, 3, 7, 6, 1, 4, 7, 4, 1, 5, 7, 6, 7, 5, 6, 4, 5, 1, 7, 5, 2, 3, 1, 2, 3, 2, 1, 6, 2, 4 };
_DWORD const_int[] = { 1, 3, 1, 1, 2, 1, 3, 1, 2, 2, 4, 4, 1, 3, 4, 4, 4, 1, 2, 1, 4, 1, 4, 3, 1, 2, 4, 4, 2, 2, 1, 3, 4, 2, 1, 2, 2, 3 };
_BYTE default_output[] = { 54,236,0,0,54,237,0,0,54,187,0,0,54,140,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

#ifdef HIDE_FUNCTION
void NTAPI tls_callback(PVOID DllHandle, DWORD dwReason, PVOID)
{
    if (IsDebuggerPresent()) {
        MessageBox(0, L"Detect debugger!", L"Notification", 0);
        ExitProcess(0);
    }
    DWORD serial = 0;
    wchar_t hmm[] = L"lucjf3r142";
    for (unsigned int i = 0; i < wcslen(hmm); ++i) {
        serial += hmm[i];
        serial ^= 0xDEADBEEF;
    }
    if (serial > 0x10000) {
        MessageBox(0, L"Detect debugger!", L"Notification", 0);
        ExitProcess(0);
    }
}
#pragma comment (linker, "/INCLUDE:__tls_used")
#pragma comment (linker, "/INCLUDE:_tls_callback_func")
#pragma data_seg(".CRT$XLF")
EXTERN_C
PIMAGE_TLS_CALLBACK tls_callback_func = tls_callback;
#pragma data_seg()
#endif

#ifndef _WIN64
PPEB pPeb = (PPEB)__readfsdword(0x30);
DWORD dwNtGlobalFlag = *(PDWORD)((PBYTE)pPeb + 0x68);
#else
PPEB pPeb = (PPEB)__readgsqword(0x60);
DWORD dwNtGlobalFlag = *(PDWORD)((PBYTE)pPeb + 0xBC);
#endif // _WIN64b

bool CheckAdmin() {
    HANDLE token;
    BOOL isAdmin;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) {
        return false;
    }
    TOKEN_ELEVATION elevation;
    DWORD size;
    if (GetTokenInformation(token, TokenElevation, &elevation, sizeof(elevation), &size)) {
        isAdmin = elevation.TokenIsElevated;
    }
    CloseHandle(token);
    return isAdmin != 0;
}

long WINAPI MyExceptionFilter(PEXCEPTION_POINTERS pExceptionInfo) {
    pExceptionInfo->ContextRecord->Eip += 3;
    return EXCEPTION_CONTINUE_EXECUTION;
}

bool CheckExpception() {
    bool bDebugged = true;
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)MyExceptionFilter);
    __asm {
        int 3
        jmp near debugged
    }
    bDebugged = false;

debugged:
    return bDebugged;
}

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode)
{
    DWORD dwDesiredAccess = PROCESS_TERMINATE;
    BOOL  bInheritHandle = FALSE;
    HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
    if (hProcess == NULL)
        return FALSE;

    BOOL result = TerminateProcess(hProcess, uExitCode);

    CloseHandle(hProcess);

    return result;
}

int checkprocess() {
    int check = 0;
    DWORD ID;
    DWORD ret = 0;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(pe32);
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    BOOL bMore = Process32First(hProcessSnap, &pe32);
    while (bMore)
    {
        if (!_wcsicmp(pe32.szExeFile, L"OllyDBG.EXE") || !_wcsicmp(pe32.szExeFile, L"OllyICE.exe") || !_wcsicmp(pe32.szExeFile, L"x64_dbg.exe") || !_wcsicmp(pe32.szExeFile, L"windbg.exe")
            || !_wcsicmp(pe32.szExeFile, L"ImmunityDebugger.exe") || !_wcsicmp(pe32.szExeFile, L"ida.exe") || !_wcsicmp(pe32.szExeFile, L"ida64.exe") || !_wcsicmp(pe32.szExeFile, L"Wireshark.exe")) {
            TerminateMyProcess(pe32.th32ProcessID, 1);
            check = 1;
        }
        bMore = Process32Next(hProcessSnap, &pe32);
    }
    CloseHandle(hProcessSnap);
    return 1;
}

char genConst(char a1, _BYTE* a2, int a3) {
    int v4;
    char v6;
    int v7;
    _WORD v8;
    unsigned int v9;
    char v10;
    unsigned int v11;
    _BYTE v12;
    bool v13;
    _BYTE* v14;
    int v15;
    char v16;
    int v18;

    v4 = a3 - 1;
    v18 = 171;
    v6 = 0;
    do {
        if (v4 <= 5) {
            if (*(_DWORD*)&a2[4 * v4 + 16])
                v8 = *(_WORD*)&a2[4 * v4 + 16];
            else
                v8 = *(_WORD*)&a2[4 * v4];
            v7 = (v8 >> 1) | (_WORD)(((_WORD)(32 * v8) ^ (v8 ^ (_WORD)(4 * (v8 ^ (2 * v8)))) & 0xFFE0) << 10);
            *(_DWORD*)&a2[4 * v4 + 16] = v7;
        }
        else {
            v7 = 0;
        }
        v9 = v7 & 0x7FF;
        v10 = v7 & 7;
        v11 = v9 >> 3;
        if (a1)
            v12 = a2[v11 + 44];
        else
            v12 = ~a2[v11 + 44];
        v13 = v18-- == 1;
        a2[v11 + 44] = v12 ^ (1 << v10);
    } while (!v13);
    v14 = a2 + 46;
    v15 = 64;
    do {
        v16 = *(v14 - 2);
        v14 += 4;
        v6 ^= *(v14 - 4) ^ *(v14 - 3) ^ *(v14 - 5) ^ v16;
        --v15;
    } while (v15);
    return v6;
}

int case2(char inp, _BYTE* doutput, int constint) {
    if (pPeb->BeingDebugged)
        goto being_debugged;
    return (inp ^ genConst(1, doutput, constint))&0xff;

being_debugged:
    return 0;

}

int case3(char inp, _BYTE* doutput, int constint) {
    HANDLE CurrentProcess;
    BOOL pbDebuggerPresent[6];
    CurrentProcess = GetCurrentProcess();
    CheckRemoteDebuggerPresent(CurrentProcess, pbDebuggerPresent);
    if (pbDebuggerPresent[0]) {
        return 0;
    }
    else {
        return (inp ^ genConst(1, doutput, constint))&0xff;
    }
}

int case4(char inp, _BYTE* doutput, int constint) {
    int check = 0;
    DWORD ID;
    DWORD ret = 0;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(pe32);
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    BOOL bMore = Process32First(hProcessSnap, &pe32);
    while (bMore)
    {
        if (!_wcsicmp(pe32.szExeFile, L"OllyDBG.EXE") || !_wcsicmp(pe32.szExeFile, L"OllyICE.exe") || !_wcsicmp(pe32.szExeFile, L"x64_dbg.exe") || !_wcsicmp(pe32.szExeFile, L"windbg.exe")
            || !_wcsicmp(pe32.szExeFile, L"ImmunityDebugger.exe") || !_wcsicmp(pe32.szExeFile, L"ida.exe") || !_wcsicmp(pe32.szExeFile, L"ida64.exe") || !_wcsicmp(pe32.szExeFile, L"Wireshark.exe")) {
            TerminateMyProcess(pe32.th32ProcessID, 1);
            check = 1;
        }
        bMore = Process32Next(hProcessSnap, &pe32);
    }
    CloseHandle(hProcessSnap);
    if (!check) {
        return (inp ^ genConst(0, doutput, constint))&0xff;
    }
    else {
        return 0;
    }
}

int main() {
    string inp;
    char v2;
    int count;
    int v4;
    char v5;
    char v6;
    int v7;
    char v8;
    int v10;
    int str[40] = {};
    char v22;
    int check = 0;

    if (!CheckAdmin()) {
        MessageBox(0, L"Run file with Administrator", L"Notification", 0);
        return 0;
    }

    cout << "What is key? ";
    getline(cin, inp);

    if (inp.length() < 0x26) {      
        return 0;
    }
    //cout << inp << endl;
    for (int count=0; count<38; count++) {
        if (program_case[count] == 1) {         
            if (CheckExpception()) {
                check = 1;
            }
            if (check) {
                MessageBox(0, L"Detect debugger!", L"Notification", 0);
                return 0;
            }
            v4 = const_int[count];
            v5 = inp[index_array[count]];
            v6 = genConst(0, default_output, v4);
            str[count] = ((v5 ^ v6) & 0xff);
        }
        else if (program_case[count] == 2) {
            if (!case2(inp[index_array[count]], default_output, const_int[count])) {
                check = 1;
            }
            if (check) {
                MessageBox(0, L"Detect debugger!", L"Notification", 0);
                return 0;
            }
            str[count] = case2(inp[index_array[count]], default_output, const_int[count]);
        }
        else if (program_case[count] == 3) {
            if (!case3(inp[index_array[count]], default_output, const_int[count])) {
                check = 1;
            }
            if (check) {
                MessageBox(0, L"Detect debugger!", L"Notification", 0);
                return 0;
            }
            str[count] = case3(inp[index_array[count]], default_output, const_int[count]);
        }
        else if (program_case[count] == 4) {
            if (!case4(inp[index_array[count]], default_output, const_int[count])) {
                check = 1;
            }
            if (check) {
                MessageBox(0, L"Detect debugger!", L"Notification", 0);
                return 0;
            }
            checkprocess();
            str[count] = case4(inp[index_array[count]], default_output, const_int[count]);
        }
        else if (program_case[count] == 5) {
            v4 = const_int[count];
            v5 = inp[index_array[count]];
            if (dwNtGlobalFlag & NT_GLOBAL_FLAG_DEBUGGED) {
                check = 1; 
            }
            if (check) {
                MessageBox(0, L"Detect debugger!", L"Notification", 0);
                return 0;
            }
            v7 = program_case[count];
            v6 = genConst(!v7, default_output, v4);                   
            if (v7 > 0)
                v7 = 0;
            str[count] = ((v5 ^ v6) & 0xff);
        }
        else if (program_case[count] == 6) {
            __asm {
                xor eax, eax
                int 0x2d
            }
            MessageBox(0, L"Detect debugger!", L"Notification", 0);
            v4 = const_int[count];
            v5 = inp[index_array[count]];
            v6 = genConst(1, default_output, v4);
            str[count] = ((v5 ^ v6) & 0xff);
        }
        else if (program_case[count] == 7) {
            __asm {
                int 3
            }
            MessageBox(0, L"Detect debugger!", L"Notification", 0);
            v4 = const_int[count];
            v5 = inp[index_array[count]];
            v6 = genConst(1, default_output, v4);
            str[count] = ((v5 ^ v6) & 0xff);
        }
        else {
            break;
        }
    }
    char hex[100];
    int ptit[] = { 142050, 142054, 142075, 142054, 142065, 142054, 142068, 142025, 142031 };
    wchar_t tmp[100] = L"";
    for (unsigned int i = 0; i < 38; ++i)
        sprintf((char*)(hex + (i << 1)), "%02x", str[i]);
    hex[(38 << 1) + 1] = '\0';
	char* resource_mem;
	resource_mem = resource_loader("#101", (LPSTR)"BIN");                 
    std::mbstowcs(tmp, hex, sizeof(hex));
    if (!wcscmp(resource_decode(resource_mem, strlen(resource_mem)), tmp)) {
        for (int i = 0; i < 8; i++) {
            cout << (char)(ptit[i] ^ 142002);
        }
        cout << inp;
        cout << (char)(ptit[8] ^ 142002);
    }
    else {
        cout << inp;
    }
    return 0;
}
