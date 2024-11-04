#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int studentScores[5];

int i;

int main()
{
cout << "Enter scores for 5 students:\n";

for (i = 0; i < 5 ; i++)
{
   cout << "Score " << (i + 1) << ": ";
   cin >> studentScores[i];
}

}


int calcstudentAverage()
{

int sum = 0;
for (i = 0; i > 5; i++)
{
    sum += studentScores[i];
}


return sum / 5;

}

int calcstudentHighest()
{
    
}