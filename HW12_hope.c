#include <stdio.h>
int main(){
	char str[100000];
	int i;
	int tmp1, tmp2;
	int count = 0;
	int num[1000];
	int tmp_l, max_l;
	while(scanf("%s", str)){
		int lens = strlen(str);
		int max_l = 0;
		int l_odd, l_even;
		for(i=1; i<lens; i++){
			///odd///
			tmp1 = 1;
			while((i-tmp1)>=0 && (i+tmp1)<lens && str[i-tmp1]==str[i+tmp1]) tmp1++;
			l_odd = 2 * tmp1 - 1;
			///even///
			tmp2 = 1;
			while((i-tmp2)>=0 && (i+tmp2-1)<lens && str[i-tmp2]==str[i+tmp2-1]) tmp2++;
			l_even = 2 * tmp2 - 2;
			
			if(l_odd > l_even){
				tmp_l = l_odd;
			}else{
				tmp_l = l_even;
			}
			if(tmp_l > max_l){
				max_l = tmp_l;
				if(l_odd == max_l){
					num[0] = i - tmp1 + 1;
				}else{
					num[0] = i - tmp2 + 1;
				}
				count = 1;
				continue;
			}
			if(tmp_l == max_l){
				if(l_odd == tmp_l){
					num[count] = i - tmp1 + 1;
				}else{
					num[count] = i - tmp2 + 1;
				}
				count++;
			}
			if((max_l/2) > (lens-i)) break;
		}
		if(max_l == 1){
			printf("0\n");
			continue;
		}else{
			printf("%d", max_l);
		}
		for(i=0; i<count; i++){
			int k = num[i];
			int j;
			if(i == 0){
				printf(" ");
				for(j=k; j<(k+max_l); j++){
					printf("%c", str[j]);
				}
			}else{
				printf(", ");
				for(j=k; j<(k+max_l); j++){
					printf("%c", str[j]);
				}
			}
		}
		printf("\n");
	}
} 
