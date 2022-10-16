//Rich Davis
//Project 13
//Oct 16, 2022

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int correctAnswers = 0;
	int incorrectAnswers = 0;
	int iterator = 0;

	char answerKey[20] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
	char answersGiven[20];
	vector<int> answeredIncorrectly;

	cout << "Please enter the student's answers for each of the questions." << endl;
	cout << "Press Enter after typing each answer." << endl;
	cout << "Please enter only an A, B, C, or D for each question." << endl;

	for (int i = 0; i < 20; i++) {
		char answer;

		inputFailed:
		cout << "Question " << i + 1 << ": ";
		cin >> answer;
		answersGiven[i] = toupper(answer);
		if (answersGiven[i] != 'A' && answersGiven[i] != 'B' && answersGiven[i] != 'C' && answersGiven[i] != 'D') { 
			cout << "Enter a valid response." << endl;
			goto inputFailed;
		}

		if (answersGiven[i] == answerKey[i]) {
			correctAnswers += 1;
		}
		else {
			incorrectAnswers += 1;
			answeredIncorrectly.push_back(i+1);
		}
	}

	if (incorrectAnswers > 5) {
		cout << "\n\nThe student has failed the exam." << endl;
	}
	else {
		cout << "\n\nThe student has passed the exam." << endl;
	}
	cout << "\nCorrect Answers: " << correctAnswers << endl;
	cout << "Incorrect Answers: " << incorrectAnswers << endl;

	cout << "\nQuestions that were answered incorrectly:" << endl;
	for (int i = 0; i < answeredIncorrectly.size(); i++) {
		if (i > 0) {
			cout << ", ";
		}
		cout << answeredIncorrectly[i];		
	}


	return 0;
}