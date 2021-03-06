#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "WINTERFA.H"
#include "MessBox.h"
#include "SPLITTER.HPP"

extern HWND mainWin;



//char * allComments = NULL;


void messageBox (const char * tx2, const char * tx1) {
		MessageBox (mainWin, tx1, tx2, MB_OK | MB_SETFOREGROUND);
}

void messageBox (const char * tx2, int f, int f2) {
	char buff[40];
	sprintf (buff, "%d - %d", f, f2);
	MessageBox (mainWin, buff, tx2, MB_OK | MB_SETFOREGROUND);
}

bool errorBox (const char * txt1, const char * txt2) {
	char * a = new char[strlen (txt1) + strlen (txt2) + 10];
	if (a) {
		sprintf (a, "%s:\n%s", txt1, txt2);
		messageBox (er, a);
		delete a;
	} else {
		messageBox (er, "Out of memory displaying error message");
	}
	return false;
}

bool errorBox (const char * txt1, unsigned int number) {
	char * a = new char[strlen (txt1) + 30];
	if (a) {
		sprintf (a, "%s:\n%d", txt1, number);
		messageBox (er, a);
		delete a;
	} else {
		messageBox (er, "Out of memory displaying error message");
	}
	return false;
}

bool ask (const char * txt) {
	return MessageBox (mainWin, txt, "SLUDGE Development Kit", MB_YESNO | MB_SETFOREGROUND) == IDYES;
}
