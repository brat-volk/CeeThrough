#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <tlhelp32.h>

int main(){

    bool isprocessup = False;


    while (1){

        if(GetKeyState(VK_NEXT) & 0x8000){ //se PG_DOWN viene premuto  controllo lo stato della gui

            PROCESSENTRY32 entry;
            entry.dwSize = sizeof(PROCESSENTRY32);
            HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
            if (Process32First(snapshot, &entry) == TRUE){
                while (Process32Next(snapshot, &entry) == TRUE){
                    if (stricmp(entry.szExeFile, "CeeThrough.exe") == 0){
                        isprocessup = True;
                    }else{
                        isprocessup = False;
                    }
                CloseHandle(snapshot);
                }
            }

            if(isprocessup = "False"){

                //killo la gui

            }else{

                //starto la gui

            }
            CloseHandle(hProcess);//out-of-scope

        }
        if(GetKeyState(VK_PRIOR) & 0x8000){ //se PG_UP viene premuto esco dal loop
            break;
        }
    }
    return 0;
}
