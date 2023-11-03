//assignmet3_1
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

struct Node
{
    int value;
    Node * next;
};

// output the linked list
void print_list(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

// output the large number stored in the linked list in reverse order.
void print_num(Node * head)
{
    Node * current = head;

    if (head == NULL){
        cout << "";
    }
    else {
        if (current->next == NULL){
            cout << head->value;
        }
        else{
        print_num(head->next);
        //fill in the blanks with 0's.
        cout << setw(3) << setfill('0')<<head->value;
        }
    }
}

// insert a value as a node to the tail of a linked list
void tail_insert(Node * & head, Node * & tail, int v)
{
    Node * p = new Node;
    p->value = v;
    p->next = NULL;

    if (head == NULL){
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;
    }
}

// delete the head node from a linked list
void delete_head( Node * & head)
{
    if (head != NULL) {
        Node * p = head;
        head = head->next;
        delete p;
    }
}

// free an entire linked list
void delete_list(Node * & head)
{
    while ( head != NULL )
    {
        delete_head(head);
    }
}

// double the capacity of an array
// array: input array
// size: original size of array, updated to new size of array
void grow_array( char * & array, int & size )
{
    if (array == NULL)
        return;

    int newSize = size * 2;

    // doubled the size of the array;
    char * tmp = new char [ newSize ];
    // copy original contents
    for (int i = 0; i < size; ++i)
        tmp[i] = array[i];

    delete [] array;

    array = tmp;
    size = newSize;
}

//take number as input and increase the array size if the number length exceeds the limit.
void input_num(char * & digits, int & numDigits)
{
    int arraysize = 32;
    digits = new char [arraysize];
    char c;
    int numRead = 0;

    // read each digit as a character until a white space is hit
    c = cin.get();
    while (!isspace(c))
    {
        if (numRead >= arraysize)
            grow_array( digits, arraysize );

        digits[numRead] = c;
        numRead++;

        c = cin.get();
    }

    numDigits = numRead;

}

//store the large number in a linked list as chunks of 3 digit numbers.
Node * create_num_list()
{
    // TASK 1a: declare a pointer pointing to the head of the link list
    Node * head = NULL, * tail = NULL;

    string str;
    char * digits = NULL;  // a dynamic array for storing an input number
    int numDigits;
    int val;

    // get a number from the user
    input_num( digits, numDigits);

    // scan the digits in reverse, and create a list of nodes for
    // the value of every 5 digits
    str.clear();
    for (int i = numDigits-1; i >=0; --i) {
        str = digits[i] + str;
        if (str.length()==3) {
            val = atoi(str.c_str());

            // TASK 1b: insert a value as a node to the head of the linked list
            tail_insert(head, tail, val);

            str.clear();
        }
    }
    // the digits array is scanned and there are still digits
    // stored in str that are not inserted into the list yet
    if (!str.empty()) {
        val = atoi(str.c_str());

        // TASK 1c: insert a value as a node to the head of the linked list
        tail_insert(head, tail, val);
    }

    if (digits != NULL) {
        delete [] digits;

    }

    // TASK 1d: return the pointer to the linked list
    return head;
}



// return the length of a linked list
int list_length(Node * head)
{
 	// TASK 3: Modify this print function to one that
	// count the number of nodes in a linked list

    int num = 0;

    Node * current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        ++num;
        current = current->next;
    }

    return num;
}

