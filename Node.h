

class Node {
public:
    int id;
    Node* north;
    Node* south;
    Node* east;
    Node* west;

    Node(int id) : id(id), north(nullptr), south(nullptr), east(nullptr), west(nullptr){}
};