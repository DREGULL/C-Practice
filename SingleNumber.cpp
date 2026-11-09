// singleNumber(std::vector<int> arrNums) : returns the only not reapeted number
#include<iostream>
#include<vector>
#include<unordered_map>

int singleNumber(std::vector<int> arrNums){
    int len = arrNums.size() ;
    
    std::unordered_map<int,bool> singleNumCont;
    
    for(unsigned int i = 0 ; i < len ; i++ ){
        // if it's alredy in the U_Map it'll set the value to true
        if(!singleNumCont.contains(arrNums[i])){
            singleNumCont[arrNums[i]] = true;
        }else{
            singleNumCont[arrNums[i]] = false;
        }
    }
    
    int keyValue ;
    bool founded = false;
    for (const auto& pair : singleNumCont){
        if(pair.second == true){
            founded = true;
            keyValue = pair.first;
            return keyValue;
            break;
        }
    }
    return keyValue;
}

int main(){
    std::vector<int> a = {1, 1, 2, 4, 2, 4, 5, 5, 7, 3, 0, 10, 7 ,6 ,8 ,6 ,0 ,10 ,3};
    
    std::cout<<singleNumber(a);
}
