#include<iostream>
#include<string.h>
using namespace std;

template <class T>
class yo
{
	int t_o_s;
	T a[1000];
	public:	
	yo()
	{
		t_o_s=-1;
	}
	void push(T n)
	{
		t_o_s++;
		if(t_o_s>9)
			cout<<"stack overflow"<<endl;
		a[t_o_s]=n;
	}
	
	T pop(T &flag)
	{
		T temp;
		if(t_o_s<0)
		{
			return flag++;
		}
		else{
			temp=a[t_o_s];
			t_o_s--;
			return temp;
		}
	}
	T val1()
	{
		return t_o_s;
	}
	T val(int n)
	{
		int q=t_o_s+n;
		if(q<0)
			return 5;
		return a[q];	
	}
	
	void display()
	{
		for(int i=0;i<=t_o_s;i++)
		{
			cout<<a[i];
		}
	}
};

int weight(char a)
{
	switch(a)
	{
		case '^':
			return 2;
		case '*':
			return 1;
		case '+':
			return 0;	
	}	
}

int asso(char a)
{
	switch(a)
	{
		case '^':
			return 0;
		default:
			return 1;
	}
}

int main()
{
	yo<char> sign,cha;
    string q;
    char flag='a';

    //int j=0,k=0;
    //char n[100],c[100];
    cout<<"Enter infix: "<<endl;
    cin>>q;
    for(int i=0;i<q.length();i++)
    {
    	if(q[i]=='+' || q[i]=='*'|| q[i]=='^')
		{
			if(i==1)
			{
				sign.push(q[i]);
				//cout<<"2."<<endl;
				goto s;
			}
			if(weight(sign.val(0))>weight(q[i]))
			{
				//cout<<"3"<<endl;
				cha.push(sign.pop(flag));
				sign.push(q[i]);
				//cout<<sign.val(0)<<endl;
				//cout<<sign.val(-1)<<endl;
				if(weight(sign.val(0))==weight(sign.val(-1)))
				{
					if(asso(q[i]))
					{
						//cout<<"44"<<endl;
						cha.push(sign.pop(flag));
						//sign.push(q[i]);
					}else{
						//cout<<"55";
						sign.push(q[i]);
					}
				}
			}else if(weight(sign.val(0))==weight(q[i]))
			{
				if(asso(q[i]))
				{
					cout<<"4"<<endl;
					cha.push(sign.pop(flag));
					sign.push(q[i]);
				}else{
					cout<<"5";
					sign.push(q[i]);
				}	
			}else{
				//cout<<"6";
				sign.push(q[i]);
			}
		}else{
			cha.push(q[i]);
			//cout<<"1."<<endl;
			char var;
			while(i==q.length()-1 && sign.val1()>=0)
			{
				var=sign.pop(flag);
				if(var!=5)
					cha.push(var);
			}
		}    
    s:;
	}
    cha.display();
    return 0;
}

