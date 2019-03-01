#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


string reverseWords(string s) {
    string answer = "";
    string temp = "";
    bool first = true;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if(first == true)
            {
                answer = temp + answer;
                first = false;
            }
            else
            {
                answer = temp + ' ' + answer;
            }
            temp = "";
        }
        else
        {
            temp = temp + s[i];
        }
    }
    answer = temp + ' ' + answer;
    if(answer[answer.length()-1] == ' ')
    {
        answer.erase(answer.length()-1);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    string input = "Tyson is the best";
    string answer = reverseWords(input);
    cout << answer << endl;
    return 0;
}
