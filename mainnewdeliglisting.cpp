#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
int main()
{
int a = 5;
int b = 7;
cout « std::min(a, b) « "\n";

// Returns the first one if both the numbers
// are same
cout « std::min(7, 7);

return 0;
}

*/
class List {
private:
struct node {
int data;
node* next;
};
node* head;
node* curr;
node* temp;

//3-element list:
node* first;
node* second;
node* third;
node* last;//last element in 3-element list

public:
List();
~List();
void show();
void insert(int addData);
void delete2();

void proc();

};

void List::proc() {
curr = head;
std::vector<int> group;
int it = 0;
std::cout « "min values: ";
while (curr != NULL) {
group.push_back(curr->data);
curr = curr->next;
it++;
if (it == 3 || curr == 0) {
auto value = std::min_element(group.begin(), group.end());
std::cout « *value « " ";
it = 0;
group.clear();
}
}
std::cout « endl;
}



int main() {
List mylist;
mylist.insert(4);
mylist.insert(7);
mylist.insert(5);
mylist.insert(1);
mylist.insert(6);
mylist.insert(1);
mylist.insert(7);
mylist.insert(3);
mylist.insert(2);
mylist.insert(9);
mylist.insert(1);

mylist.show();

cout « "--------------------------------------\n";
mylist.delete2();
cout « "--------------------------------------\n";
mylist.show();

mylist.proc();
//mylist.show();


return 0;
}




List::List() {
head = NULL;
curr = NULL;
temp = NULL;
cout « "Created!\n";
}

List::~List() {
curr = head;
if (curr != NULL) {
while (curr->next != NULL) {
temp = curr;
curr = curr->next;
delete temp;
}
}
else {
cout«"List is empty!";
delete curr;
}
cout « "Destructed!\n";
}

void List::insert(int addData) {
node* newNode = new node;
newNode->data = addData;
newNode->next = NULL;

if (head != NULL) {
curr = head;
while (curr->next != NULL) {
curr = curr->next;
}
curr->next = newNode;
}
else {
head = newNode;
}
}

void List::show() {
curr = head;
if (curr == NULL) {
cout « "List is empty!\n";
}
else {
while (curr != NULL) {
cout « curr->data « "->";
curr = curr->next;
}
cout « "NULL \n";
}
}

void List::delete2() {

int minimum = std::min(1, 7);
curr = head;
if (curr != NULL) {
last = third;
if (last != NULL) {
curr = last;
first = last->next;
second = first->next;
third = second->next;
}
else {
curr = head;
first = head;
second = head->next;
third = second->next;
}

//node* minimum = curr->data;
//node* minimum = curr->data;
while (curr != third->next) {
cout « curr->data;
if (curr->data < std::min(1,7)) {
minimum = curr->data;
}
curr = curr->next;
}
}
else {
//cout«"List is empty!";
delete curr;
}

}