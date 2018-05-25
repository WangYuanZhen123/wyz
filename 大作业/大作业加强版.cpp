#include<iostream>
#include<string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct book			//书的信息结构体 
{
	char bookname[30];
	char writer[30];
	char isbn[30];
	char place[30];				//放置的位置 
	char number[30];			//书籍编号 
	char from[30];				//出版社 
	char condition[15] ;		//出借情况 
};
class Book			//书的类 
{
	public:
		void Addbook();			//添加书目函数 
		void Deletebook();		//删除书目函数 
		void Adjustbook();		//修改书目信息函数 
		void Searchbook();		//查询书目函数 
	private:
		book book1;
};


struct e_book				//电子书的结构体 
{
	char bookname[40];
	char writer[30];
	char number[30];		//电子书编号 
	char place[40];			//存放路径 
};
class E_book			//电子书的类 
{
	public:
		void Adde_book();		//添加电子书函数 
		void Deletee_book();		//删除电子书函数 
		void Adjuste_book();		//修改电子书信息函数 
		void reade_book();			//在线阅读函数 
		void searche_book();		//查询电子书函数 
	private:
		e_book e_book1;
};


struct admin			 //管理员和用户账号信息 
{
	char zhanghao[20];		//账号 
	char mima[20];			//密码 
};
class Admin			//管理员的类 
{
	public:
		void adduser();			//添加用户函数 
		void deleteuser();		//删除用户函数 
	private:
		admin admin1;
};


struct user			//用户信息 
{
	int borrow;			//已经借了多少本书 
	int canborrow;		//还可以借多少本书 
	char borrowed[5][30];		//已经借的书的书名 
};
class User			//用户的类 
{
	public:
		void borrowbook();			//借书函数 
		void returnbook();			//还书函数 
	private:
		user user1;
};

	Book shu;
	book book1;
	Admin guanliyuan;
	admin admin1;
	E_book dianzishu;
	e_book e_book1;
	User yonghu;
	user user1;
	char zhanghao1[20];


void Book::Addbook()			//书的类里的添加函数 
{
	char ch;
	ch= getchar();
	book one;
	cout<<"输入书名: "<<endl;
	gets(one.bookname);
	cout<<"输入作者名: "<<endl;
	gets(one.writer);
	cout<<"输入书籍ISBN: "<<endl;
	gets(one.isbn);
	cout<<"输入图书位置: "<<endl;
	gets(one.place);
	cout<<"输入图书编号: "<<endl;
	gets(one.number);
	cout<<"输入图书出版社: "<<endl;
	gets(one.from);
	strcpy(one.condition,"in store");
	FILE *fp;
	if((fp = fopen(one.bookname,"wb"))== NULL)			//以书的名字 创建一个文件，一个文件对应储存一本书 
	{
		cout<<"error"<<endl;
		exit(0);
	}
	fwrite(&one,sizeof(struct book), 1, fp);			//将结构体存入文件 
	
	cout<<one.bookname<< "  is added !"<<endl;
	fclose(fp);
}

void Book::Deletebook()			//书的类里的删除函数 
{
	char ch, name1[30];
	int mm;
	ch=getchar();
	cout<<"输入要删除书目名字:"<<endl;
	gets(name1);
	mm = remove(name1);			//删点书对应的文件 
	if(mm==0)
	{
		cout<<"删除成功!"<<endl; 
	}
	else
	{
		cout<<"删除失败!"<<endl; 
	}
}

