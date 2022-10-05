//GUET	1900200920	2020.6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	struct node *lnext;		//��ͷ�ڵ�ʱ����β���ָ��
	char student_number[20];
	char name[10];
	int scores;		//��ͷ�ڵ㵱��������
	struct node *rnext;
}node;


typedef node *linklist;

linklist creat();
void add(linklist );
void bianli(linklist );
void shanchu(linklist);
void sort(linklist);
void output(linklist );
void revamped(linklist );
linklist find(linklist, char* );

void main()
{
	char index=1;
	linklist head;
	while(index)
	{
		printf("������Ҫ���еĲ���:1.����  2.����  3.������������  4.���  5.ɾ��  6.�޸�  7.����  0.�˳�\n");
		scanf("%d",&index);

		if(index==0)	break;
		switch(index)
		{
			case 1: head=creat(); break;
			case 2: sort(head); break;
			case 3: output(head); break;
			case 4: add(head); break;
			case 5: shanchu(head); break;
			case 6: revamped(head); break;
			case 7: bianli(head); break;
		}	
	}
}

linklist creat()		//����˫����
{
	linklist head;
	int i,size;

	head = (linklist)malloc(sizeof(node));
	head->lnext = head;				//ͷ�ڵ����ָ��ָ������һ���ڵ�
	head->rnext = NULL;
	head->scores = 0;
	strcpy(head->name, "tou");			
	strcpy(head->student_number, "tou");		//��ͷ�ڵ㶨��

	printf("����ѧ������\n");
	scanf("%d",&size);
	
	for(i=0; i<size; i++)
		add(head);
	return head;
}

void add(linklist head)		//����ĩβ����һ��Ԫ��
{
	int length = head->scores++;
	linklist p;

	p = head->lnext;
	
	p->rnext = (linklist)malloc(sizeof(node));
	p->rnext->lnext = p;
	p = p->rnext;
	p->rnext = NULL;
	head->lnext = p;

	printf("����ѧ����ѧ��:");
	scanf("%s",p->student_number);
	printf("����ѧ��������");
	scanf("%s",p->name);
	printf("����ѧ���ķ���");
	scanf("%d",&p->scores);
}

void bianli(linklist head)
{
	linklist p;
	p = head;
	while(p)
	{
		if(strcmp(p->name, "tou") && strcmp(p->student_number, "tou"))
			printf("ѧ������Ϊ��%s	ѧ��ѧ��Ϊ��%s	ѧ���ɼ�Ϊ��%d	\n",p->name,p->student_number,p->scores);
		else
			printf("ѧ������Ϊ��%d\n",p->scores);
		p = p->rnext;
	}
}

void shanchu(linklist head)		//ɾ��Ԫ��
{
	char name[10];
	linklist p;
	printf("����Ҫɾ����ѧ����������");
	scanf("%s",name);
	
	p = find(head, name);
	if(p)
	{
		head->scores--;
		p->lnext->rnext = p->rnext;
		if(p->rnext)
			p->rnext->lnext = p->lnext;
		else
			head->lnext = p->lnext;
		free(p);
	}
	else
		printf("δ�ҵ�������Ϣ");
}

void sort(linklist head)		//��������
{
	char flag = 1;
	linklist n, p, temp;		//n����������n��ǰ�Ľڵ�
	n = head->rnext;
	while(n && flag)
	{
		flag = 0;
		p = head->lnext;
		while(p!=n && p->rnext!=n)
		{
			if(p->lnext->scores < p->scores)
			{
				flag = 1;
				temp = p->lnext;
				temp->lnext->rnext = p;
				if(p == head->lnext)
					head->lnext = temp;
				else
					p->rnext->lnext = temp;
				temp->rnext = p->rnext;
				p->lnext = temp->lnext;
				temp->lnext = p;
				p->rnext = temp;
			}
			else
				p = p->lnext;
		}
		if(p == n)		//p!=n˵��nδ����������Ҫ����
			n = n->rnext;
	}
	printf("���������\n");
}

void output(linklist head)		//���Ҳ����
{
	char name[10];
	linklist p;
	printf("����Ҫ���ҵ�ѧ����������");
	scanf("%s",name);

	p = find(head, name);
	if(p)
		printf("ѧ������Ϊ��%s\nѧ��ѧ��Ϊ��%s\nѧ���ɼ�Ϊ��%d\n",p->name,p->student_number,p->scores);
	else
		printf("δ�ҵ�������Ϣ\n");
}

void revamped(linklist head)		//���������޸�
{
	char name[10], i;
	linklist p;
	printf("����Ҫ�޸���Ϣ��ѧ����������");
	scanf("%s",name);

	p = find(head, name);
	if(p)
	{
		printf("1.�޸�����	2.�޸�ѧ��	3.�޸ķ���\n");
		scanf("%d", &i);
		switch(i)
		{
			case 1: scanf("%s", p->name); break;
			case 2: scanf("%s", p->student_number); break;
			case 3: scanf("%d", &p->scores); break;
		}
	}
	else
		printf("δ�ҵ�������Ϣ\n");
}

linklist find(linklist head, char *name)		//�������ֲ���
{
	linklist p;
	p = head->rnext;
	while(strcmp(p->name, name) && p)
		p = p->rnext;
	return p;
}