
#ifndef STDAFX_H
#define STDAFX_H
#include <iostream>
#include <string>
#include <vector>

#endif
#include <windows.h>
#include<iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

HHOOK keyboardHook = 0;		// ���Ӿ��

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,		// �涨������δ�����Ϣ��С�� 0 ��ֱ�� CallNextHookEx
	_In_ WPARAM wParam,	// ��Ϣ����
	_In_ LPARAM lParam	// ָ��ĳ���ṹ���ָ�룬������ KBDLLHOOKSTRUCT���ͼ����������¼���
	){
    KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT*)lParam;		// �����ͼ����������¼���Ϣ
	/*
	typedef struct tagKBDLLHOOKSTRUCT {
		DWORD     vkCode;		// ��������
		DWORD     scanCode;		// Ӳ��ɨ����ţ�ͬ vkCode Ҳ������Ϊ�����Ĵ��š�
		DWORD     flags;		// �¼����ͣ�һ�㰴������Ϊ 0 ̧��Ϊ 128��
		DWORD     time;			// ��Ϣʱ���
		ULONG_PTR dwExtraInfo;	// ��Ϣ������Ϣ��һ��Ϊ 0��
	}KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;
	*/
    if(ks->flags == 128 || ks->flags == 129)
    {
		// ��ؼ���
		switch(ks->vkCode){
		case 0x30: case 0x60:
			cout << "0";
			break;
		case 0x31: case 0x61:
			cout << "1";
			break;
		case 0x32: case 0x62:
			cout << "2";
			break;
		case 0x33: case 0x63:
			cout << "3";
			break;
		case 0x34: case 0x64:
			cout << "4";
			break;
		case 0x35: case 0x65:
			cout << "5";
			break;
		case 0x36: case 0x66:
			cout << "6";
			break;
		case 0x37: case 0x67:
			cout << "7";
			break;
		case 0x38: case 0x68:
			cout << "8";
			break;
		case 0x39: case 0x69:
			cout << "9";
			break;
		case 0x41:
			cout << "A";
			break;
		case 0x42:
			cout << "B";
			break;
		case 0x43:
			cout << "C";
			break;
		case 0x44:
			cout << "D";
			break;
		case 0x45:
			cout << "E";
			break;
		case 0x46:
			cout << "F";
			break;
		case 0x47:
			cout << "G";
			break;
		case 0x48:
			cout << "H";
			break;
		case 0x49:
			cout << "I";
			break;
		case 0x4A:
			cout << "J";
			break;
		case 0x4B:
			cout << "K";
			break;
		case 0x4C:
			cout << "L";
			break;
		case 0x4D:
			cout << "M";
			break;
		case 0x4E:
			cout << "N";
			break;
		case 0x4F:
			cout << "O";
			break;
		case 0x50:
			cout << "P";
			break;
		case 0x51:
			cout << "Q";
			break;
		case 0x52:
			cout << "R";
			break;
		case 0x53:
			cout << "S";
			break;
		case 0x54:
			cout << "T";
			break;
		case 0x55:
			cout << "U";
			break;
		case 0x56:
			cout << "V";
			break;
		case 0x57:
			cout << "W";
			break;
		case 0x58:
			cout << "X";
			break;
		case 0x59:
			cout << "Y";
			break;
		case 0x5A:
			cout << "Z";
			break;
		case 0x6A:
			cout << "*";
			break;
		case 0x6B:
			cout << "+";
			break;
		case 0x6D:
			cout << "-";
			break;
		case 0x6E:
			cout << ".";
			break;
		case 0x6F:
			cout << "/";
			break;
		case 0x0D:
			cout << "<Enter>";
			break;
		case 0xA0: case 0xA1:
			cout << "<Shift>";
			break;
		case 0x08:
			cout << "<Bkspc>";
			break;
		case 0x20:
			cout << "<Space>";
			break;
		
}
		
        //return 1;		// ʹ����ʧЧ
    }

	// ����Ϣ���ݸ��������е���һ������
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main(int argc, char* argv[])
{
	// ��װ����
	keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,			// �������ͣ�WH_KEYBOARD_LL Ϊ���̹���
		LowLevelKeyboardProc,	// ָ���Ӻ�����ָ��
		GetModuleHandleA(NULL),	// Dll ���
		NULL					
		);
    if (keyboardHook == 0){return -1;}

    //����©����Ϣ������Ȼ����Ῠ��
    MSG msg;
    while(1)
    {
		// �����Ϣ����������Ϣ
        if (PeekMessageA(
			&msg,		// MSG ���������Ϣ
			NULL,		// �����Ϣ�Ĵ��ھ����NULL��������ǰ�߳����д�����Ϣ
			NULL,		// �����Ϣ��Χ�е�һ����Ϣ��ֵ��NULL�����������Ϣ������������ͬʱΪNULL��
			NULL,		// �����Ϣ��Χ�����һ����Ϣ��ֵ��NULL�����������Ϣ������������ͬʱΪNULL��
			PM_REMOVE	// ������Ϣ�ķ�ʽ��PM_REMOVE���������Ϣ�Ӷ�����ɾ��
			)){
				// �Ѱ�����Ϣ���ݸ��ַ���Ϣ
				TranslateMessage(&msg);

				// ����Ϣ���ɸ����ڳ���
				DispatchMessageW(&msg);
		}
        else
            Sleep(0);    //����CPUȫ��������
    }
	// ɾ������
    UnhookWindowsHookEx(keyboardHook);

	return 0;
}

