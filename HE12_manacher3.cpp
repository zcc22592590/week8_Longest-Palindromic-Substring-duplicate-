#include <iostream>
#include <string>
using namespace std;
string get(string& s, string& ss, int n)
{
	int *p = new int[n];//i���̥��P�̥k�Z���٬��b�| = p[i]
    int mr = 0, mp = 0, maxr = 0, maxp = 0;//mr=maxRight 
    for (int i = 0; i < n; ++i) {
        if (i < mr) {//�p�Gi�bmr������A�hi�@�w�bmp�Mmp+mr-1�����A��i�Hmp������Ij=2 mp - i�w�g�p��L�A�ҥHp[i]�����qp[j]�}�l�p��F
            //p[mirror]=p[2*mp-i] ��mp=center 
            p[i] = min(p[2*mp - i], mr - i);//�p�Gmr - i < p[j]�h�ݭn���̤p�ȡA�]���W�L�������٨S�p��L�C
        } else p[i] = 1;//�ĤG��i�bmr���k��A�hp[i]�q1�}�l�p��A�o�˴N�i�H�q�Lo(n)�o��Ʋ�p
            
        while (i - p[i] >= 0 && i + p[i] < n && ss[i - p[i]] == ss[i + p[i]]) ++ p[i];//�����X���k 
        if (i + p[i] - 1 > mr) {
            mr = i + p[i] - 1;
            mp = i;
        }
        if (mr - mp + 1> maxr) {//�w�q2�Ӧr�q�O�s�̤j�^��ꪺ�b�|maxr�M�����Imaxp
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
		//////////�N�r�ꪺ�r�������[�W#�o�ӲŸ�//////////
        string ss = "#";
        for (int i = 0; i < n; ++i) {
            ss += s[i];
            ss += "#";
        }
        n = ss.size();//��s�r�ꪺ����(���׬�2n+1�B�@�w�O�_��) 

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
