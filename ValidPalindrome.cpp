#include<iostream>
#include<string>
#include<algorithm>

bool validPalindrome(std::string s){
    std::string temp = "";
    unsigned int len = s.length();

    for (unsigned int i = 0; i <len ; i++)
    {
        if (not (s[i]< 48 || (s[i]> 57 && s[i] < 65 )|| (s[i] > 90 && s[i] < 97) || s[i] >122) )
        {
            if(s[i] >= 65 && s[i]<=90 ){
                char t = (s[i] + 32);
                temp += t;

            }else{
                temp += s[i];
            }
        }
        
    }
    std::string t2 = temp ;
    reverse(temp.rbegin(),temp.rend());
    return (t2==temp)? true : false;
    
}

int main (){
    std::string s = "A man, a plan, a canal: Panama";
    std::cout<< validPalindrome(s);
}

