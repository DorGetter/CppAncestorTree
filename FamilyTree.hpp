
#include <iostream>
#include <string>
#define COUNT 10

using namespace std;

namespace family{

    class Node{
        string my_name;
        Node *father;
        Node *mother;
    public:

        Node(string &name) : my_name(name), father(nullptr),mother(nullptr) {};
        string get_name();
        void set_father(string name);
        void set_mother(string name);
        Node* get_father();
        Node* get_mother();
        string relation(int grand,string name);

    };

    class Tree{
    private:
        Node root;

    public:

        Tree(string name): root(name){};
        Node*  get_root();

        Tree& addFather(string name ,string dad);
        Tree& addMother(string name ,string dad);

        void print_tree(Node *root, int space);
        void display();

        string relation(string name);
        string find(string name);

        void remove(string name);
        string recursive_finder(Node* root,string basicString);

        void rec_dis(Node *pNode);

        Node *nameFinder(Node* node, string basicString);

        void rec_remove(Node *pNode);

        Node *nameFinder_delete(Node *pNode, string basicString);




    };
}
