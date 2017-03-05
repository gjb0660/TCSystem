#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <io.h>
#define TCItemNum 80
void System_Out();          //�˳�ϵͳ 
void CustomerEnter();      //�û���¼ 
void CustomerSystem();     //�ͻ�����ϵͳ 
void CustomerSettlement();   //�ͻ����� 
void OrderCustom();     //������ 
void OrderAll();      //ȫ����� 
void managerEnterView();   //�����½���溯��
void managerControlView(); //����������溯��
void passwordManagement();   //�޸����뺯�� 
void managerControlEvaluationView() ;   //����Ա���۹������ 
void userEvaluationView();   //�û����۹��� 
void TCManage();//���˵�����
void TableManagement();  //����������
void OrderManage();   //�˵�����
void CheckOrder(); //�˵��鿴 
void ClearOrder();//��������
void OpinionLook();//�ۿ��Ƶ����� 
struct TeaCake * TCFind(int id);//����ַ���Һ��� 
char TableNumber[4]="0";         //�������� 
int TableMan;      //�ò�����
int TeaNumber;  //��ˮ��� 
char str[16];//������������
char TypeName[10][10]=
{
    "�h�����","��������","�������","��������",
    "����ǳ�","��������","��԰�߲�","�ߵ���Ҷ",0,0
}; //�������0��9��Ӧ������
struct TeaCake //���ṹ�� 
{
	int ID;
	char name[20];
	int price;
	int type;	     //�������"�h�����","��������","�������","��������","����ǳ�","��������","��԰�߲�","�ߵ���Ҷ"
	char intro[80];     //��� 
}TCList[TCItemNum];

