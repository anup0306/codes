#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    //Enter input file name
    string path;
    cout << "Enter Input File Path" << endl;
    cin >> path;

    ifstream in;    
    in.open(path);
    string st;
    
    int count=0;
    while (getline(in,st))
    {
       count++;
    }
    in.close();
    in.open(path);
    float arr[count][2];
    int i=0,j=0;
    while (in>> arr[i][j])
    {
        if(j == 1)
        {
            i++;
            j=0;
        }
        else
            j++;
    }
    in.close();
    vector<pair<float,float>> vecto;
    for (int i = 0; i < count; i++)
    {
        vecto.push_back(make_pair(sqrt(((arr[i][0] * arr[i][0]) + (arr[i][1] * arr[i][1]))), i));
    }
    sort(vecto.begin(),vecto.end());


     // Enter outputfile name
    cout << endl;
    cout << "Enter Output File Path" << endl;
    string outputPath;
    cin >> outputPath;
    

     // storing  results 
    ofstream outputFile(outputPath);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            outputFile << arr[(int)vecto[i].second][j] << " ";
        }
        outputFile << "\t\t" << vecto[i].first;
        outputFile << endl;
    }
    
    return 0;
}