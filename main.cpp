#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Запускаем генератор случайных чисел
    int playerNumber; // Число, выбранное игроком
    int minRange = 1; // Минимальное значение диапазона
    int maxRange = 100; // Максимальное значение диапазона
    int computerGuess = 0;
    int tries = 0;

    cout << "\tWelcome to Guess My Number (Computer Edition)\n\n";
    cout << "Think of a number between " << minRange << " and " << maxRange << "." << endl;
    cout << "Let the computer guess it!\n\n";

    cout << "Enter the number you're thinking of: ";
    cin >> playerNumber;

    while (computerGuess != playerNumber) {
        computerGuess = rand() % (maxRange - minRange + 1) + minRange;
        ++tries;

        cout << "Computer's guess: " << computerGuess << endl;

        if (computerGuess > playerNumber) {
            cout << "Too high!\n\n";
            maxRange = computerGuess - 1;
        }
        else if (computerGuess < playerNumber) {
            cout << "Too low!\n\n";
            minRange = computerGuess + 1;
        }
        else {
            cout << "\nComputer guessed it in " << tries << " tries!\n";
        }
    }

    system("pause");
    return 0;
