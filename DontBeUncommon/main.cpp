#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


vector<string> uncommonInThoseSentences(string A, string B) {
    vector<string> answer;
    vector<string> vectorA;
    vector<string> vectorB;
    bool foundSpace = false;
    string word = "";

    for(int i = 0; i < A.length(); i++)
    {
        if(A[i] == ' ')
        {
            foundSpace = true;
            vectorA.push_back(word);
            word = "";
        }
        else if(A[i+1] == NULL)
        {
            word = word + A[i];
            vectorA.push_back(word);
            word = "";
        }
        else
        {
            word = word + A[i];
        }
    }

    for(int i = 0; i < B.length(); i++)
    {
        if(B[i] == ' ')
        {
            foundSpace = true;
            vectorB.push_back(word);
            word = "";
        }
        else if(B[i+1] == NULL)
        {
            word = word + B[i];
            vectorB.push_back(word);
        }
        else
        {
            word = word + B[i];
        }
    }

    sort(vectorA.begin(), vectorA.end());
    sort(vectorB.begin(), vectorB.end());

    for(int i = 0; i < vectorA.size(); i++)
    {
        for(int j = i+1; j < vectorA.size(); j++)
        {
            if(vectorA[i] == vectorA[j])
            {
                for(int z = 0; z < vectorB.size(); z++)
                {
                    vectorB.erase(remove(vectorB.begin(), vectorB.end(), vectorA[i]), vectorB.end());
                }
                vectorA.erase(remove(vectorA.begin(), vectorA.end(), vectorA[i]), vectorA.end());
                break;
            }
        }
    }

    for(int i = 0; i < vectorB.size(); i++)
    {
        for(int j = i+1; j < vectorB.size(); j++)
        {
            if(vectorB[i] == vectorB[j])
            {
                for(int z = 0; z < vectorA.size(); z++)
                {
                    vectorA.erase(remove(vectorA.begin(), vectorA.end(), vectorB[i]), vectorA.end());
                }
                vectorB.erase(remove(vectorB.begin(), vectorB.end(), vectorB[i]), vectorB.end());
                break;
            }
        }
    }

    vector<string> eraseVectorA;
    vector<string> eraseVectorB;
    for(int i = 0; i < vectorA.size(); i++)
    {
        for(int j = 0; j < vectorB.size(); j++)
        {
            if(vectorA[i] == vectorB[j])
            {
                eraseVectorA.push_back(vectorA[i]);
                eraseVectorB.push_back(vectorB[j]);
                break;
            }
        }
    }

    for(int i = 0; i < eraseVectorA.size(); i++)
    {
        vectorA.erase(remove(vectorA.begin(), vectorA.end(), eraseVectorA[i]), vectorA.end());
    }
    for(int i = 0; i < eraseVectorB.size(); i++)
    {
        vectorB.erase(remove(vectorB.begin(), vectorB.end(), eraseVectorB[i]), vectorB.end());
    }

    for(int i = 0; i < vectorA.size(); i++)
    {
        answer.push_back(vectorA[i]);
    }
    for(int i = 0; i < vectorB.size(); i++)
    {
        answer.push_back(vectorB[i]);
    }

    return answer;
}


int main(int argc, const char * argv[]) {
//    string A = "apple apple";
//    string B = "banana";
    string A = "s z z z s";
    string B = "s z ejt";
    vector<string> answer = uncommonInThoseSentences(A, B);
    cout << "Answer: " << endl;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    cout << "Done" << endl;
    return 0;
}
