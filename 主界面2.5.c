#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <io.h>
#define TCItemNum 80
void System_Out();          //退出系统 
void CustomerEnter();      //用户登录 
void CustomerSystem();     //客户操作系统 
void CustomerSettlement();   //客户结算 
void OrderCustom();     //分类点菜 
void OrderAll();      //全部点擦 
void managerEnterView();   //经理登陆界面函数
void managerControlView(); //经理操作界面函数
void passwordManagement();   //修改密码函数 
void managerControlEvaluationView() ;   //管理员评价管理界面 
void userEvaluationView();   //用户评价管理 
void TCManage();//茶点菜单管理
void TableManagement();  //餐桌管理函数
void OrderManage();   //账单管理
void CheckOrder(); //账单查看 
void ClearOrder();//订单清理
void OpinionLook();//观看酒店评价 
struct TeaCake * TCFind(int id);//茶点地址查找函数 
char TableNumber[4]="0";         //餐桌号码 
int TableMan;      //用餐人数
int TeaNumber;  //茶水编号 
char str[16];//定义密码数组
char TypeName[10][10]=
{
    "焗出天地","蒸蒸日上","点点心意","包您满意",
    "粉面登场","心满意足","田园蔬菜","高档茶叶",0,0
}; //茶点类型0到9对应的名字
struct TeaCake //茶点结构体 
{
	int ID;
	char name[20];
	int price;
	int type;	     //茶点类型"焗出天地","蒸蒸日上","点点心意","包您满意","粉面登场","心满意足","田园蔬菜","高档茶叶"
	char intro[80];     //简介 
}TCList[TCItemNum];

