#include "../include/avl_tree.h"
#include "../include/speak.h"
int main() {
    string fileName = "../data/extended_dictionary.txt";
    vector<Word> Dictionary = AddWordToDictonary(fileName);
    Node* root = NULL;
    int choice;
    do {
        cout << "\n--- AVL Dictionary Menu ---\n";
        cout << "0. Create a dictionary from file\n";
        cout << "1. Add a word\n";
        cout << "2. Search for a word\n";
        cout << "3. Delete a word\n";
        cout << "4. Speak a word\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:{
                root = BuildAvlFromVector(Dictionary);
                break;
            }
            case 1: {
                Word newWord;
                cout << "Enter English word: ";
                cin >> newWord.english;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, newWord.mean);
                root = InsertToAvlDic(root, newWord);
                saveDictionaryToFile(root, fileName); 
                cout << "Word added successfully!\n";
                break;
            }
            case 2: {
                string searchWord;
                cout << "Enter the word to search: ";
                cin >> searchWord;
                Node* result = Search(root, searchWord);
                if (result) {
                    cout << "Found: " << result->word.english << " - " << result->word.mean << endl;
                } else {
                    cout << "Word not found in the dictionary.\n";
                }
                break;
            }
            case 3: {
                string deleteWordStr;
                cout << "Enter the word to delete: ";
                cin >> deleteWordStr;
                Word deleteWordObj = {deleteWordStr, ""};
                root = deleteWord(root, deleteWordObj);
                saveDictionaryToFile(root, fileName); 
                cout << "Word deleted successfully (if it existed).\n";
                break;
            }
            case 4: {
                string speakWord;
                cout << "Enter the word to speak: ";
                cin >> speakWord;
                speak(speakWord);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}


