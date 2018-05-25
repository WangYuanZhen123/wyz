#include<iostream>
#include<string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct book			//�����Ϣ�ṹ�� 
{
	char bookname[30];
	char writer[30];
	char isbn[30];
	char place[30];				//���õ�λ�� 
	char number[30];			//�鼮��� 
	char from[30];				//������ 
	char condition[15] ;		//������� 
};
class Book			//����� 
{
	public:
		void Addbook();			//�����Ŀ���� 
		void Deletebook();		//ɾ����Ŀ���� 
		void Adjustbook();		//�޸���Ŀ��Ϣ���� 
		void Searchbook();		//��ѯ��Ŀ���� 
	private:
		book book1;
};


struct e_book				//������Ľṹ�� 
{
	char bookname[40];
	char writer[30];
	char number[30];		//�������� 
	char place[40];			//���·�� 
};
class E_book			//��������� 
{
	public:
		void Adde_book();		//��ӵ����麯�� 
		void Deletee_book();		//ɾ�������麯�� 
		void Adjuste_book();		//�޸ĵ�������Ϣ���� 
		void reade_book();			//�����Ķ����� 
		void searche_book();		//��ѯ�����麯�� 
	private:
		e_book e_book1;
};


struct admin			 //����Ա���û��˺���Ϣ 
{
	char zhanghao[20];		//�˺� 
	char mima[20];			//���� 
};
class Admin			//����Ա���� 
{
	public:
		void adduser();			//����û����� 
		void deleteuser();		//ɾ���û����� 
	private:
		admin admin1;
};