void Book::Adjustbook()				//书的类里的修改函数 
{
	book two; 
	char ch, name2[30], where[30], change[30];
	int k;
	ch=getchar();
	cout<<"输入要修改书目名字:"<<endl;
	gets(name2);
	
	FILE *f2, *f3;
	if((f2 = fopen(name2,"rb"))== NULL)
	{
		cout<<"没有相关书籍!"<<endl;
		exit(0);
	}
	fread(&two,sizeof(struct book), 1, f2);			//将书的信息读出 
	fclose(f2);
	k=remove(name2);
	cout<<"输入需要修改的地方:"<<endl;
	gets(where);
	cout<<"输入要修改的结果:"<<endl;
	gets(change);
	
	if(strcmp(where,"bookname")==0)			//找到修改的位置 
	{
		strcpy(two.bookname,change);
		strcpy(name2,change);
	}
	else if(strcmp(where,"writer")==0)
	{
		strcpy(two.writer,change);
	}
	else if(strcmp(where,"isbn")==0)
	{
		strcpy(two.isbn,change);
	}
	else	if(strcmp(where,"place")==0)
	{
		strcpy(two.place,change);
	}
	else 	if(strcmp(where,"number")==0)
	{
		strcpy(two.number,change);
	}
	else	if(strcmp(where,"from")==0)
	{
		strcpy(two.from,change);
	}
	else	if(strcmp(where,"condition")==0)
	{
		strcpy(two.condition,change);
	}

	
	if((f3 = fopen(name2,"wb"))== NULL)			
	{
		cout<<"error"<<endl;
		exit(0);
	}
	fwrite(&two,sizeof(struct book), 1,f3);			//修改后再将结构体写进文件 
	
	cout<<"修改成功!"<<endl;
	cout<<"修改后结果:"<<endl;
	cout<<"书名：  "<<two.bookname<<endl;
	cout<<"作者：  "<<two.writer<<endl;
	cout<<"ISBN：  "<<two.isbn<<endl;
	cout<<"图书位置：  "<<two.place<<endl;
	cout<<"图书编号：  "<<two.number<<endl;
	cout<<"出版社：  "<<two.from<<endl;
	cout<<"出借情况：  "<<two.condition<<endl;

	
	fclose(f3);
}

void Book::Searchbook()			//书的类里的查询函数 
{
	FILE *f4;
	book three;
	char name3[30], ch;
	ch=getchar();	
	cout<<"输入要查找书目名字:"<<endl;
	gets(name3);
	if((f4 = fopen(name3,"rb"))== NULL)
	{
		cout<<"没有相关书籍!"<<endl;
		return ;
	}
	else
	{
		fread(&three, sizeof(struct book), 1, f4);		//读出包含书信息的结构体 
		cout<<"书名：  "<<three.bookname<<endl;
		cout<<"作者：  "<<three.writer<<endl;
		cout<<"ISBN：  "<<three.isbn<<endl;
		cout<<"图书位置：  "<<three.place<<endl;
		cout<<"图书编号：  "<<three.number<<endl;
		cout<<"出版社：  "<<three.from<<endl;
		cout<<"出借情况：  "<<three.condition<<endl;

	}
	
	fclose(f4);
}




void E_book::Adde_book()			//电子书类里的添加函数 
{
	char ch, bookname9[40], e_place[40], bookname11[40];
	ch= getchar();
	e_book e_one;
	cout<<"输入书名: "<<endl;
	gets(e_one.bookname);
	cout<<"输入作者名: "<<endl;
	gets(e_one.writer);
	cout<<"输入图书编号: "<<endl;
	gets(e_one.number);
	FILE *p1, *p2, *p3;
	strcpy(bookname11,e_one.bookname);
	strcat(bookname11,"dianzishu");
	strcpy(bookname9,e_one.bookname);
	strcat(bookname9,"e_book");
	strcpy(e_one.place,bookname9);
	if((p1 = fopen(bookname11,"wb"))== NULL)
	{
		cout<<"error"<<endl;
		exit(0);
	}
	fwrite(&e_one,sizeof(struct e_book), 1, p1);		//类似与纸质书，将电子书信息读入文件 	
	
	cout<<"输入要载入电子书资源位置："<<endl;			 
	gets(e_place);
	if((p2 = fopen(e_place,"rb"))== NULL)
	{
		cout<<"error1"<<endl;
		exit(0);
	}
	
	if((p3 = fopen(bookname9,"wb"))== NULL)			
	{
		cout<<"error"<<endl;
		exit(0);
	}
	while(!feof(p2))			//将电子书的内容读入对应的文件夹 
	{
		fputc(fgetc(p2),p3);
	}
	cout<<e_one.bookname<< "  is added !"<<endl;
	fclose(p1);
	fclose(p2);
	fclose(p3);
}

