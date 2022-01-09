/*
Question: Take String input from the User and find the longest palindromic in String(use concept of subString). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//function to find the longest palindrome string
void palindrome(char s[]) {
	int i,left, right, beg=0, end=1;
	
	for(i=1;i<strlen(s);i++){
		left=i-1;
		right=i;
		
		while(s[left]==s[right] && left>=0 && right<strlen(s)){ //check for even sized palindrome substring
			if(right - left + 1 > end){
				beg = left;
				end = right - left + 1; 
			}
			left--;
			right++;
		}
		
		left=i-1;
		right=i+1;
		
		while(s[left]==s[right] && left>=0 && right<strlen(s)){ //check for odd sized palindrome substring
			if(right - left + 1 > end){
				beg = left;
				end = right - left + 1; 
			}
			left--;
			right++;
		}
	}
	
	printf("\nPalindrome String: ");
	for(i=beg;i<=beg+end-1;i++){
		printf("%c",s[i]);	
	}	
}

//main function
int main(){
	char str[MAX];
	
	printf("\nImplementing program to print the longest palindromic string.");
	printf("\n---------------------------------------------------------------");
	printf("\nEnter the string:\n");
	fgets(str, MAX, stdin);
	
	if(strlen(str)<2){
		printf("Palindrome String: %s",str);
		exit(0);
	}
	else{
		palindrome(str);
	}
	return 0;
}

