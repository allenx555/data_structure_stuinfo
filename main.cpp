#include"stuinfo.h"
#include"view.h"

int main(void){
	int choice, flag = 0;
	LinkNode *L, *L2;

	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;

	boundar();

	do {
		 printf("\n        请输入你要使用的功能：");
		 scanf(" %d", &choice);
		switch (choice) {
		case 1: Creatlist(L);break;
			case 2:ListInsert(L);break;
			case 3:Listcombine(L, L2);break;
			case 4:Listreverse(L);break;
			case 5:PrintList(L);break;
			case 6:Listflush(L);break;
			default:;break;
		}
	 } while (choice != 6);

}