void E_book::Deletee_book()				//电子书类里的删除函数 
{
	int i1, i2;
	char e_bookname[40], e_bookname1[40], e_bookname2[40], ch;
	ch=getchar();
	cout<<"输入要删除的电子书名："<<endl;
	gets(e_bookname);
	strcpy(e_bookname1,e_bookname);
	strcpy(e_bookname2,e_bookname);
	strcat(e_bookname1,"dianzishu");
	strcat(e_bookname2,"e_book");
	i1=remove(e_bookname1);			//删点电子书信息 
	i2=remove(e_bookname2);			//删点电子书内容 
	if(i1==0&&i2==0)
	{
		cout<<"删除成功!"<<endl; 
	}
	else
	{
		cout<<"删除失败!"<<endl; 
	}
}

void E_book::reade_book()				//电子书类里的在线阅读函数 
{
	e_book e_two;
	FILE *fp8, *fp9;
	int ii;
	char bookname7[40], ch, bookname8[40];
	ch=getchar();
	cout<<"输入电子书名:"<<endl;
	gets(bookname7);
	strcpy(bookname8,bookname7);
	strcat(bookname7,"dianzishu");    
	if((fp8 = fopen(bookname7,"rb"))== NULL)			//打开电子书对应的文件夹 
	{
		cout<<"没有相关书籍!"<<endl;
		return ;
	}
	fread(&e_two, sizeof(struct e_book), 1, fp8);			//读出信息 
	cout<<"电子书书名："<<e_two.bookname<<endl;
	cout<<"电子书作者："<<e_two.writer<<endl;
	cout<<"电子书编号："<<e_two.number<<endl;
	cout<<"电子书存放路径： "<<e_two.place<<endl;
	cout<<"是否阅读？"<<endl;
	cout<<" 1, 是"<<endl;
	cout<<" 2, 否"<<endl;
	cin>>ii;
	if(ii==1)
	{
	 	strcat(bookname8,"e_book");
	
		if((fp9 = fopen(bookname8,"rb"))== NULL)
			{
			cout<<"没有相关书籍!"<<endl;
			return ;
		}
		cout<<"\t";
		while(!feof(fp9))			//将电子书内容独到屏幕上 
		{
			fputc(fgetc(fp9),stdout);
		}
	}
	fclose(fp8);

}

void E_book::searche_book()					//电子书类里的查询函数 
{
	FILE *f4;
	e_book e_three;
	char e_name3[30], ch;
	ch=getchar();	
	cout<<"输入要查找书目名字:"<<endl;
	gets(e_name3);
	strcat(e_name3,"dianzishu");
	if((f4 = fopen(e_name3,"rb"))== NULL)
	{
		cout<<"没有相关书籍!"<<endl;
		return ;
	}
	else
	{
		fread(&e_three, sizeof(struct e_book), 1, f4);
		cout<<"电子书名：  "<<e_three.bookname<<endl;
		cout<<"作者：  "<<e_three.writer<<endl;
		cout<<"图书编号：  "<<e_three.number<<endl;
		cout<<"存放路径：  "<<e_three.number<<endl;
	}
	
	fclose(f4);
}

