
#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>

bool validAnagram(std::string s,std::string t) {
	std::unordered_map<char,int> contMap;
	int lenS = s.size();

	if(lenS != t.size()) return false;

	for(int i = 0; i < lenS ; i++) {
		if(!contMap.count(s[i]) <= 0 ) {
			contMap[s[i]] += 1;
		} else {
			contMap[s[i]] = 1;
		}
	}
    
	for(const auto& pair : contMap) {
		int counter = 0;
		for(int i = 0 ; i < lenS ; i++) {
			if(t[i] == pair.first) counter++;
		}
		if(counter != pair.second) return false;
	}
	return true;

}

int main() {
	std::cout<<validAnagram("nagaram","anagram");
}