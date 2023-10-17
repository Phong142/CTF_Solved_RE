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
#define HIDE_FUNCTION

unsigned char a6g1ecpknCn18gE[] = "6G1ECPKN>CN18G;ED8RQD:=7:@;7MTEDQAK2SGM5:IHNQ>AEM2";
unsigned char a22233301232120[] = "22233301232120101011320313033011000313301133003212";

//char unk_41EE40[] = { 80, -82, -18, 84, 67, 83, 121, 95, -123, 117, -125, 29, 114, 94, 102, 110, -26, -94, 68, 73, -16, -8, 71, 3, -32, 112, 48, 96, 70, 62, -11, 99, -90, 125, 74, 14, 32, 125, 0 };
char unk_41EE40[] = { 80, -82, -18, 84, 67, 83, 121, 95, 98, 98, 121, 91, 53, 98, 102, 84, -41, -48, 52, 82, -14, 46, 52, 18, -58, 30, 68, 99, 66, 62, -61, 95, -27, 1, 112, 106, 121, 125, 0 };
#ifdef HIDE_FUNCTION
void NTAPI tls_callback(PVOID DllHandle, DWORD dwReason, PVOID)
{
    if (IsDebuggerPresent()) {
        MessageBox(0, L"Access Denied!", L"Notification.exe", 0);
        ExitProcess(0);
    }
    DWORD serial = 0;
    wchar_t hmm[] = L"lucjf3r142";
    for (unsigned int i = 0; i < wcslen(hmm); ++i) {
        serial += hmm[i];
        serial ^= 0xDEADBEEF;
    }
    if (serial > 0x10000) {
        MessageBox(0, L"Access Denied!", L"Notification.exe", 0);
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

int CheckProcess() {
    DWORD ID;
    DWORD ret = 0;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(pe32);
    HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        return 0;
    }
    BOOL bMore = Process32First(hProcessSnap, &pe32);
    while (bMore)
    {
        if (!_wcsicmp(pe32.szExeFile, L"OllyDBG.EXE")|| !_wcsicmp(pe32.szExeFile, L"OllyICE.exe")|| !_wcsicmp(pe32.szExeFile, L"x64_dbg.exe")|| !_wcsicmp(pe32.szExeFile, L"windbg.exe") 
            || !_wcsicmp(pe32.szExeFile, L"ImmunityDebugger.exe") || !_wcsicmp(pe32.szExeFile, L"ida.exe") || !_wcsicmp(pe32.szExeFile, L"ida64") || !_wcsicmp(pe32.szExeFile, L"Wireshark.exe")) {
            return 1;
        }
        bMore = Process32Next(hProcessSnap, &pe32);
    }
    CloseHandle(hProcessSnap);
    return 0;
}

void InputTime() {
    __asm {
        push    ebp
        mov     ebp, esp
        pushad 

        push    1
        call    BlockInput
        push    0x5265C00
        call    Sleep
        push    0
        call    BlockInput

        popad 
        mov     esp, ebp
        pop     ebp
    }
}

int SimpObfus(char a1[]) {
    signed int v1;
    int v3;
    signed int i;
    v1 = strlen(a1);
    v3 = 0;
    for (i = 0; i < v1; ++i)
        v3 += a1[i];
    return v3 ^ 0x226C8;
}

int SimpObfus2(int a1, unsigned int a2) {
    unsigned int i;
    for (i = 0; i < a2; ++i)
        *(unsigned char*)(a1 + i) ^= 0x22;
    return a1;
}

int CheckInput(char* a1) {
    int v2;
    int v3;
    int i;
    int j;
    int v6;
    char v7[80];
    strncpy(v7, unk_41EE40, 38);
    if (strlen(a1) < 37)
        return 0;
    for (i = 0; i < 38; ++i)
        v7[i + 40] = a1[i];
    for (j = 50; j >= 0; --j) {
        v6 = a6g1ecpknCn18gE[j] - 48;
        if (a22233301232120[j] == 49)
            v7[v6 + 40] ^= 0x2Fu;
        else if (a22233301232120[j] - 48 <= 1) {
            if (a22233301232120[j] == 48)
                --v7[v6 + 40];
        }
        else if (a22233301232120[j] == 50)
            v7[v6 + 40] += 51;
        else if (a22233301232120[j] == 51)
            v7[v6 + 40] = (unsigned __int8)v7[v6 + 40] - 142;
    }
    v3 = 0;
    v2 = 1;
    do
    {
        if (v7[v3 + 40] != v7[v3])
            v2 = 0;
        ++v3;
    } while (v3 != 37);
    return v2 != 0;
}

int main() {
    HANDLE CurrentProcess;
    BOOL pbDebuggerPresent[6];
    int v4;
    unsigned int v5;
    char v6;
    unsigned char v7[49];
    unsigned char v8[49];
    char v9[53];
    char v10[53];
    char v11[49];
    char v12[53];
    char input[257];
    unsigned char v14[255];
    char v15[16];
    char v16[4];
    char v17[8];
    char v18[4];
    char v19[9];
    char v20[4];
    strncpy(v19, "qWAAGQQ", 7);
    v19[7] = 3;
    v19[8] = 0;
    strcpy(v20, "(");
    strncpy(v15, "(cAAGQQ", 7);
    v15[7] = 2;
    v15[8] = 70;
    v15[9] = 71;
    v15[10] = 76;
    v15[11] = 75;
    v15[12] = 71;
    v15[13] = 70;
    v15[14] = 3;
    v15[15] = 0;
    strcpy(v16, "(");
    strncpy(v17, "qGAPGV", 6);
    v17[6] = 2;
    v17[7] = 0;
    strcpy(v18, "IG[\0");
    printf("Enter password: ");
    InputTime();
    scanf("%255s", &input);
    CheckExpception();
    SimpObfus2(int(v19), strlen(v19));
    SimpObfus2((int)v17, strlen(v17));
    SimpObfus2((int)v15, strlen(v15));
    CurrentProcess = GetCurrentProcess();
    CheckRemoteDebuggerPresent(CurrentProcess, pbDebuggerPresent);
    if (pbDebuggerPresent[0]) {
        printf("%s\n", v15);
        Sleep(5000);
        return 0;
    }
    if (CheckProcess()) {
        printf("%s\n", v15);
        Sleep(5000);
        return 0;
    }
    SimpObfus2((int)input, 7);
    if (*(input) == 114) {        //'r'
        if (strlen(input) >= 255) {
            Sleep(5000);
            return 0;
        }
        SimpObfus2((int)input, 7);
        v4 = SimpObfus(input);
        if (CheckInput(input) && v4 == 142002) {
            printf("%s\n", v19);                  //sucess
            printf("%s: ", v17);                  //secret
            v4 = SimpObfus(input);
            printf("%d\n", v4);
        }
        else
            printf("%s\n", v15);                  //access denied
        Sleep(5000);
        return 0;
    }
    else {
        printf("%s\n", v15);
        Sleep(5000);
        return 0;
    }
}