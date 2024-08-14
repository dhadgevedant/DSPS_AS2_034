#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Book {
public:
    int cost;
    string name;
    string aut;

    Book(int cost, string name, string aut) {
        this->cost = cost;
        this->name = name;
        this->aut = aut;
    }

    Book() {
        cost = 0;
        name = "";
        aut = "";
    }

    // Function to display the list of books
    static void disp(vector<Book>& library) {
        cout << "\n\nBook List:\n";
        for (int i = 0; i < library.size(); i++) {
            cout << "\n" << library[i].name << "\t" << library[i].aut << "\t" << library[i].cost;
        }
    }

    // Function to sort books by cost in descending order
    static void dSort(vector<Book>& library) {
        sort(library.begin(), library.end(), [](Book& a, Book& b) {
            return a.cost > b.cost;
        });
    }

    // Function to copy books with cost less than 500 into a new array
    static vector<Book> bel500(vector<Book>& library) {
        vector<Book> below500;
        for (int i = 0; i < library.size(); i++) {
            if (library[i].cost < 500) {
                below500.push_back(library[i]);
            }
        }

        cout << "\n\nBooks with cost below 500:\n";
        for (int i = 0; i < below500.size(); i++) {
            cout << "\n" << below500[i].name << "\t" << below500[i].aut << "\t" << below500[i].cost;
        }
        return below500;
    }

    // Function to delete duplicate books using a temporary array
    static void delDupWT(vector<Book>& library) {
        vector<Book> temp;
        for (int i = 0; i < library.size(); i++) {
            bool duplicate = false;
            for (int j = 0; j < temp.size(); j++) {
                if (library[i].name == temp[j].name && library[i].aut == temp[j].aut) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate) {
                temp.push_back(library[i]);
            }
        }
        library = temp;

        cout << "\n\nDuplicate elements deleted using temp array.";
    }

    // Function to delete duplicate books without using a temporary array
    static void delDup(vector<Book>& library) {
        for (int i = 0; i < library.size(); i++) {
            for (int j = i + 1; j < library.size(); j++) {
                if (library[i].name == library[j].name && library[i].aut == library[j].aut) {
                    library.erase(library.begin() + j);
                    j--;  // Adjust index after erasing element
                }
            }
        }

        cout << "\n\nDuplicate elements deleted without using temp array.";
    }

    // Function to count the number of books with cost more than 500
    static int countAbv500(vector<Book>& library) {
        int count = 0;
        for (int i = 0; i < library.size(); i++) {
            if (library[i].cost > 500) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<Book> library;
    bool flag = true;
    int ch;

    do {
        cout << "\nMAIN MENU\n\t0. EXIT\n\t1. Display\n\t2. Add new book\n\t3. Sort in descending order\n\t4. Show books below 500\n\t5. Delete duplicates with temp array\n\t6. Delete duplicates without temp array\n\t7. Count books above 500\n";
        cin >> ch;

        switch (ch) {
            case 0:
                flag = false;
                break;
            case 1:
                Book::disp(library);
                break;
            case 2: {
                int cost;
                string name, aut;
                cout << "Enter Title, Author, and cost of the book: ";
                cin >> name >> aut >> cost;
                library.push_back(Book(cost, name, aut));
                break;
            }
            case 3:
                Book::dSort(library);
                cout << "\nBooks sorted in descending order by cost.";
                break;
            case 4:
                Book::bel500(library);
                break;
            case 5:
                Book::delDupWT(library);
                break;
            case 6:
                Book::delDup(library);
                break;
            case 7:
                cout << "\nNumber of books with cost more than 500: " << Book::countAbv500(library);
                break;
            default:
                cout << "\nInvalid choice!";
        }
    } while (flag);

    return 0;
}
