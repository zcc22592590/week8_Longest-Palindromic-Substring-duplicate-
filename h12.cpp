#include<iostream>
using namespace std;

int main(void){
    string input,ans;
    int max_length,i,j,k;
    while(cin>>input){
        max_length=1;
        for(i=0;i<input.length();++i){
            j=k=i;
            while(input[j+1]==input[k]){
                j++;
                i++;
            }
            while(k-1>=0&&j+1<input.length()&&input[j+1]==input[k-1]){
                k--;
                j++;
            }
            if(j-k+1>max_length){
                max_length=j-k+1;
                ans=input.substr(k,max_length);
            }
            else if(j-k+1==max_length){
                ans+=',';
                ans+=' ';
                ans+=input.substr(k,max_length);
            }
        }
        if(max_length==1){
            cout<<'0'<<endl;
        }
        else{
            cout<<max_length<<' '<<ans<<endl;
        }
    }
}
