#include <bits/stdc++.h>
using namespace std;

// Q3(100 marks)- You are given an array (length <= 105) of 0’s and 1’s. Is it possible to split array into 3 parts such that decimal value of all 3 parts is same? If possible, return the decimal value else return -1.

// Solution - Count number of 1s. If 0, return 0. If not divisible by 3, return -1. Else divide by 3 and find the value: if you iterate from the back of given array, you can figure out the number of trailing zeros in the last split, say tz. Now you know the required number of 1s in each split and the number of trailing zeros as soon as you hit the last 1 of any split while scanning from left to right. Store the splits in vectors and remove leading zeros and compare - v1 != v2 or v2 != v3 then return -1. Else you already have the vector and you can report the desired value.

int main() {
	string s = "010100101001010";
	
	int one = count(s.begin(), s.end(), '1');
	int n = s.size();
	
	if( one%3 !=0 ){
	    cout << -1 << "\n";
	}else{
	    int req = one/3,  i = n-1;
	    
	    while(s[i] != '1'){
	        i--;
	    }
	    
	    int trail = n - i -1;
	    int temp = 0, z = 0;
	    int j =0;
	    
	    for(j=0; j<n; j++){
	        if(s[j] == '1') temp++;
	        if(temp == req){
	            if(s[j] == '0') z++;
	            if(z == trail) break;
	        }
	    }
	    
	    int temp2 = 0, z2 = 0;
	    int k =0;
	    
	    for(k=j+1; k<n; k++){
	        if(s[k] == '1') temp2++;
	        if(temp2 == req){
	            if(s[k] == '0') z2++;
	            if(z2 == trail) break;
	        }
	    }
	   
	    bool br = false;
	    if( k-j == 1 or j >= n-1 or k >= n-1) {
	        cout << -1 << "\n";
	        br = true;
	    }
	    
	    if(!br){
	       	string first = s.substr(0, j+1);
    	    string sec = s.substr(j+1, k-j);
    	    string third = s.substr(k+1, n-k);
    	    
    	    
    	    cout << first << " " <<"first"  <<"\n";
    	    cout << sec << " " << "sec" << "\n"; 
    	    cout << third << " " << "third" << "\n"; 
	    }
	    

	    
	}

	return 0;
}
