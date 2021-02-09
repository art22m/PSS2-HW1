//
//  Homework 1
//
//  Created by Murashko A.M. on 09.02.2021
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**
 * Structure which contain variables and the array, which we will use
 */

struct Data {
    int numberOfWordsToFind = 0;
    string wholeText;
    vector <string> wordsToFind;
};

/**
 * Text contains into vector of vectors of strings.
 * Each nested vector contains strings with word or punctuation mark.
 * So, each nested vector contain whole sentence.
 *
 * @param wholeText
 * @return
 */

vector <vector<string>> breakIntoSentences (const string& wholeText) {
    string word;
    vector <vector<string>> arrayOfSentences(1);

    int index = 0;

    // If we see punctuation mark or space excluding end signs, then we add into vector the word and punctuation mark.
    // Else if  we see end signs, then we add into vector the word + end sign, change the nested vector (index += 1).
    // Else just build the word.

    for (char i : wholeText) {
        if (i == '.' || i == '!' || i == '?') {
            if (word != "")
                arrayOfSentences[index].push_back(word);
            arrayOfSentences[index].push_back(string(1, i));
            word = "";

            index++;
            arrayOfSentences.resize(index + 1);
        } else if (i == ',' || i == ';' || i == '-' || i == ' ') {
            if (word != "")
                arrayOfSentences[index].push_back(word);
            arrayOfSentences[index].push_back(string(1, i));
            word = "";
        } else {
            word += i;
        }
    }

    arrayOfSentences.pop_back();
    return arrayOfSentences;
}
/**
 * Void function which find the query word into the string with whole text and output sentences into file.
 *
 * @param arrayOfSentences
 * @param wordToFind
 * @param file
 */
void searchWordAndOutput (vector<vector<string>> arrayOfSentences, const string& wordToFind, ofstream &file) {
    vector <int> arrayWithIndexes;

    // Loop add into array the index of nested vector if it contain the query word.
    for (int indexOfSentence = 0; indexOfSentence < arrayOfSentences.size(); ++indexOfSentence) {
        for (int indexOfWord = 0; indexOfWord < arrayOfSentences[indexOfSentence].size(); ++indexOfWord) {
            if (arrayOfSentences[indexOfSentence][0] == " ") // Delete space in the beginning of each sentence
                arrayOfSentences[indexOfSentence].erase(arrayOfSentences[indexOfSentence].begin());

            if (arrayOfSentences[indexOfSentence][indexOfWord] == wordToFind) {
                arrayWithIndexes.push_back(indexOfSentence);
                break;
            }
        }
    }

    // Loop makes found words uppercase
    for (int id : arrayWithIndexes) {
        for (auto & wordInSentence : arrayOfSentences[id]) {
            if (wordInSentence == wordToFind) {
                for (char & letter : wordInSentence)
                    letter = toupper(letter);
            }
        }
    }

    // Output into file
    if (file.is_open()) {
        if (!arrayWithIndexes.empty()) {
            file << arrayWithIndexes.size() << endl;
            for (int id : arrayWithIndexes) {
                for (const auto &word : arrayOfSentences[id]) {
                    file << word;
                }
                file << endl;
            }
        } else {
            file << 0 << endl << "Word '" << wordToFind << "' was not found!" << endl;
        }
    } else {
        cout << "Unable to open the output file :(";
    }
}

/**
 * Input function. Here we create string, which will contain the whole text, excluding
 * number of words and query word.
 *
 * @param numberOfWordsToFind
 * @param wholeText
 * @param wordsToFind
 */
void input (int &numberOfWordsToFind, string &wholeText, vector <string> &wordsToFind) {
    string lineOfText;

    // Open input file. You can change the path into the quotes.
    ifstream file("../in.txt");

    // Input from file
    if (file.is_open()) {
        bool flag = false;

        while (getline(file, lineOfText)) {
            // If line don't contain dot or space, than it's the number of words we need to find.
            if (lineOfText.find('.') == string::npos && lineOfText.find(' ') == string::npos && !flag) {
                flag = true;
                numberOfWordsToFind = atoi(lineOfText.c_str());
            } else if (flag) { // If we entered the number of words, then we save the words we want to find.
                wordsToFind.push_back(lineOfText);
            } else { // Create the text.
                wholeText += lineOfText;
            }
        }
    } else {
        cout << "Unable to open the input file :(" << endl;
    }
    file.close();
}

int main() {
    Data data;

    input(data.numberOfWordsToFind, data.wholeText, data.wordsToFind);
    const vector <vector<string>> arrayOfSentences = breakIntoSentences(data.wholeText); // This vector contain text, divided by sentences.

    ofstream file("../out.txt"); // Open the output file. You can change the path into the quotes.
    for (const auto& wordToFind : data.wordsToFind)
        searchWordAndOutput(arrayOfSentences, wordToFind, file);
    file.close();

return 0;
}