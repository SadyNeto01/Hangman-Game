#include <iostream>
#include <vector>

using namespace std;

int main() {
    //creating variables
    int length, chances, correct_guesses;
    bool correct_guess;

    chances = 6;
    correct_guesses = 0;
    correct_guess = false;

    cout << "Introduce the amount of letters that your password has: ";
    cin >> length;

    string password;
    cout << "\nIntroduce your word: \n";
    cin >> password;
    // Dinamic vector created to store the letters that were already typed by the user
    vector<char> guessed_letters;
    /*Main loop of the game, the game only will leave this loop if the player
    don't have anymore chances(chances=0) or the number of correct guesses is =length
    */
    while (chances > 0 && correct_guesses < length) {
        cout << "\nYou still have " << chances << " chances remaining to discover the password\n";
        cout << "\nSecret password: \n";
        //loop through each position of the password
        for (int i = 0; i < length; i++) {
            bool found = false;
            // Loop through each character 'c' in the vector 'guessed_letters'.
            for (char& c : guessed_letters) {
                if (c == password[i]) {
                    cout << c;
                    found = true;
                    break;
                }
            }
            //if there's no letter correspondent in the vector
            if (!found) {
                cout << '-';
            }
        }
        cout << "\nLetters guessed so far: ";
        for (char& c : guessed_letters) {
            cout << c << " ";
        }
        cout << "\nInform a letter that you would like to try: \n";

        char letter;
        cin >> letter;

        // Check if the letter was already guessed
        bool already_guessed = false;
        for (char& c : guessed_letters) {
            if (c == letter) {
                already_guessed = true;
                break;
            }
        }

        if (already_guessed) {
            cout << "You already tried that letter. Try a different one.\n";
            continue; 
        }
        
// Add the letter to the already guessed vector
        guessed_letters.push_back(letter); 

        correct_guess = false;
        for (int i = 0; i < length; i++) {
            if (letter == password[i]) {
                correct_guess = true;
                correct_guesses++;
            }
        }

        if (!correct_guess) {
            chances--;
        }
    }

    if (chances == 0) {
        cout << "You couldn't guess the password :/\n";
    } else {
        cout << "Congratulations, you are almost a hacker :p\n";
    }

    return 0;
}
