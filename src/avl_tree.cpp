#include"../include/avl_tree.h"
// hàn lấy chiều cao của 1 node
int getHeight(Node* root){
    if(root == NULL) return 0;
    return 1 + max(getHeight(root->pLeft), getHeight(root->pRight));
}
// hàm tính hệ số cân bằng
int balanceFactor(Node* root){
    return getHeight(root->pLeft) - getHeight(root->pRight); 
}
// hàm xoay trái
Node* leftRotation(Node* root){
    Node* root2 = root->pRight;
    Node* tmp = root2->pLeft;
    root2->pLeft = root;
    root->pRight = tmp;
    return root2;
}
// hàm xoay phải
Node* rightRotation(Node* root){
    Node* root2 = root->pLeft;
    Node* tmp = root2->pRight;
    root2->pRight = root;
    root->pLeft = tmp;
    return root2;
}
// hàm them vào cây Avl
Node* InsertToAvlDic(Node* root, Word word){
    if(root == NULL) return new Node(word);
    if(root->word.english > word.english){
        root->pLeft = InsertToAvlDic(root->pLeft, word);
    }
    else{
        root->pRight = InsertToAvlDic(root->pRight, word);
    }
    int balance = balanceFactor(root);
    if(balance > 1 && root->pLeft->word.english > word.english){
        return rightRotation(root);
    }
    else if(balance > 1 && root->pLeft->word.english < word.english){
        root->pLeft = leftRotation(root->pLeft);
        return rightRotation(root);
    }
    else if(balance < -1 && root->pRight->word.english < word.english){
        return leftRotation(root);
    }
    else if(balance < -1 && root->pRight->word.english > word.english){
        root->pRight = rightRotation(root->pRight);
        return leftRotation(root);
    }
    return root;
 }
 // hàm tìm kiếm
Node* Search(Node* root, string word){
    if(root == NULL) return NULL;
    if(root->word.english > word){
        return Search(root->pLeft, word);
    }
    else if(root->word.english < word){
        return Search(root->pRight, word);
    }
    else{
        return root;
    }
}
// hàm tìm Node nhỏ nhất bên trái
Node* FindMinNode(Node* root){
    if(root->pLeft == NULL) return root;
    return FindMinNode(root->pLeft);
}
// hàm xóa node
Node* deleteWord(Node* root, Word word){
    if(root == NULL) return root;
    if(root->word.english > word.english){
        root->pLeft = deleteWord(root->pLeft, word);
    }
    else if(root->word.english < word.english){
        root->pRight = deleteWord(root->pRight, word);
    }
    else{
        if(root->pLeft == NULL){
            Node* tmp = root->pRight;
            delete root;
            return tmp;
        }
        else if(root->pRight == NULL){
            Node* tmp = root->pLeft;
            delete root;
            return tmp;
        }
        else{
            Node* tmp = FindMinNode(root->pRight);
            root->word = tmp->word;
            root->pRight = deleteWord(root->pRight, tmp->word);
        }
    }
    int balance = balanceFactor(root);
    if(balance > 1 && balanceFactor(root->pLeft) >= 0){
        return rightRotation(root);
    }
    else if(balance > 1 && balanceFactor(root->pLeft) < 0){
        root->pLeft = leftRotation(root->pLeft);
        return rightRotation(root);
    }
    else if(balance < -1 && balanceFactor(root->pRight) <= 0){
        return leftRotation(root);
    }
    else if(balance < -1 && balanceFactor(root->pRight) > 0){
        root->pRight = rightRotation(root->pRight);
        return leftRotation(root);
    }
    return root;
}
Node* BuildAvlFromVector(vector<Word>& dictionary) {
    Node* root = NULL;
    for (const Word& w : dictionary) {
        root = InsertToAvlDic(root, w);
    }
    return root;
}
// đọc file 
vector<Word> AddWordToDictonary(string fileName){
    ifstream Fin(fileName);
    if (!Fin.is_open()) {
        cerr << "❌ Không thể mở file: " << fileName << endl;
        exit(1); 
    }
    string tmp;
    vector<Word> Dictionary;
    while(getline(Fin, tmp, '\n')){
        Word word;
        stringstream ss(tmp);
        getline(ss, word.english, ':');
        getline(ss, word.mean, '\n');
        Dictionary.push_back(word);
    }
    Fin.close();
    return Dictionary;
}
void saveInOrder(Node* root, ofstream& fout) {
    if (root == NULL) return;
    saveInOrder(root->pLeft, fout);
    fout << root->word.english << ":" << root->word.mean << endl;
    saveInOrder(root->pRight, fout);
}
void saveDictionaryToFile(Node* root, string& fileName) {
    ofstream fout(fileName, ios::trunc);
    if (!fout.is_open()) {
        cerr << "Lỗi: Không thể ghi file từ điển!" << endl;
        return;
    }

    saveInOrder(root, fout);
    fout.close();
}