void E_book::Adjuste_book()				//电子书类里的修改函数 
{
	e_book etwo; 
	char ch, e_name2[30], e_where[30], e_change[30];
	ch=getchar();
	cout<<"输入要修改电子书目名字:"<<endl;
	gets(e_name2);
	strcat(e_name2,"dianzishu");
	FILE *f2, *f3;
	if((f2 = fopen(e_name2,"rb"))== NULL)
	{
		cout<<"没有相关书籍!"<<endl;
		return ;
	}
	fread(&etwo,sizeof(struct e_book), 1, f2);
	fclose(f2);
	remove(e_name2);
	cout<<"输入需要修改的地方:"<<endl;
	gets(e_where);
	cout<<"输入要修改的结果:"<<endl;
	gets(e_change);
	
	if(strcmp(e_where,"bookname")==0)			//类似于纸质书的修改 
	{
		strcpy(etwo.bookname,e_change);
		strcpy(e_name2,e_change);
	}
	else if(strcmp(e_where,"writer")==0)
	{
		strcpy(etwo.writer,e_change);
	}
	else if(strcmp(e_where,"number")==0)
	{
		strcpy(etwo.number,e_change);
	}
	else if(strcmp(e_where,"place")==0)
	{
		strcpy(etwo.place,e_change);
	}
	if((f3 = fopen(e_name2,"wb"))== NULL)
	{
		cout<<"error"<<endl;
		exit(0);
	}
	fwrite(&etwo,sizeof(struct e_book), 1,f3);
	
	cout<<"修改成功!"<<endl;
	cout<<"修改后结果:"<<endl;
	cout<<"电子书名：  "<<etwo.bookname<<endl;
	cout<<"作者：  "<<etwo.writer<<endl;
	cout<<"电子书编号：  "<<etwo.number<<endl;
	cout<<"电子书存放路径：  "<<etwo.place<<endl;
	
	fclose(f3);
}

void User::borrowbook()			//用户类里的借书函数 
{
	FILE *fp4, *fp5, *fp12, *fp13;
	book three;
	user usertwo;
	char name3[30], ch, user11[40];
	int mm2;
	ch=getchar();	
	cout<<"书名:"<<endl;
	gets(name3);
	if((fp4 = fopen(name3,"rb"))== NULL)			//打开对应书的文件 
	{
		cout<<"没有相关书籍!"<<endl;
		return ;
	}
	else			//读出信息 
	{
		fread(&three, sizeof(struct book), 1, fp4);
		cout<<"书名：  "<<three.bookname<<endl;
		cout<<"作者：  "<<three.writer<<endl;
		cout<<"ISBN：  "<<three.isbn<<endl;
		cout<<"图书位置：  "<<three.place<<endl;
		cout<<"图书编号：  "<<three.number<<endl;
		cout<<"出版社：  "<<three.from<<endl;
		cout<<"出借情况：  "<<three.condition<<endl;
	}
	if((strcmp(three.condition,"in store"))==0)
	{

		cout<<"是否要借这本书？"<<endl;
		cout<<"1, 是"<<endl;
		cout<<"2, 否"<<endl;
		cin>>mm2;
		switch(mm2)
		{
			case 1:
			{

				strcpy(three.condition,"borrowed");
				if((fp5 = fopen(name3,"wb"))== NULL)			
				{
					cout<<"error!"<<endl;
					return ;
				}
				fwrite(&three, sizeof(struct book), 1, fp5);		//对书本信息里的出借状况惊醒修改 
				strcpy(user11,zhanghao1);
				strcat(user11,"user");
				if((fp12 = fopen(user11,"rb"))== NULL)
					{
						cout<<"error!"<<endl;
						return ;
					}
				fread(&usertwo, sizeof(struct user), 1, fp12);			//读出用户信息 
				strcpy(usertwo.borrowed[usertwo.borrow],name3);			//对用户信息里的借书情况进行修改 
				usertwo.borrow++;
				usertwo.canborrow--;
				if((fp13 = fopen(user11,"wb"))== NULL)
					{
						cout<<"error!"<<endl;
						return ;
					}
				fwrite(&usertwo, sizeof(struct user), 1, fp13);
				cout<<"借书成功!"<<endl;
				break;
			}
			case 2:
			{
				cout<<"借书失败!"<<endl;
				break;
			}
			default: cout<<"erroe!"<<endl; 
		}
	}
	else if((strcmp(three.condition,"borrowed"))==0)			//这本书已经借出 
	{
		cout<<"这本书已经出借!"<<endl; 
	}

	return ;
}

