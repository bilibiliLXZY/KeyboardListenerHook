
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

HHOOK keyboardHook = 0;		// 钩子句柄

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,		// 规定钩子如何处理消息，小于 0 则直接 CallNextHookEx
	_In_ WPARAM wParam,	// 消息类型
	_In_ LPARAM lParam	// 指向某个结构体的指针，这里是 KBDLLHOOKSTRUCT（低级键盘输入事件）
	){
    KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT*)lParam;		// 包含低级键盘输入事件信息
	/*
	typedef struct tagKBDLLHOOKSTRUCT {
		DWORD     vkCode;		// 按键代号
		DWORD     scanCode;		// 硬件扫描代号，同 vkCode 也可以作为按键的代号。
		DWORD     flags;		// 事件类型，一般按键按下为 0 抬起为 128。
		DWORD     time;			// 消息时间戳
		ULONG_PTR dwExtraInfo;	// 消息附加信息，一般为 0。
	}KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;
	*/
    if(ks->flags == 128 || ks->flags == 129)
    {
		// 监控键盘
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
		
        //return 1;		// 使按键失效
    }

	// 将消息传递给钩子链中的下一个钩子
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main(int argc, char* argv[])
{
	// 安装钩子
	keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,			// 钩子类型，WH_KEYBOARD_LL 为键盘钩子
		LowLevelKeyboardProc,	// 指向钩子函数的指针
		GetModuleHandleA(NULL),	// Dll 句柄
		NULL					
		);
    if (keyboardHook == 0){return -1;}

    //不可漏掉消息处理，不然程序会卡死
    MSG msg;
    while(1)
    {
		// 如果消息队列中有消息
        if (PeekMessageA(
			&msg,		// MSG 接收这个消息
			NULL,		// 检测消息的窗口句柄，NULL：检索当前线程所有窗口消息
			NULL,		// 检查消息范围中第一个消息的值，NULL：检查所有消息（必须和下面的同时为NULL）
			NULL,		// 检查消息范围中最后一个消息的值，NULL：检查所有消息（必须和上面的同时为NULL）
			PM_REMOVE	// 处理消息的方式，PM_REMOVE：处理后将消息从队列中删除
			)){
				// 把按键消息传递给字符消息
				TranslateMessage(&msg);

				// 将消息分派给窗口程序
				DispatchMessageW(&msg);
		}
        else
            Sleep(0);    //避免CPU全负载运行
    }
	// 删除钩子
    UnhookWindowsHookEx(keyboardHook);

	return 0;
}

