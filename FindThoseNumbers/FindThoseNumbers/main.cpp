#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> answer;
    if(nums.size() == 0)
    {
        return answer;
    }
    vector<int>::iterator maxValue = max_element(nums.begin(), nums.end());
    for(int i = 0; i < *maxValue; i++)
    {
        answer.push_back(i+1);
    }
    for(int i = 0; i < nums.size(); i++)
    {
        answer.erase(remove(answer.begin(), answer.end(), nums[i]), answer.end());
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    vector<int> answer = findDisappearedNumbers(input);
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    cout << "Done" << endl;
    return 0;
}