void User::returnbook()						//用户类里的还书函数 
{
	FILE *fp6, *fp7, *fp16, *fp17;
	char ch, bookname6[30], username3[40];
	int i, j;
	book three;
	user user3;
	ch=getchar();
	cout<<"书名："<<endl;
	gets(bookname6);
	if((fp6 = fopen(bookname6,"rb"))== NULL)
	{
		cout<<"没有相关书籍!"<<endl;
		return ;
	}
	fread(&three, sizeof(struct book), 1, fp6);
	strcpy(three.condition,"in store");				
	fp7 = fopen(bookname6,"wb");
	fwrite(&three, sizeof(struct book), 1, fp7);			//修改图书信息里的出借状况 
	
	strcpy(username3,zhanghao1);
	strcat(username3,"user");
	if((fp16 = fopen(username3,"rb"))== NULL)
	{
		cout<<"error!"<<endl;
		return ;
	}
	fread(&user3, sizeof(struct user), 1, fp16);
	for(i=0;i<user3.borrow;i++)
	{
		if(strcmp(user3.borrowed[i],bookname6)==0)
		{
			for(j=i+1;j<user3.borrow;j++)
			{
				strcpy(user3.borrowed[j-1],user3.borrowed[j]);
			}
		}
	}
	user3.borrow--;
	user3.canborrow++;
	if((fp17 = fopen(username3,"wb"))== NULL)
	{
		cout<<"error!"<<endl;
		return ;
	}
	fwrite(&user3, sizeof(struct user), 1, fp17);			//修改用户信息里的借书信息 
	cout<<"还书成功!"<<endl;
	fclose(fp6);
	fclose(fp7);
}

void Admin::adduser()			//管理员类里的添加用户函数 
{
	FILE *fp1, *fp11;
	char ch, user_zhanghao[40];
	ch=getchar();
	cout<<"添加用户账号： "<<endl;
	gets(admin1.zhanghao);
	strcpy(user_zhanghao,admin1.zhanghao);
	strcat(user_zhanghao,"user");
	cout<<"设置密码:  "<<endl;
	gets(admin1.mima);
	if((fp1 = fopen(admin1.zhanghao,"wb"))== NULL)			//创建文件保存对应账号，一个文件保存一个账号 
	{
		cout<<"error"<<endl;
		exit(0);
	}
	fwrite(&admin1,sizeof(struct admin), 1, fp1);
	if((fp11 = fopen(user_zhanghao,"wb"))== NULL)
	{
		cout<<"error"<<endl;
		exit(0);
	}
	user oneuser;
	oneuser.borrow=0;
	oneuser.canborrow=5;
	fwrite(&oneuser, sizeof(struct user), 1, fp11);			//初始化用户的借书信息 
	
	cout<<"添加用户成功!"<<endl;
	fclose(fp1);
	fclose(fp11);
}

void Admin::deleteuser()			//管理员类里的删除用户函数 
{
	char ch, zhanghao2[20];
	int mm1;
	ch=getchar();
	cout<<"输入删除账号"<<endl;
	gets(zhanghao2);
	mm1=remove(zhanghao2);		//删除账号对应文件 
	if(mm1==0)
	{
		cout<<"删除用户成功!"<<endl;
	}
	else
	{
		cout<<"删除用户失败!"<<endl;
	}
}


