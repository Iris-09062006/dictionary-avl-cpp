#include"struct.h"
using namespace std;
// hàn lấy chiều cao của 1 node
int getHeight(Node* root);
// hàm tính hệ số cân bằng
int balanceFactor(Node* root);
// hàm xoay trái
Node* leftRotation(Node* root);
// hàm xoay phải
Node* rightRotation(Node* root);
// hàm them vào cây Avl
Node* InsertToAvlDic(Node* root, Word word);
 // hàm tìm kiếm
Node* Search(Node* root, string word);
// hàm tìm Node nhỏ nhất bên trái
Node* FindMinNode(Node* root);
// hàm xóa node
Node* deleteWord(Node* root, Word word);
// tạo từ điển 
Node* BuildAvlFromVector(vector<Word>& dictionary);
// đọc file 
vector<Word> AddWordToDictonary(string fileName);
// lưu dictionary 
void saveInOrder(Node* root, ofstream& fout);
void saveDictionaryToFile(Node* root, string& fileName);