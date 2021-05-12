#include <iostream>
#include <string>
using namespace std;
string get(string& str, int a, int b)
{
	string res;
	while(a>=0 && b<str.size() && str[a]==str[b])//s[a] == s[b]是用來判斷左右的兩個位元裡的東西是否相等
	{
		res=str.substr(a,b-a+1);
		a--;
		b++;
	}
	return res;
}


int main()
{
	//////////只輸出最長回文字串，若最長字串不只一個，那這幾個都要print出來//////////
	string input, ans[1000];//輸入與輸出是字串
	int count = 0;//計算最長回文字串的長度，若回文字串的長度為1或0則輸出0
	int number = 1;//計算回文字串的數量 
	int i;
	while(cin >> input)
	{
		/*
		if(input.size()==0 || input.size()==1)
		{
			cout << count << endl;//如果長度為0或1 直接不運算
			continue;//直接繼續下一筆測資
		}
		*/
		
		for(i=0; i<input.size(); i++)
		{
			/////當回文字串是奇數個/////
			string temp = get(input , i, i);
			if(temp.size() == count && count != 1)//如果回文字串長度與原本的相等，那一樣也存進去
			{
				ans[number] = temp;
				number++;
			}
			if(temp.size() > count)//找回文字串，如果長度比他大就丟進來覆蓋count和ans
			{
				count = temp.size();
				ans[0] = temp;
			}
			temp = "0";
			
			/////當回文字串是偶數個///// 
			string temp2 = get(input , i, i+1);
			if(temp2.size() == count && count != 1)//如果回文字串長度與原本的相等，那一樣也存進去
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
