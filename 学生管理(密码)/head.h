#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define TRUE 1
#define FALSE 0
#define USER "User.txt"
#include<errno.h>
void startmenu();
int choose(char);
int next1(int,int*);
int signup();
int login();
void sys();

#endif // HEAD_H_INCLUDED