int main()
{
/*	FILE *fp11;											//前面这部分用来创建初始的管理员 
	cout<<"输入账号："<<endl;
	gets(admin1.zhanghao);
	cout<<"输入密码："<<endl;
	gets(admin1.mima);
	if((fp = fopen(admin1.zhanghao,"wb"))== NULL)
	{
		cout<<"error!"<<endl;
		return 0;
	}
	fwrite(&admin1,sizeof(struct admin), 1, fp);  
	fclose(fp11)		*/
	
	
	FILE *ff1 ;
	int i, j, k, p;
	char ch1,  mima1[20];
	cout<<" 1,管理员登录 "<<endl;
	cout<<" 2,用户登录 "<<endl;
	cin>> i;
	ch1=getchar();
	switch(i)
	{
		case 1:{
				
					cout<<" 管理员账号：   "<< endl;			//已建立管理员账号：123456，密码：123456 
					gets(zhanghao1);
					if((ff1 = fopen(zhanghao1,"rb"))== NULL)
						{
							cout<<"没有此账号!"<<endl;
							exit(0);
						}
					fread(&admin1,sizeof(struct admin), 1, ff1);
					cout<<" 密码：   "<< endl;
					gets(mima1);
					if(strcmp(admin1.mima,mima1)!=0)
					{
						cout<<" 密码错误!"<< endl;
						return 0;
					}
					else
					{
						cout<<" 1, 添加用户"<<endl;
						cout<<" 2, 删除用户"<<endl;
						cout<<" 3, 添加纸质书目"<<endl;
						cout<<" 4, 删除纸质书目"<< endl;
						cout<<" 5, 修改纸质书目信息"<< endl;
						cout<<" 6, 查询纸质书目信息"<<endl;
						cout<<" 7, 添加电子书目"<<endl;
						cout<<" 8, 删除电子书目"<<endl;
						cout<<" 9, 修改电子书目信息"<<endl;
						cout<<"10, 查询电子书目信息"<<endl;
					}
					cin>> j;
					switch(j)
					{
						case 1:	
						{
							guanliyuan.adduser();
							break;
						}
						case 2:
						{
							guanliyuan.deleteuser();
							break;
						}
						case 3:
						{
							shu.Addbook();
							break;
						}
						case 4:
						{
							shu.Deletebook();
							break;
						}
						case 5:
						{
							shu.Adjustbook();
							break;
						}
						case 6:
						{
							shu.Searchbook();
							break;
						}
						case 7:
						{
							dianzishu.Adde_book();
							break;
						}
						case 8:
						{
							dianzishu.Deletee_book();
							break;
						}
						case 9:
						{
							dianzishu.Adjuste_book();
							break;
						}
						case 10:
						{
							dianzishu.searche_book();
							break;
						}
						default: cout<<"erroe!"<<endl; 
					}		
					break;
				}
		case 2:{
					cout<<"用户账号： "<<endl;
					gets(zhanghao1);
					if((ff1 = fopen(zhanghao1,"rb"))== NULL)
						{
							cout<<"没有此账号!"<<endl;
							exit(0);
						}
					fread(&admin1,sizeof(struct admin), 1, ff1);
					cout<<" 密码：   "<< endl;
					gets(mima1);
					if(strcmp(admin1.mima,mima1)!=0)
					{
						cout<<" 密码错误!"<< endl;
						return 0;
					}
					else
					{	
						char user8[20];
						FILE *q1, *q2;
						strcpy(user8,zhanghao1);
						strcat(user8,"user");
						if((q1 = fopen(user8,"rb"))== NULL)
						{
							cout<<"error!"<<endl;
							exit(0);
						}
						fread(&user1,sizeof(struct user), 1, q1);
						cout<<"一个用户最多可以借 5 本书"<<endl;
						cout<<"您已经借了 "<<user1.borrow<<" 本书"<<endl;
						for(p=0;p<user1.borrow;p++)
						{
							cout<<"书名： ";
							cout<<user1.borrowed[p]<<endl;
						}
						cout<<"\n";
						cout<<"您还能借 "<<user1.canborrow<<" 本书"<<endl;
						cout<<"1, 纸质书查询"<<endl;
						cout<<"2, 借书"<<endl;
						cout<<"3, 还书"<<endl;
						cout<<"4, 电子书查询"<<endl;
						cout<<"5, 电子书在线阅读"<<endl;
					}
					cin>>k;
					switch(k)
					{
						case 1:
						{
							shu.Searchbook();
							break;
						}
						case 2:
						{
							yonghu.borrowbook();
							break;
						}
						case 3:
						{
							yonghu.returnbook();
							break;
						}
						case 4:
						{
							dianzishu.searche_book();
							break;
						}
						case 5:
						{
							dianzishu.reade_book();
							break;
						}
						default: cout<<"erroe!"<<endl; 
					}
					break;
				}
			default: cout<<"erroe!"<<endl; 
	}

fclose(ff1);
	
	
return 0;
}
