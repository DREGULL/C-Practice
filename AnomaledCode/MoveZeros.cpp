//This code was written using raw pointers; however, when I showed it to Gemini
//it told me that this is not the preferred approach, even though it works perfectly correctly.
#include<iostream>
#include<vector>

std::vector<int> moveZeros(std::vector<int> nums){
    int len = nums.size();
    if(len <= 1){
        return nums;
    }
    
    int PtValueTemp;
    int *PtO;
    int *PtT;
    int *nextToPtO;
    
    bool seted = false;
    
    for(int i = 0 ; i < len ; i++){
        if(!seted){
            if(nums[i] == 0 ){
                PtO = &nums[i];
                if(i < len - 1)PtT = &nums[i + 1];
                seted = true;
                continue;
            }
        }
        else{
            if(*PtT != 0){
                PtValueTemp = *PtT; 
                *PtT = *PtO;
                *PtO = PtValueTemp;
                PtO++;
                PtT = (i + 1 < len ) ? &nums[i+1] : PtT;
            }else{
               PtT = (i + 1 < len ) ? &nums[i+1] : PtT;
            }
        }
    }
  
    return nums;
    
}

int main (){
    std::vector<int> nums = {5, 2, 0};
    nums = moveZeros(nums);
    for(int i = 0 ; i < nums.size() ; i ++){
        std::cout<<nums[i]<<" ";
        
    }
}

