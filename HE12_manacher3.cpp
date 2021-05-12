#include <iostream>
#include <string>
using namespace std;
string get(string& s, string& ss, int n)
{
	int *p = new int[n];//i的最左與最右距離稱為半徑 = p[i]
    int mr = 0, mp = 0, maxr = 0, maxp = 0;//mr=maxRight 
    for (int i = 0; i < n; ++i) {
        if (i < mr) {//如果i在mr的左邊，則i一定在mp和mp+mr-1之間，而i以mp的對稱點j=2 mp - i已經計算過，所以p[i]直接從p[j]開始計算；
            //p[mirror]=p[2*mp-i] 而mp=center 
            p[i] = min(p[2*mp - i], mr - i);//如果mr - i < p[j]則需要取最小值，因為超過的部分還沒計算過。
        } else p[i] = 1;//第二種i在mr的右邊，則p[i]從1開始計算，這樣就可以通過o(n)得到數組p
            
        while (i - p[i] >= 0 && i + p[i] < n && ss[i - p[i]] == ss[i + p[i]]) ++ p[i];//中心擴散法 
        if (i + p[i] - 1 > mr) {
            mr = i + p[i] - 1;
            mp = i;
        }
        if (mr - mp + 1> maxr) {//定義2個字段保存最大回文串的半徑maxr和中心點maxp
            maxr = mr - mp + 1;
            maxp = i;
        }
    }
    string ans = s.substr((maxp - maxr + 1) / 2, p[maxp] - 1);
	return ans;
}


int main()
{
	string s, others[1000];; 
	int count=0;
	while(cin >> s)
	{
		int n = s.size();
		//////////將字串的字元之間加上#這個符號//////////
        string ss = "#";
        for (int i = 0; i < n; ++i) {
            ss += s[i];
            ss += "#";
        }
        n = ss.size();//更新字串的長度(長度為2n+1且一定是奇數) 

        string ans;
        ans = get(s, ss, n);
		count = ans.size();
		if(count <= 1){
			cout << "0\n";
		}else{
			cout << count << " ";  
        	cout << ans << endl;
		}

        count = 0;
	}
}