//*******************************************主函数界面（开启界面）****************************************************
int main() 
{
	FILE*fp;
	if((fp=fopen("TCList.dat","rb"))==NULL)
	{
		printf("\n\n\t\t\t缺少必要文件,1.233秒后自动返回主菜单");
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
    fread(TypeName,sizeof(char [10]),10,fp);//读出文件TypeName.dat到数组
    fclose(fp);
    char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"};      //设置文件的格式 
	strcat(strcat(ST,TableNumber),ST1);   //用字符组合并实现用变量值来命名相对路径的txt文件
	remove(ST);
Loop_main:
	fflush(stdin);
	system("cls");
	system("color 0f");                                    //清屏    
	printf("\n\n\n\n\n\t\t\t 欢 迎 光 临 !");
	printf("\n\n\t\t\tw e l c o m e !");	
	Sleep(1000); 
	system("cls");	
	int z;
	HANDLE wordscolor = GetStdHandle(STD_OUTPUT_HANDLE);              //创建标准输出句柄 
    SetConsoleTextAttribute(wordscolor,FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_BLUE);    //设置文本前景颜色,背景颜色
    printf("\n\n*************************★★★★★★★*************************\n\n");
	SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED);
	printf("\t\t\t");
	char out[]=" 宇 工 大 酒 店  \n\n";
	for(z=0;z<strlen(out);z++ )
	{
		printf("%c",out[z]);
		Sleep(30);                                                                          //逐字出现间隔30ms。 
	}
	z=0;
    SetConsoleTextAttribute(wordscolor,FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_BLUE);
    printf("*************************★★★★★★★*************************\n");
   	SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	printf("|现在是茶点时间|\n\n");
    SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    printf("\n\t\t        1.客户界面\n	 222 \n	2   2");Sleep(70);
    SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    printf("\n\t   2 \t        2.酒店茶点管理界面\n	 22  \n	2    ");Sleep(70); 
    SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN);
    printf("\n\t22222\t        3.退出系统\n\n");Sleep(70); 
    SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("\n请输入数字进行对应操作:");
    scanf("%d",&z);                                                                     //根据输入数字选择操作                                     
    if(z!=1&&z!=2&&z!=3)
	{
		system("cls");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
		printf("\n\n\n\n请输入数字1或数字2或数字3\n\n\n");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		system("pause"); 
		goto Loop_main;                                                                   //输入错误时回到函数开头	
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
//*******************************************退出系统****************************************************
void System_Out()
{
	fflush(stdin);                                                          //清除输入缓冲区 
	system("cls");
	system("color f8");
	printf("\n\n\n\n\t\t  期 待 您(们) 的 下 一 次 光 临");
	printf("\n\n\n\t\tLooking forward to your next visit\n\n\n\n");
	Sleep(1233);
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"};      //设置文件的格式 
	strcat(strcat(ST,TableNumber),ST1);   //用字符组合并实现用变量值来命名相对路径的txt文件
	remove(ST); 
	exit(0);                                                                 //退出系统 
}
//*******************************************客户登录****************************************************
void CustomerEnter()
{  
    void CustomerSystem();  
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"};      //设置文件的格式 
	FILE*fp;
	system("cls");                         //清屏 
	system("color b0");                  //背景颜色为淡蓝色，字体为黑色 
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("请输入您(们)的餐桌号，按ENTER键继续\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	fflush(stdin);  
	scanf("%s",TableNumber); 
	fflush(stdin); 
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("请输入用餐的人数，按ENTER键继续\n\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	scanf("%d",&TableMan);
    printf("\n\t请问您需要哪种茶水？\n*********************************************\n1.茉莉花茶\t2.菊花茶\t3.白开水    |\t4.不需茶水\n*********************************************\n输入0返回上一级\n");
Loop_2:	
	scanf("%d",&TeaNumber);
	fflush(stdin);
	if(TeaNumber!=1&&TeaNumber!=2&&TeaNumber!=3&&TeaNumber!=4&&TeaNumber!=0)
	{
		printf("请输入相应的数字\n");	
		Sleep(1500);
		goto Loop_2;       //重新输入        
	}
	else if(TeaNumber==0)return;  //返回主界面函数 
	else
	{
		strcat(strcat(ST,TableNumber),ST1);//用字符组合并实现用变量值来命名相对路径的txt文件
		fp=fopen(ST,"w");fclose(fp);
		printf("\a");	                                       
		system("cls");
		CustomerSystem();   //进入客服操作系统 
		return;
	}		
}
//*******************************************客户操作系统****************************************************
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
		printf("今日推荐菜品:\n\t\t");
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
		printf("\n\n\t\t\t\t1.|  快速点菜  |\n\n\t\t\t\t2.|  分类点菜  |");
		printf("\n\n\t\t\t\t3.|  酒店评价  |\n\n\t\t\t\tw.|  退出系统  | \n\n\t\t\t\t0.* 返回主菜单*\n\n");
		SetConsoleTextAttribute(wordscolor,BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("\n===============================================================================\n");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_GREEN);
		printf("\n\n请输入对应字母进行操作:"); 
	
	Loop_1:
		printf("\n");
		n=getchar();
		fflush(stdin);
		switch(n)
		{
			case'w':System_Out();break;    //输入w退出系统 
			case'3':OpinionLook();break;     // 输入3进入评价管理系统 
			case'2':OrderCustom();break;       // 输入2进行分类点菜 
			case'1':OrderAll();break;		  // 输入1进行快速点菜 
			case'0':main();break;      //返回主菜单 
			default:printf("\n请输入限定的字符，谢谢\n");goto Loop_1;break; 
		} 
	}
}
//*******************************************客户观看评价****************************************************
void OpinionLook()
{
	system("cls");   //这是用来跳转界面的函数
    FILE *in;
    int option;
    int evaluationNum;
    int i;
    int k;
    int bool=1;
    char tableNum[100][4];//放桌号的数组
    char ch[100][100];  //存放取出的字符
    if((in=fopen("userOpinion.txt","r"))==NULL)
    {
        printf("无法打开此文件userOpinion.txt");
    }
    /**
    *  for循环：读取文件中的数据，分别放在tableNum和ch的二维数组中
    */
    for(i = 0; i < 100; i++)
    {
        fscanf(in,"%s\t%s\n",&tableNum[i],&ch[i]);
        if(ch[i][0]==0)break;
    }
    fclose(in);
    printf("                   ★********************************************★\n");
    printf("                           ||以下为以往顾客对鄙酒店的评价||\n");
    printf("                   ★********************************************★\n");
    /*
    * 将存放在 ableNum和ch的二维数组中取出
    */
    for(k = 0; k<i; k++)
    {
        printf("\n");
        printf("%d、第%s号桌评价: %s\n",k+1,tableNum[k],ch[k]);
    }
    system("pause");
}
//*******************************************顾客结算****************************************************
void CustomerSettlement()
{
	fflush(stdin);                                                          
	system("cls");
	system("color 80");
	int i,k=0,sum=0;
	int n[30][2]={
		{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}
	};  	
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"};      //设置文件的格式 
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
	printf("\n\n***************************************************\n\t谢谢您(们)的惠顾,以下是本次消费的结算:\n***************************************************");
	SetConsoleTextAttribute(wordscolor,FOREGROUND_RED|BACKGROUND_INTENSITY);
	printf("\n以下为所点茶点：\n");
	printf("ID. 茶点名字\t     单价    已点数     应付钱数\n");
	for(i=0;i<30;i++)
	{
		if(n[i][0]==0)break;
		printf("%-4d.%-15s %-4d      %-1d  \t  %d\n",TCFind(n[i][0])->ID,TCFind(n[i][0])->name,TCFind(n[i][0])->price,n[i][1],TCFind(n[i][0])->price*n[i][1]);
	}
	printf("\n消费总价为%d元",sum);	
	SetConsoleTextAttribute(wordscolor,BACKGROUND_INTENSITY);
	printf("\n\n\n4.返回上一级(继续加茶点)\n3.返回客户操作界面(重新点茶点)\n2.进入评价界面(将无法继续点菜,默认确认结算)\n1.返回主界面\t0.确认结算(自动返回操作界面)\n请输入数字操作:"); 
	scanf("%d",&i);
	switch(i)
	{
		case 2:
			fp1=fopen(strcat(strcat(ST2,TableNumber),ST1),"a+");
			for(i=0;i<30;i++)
			{
				if(n[i][0]==0){fprintf(fp1,"\n1\n");break;}
				fprintf(fp1,"%d\t%d\t%d\n",TCFind(n[i][0])->ID,n[i][1],TCFind(n[i][0])->price*n[i][1]);   //把最终的账单写入特定文件		
			}
			fclose(fp1);
			fp=fopen(ST,"w");fclose(fp);//清空文件 
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
				fprintf(fp1,"%d\t%d\t%d\n",TCFind(n[i][0])->ID,n[i][1],TCFind(n[i][0])->price*n[i][1]);   //把最终的账单写入特定文件		
			}
			fclose(fp1);
			fp=fopen(ST,"w");fclose(fp);
			CustomerSystem(); 
			break;
		default:printf("\n请输入正确的数字\n");CustomerSettlement();break;
	} 
	CustomerSystem();		
}
//*******************************************分类点菜函数****************************************************
void OrderFind(int OrderList[3],int id) //这是一个在文件中查找点菜记录的函数 
{ 
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"};      //设置文件的格式 
	FILE*fp; 
	if ((fp=fopen(	strcat(strcat(ST,TableNumber),ST1)	,"r"))==NULL) //用字符组合并实现用变量值来命名相对路径的txt文件
        	fp=fopen(ST,"w+");
	while(feof(fp)==0)//文件指针没有在末尾时，继续读取
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
void OrderCustom() //这是分类点菜的主函数 
{
	struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
	void OrderDetail(struct TeaCake *p);//这是一个茶点详情操作的函数
	void Ordered(); //这是一个管理已点茶点的函数
	void OrderSort(); //这是一个分类点菜的函数 
	struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //选项的指针数组
    char c; //用于getchar()
    int page=0;//页数
    int i,j; //作为选项的序数，控制循环次数
    int id;//作为ID索引用
    int OrderList[3];//显示出的的菜单组号变量，第一个是菜编号，第二个是已点数量 ;第三个是总价
/*下面是输出茶点预处理的部分*/
LOOP_OrderCustom:
	j=0;//j表示茶点的数目 
	for (i=0;i<TCItemNum;i++)
	{
		p=&TCList[i];
		if(p->ID==-1) continue;//ID为-1的项目跳过 
		else 
		{
			item[j]=p;
			j++; 
		}	
	}
/*下面是输出茶点列表的部分*/	
LOOP_OrderCustom1:
    system("cls");//清屏
    system("color 4f");
    printf("*******************************************************************************\n");
    printf("                       欢  迎  进  入  点  菜  界  面                          \n");
    printf("餐桌号：%s 人数：%-55d茶水：%d\n",TableNumber,TableMan,TeaNumber);
    printf("*******************************************************************************\n");
    printf("                 ID          名  称              价格       类型               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (page*9+i>=j) break;
        p=item[page*9+i];
        printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./返回/    u./上一页/    /第%d页/    n./下一页/    *./刷新/\n\n",page+1);
    printf(" a.|通过ID号查找|  s.|查看已点|  d.|查看评价|  f.|按类型查找|  w.|结算并退出|\n");
    printf("\n请输入字符进行操作：\t");
/*下面是输入字符并处理的部分*/
LOOP_OrderCustom2:
    c=getchar();
    if (c!='u'&&c!='n'&&c!='a') fflush(stdin);//除了u,n,a字符外，清除输入缓存
    if (c-48>i&&c<='9') goto LOOP_OrderCustom2;//输入的数字不在列表内
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
        printf("正在刷新！！");
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
        printf("请输入茶点的ID号：");
        scanf("%d",&id);
        fflush(stdin);
        p=TCFind(id);
    	if (p==NULL)
		{
        	printf("ID号不存在！！");
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
        printf("输入有误，请重新输入！\t");
        Sleep(1000);
        goto LOOP_OrderCustom1;
    }
    return;
}
void OrderDetail(struct TeaCake *p) //这是一个茶点详情操作的函数 
{
	void OrderEdit(struct TeaCake *p,int num); //这是一个编辑点菜数量的函数
	void OrderFind(int OrderList[3],int id); //这是一个在文件中查找点菜记录的函数
	struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
    int add;//现在要添加的份数 
    int OrderList[3]; //显示出的的菜单组号变量，第一个是菜编号，第二个是已点数量 ;第三个是总价
LOOP_OrderDetail:
	OrderFind(OrderList,p->ID);
    system("cls");//清屏
    printf("*******************************************************************************\n");
    printf("                             茶  点  详  情  界  面                            \n");
    printf("*******************************************************************************\n");
    printf("                                   ID：%-4d\n",p->ID);
    printf("        --------------------------------------------------------------         \n");
    printf("\n");
    printf("                          名  称：%-20s\n\n",p->name);
    printf("                          价  格：%-4d\n\n",p->price);
    printf("                          类  别：%-10s\n\n",TypeName[p->type]);
    printf("                          简  介：\n");
    printf("                    %-80s\n\n",p->intro);
    printf("        --------------------------------------------------------------         \n");
    printf("            0./返回/            |目前已点了%d份|            |总价%d元|\n",OrderList[1],OrderList[2]);
    printf("\n请输入要添加的份数: ");
    scanf("%d",&add);
    fflush(stdin);
    if(add==0) return; 
	else if(OrderList[1]+add<0) 
	{
		printf("输入数字不正确");
		Sleep(1000);
	}
	else OrderEdit(p,OrderList[1]+add);
	return;
}
void OrderEdit(struct TeaCake *p,int num) //这是一个添加点菜的函数
{
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径
	char ST_[20]={".\\table\\"};
	char ST1[]={".txt"};	//设置文件的格式
	char ST2[]={".txt~"};	//设置副本格式 
	int OrderList[3]; //显示出的的菜单组号变量，第一个是菜编号，第二个是已点数量 ;第三个是总价
	FILE*fp1,*fp2;
	//用字符组合并实现用变量值来命名相对路径的txt文件 
	if ((fp1=fopen(	strcat(strcat(ST,TableNumber),ST1)	,"r"))==NULL)
        	fp1=fopen(ST,"w+");
	fp2=fopen(	strcat(strcat(ST_,TableNumber),ST2)	,"w+");//创建餐桌副本*.txt~ 
	while(1)
    {	//从*.txt复制到*.txt~
        fscanf(fp1,"%d\t%d\t%d",&OrderList[0],&OrderList[1],&OrderList[2]);
        if(OrderList[0]==p->ID||feof(fp1)) break;	//找到茶点，或文件结束时，跳出
        else fprintf(fp2,"%d\t%d\t%d\n",OrderList[0],OrderList[1],OrderList[2]);
    }
	if(num!=0) fprintf(fp2,"%d\t%d\t%d\n",p->ID,num,p->price*num);//修改的数量为0时不需要写入 
    if(feof(fp1)==0)
		while(feof(fp1)==0)//文件指针没有在末尾时，继续读取
	    {	//从*.txt复制到*.txt~
	        fscanf(fp1,"%d\t%d\t%d\n",&OrderList[0],&OrderList[1],&OrderList[2]);
	        if(OrderList[0]==p->ID) continue; 
	        else fprintf(fp2,"%d\t%d\t%d\n",OrderList[0],OrderList[1],OrderList[2]);
	    }
	fclose(fp1);
	fclose(fp2); //关闭文件*.txt
	remove(ST);//删除.\*.txt
	rename(ST_,ST);
	//把.\*.txt~改成.\*.txt，完成操作 
	return;
} 
void Ordered() //这是一个管理已点茶点的函数
{
	struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
	void OrderDetail(struct TeaCake *p); //这是一个茶点详情操作的函数
	void OrderEdit(struct TeaCake *p,int num); //这是一个添加点菜的函数
	struct TeaCake *p;
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径
	char ST1[]={".txt"};	//设置文件的格式
	char c; //用于getchar()
    int page=0;//页数
    int i,j; //作为选项的序数，控制循环次数
    int id;//作为ID索引用 
    int sum;//总价格 
	int OrderList[30][3]; //显示出的的菜单组号变量，第一个是菜编号，第二个是已点数量 ;第三个是总价
	FILE *fp;
	strcat(strcat(ST,TableNumber),ST1);//用字符组合并实现用变量值来命名相对路径的txt文件
/*下面是输出茶点预处理的部分*/
LOOP_Ordered:
	if((fp=fopen(ST,"r"))==NULL)
		fp=fopen(ST,"w+");
	j=0;//j表示茶点的数目
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
    system("cls");//清屏
    system("color fc");
    printf("*******************************************************************************\n");
    printf("                       您  已  点  了  以  下  茶  点                          \n");
    printf("餐桌号：%s 人数：%-55d茶水：%d\n",TableNumber,TableMan,TeaNumber);
    printf("*******************************************************************************\n");
    printf("            ID      名  称            价格      已点数量      应付钱数         \n");
    printf("        --------------------------------------------------------------         \n");
	for(i=0;i<9;i++)
    {
        if(page*9+i>=j) break;
        p=TCFind(OrderList[page*9+i][0]);
        if(p==NULL) printf("               您没有点任何茶点！！！              \n");
        else printf("%10d.%4d  %-20s%4d        %4d        %6d\n",i+1,p->ID,p->name,p->price,OrderList[page*9+i][1],OrderList[page*9+i][2]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./返回/    u./上一页/    /第%d页/    n./下一页/    *./刷新/\n\n",page+1);
    printf("    a.|通过ID号点菜|    s.|删除已点|    |当前总价格为%d元|    w.|结算并退出|\n",sum);
    printf("\n请输入字符进行操作：\t");
/*下面是输入字符并处理的部分*/
LOOP_Ordered2:
    c=getchar();
    if (c!='u'&&c!='n'&&c!='a'&&c!='s') fflush(stdin);//除了u,n,a,s字符外，清除输入缓存
    if (c-48>i&&c<='9') goto LOOP_Ordered2;//输入的数字不在列表内
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
        printf("正在刷新！！");
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
        printf("请输入茶点的ID号：");
        scanf("%d",&id);
        fflush(stdin);
        p=TCFind(id);
    	if (p==NULL)
		{
        	printf("ID号不存在！！");
        	Sleep(1000);
    	}
        else OrderDetail(p);
        goto LOOP_Ordered;
    case 's':
    	printf("请输入要删除的编号：");
        scanf("%d",&i);
        fflush(stdin);
        p=TCFind(OrderList[page*9+i-1][0]);
        if (p==NULL)
		{
        	printf("输入有误！！");
        	Sleep(1000);
    	}
        else OrderEdit(p,0);
        goto LOOP_Ordered;
    case 'w':
    	CustomerSettlement();
        goto LOOP_Ordered1;
    default:
        printf("输入有误，请重新输入！\t");
        Sleep(1000);
        goto LOOP_Ordered1;
    }
	return;
}
void OrderSort() //这是一个分类点菜的函数 
{
	struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
    void OrderDetail(struct TeaCake *p); //这是一个茶点详情操作的函数 
    struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //选项的指针数组
    char c; //用于getchar()
    int page=0;//页数
    int i,j; //作为选项的序数，控制循环次数
    int type[11]={0};//作为type索引用,数值表示每一类型的起始下标，最后一个表示总个数，初始值为全0
/*下面是输出茶点预处理的部分*/
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
    j=0;//恢复0 
/*下面是输出茶点列表的部分*/
LOOP_OrderSort1:
    system("cls");//清屏
    system("color 4e");
    printf("*******************************************************************************\n");
    printf("                       欢  迎  进  入  点  菜  界  面                          \n");
    printf("餐桌号：%s 人数：%-55d茶水：%d\n",TableNumber,TableMan,TeaNumber);
    printf("*******************************************************************************\n");
    printf("                 ID          名  称              价格       类型               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (type[j]+page*9+i>=type[j+1]) break;
        p=item[type[j]+page*9+i];
        printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./返回/    u./上一页/    /第%d页/    n./下一页/    *./刷新/\n\n",page+1);
    printf("    a.|切换类型显示|    s.|查看已点|    d.|查看评价|    w.|结算并退出|\n");
    printf("\n请输入字符进行管理：\t"); 
/*下面是输入字符并处理的部分*/
LOOP_OrderSort2:
	c=getchar();
    if (c!='u'&&c!='n'&&c!='a') fflush(stdin);//除了u,n,a字符外，清除输入缓存
    if (c-48>i&&c<='9') goto LOOP_OrderSort2;//输入的数字不在列表内
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
        printf("正在刷新！！");
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
	    printf("请输入数字0-9进行切换：");
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
        printf("输入有误，请重新输入！\t");
        Sleep(1000);
        goto LOOP_OrderSort1;
    }
    return;
}
//*******************************************全部点菜函数****************************************************
void OrderAll()
{
	void CustomerSystem();
	char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"};      //设置文件的格式 
	FILE*fp;
	strcat(strcat(ST,TableNumber),ST1);   //用字符组合并实现用变量值来命名相对路径的txt文件 
	HANDLE wordscolor = GetStdHandle(STD_OUTPUT_HANDLE);
	int TCNumber;		//茶点编号 
	int n[30][3];                //显示出的的菜单组号变量，第一个是菜编号，第二个是已点数量 ;第三个是总价 
	int i,flag,j,k,flag1=1,x=0,sum=0;
	for(i=0;i<30;i++){n[i][0]=0;n[i][1]=0;n[i][2]=0;}
	fflush(stdin);                                                          
	system("cls");
	system("color 80");
	srand((unsigned)time(NULL));   //设置随机种子 
	for(i=0;i<30;i++)
	{
		n[i][0]=rand()%69;
		flag=1;
		while(flag==1)
		{
			for(j=0;j<i;j++)
			if(n[i][0]==n[j][0])break;
			if(j<i)n[i][0]=rand()%69;//如果有相等，重新生成另一个随机数 
			if(j==i)flag=0;  //如果没有相等，flag变成0，跳出循环 
		}
	}    //生成一组没有重复的随机数 
    j=1;
	
	while(1)
	{
Loop_6:		
		system("cls");
		SetConsoleTextAttribute(wordscolor,FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_INTENSITY);
		printf("ID. 茶点名字\t     单价   已点数\tID. 茶点名字\t     单价   已点数\t输入0返回上一级 输入1进行结算\n"); 
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
		printf("\n目前总价格是:%d",sum);    //总价格运算 	
		printf("\n\n您所要点的茶点是(输入编号):");
		scanf("%d",&TCNumber);
		fflush(stdin);
		flag=1;
		for(k=0;k<30;k++)
		{
			if(TCList[n[k][0]].ID==(TCNumber)||TCNumber==1||TCNumber==0)flag-=1;	       //当输入不存在的茶点ID时，flag值不变 
			//if(TCList[n[k][0]].ID==1||TCList[n[k][0]].ID==0){flag-=1;break;}//输入0或1时进行flag减一,并且跳出循环 
		}
		if(flag==1)          //flag值不变，进入报错界面 
		{                                                        
			system("cls");	
			SetConsoleTextAttribute(wordscolor, FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|BACKGROUND_INTENSITY);
			printf("\n\n\n\n\t\t\\(*A*#)/请输入所显示的茶点ID，2.233秒后自动回到点菜界面\\(#*A*)/");
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
			if((TCNumber-101)==n[j][0])break;  //检索所选ID的对应价格数组编号 
		}  
		printf("\n您所要点数量是:");
		scanf("%d",&x);
		n[j][1]=x;
		n[j][2]=TCList[n[j][0]].price*n[j][1];		
		for(i=0,sum=0;i<30;i++)
		{
			sum+=n[i][2];
		}

	}
}
//*******************************************经理登陆界面***********************************************
void managerEnterView()   //经理登陆界面函数
{
    system("cls");
	printf("                      ★******************************★\n");
	printf("                          ☆ 现在进入经理管理模式 ☆\n");
	printf("                      ★******************************★\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("请输入管理员密码\n");
	printf("      ↓↓\n");

	char firstPassword[16]; //输入密码时用到的变量
    FILE *in;          //定义只想file类型文件的指针变量
    int count  = 0;
    int i;
    char encryptedPassword[16]={"\0"};

    if((in=fopen("password.dat","r"))==NULL)
    {
        printf("找不到该文件：password.dat\n");
    }
    fgets(encryptedPassword,16,in);   //将文件中的字符串读出，放入encryptedPassword
    fclose(in);
    /*
    *  解密密码，放入全局变量
    */
    count=strlen(encryptedPassword);
    for (i=0;i<count;i++)
    {
        str[i]=encryptedPassword[i]-i-5;
    }
    str[i]='\0';

    /**
    *  开始输入密码
    */
	printf("密码：");
	scanf("%s",firstPassword);

	if(strcmp(str,firstPassword)==0)  //判断密码是正确
    {
        /**
        *  缓慢输出  “经理，你好！”
        */
        system("cls");
        printf("\n\n\n\n");
		char message_hello[] = "\t\t\t\t经理,你好!";
		unsigned int i;
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
		Sleep(500);
		managerControlView();    //跳转到经理管理菜单页面
    }
    else
    {   //用do-while判断重新输入的密码，直到密码正确
        do
        {
            printf("密码错误，请重新输入：");
            scanf("%s",firstPassword);
        }while(strcmp(str,firstPassword)!=0);

        //缓慢输出  “经理，你好！”
        char message_hello[] = "\t\t\t\t经理,你好!";
		unsigned int i;
		system("cls");
		printf("\n\n");	
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
		Sleep(500);
		managerControlView();   //跳转到经理管理菜单页面
    }
}

//*******************************************经理管理菜单界面***********************************************

void managerControlView()
{
    char serialNumber;  //代表功能列表的序列号
	while(1)
	{
	    system("cls");//这是用来跳转界面的函数
	    printf("\n\n");
	    printf("                      ★******************************★\n");
	    printf("                                 ||功能列表||\n");
	    printf("                      ★******************************★\n");
	    printf("                                  <<<<  >>>>\n");
	    printf("                                 1.  评价管理\n");
	    printf("                                 2.  餐桌管理\n");
	    printf("                                 3.  订单管理\n");
	    printf("                                 4.  茶点管理\n");
	    printf("                                 5.  密码管理\n");
	    printf("                                 0.  返回\n");
	    printf("                                 w.  退出系统\n");
	    printf("\n请选择: ");
	    fflush(stdin);    //清除缓存
	    serialNumber = getchar();
	    fflush(stdin);   //输入功能列表序列号
	    /**
	    * 判断序列号，跳转至对应函数
	    */
	    if(serialNumber=='0'||serialNumber=='1'||serialNumber=='2'||serialNumber=='3'||serialNumber=='4'||serialNumber=='5'||serialNumber=='6'||serialNumber=='w')
	    {
	        switch( serialNumber )
	        {
	            case '1':
	                system("cls");   //这是用来跳转界面的函数
	                Sleep(500);
	                managerControlEvaluationView();  //评价管理函数
	                break;
	            case '2':
	                system("cls");   //这是用来跳转界面的函数
	                TableManagement();  //餐桌管理函数
	                break;
	            case '3':
	                system("cls");   //这是用来跳转界面的函数
	                OrderManage();  //订单管理函数
	                break;
	            case '4':
	                system("cls");   //这是用来跳转界面的函数
	                TCManage();   //茶点管理函数
	                break;
	            case '5':
	                system("cls");   //这是用来跳转界面的函数
	                passwordManagement();    //密码管理函数
	                break;
	            case '0':
	                system("cls");   //这是用来跳转界面的函数
	                return;   //返回上一层（主菜单）
	                break;
	            case 'w':
	                system("cls");   //这是用来跳转界面的函数
	                exit(0);
	                break;
	        }
	    }
	    else
	    {   //用do-while判断重新输入的序列号，直到正确
	        do
	        {
	            printf("\t\t\t+-+-+-+-+ 序列号有误 +-+-+-+-+\t\t\t\n");
	            printf("\n请输入0～6或w：");
	            fflush(stdin);
	            scanf("%c",&serialNumber);
	        }while(serialNumber!='0'&&serialNumber!='1'&&serialNumber!='2'&&serialNumber!='3'&&serialNumber!='4'&&serialNumber!='5'&&serialNumber!='6'&&serialNumber!='w');
	        switch( serialNumber )
	        {
	            case '1':
	                system("cls");   //这是用来跳转界面的函数
	                managerControlEvaluationView(); //评价管理函数
	                break;
	            case '2':
	                //tableView();    //餐桌管理函数
	                break;
	            case '3':
	                OrderManage();  //订单管理函数
	                break;
	            case '4':
	                TCManage();   //茶点管理函数
	                break;
	            case '5':
	                passwordManagement();    //密码管理函数
	                break;
	            case '0':
	                return;   //返回上一层（主菜单）
	                break;
	            case 'w':
	                exit(0);   //退出系统函数
	                break;
	        }
	    } 	
	}
}
//*******************************************修改密码函数**********************************************
void passwordManagement()   //修改密码函数
{
    system("cls");   //这是用来跳转界面的函数
    FILE *out;
    int count = 0;
    int i;
    char encryptedPassword[16]={"\0"};
    char secondPassword[16]; //修改密码时用到的变量
    printf("                   ★******************************★\n");
	printf("                           ☆ 修改密码页面 ☆\n");
	printf("                   ★******************************★\n");
	printf("\n\n");
	if((out = fopen("password.dat","w"))==NULL)
    {
        printf("找不到该文件：password.dat\n");
    }
	printf("请输入原密码：");
	fflush(stdin);    //清除缓存
    scanf("%s",secondPassword);
    if(strcmp(str,secondPassword)==0)
    {
        printf("请输入新密码：");
        fflush(stdin);    //清除缓存
        scanf("%s",secondPassword);
        strcpy(str,secondPassword);  //将修改后的密码闯到全局变量中
        /**
        *将密码加密后存入文件中
        */
        count=strlen(str);
        for (i=0;i<count;i++)
        {
            encryptedPassword[i]=str[i]+i+5;
        }
        encryptedPassword[i]='\0';
        fputs(encryptedPassword,out);
        fclose(out);
        char message_hello[] = "\t\t\t\t密码修改成功!";
		unsigned int i;
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
        Sleep(2000);
        managerControlView();//返回经理管理页面
    }
    else
    {
        do
        {
            printf("输入原密码错误，请重新输入：");
            fflush(stdin);    //清除缓存
            scanf("%s",secondPassword);
        }
        while(strcmp(str,secondPassword)!=0);
        printf("原密码输入正确\n");
        printf("请输入新密码：");
        fflush(stdin);    //清除缓存
        scanf("%s",secondPassword);
        strcpy(str,secondPassword);  //将修改后的密码实时更新到全局变量
         /**
        *将密码加密后存入文件中
        */
        count=strlen(str);
        for (i=0;i<count;i++)
        {
            encryptedPassword[i]=str[i]+i+5;
        }
        encryptedPassword[i]='\0';
        fputs(encryptedPassword,out);
        fclose(out);

        char message_hello[] = "\t\t\t\t密码修改成功!";
		unsigned int i;
		for(i = 0;i < strlen(message_hello); i++)
		{
			printf("%c",message_hello[i]);
			Sleep(100);
		}
        Sleep(2000);
        managerControlView();//返回经理管理页面
    }
}
//*******************************************管理员评价管理函数****************************************************
void managerControlEvaluationView()
{
	system("cls");   //这是用来跳转界面的函数
	printf("                      ★******************************★\n");
    printf("                              ||查看用户评价页面||\n");
    printf("                      ★******************************★\n");
    FILE *in;
    int option;
    int evaluationNum;
    int i,j;
    int k;
    char tableNum[100][4];//放桌号的数组
    char ch[100][100];  //存放取出的字符
loop1:
    if((in=fopen("userOpinion.txt","r"))==NULL)
    {
        printf("无法打开此文件userOpinion.txt");
    }
    for(i=0;i<100;i++)
    {
        tableNum[i][0]='\0';
        ch[i][0]='\0';
    }

    /**
    *  for循环：读取文件中的数据，分别放在tableNum和ch的二维数组中
    */
    for(i = 0; i < 100; i++)
    {
        fscanf(in,"%s\t%s\n",&tableNum[i],&ch[i]);
        if(ch[i][0]==0)break;
    }
    fclose(in);
    /*
    * 将存放在 ableNum和ch的二维数组中取出
    */
    for(k = 0; k<i; k++)
    {
        printf("\n");
        printf("      %d、第%s号桌评价: %s\n",k+1,tableNum[k],ch[k]);
    }
    printf("\n        <<*******以上评价若有恶意或不符合实际的评价，可进行删除选择*******>>\n\n");
    printf("                          <<<< 1.  返回上一层   >>>>\n");
    printf("                          <<<< 2.  删除恶意评价 >>>>\n");
    printf("请选择要进行的操作：");
    scanf("%d",&option);
    fflush(stdin);    //清除缓存
    switch( option )
    {
        case 1:
            return;
            break;
        case 2:
        {
            printf("请输入你要删除的评论编号：");
            scanf("%d",&evaluationNum);
            fflush(stdin);    //清除缓存

            FILE *out;
            out = fopen("userOpinion.txt","w");
            /**
            *  for()循环中将删除后剩余的数据存入文件中
            */
            for(k = 0; k <6; k++)
            {
                if(k==evaluationNum-1)continue;
                fprintf(out,"%s\t%s\n",tableNum[k],ch[k]);
            }
            fclose(out);

            char message_hello[] = "\t\t\t\t已删除!\n";

            for(k = 0;k < strlen(message_hello); k++)
            {
                printf("%c",message_hello[k]);
                Sleep(100);
            }
            Sleep(500);
        }break;
        system("cls");  //清除页面
    }
    system("cls");  //清除页面
    printf("                      ★******************************★\n");
    printf("                              ||用户评价页面||\n");
    printf("                      ★******************************★\n");
    printf("                                  <<<<  >>>>\n");
    printf("                              1.  返回上一层\n");
    printf("                              2.  删除恶意评价\n");
    printf("                                  <<<<  >>>>\n");
    goto loop1;
}
//*******************************************用户评价函数***********************************************
void userEvaluationView()
{
    void CustomerSystem();    //声明函数
    system("cls");
    fflush(stdin);
	int i;
    char Opinion[100];  //用来暂存用户的评价
    FILE *out;
    printf("                     ★******************************★\n");
	printf("                             ☆ 用户评价界面 ☆\n");
	printf("                     ★******************************★\n");
	printf("\n");
	printf("\n");
	printf("请输入您对本酒店的评价(完成后自动返回操作界面)\n");
	printf("      ↓↓\n");
	scanf("%s",Opinion);     //用户输入评价
	fflush(stdin);
    out = fopen("userOpinion.txt","a");
    fprintf(out,"%s\t%s\n",TableNumber,Opinion);
    fclose(out);
    printf("\n\n    ★******感谢您留下宝贵的意见，本酒店会根据您的意见不断完善自我******★\n");
    Sleep(1233); 
    CustomerSystem();   //返回客户操作系统页面
}
//*******************************************茶点菜单管理***********************************************
struct TeaCake * TCFind(int id)//这是一个通过ID号查找茶点地址的函数
{
    struct TeaCake *p;
    int i;
    for (i=0;i<TCItemNum;i++)
        if (TCList[i].ID==id) break;
    if (i==TCItemNum) p=NULL; //找不到则返回空地址
    else p=&TCList[i];
    return(p);
}
void TCManage() //这是茶点管理模块的主函数 
{
    struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
    void TCEdit(struct TeaCake *p);//这是一个编辑茶点信息的函数
    void TCAdd(int id); //这是一个添加茶点的函数
    void TCDelete(int id); //这是一个删除茶点的函数
    void TCSave(struct TeaCake *item[TCItemNum]); //这是一个保存茶点信息的函数
    void TCImport();  //从文本导入菜单
    void TCExport();  //导出菜单到文本
    void TCSort(); //这是一个分类管理界面函数 
    struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //选项的指针数组
    char c; //用于getchar()
    int page=0;//页数
    int i,j; //作为选项的序数，控制循环次数
    int id;//作为ID索引用
/*下面是输出茶点预处理的部分*/
LOOP_TC:
    id=101; //作为ID索引用,初始值为101
    j=TCItemNum-1;
    for (i=TCItemNum-1;i>=0;i--)//倒序
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
/*下面是输出茶点列表的部分*/
LOOP_TC1:
    system("cls");//清屏
    printf("*******************************************************************************\n");
    printf("                             茶  点  管  理  界  面                            \n");
    printf("*******************************************************************************\n");
    printf("                 ID          名  称              价格       类型               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (page*9+i>=TCItemNum) break;
        p=item[page*9+i];
        if (p->ID==-1) //ID为-1的项目提示已删除
            printf("%10d.\t已删除\t%-20s\t%4d\t%10s\n",i+1,p->name,p->price,TypeName[p->type]);
        else
            printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./返回/    u./上一页/    /第%d页/    n./下一页/    *./刷新/\n\n",page+1);
    printf(" a.|添加茶点|  s.|删除茶点|  d.|一键导入茶点|  f.|按类型管理|  w.|存盘并退出|\n");
    printf("\n请输入字符进行管理：\t");
/*下面是输入字符并处理的部分*/
LOOP_TC2:
    c=getchar();
    if (c!='u'&&c!='n') fflush(stdin);//除了u,n字符外，清除输入缓存
    if (c-48>i&&c<='9') goto LOOP_TC2;//输入的数字不在列表内
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
        printf("正在刷新！！");
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
        printf("请输入要添加的ID号：");
        scanf("%d",&id);
        fflush(stdin);
        TCAdd(id);
        goto LOOP_TC1;
    case 's':
        printf("请输入要删除的ID号：");
        scanf("%d",&id);
        fflush(stdin);
        TCDelete(id);
        goto LOOP_TC1;
    case 'd':
        printf("1.从文本导入菜单 or 2.导出菜单到文本："); 
        scanf("%d",&i);fflush(stdin);
        if (i==1)
            TCImport();
        else if (i==2)
            TCExport();
        else printf("请重新输入数字："); 
        goto LOOP_TC;
    case 'f':
    	TCSort();
		goto LOOP_TC1;
    case 'w':
        TCSave(item);
        return;
    default:
        printf("输入有误，请重新输入！\t");
        Sleep(1000);
        goto LOOP_TC1;
    }
    return;
}
void TCEdit(struct TeaCake *p) //这是一个编辑茶点信息的函数
{
    void TCAdd(int id); //这是一个添加茶点的函数
    void TCDelete(int id); //这是一个删除茶点的函数
    struct TeaCake temp;//存放临时数据用
    char c;//用于getchar()
    int i; //用于for循环
    int id;//作为ID索引用
LOOP_TCEdit:
    system("cls");//清屏
    printf("*******************************************************************************\n");
    printf("                             茶  点  编  辑  界  面                            \n");
    printf("*******************************************************************************\n");
    if (p->ID==-1)
        printf("                                   已 删 除\n");
    else
        printf("                                   ID：%-4d\n",p->ID);
    printf("        --------------------------------------------------------------         \n");
    printf("\n");
    printf("                      1.  名  称：%-20s\n\n",p->name);
    printf("                      2.  价  格：%-4d\n\n",p->price);
    printf("                      3.  类  别：%-10s\n\n",TypeName[p->type]);
    printf("                      4.  简  介：\n");
    printf("                    %-80s\n\n",p->intro);
    printf("        --------------------------------------------------------------         \n");
    if (p->ID==-1)
        printf("            0./返回/            s.|恢复茶点|\n");
    else
        printf("            0./返回/            s.|删除茶点|\n");
    printf("\n请选择相应的字符进行操作: ");

    c=getchar();
    fflush(stdin); //清除缓存
    switch (c)
    {
    case '0':
        return;
    case '1':
        printf("原名称：%-20s\n",p->name);
        printf("新名称：");
        scanf("%20s",&temp.name); //先赋值给临时变量
        fflush(stdin);
        printf("1.确认 or 0.取消：");
        c=getchar();
        fflush(stdin);
        if (c=='1') strcpy(p->name,temp.name); //确认后再真正赋值
        goto LOOP_TCEdit;
    case '2':
        printf("原价格：%-4d\n",p->price);
        printf("新价格：");
        scanf("%d",&temp.price);
        fflush(stdin);
        printf("1.确认 or 0.取消：");
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
        printf("原类型：%-4d\n",p->type);
        printf("新类型：");
        scanf("%d",&temp.type);
        fflush(stdin);
        printf("1.确认 or 0.取消：");
        c=getchar();
        fflush(stdin);
        if (c=='1') p->type=temp.type;
        fflush(stdin);
        goto LOOP_TCEdit;
    case '4':
        printf("原简介：%-80s\n",p->intro);
        printf("新简介：");
        scanf("%80s",&temp.intro);
        fflush(stdin);
        printf("1.确认 or 0.取消：");
        c=getchar();
        fflush(stdin);
        if (c=='1') strcpy(p->intro,temp.intro);
        goto LOOP_TCEdit;
    case 's':
        if (p->ID==-1)
        {
            printf("请输入原来的ID号：");
            scanf("%d",&temp.ID);
            fflush(stdin);
            TCAdd(temp.ID);
        }
        else
            TCDelete(p->ID);
        goto LOOP_TCEdit;
    case '*':
        printf("正在刷新！！");
        goto LOOP_TCEdit;
    default:
        printf("输入有误，请重新输入！\t");
        goto LOOP_TCEdit;
    }
    return;
}
void  TCAdd(int id) //这是一个添加茶点的函数
{
    struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
    void TCEdit(struct TeaCake *p);//这是一个编辑茶点信息的函数
    struct TeaCake *p;
    struct TeaCake temp;//存放临时数据用
    char c;//用于getchar()
    int i;
    FILE *fp;
    p=TCFind(id);
    if (p!=NULL)
        printf("ID号重复！！");
    else
    {
        system("cls");
        if ((fp=fopen("TCRecycleBin.txt","r"))==NULL) //打开回收站TCRecycleBin.txt
            fp=fopen("TCRecycleBin.txt","w+");
        p=TCFind(-1); //寻找一个空闲的位置
        while (temp.ID!=id&&feof(fp)==0)//当ID不相等，且文件指针没有在末尾时，继续读取
        	fscanf(fp,"%d\t%s\t%d\t%d\t%s",&temp.ID,&temp.name,&temp.price,&temp.type,&temp.intro);//读取回收站TCRecycleBin.txt
        printf("*******************************************************************************\n");
        printf("                             茶  点  生  成  界  面                            \n");
        printf("*******************************************************************************\n");
        if (feof(fp))//如果文件指针在末尾,表示需要手动输入一个
        {
            temp.ID=id;
            printf("\nID：%d\n",temp.ID);
            printf("\n请输入名称：");
            scanf("%20s",&temp.name);
            printf("\n请输入价格：");
            scanf("%d",&temp.price);
            for (i=0;i<5;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            for (i=5;i<10;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            printf("\n请输入类型：");
            scanf("%d",&temp.type);
            printf("\n请输入简介：");
            scanf("%80s",&temp.intro);
            fflush(stdin);
            printf("1.确认创建 or 0.取消：");
        }
        else
        {
            printf("\nID：%d\n",temp.ID);
            printf("\n名称：%-20s\n",temp.name);
            printf("\n价格：%-4d\n",temp.price);
            for (i=0;i<5;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            for (i=5;i<10;i++)
                printf("%d./%s/  ",i,TypeName[i]);
            putchar('\n');
            printf("\n类型：%-4d\n",temp.type);
            printf("\n简介：%-80s\n",temp.intro);
            printf("1.确认恢复 or 0.取消：");
        }
        c=getchar();
        fflush(stdin);
        if (c=='1')
        {
            p->ID=temp.ID;//确认后正式写入
            strcpy(p->name,temp.name);
            p->price=temp.price;
            p->type=temp.type;
            strcpy(p->intro,temp.intro);
            TCEdit(p);
        }
        fclose(fp); //关闭文件TCRecycleBin.txt
    }
    return;
}
void TCDelete(int id) //这是一个删除茶点的函数
{
    struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
    struct TeaCake *p;
    char c;//用于getchar()
    FILE *fp;
    p=TCFind(id);
    if (p==NULL||id==-1)
        printf("找不到ID号！！");
    else
    {
        printf("1.确认 or 0.取消：");
        c=getchar();
        fflush(stdin);
        if (c=='1')
        {
            if ((fp=fopen("TCRecycleBin.txt","a+"))==NULL) //打开回收站TCRecycleBin.txt
                fp=fopen("TCRecycleBin.txt","w+");
            fprintf(fp,"%d\t%s\t%d\t%d\t%s\n",p->ID,p->name,p->price,p->type,p->intro);//放入回收站TCRecycleBin.txt
            fclose(fp);
            p->ID=-1;
            printf("成功删除%d号茶点！！",id);
        }
    }
    Sleep(1000);
    return;
}
void TCImport()  //从文本导入菜单
{
    FILE *fp1,*fp2;  //
    int i;
    char FileIn[20]; //要读取的文本文件名

    printf("请输入读取的文本文件名：\n");
    scanf("%s",FileIn);
    if ((fp1=fopen(FileIn,"r"))==NULL) //打开要读取的文本文件
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (i=0;i<TCItemNum;i++)//读出文件内的内容到数组TCList[TCItemNum]
    {
        if (feof(fp1)) //如果文件位置在结尾
            for (;i<TCItemNum;i++)
                TCList[i].ID=-1; //余下全部写入-1，以便管理
        else
            fscanf(fp1,"%d\t%s\t%d\t%d\t%s\n",
                   &TCList[i].ID,&TCList[i].name,&TCList[i].price,&TCList[i].type,&TCList[i].intro);
    }
    fclose(fp1);

    if ((fp2=fopen("TCList.dat","wb+"))==NULL) //创建文件TCList.dat
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fwrite(TCList,sizeof(struct TeaCake),TCItemNum,fp2);//写入文件TCList.dat
    fclose(fp2);//关闭文件TCList.dat
    printf("已生成二进制文件TCList.dat\n");
    return;
}
void TCExport()  //导出菜单到文本
{
    FILE *fp1,*fp2;
    int i;
    char FileOut[20]; //导出的文本文件名文件名

    printf("请输入导出的文本文件名：\n");
    scanf("%s",FileOut);
    if ((fp1=fopen("TCList.dat","rb"))==NULL) //打开文件TCList.dat
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fread(TCList,sizeof(struct TeaCake),TCItemNum,fp1);//读出TCList.dat文件内的内容到数组TCList[80]
    fclose(fp1);

    if ((fp2=fopen(FileOut,"w+"))==NULL)   //创建一个文本文件
    {
        printf("cannot open this file\n");
        exit(0);
    }
    for (i=0;i<TCItemNum;i++) //写入文本文件
    {
        if (TCList[i].ID==-1) continue; //遇到结束标识-1后，跳过这一行
        fprintf(fp2,"%d\t%s\t%d\t%d\t%s\n",
                TCList[i].ID,TCList[i].name,TCList[i].price,TCList[i].type,TCList[i].intro);
    }
    fclose(fp2);
    printf("已生成文本文件%s\n",FileOut);
    return;
}
void TCSort()//这是一个分类管理界面函数 
{
    struct TeaCake * TCFind(int id);//这是一个通过ID号查找茶点地址的函数
    void TCEdit(struct TeaCake *p);//这是一个编辑茶点信息的函数
    void TypeNameEdit(); //这是一个编辑类型名的函数
    void TypeNameSave();//这是一个保存类型名信息的函数
    struct TeaCake *p;
    struct TeaCake *item[TCItemNum]; //选项的指针数组
    char c; //用于getchar()
    int page=0;//页数
    int i,j; //作为选项的序数，控制循环次数
    int type[11]={0};//作为type索引用,数值表示每一类型的起始下标，最后一个表示总个数，初始值为全0
/*下面是输出茶点预处理的部分*/
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
    j=0;//恢复0 
/*下面是输出茶点列表的部分*/
LOOP_TCSort1:
    system("cls");//清屏
    printf("*******************************************************************************\n");
    printf("                             茶  点  分  类  管  理                            \n");
    printf("*******************************************************************************\n");
    printf("                 ID          名  称              价格       类型               \n");
    printf("        --------------------------------------------------------------         \n");
    for (i=0;i<9;i++)
    {
        if (type[j]+page*9+i>=type[j+1]) break;
        p=item[type[j]+page*9+i];
        if (p->ID==-1) //ID为-1的项目提示已删除
            printf("%10d.\t已删除\t%-20s\t%4d\t%10s\n",i+1,p->name,p->price,TypeName[p->type]);
        else
            printf("%10d.\t%4d\t%-20s\t%4d\t%10s\n",i+1,p->ID,p->name,p->price,TypeName[p->type]);
    }
    printf("        --------------------------------------------------------------         \n");
    printf("         0./返回/    u./上一页/    /第%d页/    n./下一页/    *./刷新/\n\n",page+1);
    printf("        a.|切换类型显示|        f.|修改类型名|        w.|存盘并退出|\n");
    printf("\n请输入字符进行管理：\t"); 
/*下面是输入字符并处理的部分*/
LOOP_TCSort2:
	c=getchar();
    if (c!='u'&&c!='n') fflush(stdin);//除了u,n字符外，清除输入缓存
    if (c-48>i&&c<='9') goto LOOP_TCSort2;//输入的数字不在列表内
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
        printf("正在刷新！！");
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
	    printf("请输入数字0-9进行切换：");
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
        printf("输入有误，请重新输入！\t");
        Sleep(1000);
        goto LOOP_TCSort1;
    }
    return;
}
void TCSave(struct TeaCake *item[TCItemNum])//这是一个保存茶点信息的函数
{
	struct TeaCake temp;//存放临时数据用
	char c;
    int i;
    FILE *fp,*fp1,*fp2;
    printf("存盘后茶点将会长期保存，是否存盘？\n");
    printf("1.确认 or 0.取消：");
    c=getchar();
    fflush(stdin);
    if (c=='1')
    {
        printf("正在将茶点信息写入文件中。。。\n");
        if ((fp=fopen("TCList.dat","wb"))==NULL)
            printf("cannot open TCList.dat\n");
        for (i=0;i<TCItemNum;i++)
        {
            fwrite(item[i],sizeof(struct TeaCake),1,fp);//按照item排好的顺序逐行写入文件TCList.dat
        }
        fclose(fp);
        
        if ((fp1=fopen("TCRecycleBin.txt","r"))==NULL)
        	fp1=fopen("TCRecycleBin.txt","w+");
       	fp2=fopen("TCRecycleBin.txt~","w+");//创建回收站副本TCRecycleBin.txt~
        while (feof(fp1)==0)//文件指针没有在末尾时，继续读取
        {
            //从TCRecycleBin.txt复制到TCRecycleBin.txt~
            fscanf(fp1,"%d\t%s\t%d\t%d\t%s\n",&temp.ID,&temp.name,&temp.price,&temp.type,&temp.intro);//放入回收站TCRecycleBin.txt
            if(TCFind(temp.ID)!=NULL) continue;
            else fprintf(fp2,"%d\t%s\t%d\t%d\t%s\n",temp.ID,temp.name,temp.price,temp.type,temp.intro);
        }
        fclose(fp1);
        fclose(fp2); //关闭文件TCRecycleBin.txt
        remove("TCRecycleBin.txt");
        rename("TCRecycleBin.txt~","TCRecycleBin.txt");//改文件名，完成操作       	
    }
    Sleep(1000);
    return;
}
void TypeNameEdit() //这是一个编辑类型名的函数
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
    printf("请输入数字0-9进行修改：");
    scanf("%d",&i);
    fflush(stdin);
    printf("原名称：%-10s\n",TypeName[i]);
    printf("新名称：");
    scanf("%10s",temp); //先赋值给临时变量
    fflush(stdin);
    printf("1.确认 or 0.取消：");
    c=getchar();
    fflush(stdin);
    if (c=='1') strcpy(TypeName[i],temp); //确认后再真正赋值
    Sleep(1000);
    return;
}
void TypeNameSave()//这是一个保存类型名信息的函数
{
	char c;
    int i;
    FILE *fp;
    printf("存盘后类型名将会长期保存，是否存盘？\n");
    printf("1.确认 or 0.取消：");
    c=getchar();
    fflush(stdin);
    if (c=='1')
    {
        printf("正在将类型名信息写入文件中。。。\n");
        if ((fp=fopen("TypeName.dat","wb"))==NULL)
            printf("cannot open TCList.dat\n");
		fwrite(TypeName,sizeof(char [10]),10,fp);//一次性写入文件TypeName.dat
        fclose(fp);
    }
    Sleep(1000);
    return;
}
//*****************************************餐桌管理函数*********************************************
void TableManagement()  //餐桌管理函数
{
    struct TeaCake *TCFind(int id);
    struct TeaCake *p;
    printf("\n");
    char tableMessage[100][7];     //存放table文件夹下的文件名
    int i,k,j,id,num,price;
    FILE *fp;
    int attendances;   //上座率
    struct _finddata_t fa;
	long fHandle;
loop_TableManager:
    i=0;k=0;j=0;
    system("cls");
    printf("                      ★******************************★\n");
    printf("                               ||满桌情况查看||\n");
    printf("                      ★******************************★\n");
	if( (fHandle=_findfirst( ".\\table\\*.txt", &fa ))==-1L ) //这里可以改成需要的目录
	{
		printf("\n\n");
		printf("                                当前没有任何人用餐！！\n");
		printf("\n按0退出，按回车键刷新:");
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
            strcpy(tableMessage[i],fa.name);     //获取文件名
            for(k=0;k<7;k++)
            {
                if(tableMessage[i][k]=='.')
                {
                    while(k<7)
                    {
                        tableMessage[i][k]='\0';     //把.txt去掉，只剩餐桌号
                        k++;
                    }break;
                }
            }
            i++;
        }while( _findnext(fHandle,&fa)==0 );
	_findclose( fHandle );

	for(k=0;k<i;k++)
    {
        int sum=0;  //共消费金额
        char ST[20]={".\\table\\"};  //设置餐桌点菜信息文件的相对路径
        char ST1[5]={".txt"};      //设置文件的格式
        printf("\t%s号桌:\n",tableMessage[k]);

        if((fp=fopen(strcat(strcat(ST,tableMessage[k]),ST1),"r"))==NULL)
        {
            printf("文件不存放在");
        }
        printf("\t       已点茶点:  ");
        while(feof(fp)==0)
        {
            fscanf(fp,"%d\t%d\t%d",&id,&num,&price);
            if(feof(fp))break;
            p = TCFind(id);
            if(p==NULL)
            {
                break;
            }
            printf("%s\t份数:%d\t消费:%d\n",p->name,num,price);
            sum+=price;
            printf("\t                  ");
        }
        printf("\n");
        printf("\t                          \t\t一共消费%d\n",sum);
        fclose(fp);
        printf("\n");
    }
    attendances = (int)(((double)i/100)*100);
    printf("\n\t现在上座率为:%d.0%%\n",attendances);
    printf("\n按0退出，按回车键刷新:");
    if(getchar()!='0')
    {
        fflush(stdin);
        goto loop_TableManager;
    }
    fflush(stdin);

    return;
}
//*******************************************订单信息管理***********************************************
void OrderManage()
{
	while(1)
	{
		int i;
		fflush(stdin);
		system("cls");
		printf("\n\t\t1.查询以往账单\t2.清除账单记录\t3.返回上一级\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: CheckOrder();break;
			case 2: ClearOrder();break;
			case 3: return;break;
			default: printf("\n请重新输入正确的数字");Sleep(1233);break;
		}
	}
}
//*******************************************订单查看***********************************************
void CheckOrder()
{
  	
	char t[2];
	FILE*fp;
	char ST[25]={".\\orderinfo\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"}; 
	int n[100][3],i,k=0,sum=0,sum1=0;
	for(i=0;i<100;i++){n[i][0]=0;n[i][1]=0;n[i][2]=0;}
	system("cls");
	printf("\n\n\t请输入您想查看的餐桌的订单：");
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
	printf("ID. 茶点名字\t     单价    已点数     应付钱数\n");
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
			printf("\t此次的消费总额为%d",sum);
			sum=0;
			printf("\n----------------------------------------------------------------------------\n");
			continue;			
		}
		if(n[i][0]==0)break;
		printf("%-4d.%-15s %-4d      %-1d  \t  %d\n",TCFind(n[i][0])->ID,TCFind(n[i][0])->name,TCFind(n[i][0])->price,n[i][1],TCFind(n[i][0])->price*n[i][1]);		
	}
	printf("\n该餐桌总消费为%d\n\n按任意键返回上一级\n\n",sum1); 
	system("pause");	 
} 
//*******************************************清理订单***********************************************
void ClearOrder()
{
	FILE*fp;
	char ST[25]={".\\orderinfo\\"};  //设置餐桌点菜信息文件的相对路径 
	char ST1[5]={".txt"}; 
	int i;
	char t[2];
	while(1)
	{
		
		fflush(stdin);
		system("cls");
		printf("\n请输入想删除的订单记录的餐桌号:");
		scanf("%s",t);
		fflush(stdin);
		printf("\n\n此操作不可逆,请认真考虑\n输入对应数字进行操作确认\n\n1.确认删除\t2.重新选择餐桌号\t3.返回上一级\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: system("cls");
					fp=fopen(strcat(strcat(ST,t),ST1),"w");
					fclose(fp);
					printf("\n*****************************************\n删除成功\n*****************************************\n1.继续删除\t2.返回上一级");
					fflush(stdin);
					scanf("%d",&i);
					switch(i)
					{
						case 1:break;
						case 2:return;
					};break;
			case 2: break;
			case 3: return;break;
			default: printf("请输入正确的数字,稍后将自动返回");Sleep(2233);break;
		}
	}
}
