#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int Guess;
int Total;

class Question {
private :
	string Question_Text;
	string  Answer_1;
	string Answer_2;
	string Answer_3;
	string Answer_4;
	int Correct_Answer;
	int Question_Score;

public:
	void setValues(string, string, string, string, string, int, int);
	void askQuestion();
};

int main_menu() {
	cout << "**Welcome to the Quiz Game!**" << endl;
	cout << endl;
	cout << "Please press enter to start a game..." << endl;
	cin.get();
	system("cls");
	cout << "Please enter your name" << endl;
	string Name;
	cout << "What is your name? ";
	getline(cin, Name);
	string Respond;
	cout << "Are you ready to take the Quiz " << Name << " ? Yes/No. " << endl;
	cout << "Your choice: ";
	cin >> Respond;
	if (Respond == "yes" || Respond == "Yes" || Respond == "YES") 
	{
		cout << endl;
		cout << "Good luck! " << endl;
		system("cls");
	}
	else
	{
		cout << "OK. Goodbye." << endl;
		return 0;
	}
}

int main() {
	main_menu();

	Question q1;
	Question q2;
	Question q3;
	Question q4;
	Question q5;
	Question q6;
	Question q7;
	Question q8;
	Question q9;
	Question q10;

    // Set the values for the questions
    // Question, Answer1, Answer2, Answer3, Answer4, CorrectAnswer, QuestionScore

	q1.setValues("Anna, Elsa Kristoff and Olaf are all characters in what animated movie?", "Frozen", "Cars", "Tangled", "Coco", 1, 10);
	
	q2.setValues("What actor plays Ken in the 2023 blockbuster movie Barbie?", "Ryan Gosling", "Brad Pitt", "Leonardo DiCaprio", "Tom Hanks", 1, 10);

	q3.setValues("What year did the comedy sketch TV show, Saturday Night Live, debut?", "1920", "1975", "2001", "2010", 2, 10);
	
	q4.setValues("What 1949 science fiction book by author George Orwell describes a dystopian world in the future?", "Moby Dick", "Harry Potter", "A Tale of Two Cities", "1984", 4, 10);
	
	q5.setValues("What's the name of the pig in the book Charlotte's Web?", "Charles", "Anthony", "Wilbur", "Kyle", 3, 10);

	q6.setValues("In one of the most popular Dr. Seuss books, what won't Sam-I-Am eat?", "Green eggs and ham", "Steak and potatoes", "Ham sandwhich", "Candy Canes", 1, 10);
	
	q7.setValues("What president was a licensed bartender?", "George Washington", "Barrack Obama", "Donald Trump", "Abraham Lincoln", 4, 10);

	q8.setValues("When was the first iPod released?", "1999", "2005", "2001", "1997", 3, 10);
	
	q9.setValues("What was the first state?", "Arizona", "Deleware", "Iowa", "Florida", 2, 10);
	
	q10.setValues("What U.S. state grows coffee beans?", "Idaho", "Iowa", "Florida", "Hawaii", 4, 10);


	q1.askQuestion();
	q2.askQuestion();
	q3.askQuestion();
	q4.askQuestion();
	q5.askQuestion();
	q6.askQuestion();
	q7.askQuestion();
	q8.askQuestion();
	q9.askQuestion();
	q10.askQuestion();

	system("cls");

	cout << "Your total score is " << Total << " points out of 100." << endl;

	if (Total >= 70)
	{
		cout << "You passed the quiz!" << endl;
		cout << "Thanks for playing!" << endl;

	}        //end of the game
	else
	{
		cout << "Sorry, you failed the quiz!" << endl;
		cout << "Do you want to try again ? Yes/No " << endl;
		string play_again;
		cout << "Your choice: ";
		cin >> play_again;
		if (play_again == "yes" || play_again == "Yes" || play_again == "YES")
		{
			main();
		}
		else
		{
			cout << "Thanks for playing!" << endl;
			return 0;
		}

	}                 

	system("pause");
	return 0;
}

void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int pa) 
{
	Question_Text = q;
	Answer_1 = a1;
	Answer_2 = a2;
	Answer_3 = a3;
	Answer_4 = a4;
	Correct_Answer = ca;
	Question_Score = pa;

}

void Question::askQuestion() {
	cout << endl;
	cout << Question_Text << endl;
	cout << "1. " << Answer_1 << endl;
	cout << "2. " << Answer_2 << endl;
	cout << "3. " << Answer_3 << endl;
	cout << "4. " << Answer_4 << endl;
	cout << endl;


	cout << "Answer: ";
	cin >> Guess;

	if (Guess == Correct_Answer) 
	{
		cout << endl;
		cout << "Great! You are Correct." << endl;
		Total += Question_Score;
		cout << "Score: " << Total << " so far out of 100!" << endl;
		
	}
	else
	{
		cout << endl;
		cout << "Incorrect answer." << endl;
		cout<<"Score: " << Total << " so far out of 100 !" << endl;
		cout << "The correct answer is " << Correct_Answer << endl;
		cout<<endl;
	}
}