//*******************************************���������棨�������棩****************************************************
int main() 
{
	FILE*fp;
	if((fp=fopen("TCList.dat","rb"))==NULL)
	{
		printf("\n\n\t\t\tȱ�ٱ�Ҫ�ļ�,1.233����Զ��������˵�");
		Sleep(1233);
		exit(0);
	}
	fread(TCList,sizeof(struct TeaCake),80,fp);
	fclose(fp);
	if ((fp=fopen("TypeName.dat","rb"))==NULL)
    {
        printf("cannot open TypeName.dat\n");
        exit(0);
    }
    fread(TypeName,sizeof(char [10]),10,fp);//�����ļ�TypeName.dat������
    fclose(fp);
    char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ 
	strcat(strcat(ST,TableNumber),ST1);   //���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ�
	remove(ST);
Loop_main:
	fflush(stdin);
	system("cls");
	system("color 0f");                                    //����    
	printf("\n\n\n\n\n\t\t\t �� ӭ �� �� !");
	printf("\n\n\t\t\tw e l c o m e !");	
	Sleep(1000); 
	system("cls");	
	int z;
	HANDLE wordscolor = GetStdHandle(STD_OUTPUT_HANDLE);              //������׼������ 
    SetConsoleTextAttribute(wordscolor,FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_BLUE);    //�����ı�ǰ����ɫ,������ɫ
    printf("\n\n*************************��������*************************\n\n");
	SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED);
	printf("\t\t\t");
	char out[]=" �� �� �� �� ��  \n\n";
	for(z=0;z<strlen(out);z++ )
	{
		printf("%c",out[z]);
		Sleep(30);                                                                          //���ֳ��ּ��30ms�� 
	}
	z=0;
    SetConsoleTextAttribute(wordscolor,FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_BLUE);
    printf("*************************��������*************************\n");
   	SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("|�����ǲ��ʱ��|\n\n");
    SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    printf("\n\t\t        1.�ͻ�����\n	 222 \n	2   2");Sleep(70);
    SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    printf("\n\t   2 \t        2.�Ƶ���������\n	 22  \n	2    ");Sleep(70); 
    SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("\n\t22222\t        3.�˳�ϵͳ\n\n");Sleep(70); 
    SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("\n���������ֽ��ж�Ӧ����:");
    scanf("%d",&z);                                                                     //������������ѡ�����                                     
    if(z!=1&&z!=2&&z!=3)
	{
		system("cls");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
		printf("\n\n\n\n����������1������2������3\n\n\n");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		system("pause"); 
		goto Loop_main;                                                                   //�������ʱ�ص�������ͷ	
	}
	else
	{
	 	switch(z)              
 		{
 			case 1:CustomerEnter();break;
			case 2:managerEnterView();break;
			case 3:System_Out();break;
 		}
        system("cls");	
        goto Loop_main;
	}

}
//*******************************************�˳�ϵͳ****************************************************
void System_Out()
{
	fflush(stdin);                                                          //������뻺���� 
	system("cls");
	system("color f8");
	printf("\n\n\n\n\t\t  �� �� ��(��) �� �� һ �� �� ��");
	printf("\n\n\n\t\tLooking forward to your next visit\n\n\n\n");
	Sleep(1233);
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ 
	strcat(strcat(ST,TableNumber),ST1);   //���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ�
	remove(ST); 
	exit(0);                                                                 //�˳�ϵͳ 
}
//*******************************************�ͻ���¼****************************************************
void CustomerEnter()
{  
    void CustomerSystem();  
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ 
	FILE*fp;
	system("cls");                         //���� 
	system("color b0");                  //������ɫΪ����ɫ������Ϊ��ɫ 
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("��������(��)�Ĳ����ţ���ENTER������\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	fflush(stdin);  
	scanf("%s",TableNumber); 
	fflush(stdin); 
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("�������ò͵���������ENTER������\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	scanf("%d",&TableMan);
    printf("\n\t��������Ҫ���ֲ�ˮ��\n*********************************************\n1.���򻨲�\t2.�ջ���\t3.�׿�ˮ    |\t4.�����ˮ\n*********************************************\n����0������һ��\n");
Loop_2:	
	scanf("%d",&TeaNumber);
	fflush(stdin);
	if(TeaNumber!=1&&TeaNumber!=2&&TeaNumber!=3&&TeaNumber!=4&&TeaNumber!=0)
	{
		printf("��������Ӧ������\n");	
		Sleep(1500);
		goto Loop_2;       //��������        
	}
	else if(TeaNumber==0)return;  //���������溯�� 
	else
	{
		strcat(strcat(ST,TableNumber),ST1);//���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ�
		fp=fopen(ST,"w");fclose(fp);
		printf("\a");	                                       
		system("cls");
		CustomerSystem();   //����ͷ�����ϵͳ 
		return;
	}		
}
//*******************************************�ͻ�����ϵͳ****************************************************
void CustomerSystem()
{
	void System_Out();
	void OrderAll();
	void OrderCustom();
	void Tablemange();
	void Opinionmange();
	int x[3],i,flag,flag1,j;
	char n;
	while(1)
	{
		system("cls");
		fflush(stdin);
		system("color 30");
		HANDLE wordscolor = GetStdHandle(STD_OUTPUT_HANDLE);
		srand((unsigned)time(NULL));
		printf("�����Ƽ���Ʒ:\n\t\t");
		for(i=0;i<3;i++)
		{
			x[i]=rand()%69;
			flag=1;
			while(flag==1)
			{
				for(j=0;j<i;j++)
				if(x[i]==x[j])break;
				if(j<i)x[i]=rand()%69;
				if(j==i)flag=0;
			}
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("%-15s",TCList[x[i]].name);
		}	
		SetConsoleTextAttribute(wordscolor,BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("\n===============================================================================\n");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("\n\n\t\t\t\t1.|  ���ٵ��  |\n\n\t\t\t\t2.|  ������  |");
		printf("\n\n\t\t\t\t3.|  �Ƶ�����  |\n\n\t\t\t\tw.|  �˳�ϵͳ  | \n\n\t\t\t\t0.* �������˵�*\n\n");
		SetConsoleTextAttribute(wordscolor,BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("\n===============================================================================\n");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("\n\n�������Ӧ��ĸ���в���:"); 
	
	Loop_1:
		printf("\n");
		n=getchar();
		fflush(stdin);
		switch(n)
		{
			case'w':System_Out();break;    //����w�˳�ϵͳ 
			case'3':OpinionLook();break;     // ����3�������۹���ϵͳ 
			case'2':OrderCustom();break;       // ����2���з����� 
			case'1':OrderAll();break;		  // ����1���п��ٵ�� 
			case'0':main();break;      //�������˵� 
			default:printf("\n�������޶����ַ���лл\n");goto Loop_1;break; 
		} 
	}
}
//*******************************************�ͻ��ۿ�����****************************************************
void OpinionLook()
{
	system("cls");   //����������ת����ĺ���
    FILE *in;
    int option;
    int evaluationNum;
    int i;
    int k;
    int bool=1;
    char tableNum[100][4];//�����ŵ�����
    char ch[100][100];  //���ȡ�����ַ�
    if((in=fopen("userOpinion.txt","r"))==NULL)
    {
        printf("�޷��򿪴��ļ�userOpinion.txt");
    }
    /**
    *  forѭ������ȡ�ļ��е����ݣ��ֱ����tableNum��ch�Ķ�ά������
    */
    for(i = 0; i < 100; i++)
    {
        fscanf(in,"%s\t%s\n",&tableNum[i],&ch[i]);
        if(ch[i][0]==0)break;
    }
    fclose(in);
    printf("                   ��********************************************��\n");
    printf("                           ||����Ϊ�����˿ͶԱɾƵ������||\n");
    printf("                   ��********************************************��\n");
    /*
    * ������� ableNum��ch�Ķ�ά������ȡ��
    */
    for(k = 0; k<i; k++)
    {
        printf("\n");
        printf("%d����%s��������: %s\n",k+1,tableNum[k],ch[k]);
    }
    system("pause");
}
//*******************************************�˿ͽ���****************************************************
void CustomerSettlement()
{
	fflush(stdin);                                                          
	system("cls");
	system("color 80");
	int i,k=0,sum=0;
	int n[30][2]={
		{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}
	};  	
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ 
	char ST2[20]={".\\orderinfo\\"};
	HANDLE wordscolor = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(wordscolor,BACKGROUND_INTENSITY);
	FILE*fp;
	FILE*fp1;
	fp=fopen(strcat(strcat(ST,TableNumber),ST1),"r");
	for(i=0;i<30;i++)
	{
		
		fscanf(fp,"%d",&n[i][0]);
		fscanf(fp,"%d",&n[i][1]);
		fscanf(fp,"%d",&k);
		if(n[i][0]==0)break;	
	}
	fclose(fp);
	for(i=0;i<30;i++)
	{
		if(n[i][0]==0)break;
		sum+=TCFind(n[i][0])->price*n[i][1];
	}
	printf("\n\n***************************************************\n\tлл��(��)�Ļݹ�,�����Ǳ������ѵĽ���:\n***************************************************");
	SetConsoleTextAttribute(wordscolor,FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf("\n����Ϊ�����㣺\n");
	printf("ID. �������\t     ����    �ѵ���     Ӧ��Ǯ��\n");
	for(i=0;i<30;i++)
	{
		if(n[i][0]==0)break;
		printf("%-4d.%-15s %-4d      %-1d  \t  %d\n",TCFind(n[i][0])->ID,TCFind(n[i][0])->name,TCFind(n[i][0])->price,n[i][1],TCFind(n[i][0])->price*n[i][1]);
	}
	printf("\n�����ܼ�Ϊ%dԪ",sum);	
	SetConsoleTextAttribute(wordscolor,BACKGROUND_INTENSITY);
	printf("\n\n\n4.������һ��(�����Ӳ��)\n3.���ؿͻ���������(���µ���)\n2.�������۽���(���޷��������,Ĭ��ȷ�Ͻ���)\n1.����������\t0.ȷ�Ͻ���(�Զ����ز�������)\n���������ֲ���:"); 
	scanf("%d",&i);
	switch(i)
	{
		case 2:
			fp1=fopen(strcat(strcat(ST2,TableNumber),ST1),"a+");
			for(i=0;i<30;i++)
			{
				if(n[i][0]==0){fprintf(fp1,"\n1\n");break;}
				fprintf(fp1,"%d\t%d\t%d\n",TCFind(n[i][0])->ID,n[i][1],TCFind(n[i][0])->price*n[i][1]);   //�����յ��˵�д���ض��ļ�		
			}
			fclose(fp1);
			fp=fopen(ST,"w");fclose(fp);//����ļ� 
			userEvaluationView();
			break;
		case 4:return;break;
		case 3:CustomerSystem();break;
		case 1:main();break;
		case 0:
			fp1=fopen(strcat(strcat(ST2,TableNumber),ST1),"a+");
			for(i=0;i<30;i++)
			{
				if(n[i][0]==0){fprintf(fp1,"\n1\n");break;}
				fprintf(fp1,"%d\t%d\t%d\n",TCFind(n[i][0])->ID,n[i][1],TCFind(n[i][0])->price*n[i][1]);   //�����յ��˵�д���ض��ļ�		
			}
			fclose(fp1);
			fp=fopen(ST,"w");fclose(fp);
			CustomerSystem(); 
			break;
		default:printf("\n��������ȷ������\n");CustomerSettlement();break;
	} 
	CustomerSystem();		
}
//*******************************************�����˺���****************************************************
void OrderFind(int OrderList[3],int id) //����һ�����ļ��в��ҵ�˼�¼�ĺ��� 
{ 
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ 
	FILE*fp; 
	if ((fp=fopen(	strcat(strcat(ST,TableNumber),ST1)	,"r"))==NULL) //���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ�
        	fp=fopen(ST,"w+");
	while(feof(fp)==0)//�ļ�ָ��û����ĩβʱ��������ȡ
    {
		fscanf(fp,"%d\t%d\t%d",&OrderList[0],&OrderList[1],&OrderList[2]);
    	if(OrderList[0]==id) break;
	}
    if(feof(fp))
	{
		OrderList[0]=0;
		OrderList[1]=0;
		OrderList[2]=0;
	}
	fclose(fp);	
} 
void OrderCustom() //���Ƿ����˵������� 
{
	struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
	void OrderDetail(struct TeaCake *p);//����һ�������������ĺ���
	void Ordered(); //����һ�������ѵ���ĺ���
	void OrderSort(); //����һ�������˵ĺ��� 
	struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //ѡ���ָ������
    char c; //����getchar()
    int page=0;//ҳ��
    int i,j; //��Ϊѡ�������������ѭ������
    int id;//��ΪID������
    int OrderList[3];//��ʾ���ĵĲ˵���ű�������һ���ǲ˱�ţ��ڶ������ѵ����� ;���������ܼ�
/*������������Ԥ����Ĳ���*/
LOOP_OrderCustom:
	j=0;//j��ʾ������Ŀ 
	for (i=0;i<TCItemNum;i++)
	{
		p=&TCList[i];
		if(p->ID==-1) continue;//IDΪ-1����Ŀ���� 
		else 
		{
			item[j]=p;
			j++; 
		}	
	}
/*�������������б�Ĳ���*/	
LOOP_OrderCustom1:
    system("cls");//����
    system("color 4f");
    printf("*******************************************************************************\n");
    printf("                       ��  ӭ  ��  ��  ��  ��  ��  ��                          \n");
    printf("�����ţ�%s ������%-55d��ˮ��%d\n",TableNumber,TableMan,TeaNumber);
    printf("*******************************************************************************\n");
    printf("                 ID          ��  ��              �۸�       ����               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (page*9+i>=j) break;
        p=item[page*9+i];
        printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./����/    u./��һҳ/    /��%dҳ/    n./��һҳ/    *./ˢ��/\n\n",page+1);
    printf(" a.|ͨ��ID�Ų���|  s.|�鿴�ѵ�|  d.|�鿴����|  f.|�����Ͳ���|  w.|���㲢�˳�|\n");
    printf("\n�������ַ����в�����\t");
/*�����������ַ�������Ĳ���*/
LOOP_OrderCustom2:
    c=getchar();
    if (c!='u'&&c!='n'&&c!='a') fflush(stdin);//����u,n,a�ַ��⣬������뻺��
    if (c-48>i&&c<='9') goto LOOP_OrderCustom2;//��������ֲ����б���
    switch (c)
    {
    case '0':
        return;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        OrderDetail(item[page*9+c-48-1]);
        goto LOOP_OrderCustom1;
    case '*':
        printf("����ˢ�£���");
        goto LOOP_OrderCustom;
    case '\n':
        goto LOOP_OrderCustom1;
    case 'n':
        if (page*9+i>=j) page=0;
        else page++;
        goto LOOP_OrderCustom1;
    case 'u':
        if (page==0) page=(j-1)/9;
        else page--;
        goto LOOP_OrderCustom1;
    case 'a':
        printf("���������ID�ţ�");
        scanf("%d",&id);
        fflush(stdin);
        p=TCFind(id);
    	if (p==NULL)
		{
        	printf("ID�Ų����ڣ���");
        	Sleep(1000);
    	}
        else OrderDetail(p);
        goto LOOP_OrderCustom1;
    case 's':
        Ordered();
        goto LOOP_OrderCustom1;
    case 'd':
    	OpinionLook();
    	goto LOOP_OrderCustom1;
    case 'f':
    	OrderSort();
		goto LOOP_OrderCustom1;
    case 'w':
        CustomerSettlement();
        goto LOOP_OrderCustom1; 
    default:
        printf("�����������������룡\t");
        Sleep(1000);
        goto LOOP_OrderCustom1;
    }
    return;
}
void OrderDetail(struct TeaCake *p) //����һ�������������ĺ��� 
{
	void OrderEdit(struct TeaCake *p,int num); //����һ���༭��������ĺ���
	void OrderFind(int OrderList[3],int id); //����һ�����ļ��в��ҵ�˼�¼�ĺ���
	struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
    int add;//����Ҫ��ӵķ��� 
    int OrderList[3]; //��ʾ���ĵĲ˵���ű�������һ���ǲ˱�ţ��ڶ������ѵ����� ;���������ܼ�
LOOP_OrderDetail:
	OrderFind(OrderList,p->ID);
    system("cls");//����
    printf("*******************************************************************************\n");
    printf("                             ��  ��  ��  ��  ��  ��                            \n");
    printf("*******************************************************************************\n");
    printf("                                   ID��%-4d\n",p->ID);
    printf("        --------------------------------------------------------------         \n");
    printf("\n");
    printf("                          ��  �ƣ�%-20s\n\n",p->name);
    printf("                          ��  ��%-4d\n\n",p->price);
    printf("                          ��  ��%-10s\n\n",TypeName[p->type]);
    printf("                          ��  �飺\n");
    printf("                    %-80s\n\n",p->intro);
    printf("        --------------------------------------------------------------         \n");
    printf("            0./����/            |Ŀǰ�ѵ���%d��|            |�ܼ�%dԪ|\n",OrderList[1],OrderList[2]);
    printf("\n������Ҫ��ӵķ���: ");
    scanf("%d",&add);
    fflush(stdin);
    if(add==0) return; 
	else if(OrderList[1]+add<0) 
	{
		printf("�������ֲ���ȷ");
		Sleep(1000);
	}
	else OrderEdit(p,OrderList[1]+add);
	return;
}
void OrderEdit(struct TeaCake *p,int num) //����һ����ӵ�˵ĺ���
{
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·��
	char ST_[20]={".\\table\\"};
	char ST1[]={".txt"};	//�����ļ��ĸ�ʽ
	char ST2[]={".txt~"};	//���ø�����ʽ 
	int OrderList[3]; //��ʾ���ĵĲ˵���ű�������һ���ǲ˱�ţ��ڶ������ѵ����� ;���������ܼ�
	FILE*fp1,*fp2;
	//���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ� 
	if ((fp1=fopen(	strcat(strcat(ST,TableNumber),ST1)	,"r"))==NULL)
        	fp1=fopen(ST,"w+");
	fp2=fopen(	strcat(strcat(ST_,TableNumber),ST2)	,"w+");//������������*.txt~ 
	while(1)
    {	//��*.txt���Ƶ�*.txt~
        fscanf(fp1,"%d\t%d\t%d",&OrderList[0],&OrderList[1],&OrderList[2]);
        if(OrderList[0]==p->ID||feof(fp1)) break;	//�ҵ���㣬���ļ�����ʱ������
        else fprintf(fp2,"%d\t%d\t%d\n",OrderList[0],OrderList[1],OrderList[2]);
    }
	if(num!=0) fprintf(fp2,"%d\t%d\t%d\n",p->ID,num,p->price*num);//�޸ĵ�����Ϊ0ʱ����Ҫд�� 
    if(feof(fp1)==0)
		while(feof(fp1)==0)//�ļ�ָ��û����ĩβʱ��������ȡ
	    {	//��*.txt���Ƶ�*.txt~
	        fscanf(fp1,"%d\t%d\t%d\n",&OrderList[0],&OrderList[1],&OrderList[2]);
	        if(OrderList[0]==p->ID) continue; 
	        else fprintf(fp2,"%d\t%d\t%d\n",OrderList[0],OrderList[1],OrderList[2]);
	    }
	fclose(fp1);
	fclose(fp2); //�ر��ļ�*.txt
	remove(ST);//ɾ��.\*.txt
	rename(ST_,ST);
	//��.\*.txt~�ĳ�.\*.txt����ɲ��� 
	return;
} 
void Ordered() //����һ�������ѵ���ĺ���
{
	struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
	void OrderDetail(struct TeaCake *p); //����һ�������������ĺ���
	void OrderEdit(struct TeaCake *p,int num); //����һ����ӵ�˵ĺ���
	struct TeaCake *p;
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·��
	char ST1[]={".txt"};	//�����ļ��ĸ�ʽ
	char c; //����getchar()
    int page=0;//ҳ��
    int i,j; //��Ϊѡ�������������ѭ������
    int id;//��ΪID������ 
    int sum;//�ܼ۸� 
	int OrderList[30][3]; //��ʾ���ĵĲ˵���ű�������һ���ǲ˱�ţ��ڶ������ѵ����� ;���������ܼ�
	FILE *fp;
	strcat(strcat(ST,TableNumber),ST1);//���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ�
/*������������Ԥ����Ĳ���*/
LOOP_Ordered:
	if((fp=fopen(ST,"r"))==NULL)
		fp=fopen(ST,"w+");
	j=0;//j��ʾ������Ŀ
	while(feof(fp)==0)
	{
		fscanf(fp,"%d\t%d\t%d",&OrderList[j][0],&OrderList[j][1],&OrderList[j][2]);
		if(feof(fp)==0) j++;
	}
	fclose(fp);
	sum=0;
	for(i=0;i<j;i++)
		sum+=OrderList[i][2];	
LOOP_Ordered1:
    system("cls");//����
    system("color fc");
    printf("*******************************************************************************\n");
    printf("                       ��  ��  ��  ��  ��  ��  ��  ��                          \n");
    printf("�����ţ�%s ������%-55d��ˮ��%d\n",TableNumber,TableMan,TeaNumber);
    printf("*******************************************************************************\n");
    printf("            ID      ��  ��            �۸�      �ѵ�����      Ӧ��Ǯ��         \n");
    printf("        --------------------------------------------------------------         \n");
	for(i=0;i<9;i++)
    {
        if(page*9+i>=j) break;
        p=TCFind(OrderList[page*9+i][0]);
        if(p==NULL) printf("               ��û�е��κβ�㣡����              \n");
        else printf("%10d.%4d  %-20s%4d        %4d        %6d\n",i+1,p->ID,p->name,p->price,OrderList[page*9+i][1],OrderList[page*9+i][2]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./����/    u./��һҳ/    /��%dҳ/    n./��һҳ/    *./ˢ��/\n\n",page+1);
    printf("    a.|ͨ��ID�ŵ��|    s.|ɾ���ѵ�|    |��ǰ�ܼ۸�Ϊ%dԪ|    w.|���㲢�˳�|\n",sum);
    printf("\n�������ַ����в�����\t");
/*�����������ַ�������Ĳ���*/
LOOP_Ordered2:
    c=getchar();
    if (c!='u'&&c!='n'&&c!='a'&&c!='s') fflush(stdin);//����u,n,a,s�ַ��⣬������뻺��
    if (c-48>i&&c<='9') goto LOOP_Ordered2;//��������ֲ����б���
    switch (c)
    {
    case '0':
        return;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        OrderDetail(TCFind(OrderList[page*9+c-48-1][0]));
        goto LOOP_Ordered;
    case '*':
        printf("����ˢ�£���");
        goto LOOP_Ordered;
    case '\n':
        goto LOOP_Ordered1;
    case 'n':
        if (page*9+i>=j) page=0;
        else page++;
        goto LOOP_Ordered1;
    case 'u':
        if (page==0) page=(j-1)/9;
        else page--;
        goto LOOP_Ordered1;
    case 'a':
        printf("���������ID�ţ�");
        scanf("%d",&id);
        fflush(stdin);
        p=TCFind(id);
    	if (p==NULL)
		{
        	printf("ID�Ų����ڣ���");
        	Sleep(1000);
    	}
        else OrderDetail(p);
        goto LOOP_Ordered;
    case 's':
    	printf("������Ҫɾ���ı�ţ�");
        scanf("%d",&i);
        fflush(stdin);
        p=TCFind(OrderList[page*9+i-1][0]);
        if (p==NULL)
		{
        	printf("�������󣡣�");
        	Sleep(1000);
    	}
        else OrderEdit(p,0);
        goto LOOP_Ordered;
    case 'w':
    	CustomerSettlement();
        goto LOOP_Ordered1;
    default:
        printf("�����������������룡\t");
        Sleep(1000);
        goto LOOP_Ordered1;
    }
	return;
}
void OrderSort() //����һ�������˵ĺ��� 
{
	struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
    void OrderDetail(struct TeaCake *p); //����һ�������������ĺ��� 
    struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //ѡ���ָ������
    char c; //����getchar()
    int page=0;//ҳ��
    int i,j; //��Ϊѡ�������������ѭ������
    int type[11]={0};//��Ϊtype������,��ֵ��ʾÿһ���͵���ʼ�±꣬���һ����ʾ�ܸ�������ʼֵΪȫ0
/*������������Ԥ����Ĳ���*/
LOOP_OrderSort: 
    for(j=0;j<=9;j++)
    {
	    type[j+1]=type[j];
		for (i=0;i<TCItemNum;i++)
	    {
	        p=&TCList[i];
	        if (p->type==j&&p->ID!=-1) 
			{
				item[type[j+1]]=p;
				type[j+1]++;
			}
	    }
    }
    j=0;//�ָ�0 
/*�������������б�Ĳ���*/
LOOP_OrderSort1:
    system("cls");//����
    system("color 4e");
    printf("*******************************************************************************\n");
    printf("                       ��  ӭ  ��  ��  ��  ��  ��  ��                          \n");
    printf("�����ţ�%s ������%-55d��ˮ��%d\n",TableNumber,TableMan,TeaNumber);
    printf("*******************************************************************************\n");
    printf("                 ID          ��  ��              �۸�       ����               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (type[j]+page*9+i>=type[j+1]) break;
        p=item[type[j]+page*9+i];
        printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./����/    u./��һҳ/    /��%dҳ/    n./��һҳ/    *./ˢ��/\n\n",page+1);
    printf("    a.|�л�������ʾ|    s.|�鿴�ѵ�|    d.|�鿴����|    w.|���㲢�˳�|\n");
    printf("\n�������ַ����й���\t"); 
/*�����������ַ�������Ĳ���*/
LOOP_OrderSort2:
	c=getchar();
    if (c!='u'&&c!='n'&&c!='a') fflush(stdin);//����u,n,a�ַ��⣬������뻺��
    if (c-48>i&&c<='9') goto LOOP_OrderSort2;//��������ֲ����б���
    switch (c)
    {
    case '0':
        return;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        OrderDetail(item[type[j]+page*9+c-48-1]);
        goto LOOP_OrderSort1;
    case '*':
        printf("����ˢ�£���");
        goto LOOP_OrderSort;
    case '\n':
        goto LOOP_OrderSort1;
    case 'n':
        if (type[j]+page*9+i>=type[j+1]) page=0;
        else page++;
        goto LOOP_OrderSort1;
    case 'u':
        if (page==0) page=(type[j+1]-type[j]+1)/9;
        else page--;
        goto LOOP_OrderSort1;
    case 'a':
    	for (i=0;i<5;i++)
        	printf("%d./%s/  ",i,TypeName[i]);
	    putchar('\n');
	    for (i=5;i<10;i++)
	        printf("%d./%s/  ",i,TypeName[i]);
	    putchar('\n');
	    printf("����������0-9�����л���");
	    scanf("%d",&i);
	    fflush(stdin);
	    j=i;
	    page=0;
        goto LOOP_OrderSort1;
	case 's':
        Ordered();
        goto LOOP_OrderSort1;
    case 'd':
    	OpinionLook();
    	goto LOOP_OrderSort1;
    case 'w':
        CustomerSettlement();
        goto LOOP_OrderSort1;
    default:
        printf("�����������������룡\t");
        Sleep(1000);
        goto LOOP_OrderSort1;
    }
    return;
}
//*******************************************ȫ����˺���****************************************************
void OrderAll()
{
	void CustomerSystem();
	char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ 
	FILE*fp;
	strcat(strcat(ST,TableNumber),ST1);   //���ַ���ϲ�ʵ���ñ���ֵ���������·����txt�ļ� 
	HANDLE wordscolor = GetStdHandle(STD_OUTPUT_HANDLE);
	int TCNumber;		//����� 
	int n[30][3];                //��ʾ���ĵĲ˵���ű�������һ���ǲ˱�ţ��ڶ������ѵ����� ;���������ܼ� 
	int i,flag,j,k,flag1=1,x=0,sum=0;
	for(i=0;i<30;i++){n[i][0]=0;n[i][1]=0;n[i][2]=0;}
	fflush(stdin);                                                          
	system("cls");
	system("color 80");
	srand((unsigned)time(NULL));   //����������� 
	for(i=0;i<30;i++)
	{
		n[i][0]=rand()%69;
		flag=1;
		while(flag==1)
		{
			for(j=0;j<i;j++)
			if(n[i][0]==n[j][0])break;
			if(j<i)n[i][0]=rand()%69;//�������ȣ�����������һ������� 
			if(j==i)flag=0;  //���û����ȣ�flag���0������ѭ�� 
		}
	}    //����һ��û���ظ�������� 
    j=1;
	
	while(1)
	{
Loop_6:		
		system("cls");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_INTENSITY);
		printf("ID. �������\t     ����   �ѵ���\tID. �������\t     ����   �ѵ���\t����0������һ�� ����1���н���\n"); 
		for(i=0;i<30;i++)
		{
			SetConsoleTextAttribute(wordscolor,BACKGROUND_INTENSITY);
			flag1*=(-1);
			if(flag1==-1)
			{
					SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|BACKGROUND_INTENSITY);
					printf("%-4d.%-15s %-4d   %-1d",TCList[n[i][0]].ID,TCList[n[i][0]].name,TCList[n[i][0]].price,n[i][1]);
			}
			if(flag1==1)
			{
					SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|BACKGROUND_INTENSITY);
					printf("\t\t%-4d.%-15s %-4d   %-1d\n",TCList[n[i][0]].ID,TCList[n[i][0]].name,TCList[n[i][0]].price,n[i][1]);
			}			 		
		}                        
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_INTENSITY);	
		printf("\nĿǰ�ܼ۸���:%d",sum);    //�ܼ۸����� 	
		printf("\n\n����Ҫ��Ĳ����(������):");
		scanf("%d",&TCNumber);
		fflush(stdin);
		flag=1;
		for(k=0;k<30;k++)
		{
			if(TCList[n[k][0]].ID==(TCNumber)||TCNumber==1||TCNumber==0)flag-=1;	       //�����벻���ڵĲ��IDʱ��flagֵ���� 
			//if(TCList[n[k][0]].ID==1||TCList[n[k][0]].ID==0){flag-=1;break;}//����0��1ʱ����flag��һ,��������ѭ�� 
		}
		if(flag==1)          //flagֵ���䣬���뱨����� 
		{                                                        
			system("cls");	
			SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_INTENSITY);
			printf("\n\n\n\n\t\t\\(*A*#)/����������ʾ�Ĳ��ID��2.233����Զ��ص���˽���\\(#*A*)/");
			Sleep(2233);
			goto Loop_6;
		}	
		if(TCNumber==0)
		{
			fp=fopen(ST,"w");
			for(i=0;i<30;i++)
			{
				if(n[i][2]!=0)
				fprintf(fp,"%d\t%d\t%d\n",TCList[n[i][0]].ID,n[i][1],n[i][2]);
			}		
			fclose(fp);
			CustomerSystem();	
			goto Loop_6;
		}
		if(TCNumber==1)
		{
			fp=fopen(ST,"w"); 
			for(i=0;i<30;i++)
			{
				if(n[i][2]!=0)
				fprintf(fp,"%d\t%d\t%d\n",TCList[n[i][0]].ID,n[i][1],n[i][2]);
			}		
			fclose(fp);
			CustomerSettlement();        
			goto Loop_6;
		} 		
		
		for(j=0;j<30;j++)
		{
			if((TCNumber-101)==n[j][0])break;  //������ѡID�Ķ�Ӧ�۸������� 
		}  
		printf("\n����Ҫ��������:");
		scanf("%d",&x);
		n[j][1]=x;
		n[j][2]=TCList[n[j][0]].price*n[j][1];		
		for(i=0,sum=0;i<30;i++)
		{
			sum+=n[i][2];
		}

	}
}
//*******************************************�����½����***********************************************
void managerEnterView()   //�����½���溯��
{
    system("cls");
	printf("                      ��******************************��\n");
	printf("                          �� ���ڽ��뾭�����ģʽ ��\n");
	printf("                      ��******************************��\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("���������Ա����\n");
	printf("      ����\n");

	char firstPassword[16]; //��������ʱ�õ��ı���
    FILE *in;          //����ֻ��file�����ļ���ָ�����
    int count  = 0;
    int i;
    char encryptedPassword[16]={"\0"};

    if((in=fopen("password.dat","r"))==NULL)
    {
        printf("�Ҳ������ļ���password.dat\n");
    }
    fgets(encryptedPassword,16,in);   //���ļ��е��ַ�������������encryptedPassword
    fclose(in);
    /*
    *  �������룬����ȫ�ֱ���
    */
    count=strlen(encryptedPassword);
    for (i=0;i<count;i++)
    {
        str[i]=encryptedPassword[i]-i-5;
    }
    str[i]='\0';

    /**
    *  ��ʼ��������
    */
	printf("���룺");
	scanf("%s",firstPassword);

	if(strcmp(str,firstPassword)==0)  //�ж���������ȷ
    {
        /**
        *  �������  ��������ã���
        */
        system("cls");
        printf("\n\n\n\n");
		char message_hello[] = "\t\t\t\t����,���!";
		unsigned int i;
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
		Sleep(500);
		managerControlView();    //��ת���������˵�ҳ��
    }
    else
    {   //��do-while�ж�������������룬ֱ��������ȷ
        do
        {
            printf("����������������룺");
            scanf("%s",firstPassword);
        }while(strcmp(str,firstPassword)!=0);

        //�������  ��������ã���
        char message_hello[] = "\t\t\t\t����,���!";
		unsigned int i;
		system("cls");
		printf("\n\n");	
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
		Sleep(500);
		managerControlView();   //��ת���������˵�ҳ��
    }
}

//*******************************************�������˵�����***********************************************

void managerControlView()
{
    char serialNumber;  //�������б�����к�
	while(1)
	{
	    system("cls");//����������ת����ĺ���
	    printf("\n\n");
	    printf("                      ��******************************��\n");
	    printf("                                 ||�����б�||\n");
	    printf("                      ��******************************��\n");
	    printf("                                  <<<<  >>>>\n");
	    printf("                                 1.  ���۹���\n");
	    printf("                                 2.  ��������\n");
	    printf("                                 3.  ��������\n");
	    printf("                                 4.  ������\n");
	    printf("                                 5.  �������\n");
	    printf("                                 0.  ����\n");
	    printf("                                 w.  �˳�ϵͳ\n");
	    printf("\n��ѡ��: ");
	    fflush(stdin);    //�������
	    serialNumber = getchar();
	    fflush(stdin);   //���빦���б����к�
	    /**
	    * �ж����кţ���ת����Ӧ����
	    */
	    if(serialNumber=='0'||serialNumber=='1'||serialNumber=='2'||serialNumber=='3'||serialNumber=='4'||serialNumber=='5'||serialNumber=='6'||serialNumber=='w')
	    {
	        switch( serialNumber )
	        {
	            case '1':
	                system("cls");   //����������ת����ĺ���
	                Sleep(500);
	                managerControlEvaluationView();  //���۹�����
	                break;
	            case '2':
	                system("cls");   //����������ת����ĺ���
	                TableManagement();  //����������
	                break;
	            case '3':
	                system("cls");   //����������ת����ĺ���
	                OrderManage();  //����������
	                break;
	            case '4':
	                system("cls");   //����������ת����ĺ���
	                TCManage();   //��������
	                break;
	            case '5':
	                system("cls");   //����������ת����ĺ���
	                passwordManagement();    //���������
	                break;
	            case '0':
	                system("cls");   //����������ת����ĺ���
	                return;   //������һ�㣨���˵���
	                break;
	            case 'w':
	                system("cls");   //����������ת����ĺ���
	                exit(0);
	                break;
	        }
	    }
	    else
	    {   //��do-while�ж�������������кţ�ֱ����ȷ
	        do
	        {
	            printf("\t\t\t+-+-+-+-+ ���к����� +-+-+-+-+\t\t\t\n");
	            printf("\n������0��6��w��");
	            fflush(stdin);
	            scanf("%c",&serialNumber);
	        }while(serialNumber!='0'&&serialNumber!='1'&&serialNumber!='2'&&serialNumber!='3'&&serialNumber!='4'&&serialNumber!='5'&&serialNumber!='6'&&serialNumber!='w');
	        switch( serialNumber )
	        {
	            case '1':
	                system("cls");   //����������ת����ĺ���
	                managerControlEvaluationView(); //���۹�����
	                break;
	            case '2':
	                //tableView();    //����������
	                break;
	            case '3':
	                OrderManage();  //����������
	                break;
	            case '4':
	                TCManage();   //��������
	                break;
	            case '5':
	                passwordManagement();    //���������
	                break;
	            case '0':
	                return;   //������һ�㣨���˵���
	                break;
	            case 'w':
	                exit(0);   //�˳�ϵͳ����
	                break;
	        }
	    } 	
	}
}
//*******************************************�޸����뺯��**********************************************
void passwordManagement()   //�޸����뺯��
{
    system("cls");   //����������ת����ĺ���
    FILE *out;
    int count = 0;
    int i;
    char encryptedPassword[16]={"\0"};
    char secondPassword[16]; //�޸�����ʱ�õ��ı���
    printf("                   ��******************************��\n");
	printf("                           �� �޸�����ҳ�� ��\n");
	printf("                   ��******************************��\n");
	printf("\n\n");
	if((out = fopen("password.dat","w"))==NULL)
    {
        printf("�Ҳ������ļ���password.dat\n");
    }
	printf("������ԭ���룺");
	fflush(stdin);    //�������
    scanf("%s",secondPassword);
    if(strcmp(str,secondPassword)==0)
    {
        printf("�����������룺");
        fflush(stdin);    //�������
        scanf("%s",secondPassword);
        strcpy(str,secondPassword);  //���޸ĺ�����봳��ȫ�ֱ�����
        /**
        *��������ܺ�����ļ���
        */
        count=strlen(str);
        for (i=0;i<count;i++)
        {
            encryptedPassword[i]=str[i]+i+5;
        }
        encryptedPassword[i]='\0';
        fputs(encryptedPassword,out);
        fclose(out);
        char message_hello[] = "\t\t\t\t�����޸ĳɹ�!";
		unsigned int i;
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
        Sleep(2000);
        managerControlView();//���ؾ������ҳ��
    }
    else
    {
        do
        {
            printf("����ԭ����������������룺");
            fflush(stdin);    //�������
            scanf("%s",secondPassword);
        }
        while(strcmp(str,secondPassword)!=0);
        printf("ԭ����������ȷ\n");
        printf("�����������룺");
        fflush(stdin);    //�������
        scanf("%s",secondPassword);
        strcpy(str,secondPassword);  //���޸ĺ������ʵʱ���µ�ȫ�ֱ���
         /**
        *��������ܺ�����ļ���
        */
        count=strlen(str);
        for (i=0;i<count;i++)
        {
            encryptedPassword[i]=str[i]+i+5;
        }
        encryptedPassword[i]='\0';
        fputs(encryptedPassword,out);
        fclose(out);

        char message_hello[] = "\t\t\t\t�����޸ĳɹ�!";
		unsigned int i;
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
        Sleep(2000);
        managerControlView();//���ؾ������ҳ��
    }
}
//*******************************************����Ա���۹�����****************************************************
void managerControlEvaluationView()
{
	system("cls");   //����������ת����ĺ���
	printf("                      ��******************************��\n");
    printf("                              ||�鿴�û�����ҳ��||\n");
    printf("                      ��******************************��\n");
    FILE *in;
    int option;
    int evaluationNum;
    int i,j;
    int k;
    char tableNum[100][4];//�����ŵ�����
    char ch[100][100];  //���ȡ�����ַ�
loop1:
    if((in=fopen("userOpinion.txt","r"))==NULL)
    {
        printf("�޷��򿪴��ļ�userOpinion.txt");
    }
    for(i=0;i<100;i++)
    {
        tableNum[i][0]='\0';
        ch[i][0]='\0';
    }

    /**
    *  forѭ������ȡ�ļ��е����ݣ��ֱ����tableNum��ch�Ķ�ά������
    */
    for(i = 0; i < 100; i++)
    {
        fscanf(in,"%s\t%s\n",&tableNum[i],&ch[i]);
        if(ch[i][0]==0)break;
    }
    fclose(in);
    /*
    * ������� ableNum��ch�Ķ�ά������ȡ��
    */
    for(k = 0; k<i; k++)
    {
        printf("\n");
        printf("      %d����%s��������: %s\n",k+1,tableNum[k],ch[k]);
    }
    printf("\n        <<*******�����������ж���򲻷���ʵ�ʵ����ۣ��ɽ���ɾ��ѡ��*******>>\n\n");
    printf("                          <<<< 1.  ������һ��   >>>>\n");
    printf("                          <<<< 2.  ɾ���������� >>>>\n");
    printf("��ѡ��Ҫ���еĲ�����");
    scanf("%d",&option);
    fflush(stdin);    //�������
    switch( option )
    {
        case 1:
            return;
            break;
        case 2:
        {
            printf("��������Ҫɾ�������۱�ţ�");
            scanf("%d",&evaluationNum);
            fflush(stdin);    //�������

            FILE *out;
            out = fopen("userOpinion.txt","w");
            /**
            *  for()ѭ���н�ɾ����ʣ������ݴ����ļ���
            */
            for(k = 0; k <6; k++)
            {
                if(k==evaluationNum-1)continue;
                fprintf(out,"%s\t%s\n",tableNum[k],ch[k]);
            }
            fclose(out);

            char message_hello[] = "\t\t\t\t��ɾ��!\n";

            for(k = 0;k < strlen(message_hello); k++)
            {
                printf("%c",message_hello[k]);
                Sleep(100);
            }
            Sleep(500);
        }break;
        system("cls");  //���ҳ��
    }
    system("cls");  //���ҳ��
    printf("                      ��******************************��\n");
    printf("                              ||�û�����ҳ��||\n");
    printf("                      ��******************************��\n");
    printf("                                  <<<<  >>>>\n");
    printf("                              1.  ������һ��\n");
    printf("                              2.  ɾ����������\n");
    printf("                                  <<<<  >>>>\n");
    goto loop1;
}
//*******************************************�û����ۺ���***********************************************
void userEvaluationView()
{
    void CustomerSystem();    //��������
    system("cls");
    fflush(stdin);
	int i;
    char Opinion[100];  //�����ݴ��û�������
    FILE *out;
    printf("                     ��******************************��\n");
	printf("                             �� �û����۽��� ��\n");
	printf("                     ��******************************��\n");
	printf("\n");
	printf("\n");
	printf("���������Ա��Ƶ������(��ɺ��Զ����ز�������)\n");
	printf("      ����\n");
	scanf("%s",Opinion);     //�û���������
	fflush(stdin);
    out = fopen("userOpinion.txt","a");
    fprintf(out,"%s\t%s\n",TableNumber,Opinion);
    fclose(out);
    printf("\n\n    ��******��л�����±������������Ƶ������������������������******��\n");
    Sleep(1233); 
    CustomerSystem();   //���ؿͻ�����ϵͳҳ��
}
//*******************************************���˵�����***********************************************
struct TeaCake * TCFind(int id)//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
{
    struct TeaCake *p;
    int i;
    for (i=0;i<TCItemNum;i++)
        if (TCList[i].ID==id) break;
    if (i==TCItemNum) p=NULL; //�Ҳ����򷵻ؿյ�ַ
    else p=&TCList[i];
    return(p);
}
void TCManage() //���ǲ�����ģ��������� 
{
    struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
    void TCEdit(struct TeaCake *p);//����һ���༭�����Ϣ�ĺ���
    void TCAdd(int id); //����һ����Ӳ��ĺ���
    void TCDelete(int id); //����һ��ɾ�����ĺ���
    void TCSave(struct TeaCake *item[TCItemNum]); //����һ����������Ϣ�ĺ���
    void TCImport();  //���ı�����˵�
    void TCExport();  //�����˵����ı�
    void TCSort(); //����һ�����������溯�� 
    struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //ѡ���ָ������
    char c; //����getchar()
    int page=0;//ҳ��
    int i,j; //��Ϊѡ�������������ѭ������
    int id;//��ΪID������
/*������������Ԥ����Ĳ���*/
LOOP_TC:
    id=101; //��ΪID������,��ʼֵΪ101
    j=TCItemNum-1;
    for (i=TCItemNum-1;i>=0;i--)//����
    {
        p=&TCList[i];
        if (p->ID==-1)
        {
            item[j]=p;
            j--;
        }
    }
    for (i=0;i<=j;i++)
    {
        do
        {
            p=TCFind(id);
            id++;
        }
        while (p==NULL);
        item[i]=p;
    }
    Sleep(1000);
/*�������������б�Ĳ���*/
LOOP_TC1:
    system("cls");//����
    printf("*******************************************************************************\n");
    printf("                             ��  ��  ��  ��  ��  ��                            \n");
    printf("*******************************************************************************\n");
    printf("                 ID          ��  ��              �۸�       ����               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (page*9+i>=TCItemNum) break;
        p=item[page*9+i];
        if (p->ID==-1) //IDΪ-1����Ŀ��ʾ��ɾ��
            printf("%10d.\t��ɾ��\t%-20s\t%4d\t%10s\n",i+1,p->name,p->price,TypeName[p->type]);
        else
            printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./����/    u./��һҳ/    /��%dҳ/    n./��һҳ/    *./ˢ��/\n\n",page+1);
    printf(" a.|��Ӳ��|  s.|ɾ�����|  d.|һ��������|  f.|�����͹���|  w.|���̲��˳�|\n");
    printf("\n�������ַ����й���\t");
/*�����������ַ�������Ĳ���*/
LOOP_TC2:
    c=getchar();
    if (c!='u'&&c!='n') fflush(stdin);//����u,n�ַ��⣬������뻺��
    if (c-48>i&&c<='9') goto LOOP_TC2;//��������ֲ����б���
    switch (c)
    {
    case '0':
        return;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        TCEdit(item[page*9+c-48-1]);
        goto LOOP_TC1;
    case '*':
        printf("����ˢ�£���");
        goto LOOP_TC;
    case '\n':
        goto LOOP_TC1;
    case 'n':
        if (page*9+i>=TCItemNum) page=0;
        else page++;
        goto LOOP_TC1;
    case 'u':
        if (page==0) page=(TCItemNum-1)/9;
        else page--;
        goto LOOP_TC1;
    case 'a':
        printf("������Ҫ��ӵ�ID�ţ�");
        scanf("%d",&id);
        fflush(stdin);
        TCAdd(id);
        goto LOOP_TC1;
    case 's':
        printf("������Ҫɾ����ID�ţ�");
        scanf("%d",&id);
        fflush(stdin);
        TCDelete(id);
        goto LOOP_TC1;
    case 'd':
        printf("1.���ı�����˵� or 2.�����˵����ı���"); 
        scanf("%d",&i);fflush(stdin);
        if (i==1)
            TCImport();
        else if (i==2)
            TCExport();
        else printf("�������������֣�"); 
        goto LOOP_TC;
    case 'f':
    	TCSort();
		goto LOOP_TC1;
    case 'w':
        TCSave(item);
        return;
    default:
        printf("�����������������룡\t");
        Sleep(1000);
        goto LOOP_TC1;
    }
    return;
}
void TCEdit(struct TeaCake *p) //����һ���༭�����Ϣ�ĺ���
{
    void TCAdd(int id); //����һ����Ӳ��ĺ���
    void TCDelete(int id); //����һ��ɾ�����ĺ���
    struct TeaCake temp;//�����ʱ������
    char c;//����getchar()
    int i; //����forѭ��
    int id;//��ΪID������
LOOP_TCEdit:
    system("cls");//����
    printf("*******************************************************************************\n");
    printf("                             ��  ��  ��  ��  ��  ��                            \n");
    printf("*******************************************************************************\n");
    if (p->ID==-1)
        printf("                                   �� ɾ ��\n");
    else
        printf("                                   ID��%-4d\n",p->ID);
    printf("        --------------------------------------------------------------         \n");
    printf("\n");
    printf("                      1.  ��  �ƣ�%-20s\n\n",p->name);
    printf("                      2.  ��  ��%-4d\n\n",p->price);
    printf("                      3.  ��  ��%-10s\n\n",TypeName[p->type]);
    printf("                      4.  ��  �飺\n");
    printf("                    %-80s\n\n",p->intro);
    printf("        --------------------------------------------------------------         \n");
    if (p->ID==-1)
        printf("            0./����/            s.|�ָ����|\n");
    else
        printf("            0./����/            s.|ɾ�����|\n");
    printf("\n��ѡ����Ӧ���ַ����в���: ");

    c=getchar();
    fflush(stdin); //�������
    switch (c)
    {
    case '0':
        return;
    case '1':
        printf("ԭ���ƣ�%-20s\n",p->name);
        printf("�����ƣ�");
        scanf("%20s",&temp.name); //�ȸ�ֵ����ʱ����
        fflush(stdin);
        printf("1.ȷ�� or 0.ȡ����");
        c=getchar();
        fflush(stdin);
        if (c=='1') strcpy(p->name,temp.name); //ȷ�Ϻ���������ֵ
        goto LOOP_TCEdit;
    case '2':
        printf("ԭ�۸�%-4d\n",p->price);
        printf("�¼۸�");
        scanf("%d",&temp.price);
        fflush(stdin);
        printf("1.ȷ�� or 0.ȡ����");
        c=getchar();
        fflush(stdin);
        if (c=='1') p->price=temp.price;
        goto LOOP_TCEdit;
    case '3':
        for (i=0;i<5;i++)
            printf("%d./%s/  ",i,TypeName[i]);
        putchar('\n');
        for (i=5;i<10;i++)
            printf("%d./%s/  ",i,TypeName[i]);
        putchar('\n');
        printf("ԭ���ͣ�%-4d\n",p->type);
        printf("�����ͣ�");
        scanf("%d",&temp.type);
        fflush(stdin);
        printf("1.ȷ�� or 0.ȡ����");
        c=getchar();
        fflush(stdin);
        if (c=='1') p->type=temp.type;
        fflush(stdin);
        goto LOOP_TCEdit;
    case '4':
        printf("ԭ��飺%-80s\n",p->intro);
        printf("�¼�飺");
        scanf("%80s",&temp.intro);
        fflush(stdin);
        printf("1.ȷ�� or 0.ȡ����");
        c=getchar();
        fflush(stdin);
        if (c=='1') strcpy(p->intro,temp.intro);
        goto LOOP_TCEdit;
    case 's':
        if (p->ID==-1)
        {
            printf("������ԭ����ID�ţ�");
            scanf("%d",&temp.ID);
            fflush(stdin);
            TCAdd(temp.ID);
        }
        else
            TCDelete(p->ID);
        goto LOOP_TCEdit;
    case '*':
        printf("����ˢ�£���");
        goto LOOP_TCEdit;
    default:
        printf("�����������������룡\t");
        goto LOOP_TCEdit;
    }
    return;
}
void  TCAdd(int id) //����һ����Ӳ��ĺ���
{
    struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
    void TCEdit(struct TeaCake *p);//����һ���༭�����Ϣ�ĺ���
    struct TeaCake *p;
    struct TeaCake temp;//�����ʱ������
    char c;//����getchar()
    int i;
    FILE *fp;
    p=TCFind(id);
    if (p!=NULL)
        printf("ID���ظ�����");
    else
    {
        system("cls");
        if ((fp=fopen("TCRecycleBin.txt","r"))==NULL) //�򿪻���վTCRecycleBin.txt
            fp=fopen("TCRecycleBin.txt","w+");
        p=TCFind(-1); //Ѱ��һ�����е�λ��
        while (temp.ID!=id&&feof(fp)==0)//��ID����ȣ����ļ�ָ��û����ĩβʱ��������ȡ
        	fscanf(fp,"%d\t%s\t%d\t%d\t%s",&temp.ID,&temp.name,&temp.price,&temp.type,&temp.intro);//��ȡ����վTCRecycleBin.txt
        printf("*******************************************************************************\n");
        printf("                             ��  ��  ��  ��  ��  ��                            \n");
        printf("*******************************************************************************\n");
        if (feof(fp))//����ļ�ָ����ĩβ,��ʾ��Ҫ�ֶ�����һ��
        {
            temp.ID=id;
            printf("\nID��%d\n",temp.ID);
            printf("\n���������ƣ�");
            scanf("%20s",&temp.name);
            printf("\n������۸�");
            scanf("%d",&temp.price);
            for (i=0;i<5;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            for (i=5;i<10;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            printf("\n���������ͣ�");
            scanf("%d",&temp.type);
            printf("\n�������飺");
            scanf("%80s",&temp.intro);
            fflush(stdin);
            printf("1.ȷ�ϴ��� or 0.ȡ����");
        }
        else
        {
            printf("\nID��%d\n",temp.ID);
            printf("\n���ƣ�%-20s\n",temp.name);
            printf("\n�۸�%-4d\n",temp.price);
            for (i=0;i<5;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            for (i=5;i<10;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            printf("\n���ͣ�%-4d\n",temp.type);
            printf("\n��飺%-80s\n",temp.intro);
            printf("1.ȷ�ϻָ� or 0.ȡ����");
        }
        c=getchar();
        fflush(stdin);
        if (c=='1')
        {
            p->ID=temp.ID;//ȷ�Ϻ���ʽд��
            strcpy(p->name,temp.name);
            p->price=temp.price;
            p->type=temp.type;
            strcpy(p->intro,temp.intro);
            TCEdit(p);
        }
        fclose(fp); //�ر��ļ�TCRecycleBin.txt
    }
    return;
}
void TCDelete(int id) //����һ��ɾ�����ĺ���
{
    struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
    struct TeaCake *p;
    char c;//����getchar()
    FILE *fp;
    p=TCFind(id);
    if (p==NULL||id==-1)
        printf("�Ҳ���ID�ţ���");
    else
    {
        printf("1.ȷ�� or 0.ȡ����");
        c=getchar();
        fflush(stdin);
        if (c=='1')
        {
            if ((fp=fopen("TCRecycleBin.txt","a+"))==NULL) //�򿪻���վTCRecycleBin.txt
                fp=fopen("TCRecycleBin.txt","w+");
            fprintf(fp,"%d\t%s\t%d\t%d\t%s\n",p->ID,p->name,p->price,p->type,p->intro);//�������վTCRecycleBin.txt
            fclose(fp);
            p->ID=-1;
            printf("�ɹ�ɾ��%d�Ų�㣡��",id);
        }
    }
    Sleep(1000);
    return;
}
void TCImport()  //���ı�����˵�
{
    FILE *fp1,*fp2;  //
    int i;
    char FileIn[20]; //Ҫ��ȡ���ı��ļ���

    printf("�������ȡ���ı��ļ�����\n");
    scanf("%s",FileIn);
    if ((fp1=fopen(FileIn,"r"))==NULL) //��Ҫ��ȡ���ı��ļ�
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (i=0;i<TCItemNum;i++)//�����ļ��ڵ����ݵ�����TCList[TCItemNum]
    {
        if (feof(fp1)) //����ļ�λ���ڽ�β
            for (;i<TCItemNum;i++)
                TCList[i].ID=-1; //����ȫ��д��-1���Ա����
        else
            fscanf(fp1,"%d\t%s\t%d\t%d\t%s\n",
                   &TCList[i].ID,&TCList[i].name,&TCList[i].price,&TCList[i].type,&TCList[i].intro);
    }
    fclose(fp1);

    if ((fp2=fopen("TCList.dat","wb+"))==NULL) //�����ļ�TCList.dat
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fwrite(TCList,sizeof(struct TeaCake),TCItemNum,fp2);//д���ļ�TCList.dat
    fclose(fp2);//�ر��ļ�TCList.dat
    printf("�����ɶ������ļ�TCList.dat\n");
    return;
}
void TCExport()  //�����˵����ı�
{
    FILE *fp1,*fp2;
    int i;
    char FileOut[20]; //�������ı��ļ����ļ���

    printf("�����뵼�����ı��ļ�����\n");
    scanf("%s",FileOut);
    if ((fp1=fopen("TCList.dat","rb"))==NULL) //���ļ�TCList.dat
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fread(TCList,sizeof(struct TeaCake),TCItemNum,fp1);//����TCList.dat�ļ��ڵ����ݵ�����TCList[80]
    fclose(fp1);

    if ((fp2=fopen(FileOut,"w+"))==NULL)   //����һ���ı��ļ�
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (i=0;i<TCItemNum;i++) //д���ı��ļ�
    {
        if (TCList[i].ID==-1) continue; //����������ʶ-1��������һ��
        fprintf(fp2,"%d\t%s\t%d\t%d\t%s\n",
                TCList[i].ID,TCList[i].name,TCList[i].price,TCList[i].type,TCList[i].intro);
    }
    fclose(fp2);
    printf("�������ı��ļ�%s\n",FileOut);
    return;
}
void TCSort()//����һ�����������溯�� 
{
    struct TeaCake * TCFind(int id);//����һ��ͨ��ID�Ų��Ҳ���ַ�ĺ���
    void TCEdit(struct TeaCake *p);//����һ���༭�����Ϣ�ĺ���
    void TypeNameEdit(); //����һ���༭�������ĺ���
    void TypeNameSave();//����һ��������������Ϣ�ĺ���
    struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //ѡ���ָ������
    char c; //����getchar()
    int page=0;//ҳ��
    int i,j; //��Ϊѡ�������������ѭ������
    int type[11]={0};//��Ϊtype������,��ֵ��ʾÿһ���͵���ʼ�±꣬���һ����ʾ�ܸ�������ʼֵΪȫ0
/*������������Ԥ����Ĳ���*/
LOOP_TCSort: 
    for(j=0;j<=9;j++)
    {
	    type[j+1]=type[j];
		for (i=0;i<TCItemNum;i++)
	    {
	        p=&TCList[i];
	        if (p->type==j) 
			{
				item[type[j+1]]=p;
				type[j+1]++;
			} 
	    }
    }
    j=0;//�ָ�0 
/*�������������б�Ĳ���*/
LOOP_TCSort1:
    system("cls");//����
    printf("*******************************************************************************\n");
    printf("                             ��  ��  ��  ��  ��  ��                            \n");
    printf("*******************************************************************************\n");
    printf("                 ID          ��  ��              �۸�       ����               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (type[j]+page*9+i>=type[j+1]) break;
        p=item[type[j]+page*9+i];
        if (p->ID==-1) //IDΪ-1����Ŀ��ʾ��ɾ��
            printf("%10d.\t��ɾ��\t%-20s\t%4d\t%10s\n",i+1,p->name,p->price,TypeName[p->type]);
        else
            printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./����/    u./��һҳ/    /��%dҳ/    n./��һҳ/    *./ˢ��/\n\n",page+1);
    printf("        a.|�л�������ʾ|        f.|�޸�������|        w.|���̲��˳�|\n");
    printf("\n�������ַ����й���\t"); 
/*�����������ַ�������Ĳ���*/
LOOP_TCSort2:
	c=getchar();
    if (c!='u'&&c!='n') fflush(stdin);//����u,n�ַ��⣬������뻺��
    if (c-48>i&&c<='9') goto LOOP_TCSort2;//��������ֲ����б���
    switch (c)
    {
    case '0':
        return;
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        TCEdit(item[type[j]+page*9+c-48-1]);
        goto LOOP_TCSort1;
    case '*':
        printf("����ˢ�£���");
        goto LOOP_TCSort;
    case '\n':
        goto LOOP_TCSort1;
    case 'n':
        if (type[j]+page*9+i>=type[j+1]) page=0;
        else page++;
        goto LOOP_TCSort1;
    case 'u':
        if (page==0) page=(type[j+1]-type[j]+1)/9;
        else page--;
        goto LOOP_TCSort1;
    case 'a':
    	for (i=0;i<5;i++)
        	printf("%d./%s/  ",i,TypeName[i]);
	    putchar('\n');
	    for (i=5;i<10;i++)
	        printf("%d./%s/  ",i,TypeName[i]);
	    putchar('\n');
	    printf("����������0-9�����л���");
	    scanf("%d",&i);
	    fflush(stdin);
	    j=i;
	    page=0;
        goto LOOP_TCSort1;
    case 'f':
    	TypeNameEdit();
    	goto LOOP_TCSort1;
    case 'w':
        TypeNameSave(item);
        return;
    default:
        printf("�����������������룡\t");
        Sleep(1000);
        goto LOOP_TCSort1;
    }
    return;
}
void TCSave(struct TeaCake *item[TCItemNum])//����һ����������Ϣ�ĺ���
{
	struct TeaCake temp;//�����ʱ������
	char c;
    int i;
    FILE *fp,*fp1,*fp2;
    printf("���̺��㽫�᳤�ڱ��棬�Ƿ���̣�\n");
    printf("1.ȷ�� or 0.ȡ����");
    c=getchar();
    fflush(stdin);
    if (c=='1')
    {
        printf("���ڽ������Ϣд���ļ��С�����\n");
        if ((fp=fopen("TCList.dat","wb"))==NULL)
            printf("cannot open TCList.dat\n");
        for (i=0;i<TCItemNum;i++)
        {
            fwrite(item[i],sizeof(struct TeaCake),1,fp);//����item�źõ�˳������д���ļ�TCList.dat
        }
        fclose(fp);
        
        if ((fp1=fopen("TCRecycleBin.txt","r"))==NULL)
        	fp1=fopen("TCRecycleBin.txt","w+");
       	fp2=fopen("TCRecycleBin.txt~","w+");//��������վ����TCRecycleBin.txt~
        while (feof(fp1)==0)//�ļ�ָ��û����ĩβʱ��������ȡ
        {
            //��TCRecycleBin.txt���Ƶ�TCRecycleBin.txt~
            fscanf(fp1,"%d\t%s\t%d\t%d\t%s\n",&temp.ID,&temp.name,&temp.price,&temp.type,&temp.intro);//�������վTCRecycleBin.txt
            if(TCFind(temp.ID)!=NULL) continue;
            else fprintf(fp2,"%d\t%s\t%d\t%d\t%s\n",temp.ID,temp.name,temp.price,temp.type,temp.intro);
        }
        fclose(fp1);
        fclose(fp2); //�ر��ļ�TCRecycleBin.txt
        remove("TCRecycleBin.txt");
        rename("TCRecycleBin.txt~","TCRecycleBin.txt");//���ļ�������ɲ���       	
    }
    Sleep(1000);
    return;
}
void TypeNameEdit() //����һ���༭�������ĺ���
{
    char c;
	char temp[10];
    int i;
    for (i=0;i<5;i++)
        printf("%d./%s/  ",i,TypeName[i]);
    putchar('\n');
    for (i=5;i<10;i++)
        printf("%d./%s/  ",i,TypeName[i]);
    putchar('\n');
    printf("����������0-9�����޸ģ�");
    scanf("%d",&i);
    fflush(stdin);
    printf("ԭ���ƣ�%-10s\n",TypeName[i]);
    printf("�����ƣ�");
    scanf("%10s",temp); //�ȸ�ֵ����ʱ����
    fflush(stdin);
    printf("1.ȷ�� or 0.ȡ����");
    c=getchar();
    fflush(stdin);
    if (c=='1') strcpy(TypeName[i],temp); //ȷ�Ϻ���������ֵ
    Sleep(1000);
    return;
}
void TypeNameSave()//����һ��������������Ϣ�ĺ���
{
	char c;
    int i;
    FILE *fp;
    printf("���̺����������᳤�ڱ��棬�Ƿ���̣�\n");
    printf("1.ȷ�� or 0.ȡ����");
    c=getchar();
    fflush(stdin);
    if (c=='1')
    {
        printf("���ڽ���������Ϣд���ļ��С�����\n");
        if ((fp=fopen("TypeName.dat","wb"))==NULL)
            printf("cannot open TCList.dat\n");
		fwrite(TypeName,sizeof(char [10]),10,fp);//һ����д���ļ�TypeName.dat
        fclose(fp);
    }
    Sleep(1000);
    return;
}
//*****************************************����������*********************************************
void TableManagement()  //����������
{
    struct TeaCake *TCFind(int id);
    struct TeaCake *p;
    printf("\n");
    char tableMessage[100][7];     //���table�ļ����µ��ļ���
    int i,k,j,id,num,price;
    FILE *fp;
    int attendances;   //������
    struct _finddata_t fa;
	long fHandle;
loop_TableManager:
    i=0;k=0;j=0;
    system("cls");
    printf("                      ��******************************��\n");
    printf("                               ||��������鿴||\n");
    printf("                      ��******************************��\n");
	if( (fHandle=_findfirst( ".\\table\\*.txt", &fa ))==-1L ) //������Ըĳ���Ҫ��Ŀ¼
	{
		printf("\n\n");
		printf("                                ��ǰû���κ����òͣ���\n");
		printf("\n��0�˳������س���ˢ��:");
		if(getchar()!='0')
	    {
	        fflush(stdin);
	        goto loop_TableManager;
	    }
	    fflush(stdin);
	    return; 
	}
	else
        do
        {
            strcpy(tableMessage[i],fa.name);     //��ȡ�ļ���
            for(k=0;k<7;k++)
            {
                if(tableMessage[i][k]=='.')
                {
                    while(k<7)
                    {
                        tableMessage[i][k]='\0';     //��.txtȥ����ֻʣ������
                        k++;
                    }break;
                }
            }
            i++;
        }while( _findnext(fHandle,&fa)==0 );
	_findclose( fHandle );

	for(k=0;k<i;k++)
    {
        int sum=0;  //�����ѽ��
        char ST[20]={".\\table\\"};  //���ò��������Ϣ�ļ������·��
        char ST1[5]={".txt"};      //�����ļ��ĸ�ʽ
        printf("\t%s����:\n",tableMessage[k]);

        if((fp=fopen(strcat(strcat(ST,tableMessage[k]),ST1),"r"))==NULL)
        {
            printf("�ļ��������");
        }
        printf("\t       �ѵ���:  ");
        while(feof(fp)==0)
        {
            fscanf(fp,"%d\t%d\t%d",&id,&num,&price);
            if(feof(fp))break;
            p = TCFind(id);
            if(p==NULL)
            {
                break;
            }
            printf("%s\t����:%d\t����:%d\n",p->name,num,price);
            sum+=price;
            printf("\t                  ");
        }
        printf("\n");
        printf("\t                          \t\tһ������%d\n",sum);
        fclose(fp);
        printf("\n");
    }
    attendances = (int)(((double)i/100)*100);
    printf("\n\t����������Ϊ:%d.0%%\n",attendances);
    printf("\n��0�˳������س���ˢ��:");
    if(getchar()!='0')
    {
        fflush(stdin);
        goto loop_TableManager;
    }
    fflush(stdin);

    return;
}
//*******************************************������Ϣ����***********************************************
void OrderManage()
{
	while(1)
	{
		int i;
		fflush(stdin);
		system("cls");
		printf("\n\t\t1.��ѯ�����˵�\t2.����˵���¼\t3.������һ��\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: CheckOrder();break;
			case 2: ClearOrder();break;
			case 3: return;break;
			default: printf("\n������������ȷ������");Sleep(1233);break;
		}
	}
}
//*******************************************�����鿴***********************************************
void CheckOrder()
{
  	
	char t[2];
	FILE*fp;
	char ST[25]={".\\orderinfo\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"}; 
	int n[100][3],i,k=0,sum=0,sum1=0;
	for(i=0;i<100;i++){n[i][0]=0;n[i][1]=0;n[i][2]=0;}
	system("cls");
	printf("\n\n\t����������鿴�Ĳ����Ķ�����");
	fflush(stdin);
	scanf("%s",t);
	fflush(stdin);
	system("cls");
	fp=fopen(strcat(strcat(ST,t),ST1),"r");	
	for(i=0;i<100;i++)
	{
Loop_10:
		fscanf(fp,"%d",&n[i][0]);
		if(n[i][0]==1)
		{
			n[i][1]=0;n[i][2]=0;i++;goto Loop_10;
		}
		fscanf(fp,"%d",&n[i][1]);
		fscanf(fp,"%d",&n[i][2]);
	}
	fclose(fp);
	printf("ID. �������\t     ����    �ѵ���     Ӧ��Ǯ��\n");
	printf("----------------------------------------------------------------------------\n");
	for(i=0;i<100;i++)
	{
		if(n[i][0]==1)
		{
			printf("\n");
			for(;k<=i;k++)
			{
				sum+=n[k][2];
			}
			sum1+=sum;
			printf("\t�˴ε������ܶ�Ϊ%d",sum);
			sum=0;
			printf("\n----------------------------------------------------------------------------\n");
			continue;			
		}
		if(n[i][0]==0)break;
		printf("%-4d.%-15s %-4d      %-1d  \t  %d\n",TCFind(n[i][0])->ID,TCFind(n[i][0])->name,TCFind(n[i][0])->price,n[i][1],TCFind(n[i][0])->price*n[i][1]);		
	}
	printf("\n�ò���������Ϊ%d\n\n�������������һ��\n\n",sum1); 
	system("pause");	 
} 
//*******************************************������***********************************************
void ClearOrder()
{
	FILE*fp;
	char ST[25]={".\\orderinfo\\"};  //���ò��������Ϣ�ļ������·�� 
	char ST1[5]={".txt"}; 
	int i;
	char t[2];
	while(1)
	{
		
		fflush(stdin);
		system("cls");
		printf("\n��������ɾ���Ķ�����¼�Ĳ�����:");
		scanf("%s",t);
		fflush(stdin);
		printf("\n\n�˲���������,�����濼��\n�����Ӧ���ֽ��в���ȷ��\n\n1.ȷ��ɾ��\t2.����ѡ�������\t3.������һ��\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: system("cls");
					fp=fopen(strcat(strcat(ST,t),ST1),"w");
					fclose(fp);
					printf("\n*****************************************\nɾ���ɹ�\n*****************************************\n1.����ɾ��\t2.������һ��");
					fflush(stdin);
					scanf("%d",&i);
					switch(i)
					{
						case 1:break;
						case 2:return;
					};break;
			case 2: break;
			case 3: return;break;
			default: printf("��������ȷ������,�Ժ��Զ�����");Sleep(2233);break;
		}
	}
}