//perform addition to the two linked lists n1 and n2.
void addition (Node * & n1, Node * & n2){
    //declare len1 and len2, which are lengths of the linked lists n1 and n2, respectively.
    int len1 = list_length(n1);
    int len2 = list_length(n2);

    //declare two pointers current1 and current2 to point to the current nodes.
    Node * current1 = n1, * current2 = n2;


    //CASE1: if len1 is greater than len2
    if (len1 > len2){
        while (current1 != NULL && current2 != NULL){     //check whether both current1 and current2 have values.
            //add two values of current nodes, and if they are smaller than 1000, set current1 as a sum of the two current nodes.
            if (current1->value + current2->value < 1000){
                current1->value = current1->value + current2->value;
            }
            //add two values of current nodes, and if they are greater than 1000, set current1 as the remainder of (the sum of the two current nodes divided by 1000).
            //then add 1 to the value of the next node of current1.
            else if (current1->value + current2->value >= 1000){
                current1->value = (current1->value + current2->value) % 1000;
                current1->next->value ++;
            }
            //move on to the next nodes.
            current1 = current1 -> next;
            current2 = current2 -> next;
        }
        //when current2 has reached a NULL value,
        //check if the current1's value has reached 1000.
        while (current1->value >= 1000){
            //if it has reached 1000, set current1's value as the remainer of (current1->value divided by 1000).
            current1->value = current1->value % 1000;
            //if the next node is NULL, create a new node "tail" and set it as 1.
            //break the while loop.
            if (current1->next == NULL){
                Node *tail = new Node;
                tail->value = 1;
                tail->next = current1->next;
                current1->next = tail;
                break;
            }
            //if the next node exists, add 1 to the value of the next node.
            //move onto the next node.
            else{
            current1->next->value ++;
            current1 = current1->next;
            }
        }
    }

    //CASE2: if len1 and len2 are equal.
    else if (len1 == len2){
        while (current1->next != NULL){     //check whether current1->next has a value.
            //add two values of current nodes, and if they are smaller than 1000, set current1 as a sum of the two current nodes.
            if (current1->value + current2->value < 1000){
                current1->value = current1->value + current2->value;
            }
            //add two values of current nodes, and if they are greater than 1000, set current1 as the remainder of (the sum of the two current nodes divided by 1000).
            //then add 1 to the value of the next node of current1.
            else if (current1->value + current2->value >= 1000){
                current1->value = (current1->value + current2->value) % 1000;
                current1->next->value ++;
            }
            //move on to the next nodes.
            current1 = current1 -> next;
            current2 = current2 -> next;
        }
        //when current1->next has reached a NULL value,
        //set current1 as a sum of values of current1 and current2.
        current1->value = (current1->value + current2->value);
        //if current1->value exceeds 1000, then set current1 as the remainder of current1->value divided by 1000.
        //create new node "tail" and set it as 1.
        if (current1->value >= 1000){
            current1->value = current1->value % 1000;
            Node *tail = new Node;
            tail->value = 1;
            tail->next = current1->next;
            current1->next = tail;
        }
    }

    //CASE3: if len2 is greater than len1. This case is the equivalent of CASE1, except for the fact that we are doing the addition to len2, instead of len1.
    else if (len1 < len2){
        while (current1 != NULL && current2 != NULL){     //check whether both current1 and current2 have values.
            //add two values of current nodes, and if they are smaller than 1000, set current2 as a sum of the two current nodes.
            if (current1->value + current2->value < 1000){
                current2->value = current1->value + current2->value;
            }
            //add two values of current nodes, and if they are greater than 1000, set current2 as the remainder of (the sum of the two current nodes divided by 1000).
            //then add 1 to the value of the next node of current2.
            else if(current1->value + current2->value >= 1000){
                current2->value = (current1->value + current2->value) % 1000;
                current2->next->value ++;
            }
            //move on to the next nodes.
            current1 = current1 -> next;
            current2 = current2 -> next;
        }
        //when current1 has reached a NULL value,
        //check if the current2's value has reached 1000.
        while (current2->value >= 1000){
            //if it has reached 1000, set current2's value as the remainer of (current2->value divided by 1000).
            current2->value = current2->value % 1000;
            //if the next node is NULL, create a new node "tail" and set it as 1.
            //break the while loop.
            if (current2->next == NULL){
                Node *tail = new Node;
                tail->value = 1;
                tail->next = current2->next;
                current2->next = tail;
                break;
            }
            //if the next node exists, add 1 to the value of the next node.
            //move onto the next node.
            else{
            current2->next->value ++;
            current2 = current2->next;
            }
        }
    }
}

int main()
{
    Node * n1, * n2;
    n1 = create_num_list();     //create a linked list n1.
    cin.get();       // skip the '+' sign
    cin.get();       // skip the space after the '+' sign
    n2 = create_num_list();     //create a linked list n2.

    //print two linked lists n1 and n2 to check if they are successfully created.
    print_list(n1);
    print_list(n2);

    //perform addition to the two linked lists n1 and n2.
    addition(n1, n2);

    int len1 = list_length(n1);
    int len2 = list_length(n2);

    //if len1 is greater than or equal to len2, print the linked list of n1.
    //print the linked list of n1 in a numerical form.
    if (len1 >= len2){
        print_list(n1);
        print_num(n1);
    }

    //if len2 is greater than len1, print the linked list of n2.
    //print the linked list of n2 in a numerical form.
    else {
        print_list(n2);
        print_num(n2);
    }
    
    //newline at the end of file
    cout << endl;

    //after all the procedures, delete both linked lists to save memory.
    delete_list(n1);
    delete_list(n2);

    return 0;
}

