#include <iostream>
#include "LStack.h"
#include "Link.h"
#include<string.h>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int isp (char ch){
	char a,b,c,d,e,f,g,h,i,j;
	a='=';
	b='+';
	c='-';
	d='*';
	e='/';
	f='%';
	g='(';
	h=')';
	i='^';
	j= '&';
	if (ch==a) {
		return 0;
	}
	else if (ch==b){
		return 3;
	}
	else if (ch==c){
		return 3;
	}
	else if (ch==d){
		return 5;
	}
	else if (ch==e){
		return 5;
	}
	else if (ch==f){
		return 5;
	}
	else if (ch==g)
	{
		return 1;
	}
	else if (ch==h){
		return 8;
	}
	else if (ch==i){
		return 7;
	}
	else if (ch==j){
		return 7;
	}
}
int osp(char ch) {
	char a,b,c,d,e,f,g,h,i,j;
	a='=';
	b='+';
	c='-';
	d='*';
	e='/';
	f='%';
	g='(';
	h=')';
	i='^';
	j= '&';
	if (ch==a) {
		return 0;
	}
	else if (ch==b){
		return 2;
	}
	else if (ch==c){
		return 2;
	}
	else if (ch==d){
		return 4;
	}
	else if (ch==e){
		return 4;
	}
	else if (ch==f){
		return 4;
	}
	else if (ch==g)
	{
		return 8;
	}
	else if (ch==h){
		return 1;
	}
	else if (ch==i){
		return 6;
	}
	else if (ch==j){
		return 6;
	}	
}
bool  cal( char op, double x, double y, double & r){
	char a,b,c,d,e,f,g,h,i,j;
	a='=';
	b='+';
	c='-';
	d='*';
	e='/';
	f='%';
	g='(';
	h=')';
	i='^';
	j= '&';
	if(op==a){
		
	}
	if(op==b){
		r=x+y;
	}
	if(op==c){
		r=y-x;
	}
	if(op==d){
		r=x*y;
	}
	if(op==e){
		r=y/x;
	}
	if(op==f){
		r=fmod(y,x);
	}
	if(op==g){
		;
	}
	if(op==h){
		;
	}	
	if(op==i){
		r=pow(y,x);
	}	
	if(op==j){
		r=pow(y,1/x);
	}
	return 0;
}
void GetNextchar(char &ch){ 
	 ch=getchar(); 
}
bool isdigit(char ch) {
	int tmp = (int)ch;
	if (tmp >= 48 && tmp <= 57){
			return true;
		}
	else{
		return false;
	}
}
bool IsOperator(char ch)  {
	char a,b,c,d,e,f,g,h,i,j;
	a='=';
	b='+';
	c='-';
	d='*';
	e='/';
	f='%';
	g='(';
	h=')';
	i='^';
	j= '&';
	if (ch==a) {
		return true;
	}
	else if (ch==b){
		return true;
	}
	else if (ch==c){
		return true;
	}
	else if (ch==d){
		return true;
	}
	else if (ch==e){
		return true;
	}
	else if (ch==f){
		return true;
	}
	else if (ch==g)
	{
		return true;
	}
	else if (ch==h){
		return true;
	}
	else if (ch==i){
		return true;
	}
	else if (ch==j){
		return true;
	}
	else{
		return false;
	}
}
bool Get2Operands( LStack<double> &opnd,  double &x, double &y) 
{
	bool temp=true;
	if(opnd.pop(x)!=1){
		temp=false;
	}
	if(opnd.pop(y)!=1){
		temp=false;
	}
	return temp;
}

