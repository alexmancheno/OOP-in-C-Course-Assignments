//Mancheno, Alex
//CS 211 - Lab section 52B
//Hw # 4
#include <iostream>
#include <algorithm>
using namespace std;

bool raceIsValid(string result) {
    //returns false if there have been no results entered:
    if (result.empty())
        return false;
    sort(result.begin(), result.end());
    int biggestTeam = 0;
    //this nested for-loop is to find the team with the highest number of runners, which I use to create the substrings below:
    for (int i = 0; i < result.length(); i++) {
        int runnersOnThisTeam = 0;
        for (int j = i; result[i] == result[j]; j++) {
            runnersOnThisTeam++;
        }
        if (runnersOnThisTeam > biggestTeam) biggestTeam = runnersOnThisTeam;
    }
    string copy;
    //nested for-loop returns false if there is any substring with more than one unique letter (or member from another team):
    for (int i = 0; i < result.length() / biggestTeam; i++) {
        copy = result.substr(i * biggestTeam, result.length());
        for (int j = 0; j < biggestTeam; j++) {
            if (copy[0] != copy[j]) return false;
        }
    }
    //this has the method return false if there is an uneven distribution of runners per team:
    if (copy.length() > biggestTeam) return false;
    return true;
}

//helper method; returns the number of teams in the race results (assuming race results are valid):
int numOfTeams(string result) {
    int numOfTeams = 0;
    sort(result.begin(), result.end());
    for (int i = 0; i < result.length(); i++) {
        if (result[i] != result[i + 1])
            numOfTeams++;
    }
    return numOfTeams;
}

//helper method; returns the number of runners per team (assuming race results are valid):
int runnersPerTeam(string result) {
    int runners = 0;
    sort(result.begin(), result.end());
    for (int i = 0; result[0] == result[i]; i++)
        runners++;
    return runners;
}

//helper method; returns the name of the race is winning team (assuming race is valid):
char winningTeam(int results[], int size) {
    int winner;
    //to find index of first non-zero value:
    for (int i = 0; i < size; i++) {
        if (results[i] > 0) {
            winner = i;
            break;
        }
    }
    //to compare first non-zero value with every other non-zero value to find index of lowest non-zero value:
    for (int i = 0; i < size; i++) {
        if ((results[winner] > results[i]) && (results[i] > 0))
            winner = i;
    }
    return winner + 65;
}

//helper method; returns the races winning score (assuming race is valid):
double winningScore(int results[], int size, int numOfRunners) {
    int lowestScore;
    //to find first non-zero value:
    for (int i = 0; i < size; i++) {
        if (results[i] > 0) {
            lowestScore = results[i];
            break;
        }
    }
    //to find lowest non-zero value:
    for (int i = 0; i < size; i++) {
        if ((lowestScore > results[i]) && (results[i] > 0)) {
            lowestScore = results[i];
        }
    }
    return ((double) lowestScore / numOfRunners);
}

int main() {
    string result = "";
    string competitor = "";
    cout << "Enter the results of the race: ";
//following while-loop gets the race results from the user until race results are valid:    
retest:
    cin >> competitor;
    while (true) {
        if (competitor == "done") {
            if (raceIsValid(result)) break;
            else {
                cout << "Results are not valid!" << endl;
                goto retest;
            }
        } else result += competitor;
        cin >> competitor;
    }
    //array for storing race results:
    int raceResults[26] = {0};
    //one race results are valid, this for-loop will enter race results into the 'raceResults' array:
    for (int i = 0; i < result.length(); i++) {
        int runner = (int) result[i] - 97;
        raceResults[runner] += (i + 1);
    }
    cout << "There are " << numOfTeams(result) << " teams." << endl << endl;
    cout << "Each team has " << runnersPerTeam(result) << " runners." << endl << endl;
    cout << "Team  Score" << endl;
    //this for-loop prints the team names and scores of every team who participated in the race:
    for (int i = 0; i < 26; i++) {
        if (raceResults[i] != 0) {
            char team = i + 65;
            cout << team << "     " << (double) raceResults[i] / runnersPerTeam(result) << endl;
        }
    }
    cout << endl;
    cout << "The winning team is team " << winningTeam(raceResults, 26)
            << " with a score of " << winningScore(raceResults, 26, runnersPerTeam(result));
}