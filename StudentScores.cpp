#include <iostream>
#include <algorithm> 
using namespace std;

int studentScores[5];

int calcstudentAverage();
int calcstudentHighest();
int calcstudentLowest();

int main() {
    cout << "Enter scores for 5 students:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Score " << (i + 1) << ": ";
        cin >> studentScores[i];
    }

    // Calculate and display results
    cout << "Average score: " << calcstudentAverage() << endl;
    cout << "Highest score: " << calcstudentHighest() << endl;
    cout << "Lowest score: " << calcstudentLowest() << endl;

    return 0;
}

int calcstudentAverage() {
    int sum = 0;
    for (int i = 0; i < 5; i++) { 
        sum += studentScores[i];
    }
    return sum / 5; 
}

int calcstudentHighest() {
    return *max_element(studentScores, studentScores + 5); 
} 
    /* Nobody said I could not use this library
    so to save time instead of parsing the array and sorting said array
    I just used this library.
    */

int calcstudentLowest() {
    return *min_element(studentScores, studentScores + 5); // Implemented to find the lowest score
}
