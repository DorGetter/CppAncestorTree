#include <iostream>
#include <string>
#include "FamilyTree.hpp"
#define COUNT 10

using namespace std;
using namespace family;

struct Mexception : std::exception {
    const char* what() const throw() {
        const char* ex = "Error,illegal operation";
        return ex;
    }
};

string Node::get_name() {
    return this->my_name;
}

void Node::set_father(string x){
    if(x == "delete"){
        father = nullptr;

    }else{
        this->father = new Node(x);

    }
}

void Node::set_mother(string x){

    if(x == "delete"){
        mother = nullptr;

    }else {
        this->mother = new Node(x);
    }
};

Node* Node:: get_father(){
    return this->father;
};
Node* Node:: get_mother(){
    return this->mother;
};

string Node::relation(int check,string name) {

    string temp=my_name;
    if((check==0)&&(my_name==name)){
        return "me";
    }
    string ans="";
    if(father&&(*father).my_name==name){
        for (int i=0;i<check;i++){
            if(i!=check-1)
                ans+="great-";
            else
                ans+="grand";
        }
        ans+="father";
        return ans;
    }
    else if(mother&&(*mother).my_name==name){
        for (int i=0;i<check;i++){
            if(i!=check-1)
                ans+="great-";
            else
                ans+="grand";

        }
        ans+="mother";
        return ans;
    }
    if((!mother)&&(!father))
        return "unrelated";

    string relate="unrelated";

    if(father) {
        relate = this->father->relation(check+1, name);
    }
    if(relate=="unrelated"&&mother){
        relate = this->mother->relation(check+1, name);
    }
    return relate;

}



Tree& Tree::addFather(string name ,string dad){

    Node* temp = nameFinder(&root,name);
    if(temp == nullptr || temp->get_father() != nullptr){
        throw Mexception();
    }
    temp->set_father(dad);

    return *this;
}

Tree& Tree::addMother(string name ,string mom){

    Node* temp = nameFinder(&root,name);
    if(temp == nullptr || temp->get_mother() != nullptr){
        throw Mexception();
    }

    temp->set_mother(mom);
    //cout<<temp->get_name();

    return *this;
};

string Tree::relation(string name){
    return this->root.relation(0,name);
};


void static is_valid_name(string s) {

    for (char i : s) {
        if( (int(i)>= 97 && int(i)<=122) || (int(i)>= 65 && int(i)<=90) || (i == '-') ){

        }else{   throw Mexception();}
    }

};


string Tree::find(string name){

    is_valid_name(name);

    if(name == "me"){ return this->root.get_name();}
    else if(this->root.get_father() && name == "father" ){
        return this->root.get_father()->get_name();
    } else if(this->root.get_mother() != NULL && name == "mother" ){
        return this->root.get_mother()->get_name();
    }else if(!this->root.get_father() && name == "father" ){
        throw Mexception();;
    }else if(this->root.get_mother() != NULL && name == "mother" ){
        throw Mexception();
    }

    string a,b;
    if(this->root.get_father()){
        a = recursive_finder(this->root.get_father(),name);
        if(a != "x") return a;
    }
    if(this->root.get_mother()){
        b=recursive_finder(this->root.get_mother(),name);
        if(b != "x") return b;

    }

    throw Mexception();

};
void Tree::remove(string name){

    if(name == this->root.get_name()){
        throw Mexception();
    }

    Node* temp = nameFinder_delete(&root,name);
    if(!temp){
        throw Mexception();
    }
    rec_remove(temp);

}

string Tree::recursive_finder(Node* root,string name) {

    if(root == NULL){
        return "x";
    }

    if((int)name.find('-') == -1){

        if((int)name.find("father") != -1 && root->get_father()){
            return root->get_father()->get_name();
        }
        if((int)name.find("mother") != -1 && root->get_mother()){
            return root->get_mother()->get_name();
        }
        else
            return "x";
    }

    int index = name.find('-');
    index++;
    int len = name.length();

    if(recursive_finder(root->get_father(),name.substr(index,len)) != "x"){
        return recursive_finder(root->get_father(),name.substr(index,len));
    } else if(recursive_finder(root->get_mother(),name.substr(index,len)) != "x" ){
        return recursive_finder(root->get_mother(),name.substr(index,len));
    }

    return "x";
}

void Tree::rec_dis(Node *root) {

    if(root == NULL){
        return;;
    }

    string f="",m="";
    if(root->get_father()){
        f= root->get_father()->get_name();
    }
    if(root->get_mother()){
        m = root->get_mother()->get_name();
    }

    rec_dis(root->get_father());

    rec_dis(root->get_mother());

}



Node *Tree::nameFinder(Node* node, string name) {
    if(node == NULL){
        return nullptr;
    }

    if(node->get_name() == name){
        return node;
    }
    else if(node->get_father() && node->get_father()->get_name() == name){
        return node->get_father();
    }
    else if(node->get_mother() && node->get_mother()->get_name() == name){
        return node->get_mother();
    }

    Node* a = nameFinder(node->get_father(),name);
    Node* b = nameFinder(node->get_mother(),name);
    if(a) {
        return a;
    }
    if(b) {
        return b;
    }

    return nullptr;
}

void Tree::rec_remove(Node *root) {

    if(root->get_father() == nullptr && root->get_mother()== nullptr){
        delete(root);
        return;
    }

    if(root->get_father() != nullptr){
        rec_remove(root->get_father());
    }

    if(root->get_mother() != nullptr){
        rec_remove(root->get_mother());
    }

    root = nullptr;
}




Node *Tree::nameFinder_delete(Node *node, string name) {

    if(node == NULL){
        return nullptr;
    }

    if(node->get_name() == name){
        return node;
    }
    else if(node->get_father() && node->get_father()->get_name() == name){
        Node* temp = node->get_father();
        node->set_father("delete");
        return temp;
    }
    else if(node->get_mother() && node->get_mother()->get_name() == name){
        Node* temp = node->get_mother();
        node->set_mother("delete");
        return temp;
    }


    Node* a = nameFinder_delete(node->get_father(),name);
    Node* b = nameFinder_delete(node->get_mother(),name);
    if(a) {
        return a;
    }
    if(b) {
        return b;
    }

    return nullptr;
};
Node* Tree::get_root() {

    return &this->root;
}








/////printing/////
void Tree::display() {
    Node* r = get_root();
    if(r == NULL){
        std::cout << "Tree is empty" << std::endl;
    }
    //send to printing//
    print_tree(r,0);
}
//printing the tree recursivly//
void Tree::print_tree(Node *root, int space){
    // Base case
    if (root == NULL)
        return;
    //incharge of spacing lelveling//
    space += COUNT;

    print_tree(root->get_mother(), space);

    // Print current node after space
    // count
    std::cout<<std::endl;
    for (int i = COUNT; i < space; i++) {
        std::cout<<" ";
    }
    std::cout<<root->get_name()<<"\n";

    // Process left child
    print_tree(root->get_father(), space);
}


