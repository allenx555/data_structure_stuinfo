#include"stuinfo.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

void Sortlist(LinkNode *&L) {
	LinkNode *p, *pre, *q;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->data.stuID < p->data.stuID) 
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}

bool ListInsert(LinkNode *&L) {
	LinkNode *p = L->next, *s;
	struct stuInfo newdata;

	printf("        请输入学生的学号，姓名，年龄:");
	scanf("%d %s %d", &newdata.stuID, &newdata.stuName, &newdata.Age);

	while (p->data.stuID < newdata.stuID &&  p->next!= NULL) 
		p = p->next;
	if (p == NULL)
		return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data.stuID = newdata.stuID;
		s->data.Age = newdata.Age;
		strcpy(s->data.stuName, newdata.stuName);
		s->next = p->next;
		p->next = s;
		Sortlist(L);
		return true;
	}
}

void Listcombine(LinkNode *&L1, LinkNode *&L2) {
	LinkNode *p = L1->next, *s = L2->next, *t;
	int flag;
	t = (LinkNode*)malloc(sizeof(LinkNode));
	if (L1->next->data.stuID > L2->next->data.stuID) {
		p = L2->next;
		s = L1->next;
		flag = 1;
	}
	while (p != NULL) {
		while (p->next->data.stuID < s->data.stuID && p != NULL) {
			p = p->next;
		}
		t = p->next;
		p->next = s;
		p->next->next = t;
		s = s->next;
	}
	if (flag = 1) 
		L1 = L2;
}

void Listreverse(LinkNode *&L) {
	LinkNode *p1 = L->next, *p2 = p1->next, *p3 = p2->next;
	p1->next = NULL;
	while (p3 != NULL){
		p2->next = p1; 
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1; 
	L->next = p2;
}

void PrintList(LinkNode *&L) {
	LinkNode *p = L->next;
	while (p != NULL) {
		printf("\n        %d  %s  %d", p->data.stuID, p->data.stuName, p->data.Age);
		p = p->next;
	}
}

void Creatlist(LinkNode *&L)
{
	FILE *fp;
	LinkNode *s, *r;

	L = (LinkNode *)malloc(sizeof(LinkNode));
	r  =  L;

	fp = fopen("信息.txt", "r");
	if (fp == NULL) {
		printf("        文件不存在或无法打开\n");
		exit(EXIT_FAILURE);
	}

	do {
		s = (LinkNode *)malloc(sizeof(LinkNode));
		fscanf(fp, "%d %s %d", &(s->data.stuID),&(s->data.stuName), &(s->data.Age));
		r->next = s;
		r = s;
	} while (!feof(fp));
	r->next = NULL;
	fclose(fp);

	Sortlist(L);
}

void Listflush(LinkNode *&L)
{
	FILE *fp;
	fp = fopen("信息.txt", "w");
	if (fp == NULL) {
		printf("        文件不存在或无法打开\n");
		exit(EXIT_FAILURE);
	}
	else {
		for (;L->next != NULL;) {
			L = L->next;
			fprintf(fp, "%d %s %d\n", L->data.stuID, L->data.stuName, L->data.Age);
		}
	}
	fclose(fp);
}