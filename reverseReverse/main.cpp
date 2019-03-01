#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

void reverseString(vector<char>& s)
{
    int firstIndex = 0;
    int secondIndex = s.size()-1;
    while (firstIndex < secondIndex)
    {
        char temp = s[firstIndex];
        s[firstIndex] = s[secondIndex];
        s[secondIndex] = temp;
        firstIndex++;
        secondIndex--;
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
}

int main(int argc, const char * argv[]) {
    vector<char> input;
    input.push_back('h');
    input.push_back('e');
    input.push_back('l');
    input.push_back('l');
    input.push_back('o');
    reverseString(input);
    cout << "" << endl;
    return 0;
}
