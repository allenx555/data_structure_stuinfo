#pragma once
#include<stdio.h>
#include<malloc.h>
#pragma warning(disable:4996)

typedef struct stuInfo {
	int stuID;
	char stuName[10];
	int Age;
}data;

typedef struct node {
	struct stuInfo data;
	struct node *next;
}LinkNode;

void Creatlist(LinkNode *&L);

void Sortlist(LinkNode *&L);

bool  ListInsert(LinkNode *&L);

void Listcombine(LinkNode *&L1, LinkNode *&L2);

void Listreverse(LinkNode *&L);

void PrintList(LinkNode *&L);

void Listflush(LinkNode *&L);