struct user			//�û���Ϣ 
{
	int borrow;			//�Ѿ����˶��ٱ��� 
	int canborrow;		//�����Խ���ٱ��� 
	char borrowed[5][30];		//�Ѿ����������� 
};
class User			//�û����� 
{
	public:
		void borrowbook();			//���麯�� 
		void returnbook();			//���麯�� 
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


void Book::Addbook()			//����������Ӻ��� 
{
	char ch;
	ch= getchar();
	book one;
	cout<<"��������: "<<endl;
	gets(one.bookname);
	cout<<"����������: "<<endl;
	gets(one.writer);
	cout<<"�����鼮ISBN: "<<endl;
	gets(one.isbn);
	cout<<"����ͼ��λ��: "<<endl;
	gets(one.place);
	cout<<"����ͼ����: "<<endl;
	gets(one.number);
	cout<<"����ͼ�������: "<<endl;
	gets(one.from);
	strcpy(one.condition,"in store");
	FILE *fp;
	if((fp = fopen(one.bookname,"wb"))== NULL)			//��������� ����һ���ļ���һ���ļ���Ӧ����һ���� 
	{
		cout<<"error"<<endl;
		exit(0);
	}
	fwrite(&one,sizeof(struct book), 1, fp);			//���ṹ������ļ� 
	
	cout<<one.bookname<< "  is added !"<<endl;
	fclose(fp);
}

void Book::Deletebook()			//��������ɾ������ 
{
	char ch, name1[30];
	int mm;
	ch=getchar();
	cout<<"����Ҫɾ����Ŀ����:"<<endl;
	gets(name1);
	mm = remove(name1);			//ɾ�����Ӧ���ļ� 
	if(mm==0)
	{
		cout<<"ɾ���ɹ�!"<<endl; 
	}
	else
	{
		cout<<"ɾ��ʧ��!"<<endl; 
	}
}

void Book::Adjustbook()				//���������޸ĺ��� 
{
	book two; 
	char ch, name2[30], where[30], change[30];
	int k;
	ch=getchar();
	cout<<"����Ҫ�޸���Ŀ����:"<<endl;
	gets(name2);
	
	FILE *f2, *f3;
	if((f2 = fopen(name2,"rb"))== NULL)
	{
		cout<<"û������鼮!"<<endl;
		exit(0);
	}
	fread(&two,sizeof(struct book), 1, f2);			//�������Ϣ���� 
	fclose(f2);
	k=remove(name2);
	cout<<"������Ҫ�޸ĵĵط�:"<<endl;
	gets(where);
	cout<<"����Ҫ�޸ĵĽ��:"<<endl;
	gets(change);
	
	if(strcmp(where,"bookname")==0)			//�ҵ��޸ĵ�λ�� 
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
	fwrite(&two,sizeof(struct book), 1,f3);			//�޸ĺ��ٽ��ṹ��д���ļ� 
	
	cout<<"�޸ĳɹ�!"<<endl;
	cout<<"�޸ĺ���:"<<endl;
	cout<<"������  "<<two.bookname<<endl;
	cout<<"���ߣ�  "<<two.writer<<endl;
	cout<<"ISBN��  "<<two.isbn<<endl;
	cout<<"ͼ��λ�ã�  "<<two.place<<endl;
	cout<<"ͼ���ţ�  "<<two.number<<endl;
	cout<<"�����磺  "<<two.from<<endl;
	cout<<"���������  "<<two.condition<<endl;

	
	fclose(f3);
}

void Book::Searchbook()			//�������Ĳ�ѯ���� 
{
	FILE *f4;
	book three;
	char name3[30], ch;
	ch=getchar();	
	cout<<"����Ҫ������Ŀ����:"<<endl;
	gets(name3);
	if((f4 = fopen(name3,"rb"))== NULL)
	{
		cout<<"û������鼮!"<<endl;
		return ;
	}
	else
	{
		fread(&three, sizeof(struct book), 1, f4);		//������������Ϣ�Ľṹ�� 
		cout<<"������  "<<three.bookname<<endl;
		cout<<"���ߣ�  "<<three.writer<<endl;
		cout<<"ISBN��  "<<three.isbn<<endl;
		cout<<"ͼ��λ�ã�  "<<three.place<<endl;
		cout<<"ͼ���ţ�  "<<three.number<<endl;
		cout<<"�����磺  "<<three.from<<endl;
		cout<<"���������  "<<three.condition<<endl;

	}
	
	fclose(f4);
}




void E_book::Adde_book()			//�������������Ӻ��� 
{
	char ch, bookname9[40], e_place[40], bookname11[40];
	ch= getchar();
	e_book e_one;
	cout<<"��������: "<<endl;
	gets(e_one.bookname);
	cout<<"����������: "<<endl;
	gets(e_one.writer);
	cout<<"����ͼ����: "<<endl;
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
	fwrite(&e_one,sizeof(struct e_book), 1, p1);		//������ֽ���飬����������Ϣ�����ļ� 	
	
	cout<<"����Ҫ�����������Դλ�ã�"<<endl;			 
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
	while(!feof(p2))			//������������ݶ����Ӧ���ļ��� 
	{
		fputc(fgetc(p2),p3);
	}
	cout<<e_one.bookname<< "  is added !"<<endl;
	fclose(p1);
	fclose(p2);
	fclose(p3);
}

void E_book::Deletee_book()				//�����������ɾ������ 
{
	int i1, i2;
	char e_bookname[40], e_bookname1[40], e_bookname2[40], ch;
	ch=getchar();
	cout<<"����Ҫɾ���ĵ���������"<<endl;
	gets(e_bookname);
	strcpy(e_bookname1,e_bookname);
	strcpy(e_bookname2,e_bookname);
	strcat(e_bookname1,"dianzishu");
	strcat(e_bookname2,"e_book");
	i1=remove(e_bookname1);			//ɾ���������Ϣ 
	i2=remove(e_bookname2);			//ɾ����������� 
	if(i1==0&&i2==0)
	{
		cout<<"ɾ���ɹ�!"<<endl; 
	}
	else
	{
		cout<<"ɾ��ʧ��!"<<endl; 
	}
}

void E_book::reade_book()				//����������������Ķ����� 
{
	e_book e_two;
	FILE *fp8, *fp9;
	int ii;
	char bookname7[40], ch, bookname8[40];
	ch=getchar();
	cout<<"�����������:"<<endl;
	gets(bookname7);
	strcpy(bookname8,bookname7);
	strcat(bookname7,"dianzishu");    
	if((fp8 = fopen(bookname7,"rb"))== NULL)			//�򿪵������Ӧ���ļ��� 
	{
		cout<<"û������鼮!"<<endl;
		return ;
	}
	fread(&e_two, sizeof(struct e_book), 1, fp8);			//������Ϣ 
	cout<<"������������"<<e_two.bookname<<endl;
	cout<<"���������ߣ�"<<e_two.writer<<endl;
	cout<<"�������ţ�"<<e_two.number<<endl;
	cout<<"��������·���� "<<e_two.place<<endl;
	cout<<"�Ƿ��Ķ���"<<endl;
	cout<<" 1, ��"<<endl;
	cout<<" 2, ��"<<endl;
	cin>>ii;
	if(ii==1)
	{
	 	strcat(bookname8,"e_book");
	
		if((fp9 = fopen(bookname8,"rb"))== NULL)
			{
			cout<<"û������鼮!"<<endl;
			return ;
		}
		cout<<"\t";
		while(!feof(fp9))			//�����������ݶ�����Ļ�� 
		{
			fputc(fgetc(fp9),stdout);
		}
	}
	fclose(fp8);

}

void E_book::searche_book()					//����������Ĳ�ѯ���� 
{
	FILE *f4;
	e_book e_three;
	char e_name3[30], ch;
	ch=getchar();	
	cout<<"����Ҫ������Ŀ����:"<<endl;
	gets(e_name3);
	strcat(e_name3,"dianzishu");
	if((f4 = fopen(e_name3,"rb"))== NULL)
	{
		cout<<"û������鼮!"<<endl;
		return ;
	}
	else
	{
		fread(&e_three, sizeof(struct e_book), 1, f4);
		cout<<"����������  "<<e_three.bookname<<endl;
		cout<<"���ߣ�  "<<e_three.writer<<endl;
		cout<<"ͼ���ţ�  "<<e_three.number<<endl;
		cout<<"���·����  "<<e_three.number<<endl;
	}
	
	fclose(f4);
}

void E_book::Adjuste_book()				//������������޸ĺ��� 
{
	e_book etwo; 
	char ch, e_name2[30], e_where[30], e_change[30];
	ch=getchar();
	cout<<"����Ҫ�޸ĵ�����Ŀ����:"<<endl;
	gets(e_name2);
	strcat(e_name2,"dianzishu");
	FILE *f2, *f3;
	if((f2 = fopen(e_name2,"rb"))== NULL)
	{
		cout<<"û������鼮!"<<endl;
		return ;
	}
	fread(&etwo,sizeof(struct e_book), 1, f2);
	fclose(f2);
	remove(e_name2);
	cout<<"������Ҫ�޸ĵĵط�:"<<endl;
	gets(e_where);
	cout<<"����Ҫ�޸ĵĽ��:"<<endl;
	gets(e_change);
	
	if(strcmp(e_where,"bookname")==0)			//������ֽ������޸� 
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
	
	cout<<"�޸ĳɹ�!"<<endl;
	cout<<"�޸ĺ���:"<<endl;
	cout<<"����������  "<<etwo.bookname<<endl;
	cout<<"���ߣ�  "<<etwo.writer<<endl;
	cout<<"�������ţ�  "<<etwo.number<<endl;
	cout<<"��������·����  "<<etwo.place<<endl;
	
	fclose(f3);
}

void User::borrowbook()			//�û�����Ľ��麯�� 
{
	FILE *fp4, *fp5, *fp12, *fp13;
	book three;
	user usertwo;
	char name3[30], ch, user11[40];
	int mm2;
	ch=getchar();	
	cout<<"����:"<<endl;
	gets(name3);
	if((fp4 = fopen(name3,"rb"))== NULL)			//�򿪶�Ӧ����ļ� 
	{
		cout<<"û������鼮!"<<endl;
		return ;
	}
	else			//������Ϣ 
	{
		fread(&three, sizeof(struct book), 1, fp4);
		cout<<"������  "<<three.bookname<<endl;
		cout<<"���ߣ�  "<<three.writer<<endl;
		cout<<"ISBN��  "<<three.isbn<<endl;
		cout<<"ͼ��λ�ã�  "<<three.place<<endl;
		cout<<"ͼ���ţ�  "<<three.number<<endl;
		cout<<"�����磺  "<<three.from<<endl;
		cout<<"���������  "<<three.condition<<endl;
	}
	if((strcmp(three.condition,"in store"))==0)
	{

		cout<<"�Ƿ�Ҫ���Ȿ�飿"<<endl;
		cout<<"1, ��"<<endl;
		cout<<"2, ��"<<endl;
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
				fwrite(&three, sizeof(struct book), 1, fp5);		//���鱾��Ϣ��ĳ���״�������޸� 
				strcpy(user11,zhanghao1);
				strcat(user11,"user");
				if((fp12 = fopen(user11,"rb"))== NULL)
					{
						cout<<"error!"<<endl;
						return ;
					}
				fread(&usertwo, sizeof(struct user), 1, fp12);			//�����û���Ϣ 
				strcpy(usertwo.borrowed[usertwo.borrow],name3);			//���û���Ϣ��Ľ�����������޸� 
				usertwo.borrow++;
				usertwo.canborrow--;
				if((fp13 = fopen(user11,"wb"))== NULL)
					{
						cout<<"error!"<<endl;
						return ;
					}
				fwrite(&usertwo, sizeof(struct user), 1, fp13);
				cout<<"����ɹ�!"<<endl;
				break;
			}
			case 2:
			{
				cout<<"����ʧ��!"<<endl;
				break;
			}
			default: cout<<"erroe!"<<endl; 
		}
	}
	else if((strcmp(three.condition,"borrowed"))==0)			//�Ȿ���Ѿ���� 
	{
		cout<<"�Ȿ���Ѿ�����!"<<endl; 
	}

	return ;
}