int main ( ) {
LStack<double> OPND;   //  ������ջ���壻
LStack<char>   OPTR; //  ������ջ���壻
bool islogon=1; 
while(islogon) 
{
	char ch;
	char ch1; 
	int i=0;
	cout<<"******************��ӭʹ��calculator 1.0******************"<<endl;
	cout<<"ʹ��˵����"<<endl;
	cout<<"���ʽ�ɰ�����"<<endl;
	cout<<"1.�ӣ�+��������-�����ˣ�*��������/������ģ��%����������&���ͳ˷���^�������"<<endl;
	cout<<"2.С����"<<endl;
	cout<<"���������㹫ʽ!<�ԵȺš�=������>"<<endl;
	char a='=';
	double b=0;
	double operand;
	OPTR.push(a); 
	char prior_char = '=';    //prior_char ��ʾ��ǰ�����ַ���ǰһ���ַ�����Ϊ��������ֵ'0'
	char OPTR_top;
	OPTR.topValue(OPTR_top);
	GetNextchar(ch);
	while(OPTR_top!= a || ch != a ) {

          if(isdigit(ch)||ch=='.')  {  //����С��
          			if(ch!='.')	{					  		  
					operand=(int)ch-48;
		  			prior_char=ch;
					GetNextchar(ch);
					double temp;
          		  while(isdigit(ch)) {    
					temp=(int)ch-48;
					operand=operand*10+temp;			
					prior_char=ch;
					GetNextchar(ch);	
                  }
               }	 
                  if(ch=='.'){
                  	if(!isdigit(prior_char)){
                  		operand=0;    //������.xxx(xΪ����),ch=='.'ʱoperand����0
					  }
		  			prior_char=ch; 
					GetNextchar(ch);
					if(!isdigit(ch)){
						cout<<"������ʽ�д� ��������"<<endl;
						return 1;
					}
					double operand2;
					operand2=(int)ch-48;   
					double temp2;
		  			prior_char=ch;
					GetNextchar(ch);
					int i = 1;
         		  while(isdigit(ch)) {    
					temp2=(int)ch-48;
					operand2=operand2*10+temp2;			
					prior_char=ch;
					GetNextchar(ch);
					i++;
                  }	
				  operand=operand+operand2*pow(10,-i);				  				           	
				  }
                  
				  OPND.push(operand);
				  prior_char='0';  

				    }
          else if(!IsOperator(ch)) 
		   {  
		   cout<<ch<<endl;
		   cout<<"������ʽ�г��ַǷ��ַ�!"<<endl;  return 0; } 
          else {
          	
               if(( prior_char=='='||prior_char=='(')&&(ch=='+'||ch=='-'))   OPND.push(b);           
               if (osp(ch)>isp(OPTR_top))    { 
			   		OPTR.push(ch);
					OPTR.topValue(OPTR_top);
			   		prior_char=ch;     			   
					GetNextchar(ch);
			    }
               else if(osp(ch)<isp(OPTR_top))    {
				   while(osp(ch) < isp(OPTR_top)){
					   double tmp1, tmp2, answer;
					   OPTR.pop(ch1);
					   OPTR.topValue(OPTR_top);
					   if (ch1 != '(' && ch1 != ')')
					   {
						   Get2Operands(OPND, tmp1, tmp2);
						   cal(ch1, tmp1, tmp2, answer);
						   OPND.push(answer);
					   }
					   }
				   if (osp(ch) > isp(OPTR_top)) {
					   OPTR.push(ch);
					   OPTR.topValue(OPTR_top);
					   prior_char = ch;
					   GetNextchar(ch);
				   }
				   else if(ch!='=') {
					   char tep;
					   OPTR.pop(tep);
					   OPTR.topValue(OPTR_top);
					   prior_char = ch;
					   GetNextchar(ch);
					   continue;
				   }
				  if (ch == '=' && OPTR_top != '=')
				   {
					   cout << "������ʽ�д�!" << endl;
					   return 0;
				   }
			   }
               else  {
               	char tep;
               	OPTR.pop(tep);
				OPTR.topValue(OPTR_top);
               	prior_char=ch;     			   
				GetNextchar(ch);
			   }
		 }
	}

    if ( ! OPTR.topValue(OPTR_top) )
		  	{			  	
				cout<<"������ʽ�д�!"<<endl;  
		  		return 0;
		    } 
	 
	  


	if (OPND.length() != 1)  {  
	cout<<"������ʽ�д�!"<<endl;  return 0;  } 
	else{
		double answer;
		OPND.pop(answer);
		cout<<answer<<endl;
	}
	

	bool choiceget=true;
	char choice;
	while(choiceget)
	{
		cout<<"�Ƿ�Ҫ������������Y/N"<<endl;
		cin>>choice;
		getchar();
		if(choice=='Y'){
			choiceget=false;
		}
		else if(choice=='N'){
			islogon=false;
			choiceget=false;
		}
		else{
			choiceget=true;
		}
	
	}
	
	
}


		
} 
