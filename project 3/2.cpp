//assignment 3.2
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;

struct Page {
    int id;
    string path;
    int counter;
    Page(int id, string path) {
        this->id = id;
        this->path = path;
        counter = 0;
    };
};

// This function can facilitate sorting
bool operator<(const Page & a, const Page & b) {
    return (a.id < b.id);
}

vector<Page> pages;

struct User {
    int id;
    vector<string> visits;
    User(int id) {
        this->id = id;
    };
    void add_visit(int page_id) {
        Page p(page_id, "");

        vector<Page>::iterator iter;
          for (iter = pages.begin(); iter != pages.end(); ++iter){
              if(iter->id == page_id){
                  visits.push_back(iter->path);
              }
          }
    };
    int size() const {
        return visits.size();
    };
    void print_visits() {
        sort(visits.begin(), visits.end());
        vector<string>::iterator iter;
        for(iter = visits.begin(); iter != visits.end(); iter++) {
            cout << "- " << *iter << endl;
        }
    }
};

vector<User> users;

// Please implement the following function to facilitate the sorting of users
//if the visit count of User a is greater than that of User b, then a should be sorted before b.
//if the visit count of User a and b are equal, and if id of a is smaller than id of b, a should be sorted before b.
//else b should be sorted before a.
bool operator<(const User & a, const User & b) {
    //return (a.visits.size() > b.visits.size());
    if (a.visits.size() > b.visits.size()){
	return true;
    }
    else if (a.visits.size() == b.visits.size()){
	if (a.id < b.id){
	    return true;
	}
    }
    return false;
}

// Please implement the following function
//use the push_back() function to add Page p to the end of the vector pages.
void add_page(const Page& p) {
    pages.push_back(p);
}

// Please implement the following function
//if the counter of a is greater than b, a should be sorted before b.
//if the counter of a and b are equal, and if path of a is lexicographically smaller than the path of b, then a should be sorted before b.
//else b should be sorted before a.
bool cmp_page_count(const Page & a, const Page & b) {
    if (a.counter > b.counter){
        return true;
    }
    else if (a.counter == b.counter){
        if (a.path < b.path){
            return true;
        }
    }
    return false;
}

// Please implement the following function
//print the visited count and the path of the first (number) users from the vector pages.
void print_pages(int number) {
    for (int i = 0; i < number; i++){
        cout << pages[i].counter << ":" <<pages[i].path << endl;
    }
}

// Please implement the following function
//use the push_back() function to add User u to the vector users.
void add_user(User u) {
    users.push_back(u);
}

// Please implement the following function
//add visits to the last (most currently added) user of the user vector.
void add_visit(int page_id) {
    users[users.size() - 1].add_visit(page_id);
}

// Please implement the following function
//print the visit count and id of the first (number) users from the vector users.
void print_users(int number) {
    for (int i = 0; i < number; i++){
        cout << users[i].visits.size() << ":" << users[i].id << endl;
        users[i].print_visits();
    }
}



int main() {

    string type;
    while(cin >> type) {
        if(type == "USER") {
          int user_id;
          cin >> user_id;
          User u(user_id);
          add_user(u);
        } else if(type == "PAGE") {
          int page_id;
          string page_path;
          cin >> page_id;
          cin >> page_path;
          Page p(page_id, page_path);
          add_page(p);
        } else if(type == "VISIT") {
          int page_id;
          cin >> page_id;
          Page p(page_id, "");
          vector<Page>::iterator iter;
          for (iter = pages.begin(); iter != pages.end(); ++iter){
              if(iter->id == p.id){
                  iter->counter++;
              }
          }
          add_visit(p.id);
        }
    }
    sort(pages.begin(), pages.end(), cmp_page_count);
    cout << "*** 5 most popular pages ***" << endl;
    print_pages(5);
    sort(pages.begin(), pages.end());

    sort(users.begin(), users.end());
    cout << "*** 5 most active users ***" << endl;
    print_users(5);

    return 0;

}