void User::returnbook()						//�û�����Ļ��麯�� 
{
	FILE *fp6, *fp7, *fp16, *fp17;
	char ch, bookname6[30], username3[40];
	int i, j;
	book three;
	user user3;
	ch=getchar();
	cout<<"������"<<endl;
	gets(bookname6);
	if((fp6 = fopen(bookname6,"rb"))== NULL)
	{
		cout<<"û������鼮!"<<endl;
		return ;
	}
	fread(&three, sizeof(struct book), 1, fp6);
	strcpy(three.condition,"in store");				
	fp7 = fopen(bookname6,"wb");
	fwrite(&three, sizeof(struct book), 1, fp7);			//�޸�ͼ����Ϣ��ĳ���״�� 
	
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
	fwrite(&user3, sizeof(struct user), 1, fp17);			//�޸��û���Ϣ��Ľ�����Ϣ 
	cout<<"����ɹ�!"<<endl;
	fclose(fp6);
	fclose(fp7);
}

void Admin::adduser()			//����Ա���������û����� 
{
	FILE *fp1, *fp11;
	char ch, user_zhanghao[40];
	ch=getchar();
	cout<<"����û��˺ţ� "<<endl;
	gets(admin1.zhanghao);
	strcpy(user_zhanghao,admin1.zhanghao);
	strcat(user_zhanghao,"user");
	cout<<"��������:  "<<endl;
	gets(admin1.mima);
	if((fp1 = fopen(admin1.zhanghao,"wb"))== NULL)			//�����ļ������Ӧ�˺ţ�һ���ļ�����һ���˺� 
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
	fwrite(&oneuser, sizeof(struct user), 1, fp11);			//��ʼ���û��Ľ�����Ϣ 
	
	cout<<"����û��ɹ�!"<<endl;
	fclose(fp1);
	fclose(fp11);
}

