#include <iostream>
#include <string>
using namespace std;
string get(string& str, int a, int b)
{
	string res;
	while(a>=0 && b<str.size() && str[a]==str[b])//s[a] == s[b]�O�ΨӧP�_���k����Ӧ줸�̪��F��O�_�۵�
	{
		res=str.substr(a,b-a+1);
		a--;
		b++;
	}
	return res;
}


int main()
{
	//////////�u��X�̪��^��r��A�Y�̪��r�ꤣ�u�@�ӡA���o�X�ӳ��nprint�X��//////////
	string input, ans[1000];//��J�P��X�O�r��
	int count = 0;//�p��̪��^��r�ꪺ���סA�Y�^��r�ꪺ���׬�1��0�h��X0
	int number = 1;//�p��^��r�ꪺ�ƶq 
	int i;
	while(cin >> input)
	{
		/*
		if(input.size()==0 || input.size()==1)
		{
			cout << count << endl;//�p�G���׬�0��1 �������B��
			continue;//�����~��U�@������
		}
		*/
		
		for(i=0; i<input.size(); i++)
		{
			/////��^��r��O�_�ƭ�/////
			string temp = get(input , i, i);
			if(temp.size() == count && count != 1)//�p�G�^��r����׻P�쥻���۵��A���@�ˤ]�s�i�h
			{
				ans[number] = temp;
				number++;
			}
			if(temp.size() > count)//��^��r��A�p�G���פ�L�j�N��i���л\count�Mans
			{
				count = temp.size();
				ans[0] = temp;
			}
			temp = "0";
			
			/////��^��r��O���ƭ�///// 
			string temp2 = get(input , i, i+1);
			if(temp2.size() == count && count != 1)//�p�G�^��r����׻P�쥻���۵��A���@�ˤ]�s�i�h
			{
				ans[number] = temp2;
				number++;
			}
			if(temp2.size() > count)
			{
				count = temp2.size();
				ans[0] = temp2;
			}
			temp = "0";
			
			int max_length = input.size();
			if(count == max_length) break;
			
		}
		if(number == 1 && count >= 1)
		{
			cout << count << " " << ans[0] << endl;
		}
		else if(number > 1 && count >= 1)
		{
			cout << count << " " << ans[0];
			for(i=1; i<number; i++)
			{
				cout << ", " << ans[i];
			}
			cout << endl;
		}
		else if (count == 0)
		{
			cout << 0 << endl;
		}
		
		count = 0;	
		number = 1;
	}
	return 0;
} 