void Admin::deleteuser()			//����Ա�����ɾ���û����� 
{
	char ch, zhanghao2[20];
	int mm1;
	ch=getchar();
	cout<<"����ɾ���˺�"<<endl;
	gets(zhanghao2);
	mm1=remove(zhanghao2);		//ɾ���˺Ŷ�Ӧ�ļ� 
	if(mm1==0)
	{
		cout<<"ɾ���û��ɹ�!"<<endl;
	}
	else
	{
		cout<<"ɾ���û�ʧ��!"<<endl;
	}
}


int main()
{
/*	FILE *fp11;											//ǰ���ⲿ������������ʼ�Ĺ���Ա 
	cout<<"�����˺ţ�"<<endl;
	gets(admin1.zhanghao);
	cout<<"�������룺"<<endl;
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
	cout<<" 1,����Ա��¼ "<<endl;
	cout<<" 2,�û���¼ "<<endl;
	cin>> i;
	ch1=getchar();
	switch(i)
	{
		case 1:{
				
					cout<<" ����Ա�˺ţ�   "<< endl;			//�ѽ�������Ա�˺ţ�123456�����룺123456 
					gets(zhanghao1);
					if((ff1 = fopen(zhanghao1,"rb"))== NULL)
						{
							cout<<"û�д��˺�!"<<endl;
							exit(0);
						}
					fread(&admin1,sizeof(struct admin), 1, ff1);
					cout<<" ���룺   "<< endl;
					gets(mima1);
					if(strcmp(admin1.mima,mima1)!=0)
					{
						cout<<" �������!"<< endl;
						return 0;
					}
					else
					{
						cout<<" 1, ����û�"<<endl;
						cout<<" 2, ɾ���û�"<<endl;
						cout<<" 3, ���ֽ����Ŀ"<<endl;
						cout<<" 4, ɾ��ֽ����Ŀ"<< endl;
						cout<<" 5, �޸�ֽ����Ŀ��Ϣ"<< endl;
						cout<<" 6, ��ѯֽ����Ŀ��Ϣ"<<endl;
						cout<<" 7, ��ӵ�����Ŀ"<<endl;
						cout<<" 8, ɾ��������Ŀ"<<endl;
						cout<<" 9, �޸ĵ�����Ŀ��Ϣ"<<endl;
						cout<<"10, ��ѯ������Ŀ��Ϣ"<<endl;
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
					cout<<"�û��˺ţ� "<<endl;
					gets(zhanghao1);
					if((ff1 = fopen(zhanghao1,"rb"))== NULL)
						{
							cout<<"û�д��˺�!"<<endl;
							exit(0);
						}
					fread(&admin1,sizeof(struct admin), 1, ff1);
					cout<<" ���룺   "<< endl;
					gets(mima1);
					if(strcmp(admin1.mima,mima1)!=0)
					{
						cout<<" �������!"<< endl;
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
						cout<<"һ���û������Խ� 5 ����"<<endl;
						cout<<"���Ѿ����� "<<user1.borrow<<" ����"<<endl;
						for(p=0;p<user1.borrow;p++)
						{
							cout<<"������ ";
							cout<<user1.borrowed[p]<<endl;
						}
						cout<<"\n";
						cout<<"�����ܽ� "<<user1.canborrow<<" ����"<<endl;
						cout<<"1, ֽ�����ѯ"<<endl;
						cout<<"2, ����"<<endl;
						cout<<"3, ����"<<endl;
						cout<<"4, �������ѯ"<<endl;
						cout<<"5, �����������Ķ�"<<endl;
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
