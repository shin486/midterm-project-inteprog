#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


string toUpperCase(string str) {
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c -= 32; 
        }
    }
    return str;
}
string capitalize(string str) {
    if (str.length() > 0) {
        if (str[0] >= 'a' && str[0] <= 'z') {
            str[0] -= 32; 
        }
        for (int i = 1; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32; 
            }
        }
    }
    return str;
}


const int SIZE = 50;
int choice;

class Book {
private:
    string ID;
    string ISBN;
    string Title;
    string Author;
    string Edition;
    string Publication;
    string Category;

public:
    Book() {
        ID = ISBN = Title = Author = Edition = Publication = Category = "";
    }

    string getID() const { return ID; }
    void setID(string id) { ID = id; }

    string getISBN() const { return ISBN; }
    void setISBN(string isbn) { ISBN = isbn; }

    string getTitle() const { return Title; }
    void setTitle(string title) { Title = title; }

    string getAuthor() const { return Author; }
    void setAuthor(string author) { Author = author; }

    string getEdition() const { return Edition; }
    void setEdition(string edition) { Edition = edition; }

    string getPublication() const { return Publication; }
    void setPublication(string publication) { Publication = publication; }

    string getCategory() const { return Category; }
    void setCategory(string category) { Category = category; }
};

void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1 - Add Book\n";
    cout << "2 - Edit Book\n";
    cout << "3 - Search Book\n";
    cout << "4 - Delete Book\n";
    cout << "5 - View Books by Category\n";
    cout << "6 - View All Books\n";
    cout << "7 - Exit\n";
    cout << "Enter Choice (1-7): ";
}

int main() {
    Book books[SIZE];
    int bookcount = 0;

   do {
       displayMenu();
       cin >> choice;
       
       if (!cin || cin.peek() != '\n') {
           cout << "Invalid input! Please enter a digit only." << endl;
           cin.clear();
           cin.ignore(100, '\n');
       } else if (choice == 1) {  
           if (bookcount >= SIZE) {
               cout << "Library is full. Cannot add more books.\n";
               continue;
           }
        cout << "Category (Fiction/Non-Fiction): ";
        string category;
        getline(cin, category);
        for (int i = 0; i < category.length(); i++) {
            category[i] = tolower(category[i]);
        }
        
        while ((category != "fiction" && category != "non-fiction") || (category.length() == 1 && isdigit(category[0]))) {
            getline(cin, category);
            for (int i = 0; i < category.length(); i++) {
                category[i] = tolower(category[i]);
            }
        
            if ((category != "fiction" && category != "non-fiction") || (category.length() == 1 && isdigit(category[0]))) {
                cout << "Invalid input! Please enter Fiction or Non-Fiction: ";
            }
        }
           
            books[bookcount].setCategory(category);

            string id, isbn, title, author, edition, publication;
            
          
           cout << "Add ID: ";
           getline(cin, id);
           while (id.find(" ") != string::npos) {
               cout << "Invalid input! ID should not contain spaces. Please enter ID again: ";
               getline(cin, id);
           }
        
            string id_upper = toUpperCase(id);
            bool dupID = false;
        
            for (int i = 0; i < bookcount; i++) {
                if (toUpperCase(books[i].getID()) == id_upper) {
                    dupID = true;
                    break;
                }
            }
        
            while (dupID) {
                cout << "Duplicate ID! Please try again: ";
                cin >> id;
                id_upper = toUpperCase(id); 
                dupID = false;
                cin.ignore();
        
                for (int i = 0; i < bookcount; i++) {
                    if (toUpperCase(books[i].getID()) == id_upper) {
                        dupID = true;
                        break;
                    }
                }
            }
        
            books[bookcount].setID(id);

           
            cout << "Add ISBN (10 or 13 digits): ";
getline(cin, isbn);

string cleaned_isbn;
for (char ch : isbn) {
    if (ch != '-' && ch != ' ') { // ignore hyphens and spaces
        if (ch < '0' || ch > '9') { 
            cleaned_isbn = ""; // reset cleaned_isbn to empty string
            break;
        }
        cleaned_isbn += ch;
    }
}

while (cleaned_isbn.empty() || (cleaned_isbn.length() != 10 && cleaned_isbn.length() != 13)) {
    cout << "Invalid ISBN! Please enter a 10 or 13-digit number: ";
    getline(cin, isbn);

    cleaned_isbn = ""; 
    for (char ch : isbn) {
        if (ch != '-' && ch != ' ') { 
            if (ch < '0' || ch > '9') {
                cleaned_isbn = ""; 
                break;
            }
            cleaned_isbn += ch;
        }
    } 
} 
books[bookcount].setISBN(cleaned_isbn);
                
            
            cout << "Add Title: ";
            if (cin.peek() == '\n') cin.ignore();  
            getline(cin, title);
            
            while (title.empty()) {
                cout << "Title cannot be empty! Please enter a valid title: ";
                getline(cin, title);
            }
            
            books[bookcount].setTitle(title);
            
cout << "Add Author: ";
getline(cin, author);
while (author.empty()) {
    cout << "Author cannot be empty! Please enter a valid author name: ";
    getline(cin, author);
}
books[bookcount].setAuthor(author);

cout << "Add Edition: ";
getline(cin, edition);

while (edition.empty()) 
{
    cout << "Edition cannot be empty! Please enter a valid edition: ";
    getline(cin, edition);
}


books[bookcount].setEdition(edition);


cout << "Add Publication: ";
getline(cin, publication);
while (publication.empty()) {
    cout << "Publication cannot be empty! Please enter a valid publication: ";
    getline(cin, publication);
}
books[bookcount].setPublication(publication);


            cout << "Book added successfully!\n";
            bookcount++;
                cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
    }

        else if (choice == 2) {  
            string id;
            bool found = false;
            cout << "Enter Book ID to edit: ";
            cin.ignore();
            getline(cin, id);
            while (id.find(" ") != string::npos) {
                cout << "Invalid input! ID should not contain spaces. Please enter ID again: ";
                getline(cin, id);
            }
            const string id_upper = toUpperCase(id);
        
            for (int i = 0; i < bookcount; i++) {
                if (toUpperCase(books[i].getID()) == id_upper) {
                    found = true;
                    string isbn, title, author, edition, publication;
        
                    cout << "Edit ISBN (10 or 13 digits): ";
getline(cin, isbn);

string cleaned_isbn;
for (char ch : isbn) {
    if (ch != '-' && ch != ' ') { // ignore hyphens and spaces
        if (ch < '0' || ch > '9') { 
            cleaned_isbn = ""; // reset cleaned_isbn to empty string
            break;
        }
        cleaned_isbn += ch;
    }
}

while (cleaned_isbn.empty() || (cleaned_isbn.length() != 10 && cleaned_isbn.length() != 13)) {
    cout << "Invalid ISBN! Please enter a 10 or 13-digit number: ";
    getline(cin, isbn);

    cleaned_isbn = ""; 
    for (char ch : isbn) {
        if (ch != '-' && ch != ' ') { 
            if (ch < '0' || ch > '9') {
                cleaned_isbn = ""; 
                break;
            }
            cleaned_isbn += ch;
        }
    } 
} 
books[i].setISBN(cleaned_isbn);
                
        
                    cout << "Edit Title: ";
                    cin.ignore();
                    getline(cin, title);
                    while (title.empty()) {
                        cout << "Invalid input! Title should not be empty. Please enter title again: ";
                        getline(cin, title);
                    }
                    books[i].setTitle(title);
        
                    cout << "Edit Author: ";
                    getline(cin, author);
                    while (author.empty()) {
                        cout << "Invalid input! Author should not be empty. Please enter author again: ";
                        getline(cin, author);
                    }
                    books[i].setAuthor(author);
        
                    cout << "Edit Edition: ";
getline(cin, edition);

while (edition.empty())
{
    cout << "Invalid edit! Edition should not be empty. Please enter edition again: ";
    getline(cin, edition);
}
books[i].setEdition(edition);
        
                    cout << "Edit Publication: ";
                    cin.ignore();
                    getline(cin, publication);
                    while (publication.empty()) {
                        cout << "Invalid input! Publication should not be empty. Please enter publication again: ";
                        getline(cin, publication);
                    }
                    books[i].setPublication(publication);
        
                    cout << "Book edited successfully!\n";
                    break;
                }
            }
        
            if (!found) {
                cout << "Book with ID not found!\n";
                cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
                
            }
        }
        
        else if (choice == 3) {  
            if (bookcount == 0) {
                cout << "No books have been added. Add books first!\n";
                continue;
            }
            
            string id;
            bool found = false;
            cout << "Enter Book ID to search: ";
            cin.ignore();
            getline(cin, id);
            while (id.find(" ") != string::npos) {
                cout << "Invalid input! ID should not contain spaces. Please enter ID again: ";
                getline(cin, id);
            }
            const string id_upper = toUpperCase(id);

            for (int i = 0; i < bookcount; i++) {
                if (toUpperCase(books[i].getID()) == id_upper) {
                    found = true;
                    cout << "\nBook Found!\n";
                    cout << "--------------------------\n";
                    cout << "Book ID       : " << books[i].getID() << endl;
                    cout << "ISBN          : " << books[i].getISBN() << endl;
                    cout << "Title         : " << books[i].getTitle() << endl;
                    cout << "Author        : " << books[i].getAuthor() << endl;
                    cout << "Edition       : " << books[i].getEdition() << endl;
                    cout << "Publication   : " << books[i].getPublication() << endl;
                    cout << "--------------------------\n";
                    cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
                    break;
                }
            }
    
            if (!found) {
                cout << "Book ID not found!\n";
                cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
            }
        } 
        
        else if (choice == 4) {
            string id;
            bool found = false;
            int index = -1;
        
            cout << "Enter Book ID to delete: ";
            cin >> id;
            string id_upper = toUpperCase(id);
        
            for (int i = 0; i < bookcount; i++) {
                if (toUpperCase(books[i].getID()) == id_upper) {
                    found = true;
                    index = i;
                    cout << "--------------------------\n";
                    cout << "Book ID       : " << books[i].getID() << endl;
                    cout << "ISBN          : " << books[i].getISBN() << endl;
                    cout << "Title         : " << books[i].getTitle() << endl;
                    cout << "Author        : " << books[i].getAuthor() << endl;
                    cout << "Edition       : " << books[i].getEdition() << endl;
                    cout << "Publication   : " << books[i].getPublication() << endl;
                    cout << "--------------------------\n";
                    break;
                }
            }
        
            if (!found) {
                cout << "Book ID not found!\n";
            } else {
          cout << "Do you want to delete this book? (Y/N): ";
          string confirm;
          bool validInput = false;
          while (!validInput){
              cin >> confirm;
              if (confirm == "Y" || confirm == "y") {
                  for (int j = index; j < bookcount - 1; j++) {
                      books[j] = books[j + 1];
                  }
                  bookcount--;
                  cout << "Book deleted successfully.\n";
                  validInput = true;
                  cout << "Press any key to continue: ";
                  string key;
                  cin >> key;
                  getline(cin, key);
              for (int i = 0; i < key.length(); i++) {
                  key[i] = tolower(key[i]);
                  (key.length() == 1);
              }
              } else if (confirm == "N" || confirm == "n") {
                  cout << "Deletion cancelled." << endl;
                  validInput = true;
              } else {
                  cout << "Invalid input! Please enter Y or N only: ";
              }
          } }
        }   else if (choice == 5) {  
            string category;
            cout << "Enter Category (Fiction/Non-Fiction): ";
cin.ignore();
getline(cin, category);
while (category.empty() || category.find(" ") != string::npos) {
    cout << "Invalid input! Category should not be empty and should not contain spaces. Please enter category again: ";
    getline(cin, category);
}
     

            string lowerCategory = category;
            for (int i = 0; i < lowerCategory.length(); i++) {
                lowerCategory[i] = tolower(lowerCategory[i]);
            }
            while ((lowerCategory != "fiction" && lowerCategory != "non-fiction") || category.find(" ") != string::npos) {
                cout << "Invalid input! Please enter Fiction or Non-Fiction: ";
                cin >> category;
                lowerCategory = category;
                for (int i = 0; i < lowerCategory.length(); i++) {
                    lowerCategory[i] = tolower(lowerCategory[i]);
                }
            }
    
           
            
            
            string cat_upper = toUpperCase(category);
            bool found = false;
        
            cout << "\nAll Books in " << category << ":\n";
            cout << "---------------------------------------------------------------------------------------------\n";
            cout << left << setw(10) << "ID"
                 << setw(15) << "ISBN"
                 << setw(20) << "Title"
                 << setw(20) << "Author"
                 << setw(10) << "Edition"
                 << setw(20) << "Publication"
                 << setw(15) << "Category" << endl;
            cout << "---------------------------------------------------------------------------------------------\n";
            
            for (int i = 0; i < bookcount; i++) {
                string bookCategory = toUpperCase(books[i].getCategory());
            
                if (bookCategory == cat_upper) {
                    found = true;
                    cout << left << setw(10) << books[i].getID()
                         << setw(15) << books[i].getISBN()
                         << setw(20) << books[i].getTitle()
                         << setw(20) << books[i].getAuthor()
                         << setw(10) << books[i].getEdition()
                         << setw(20) << books[i].getPublication()
                         << setw(15) << books[i].getCategory() << endl;
                }
            }
            
            cout << "---------------------------------------------------------------------------------------------\n";
        
            if (!found) {
                cout << "No books found in this category!\n";
            }
        
            cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
        } 
        else if (choice == 6) {  
            if (bookcount == 0) {
                cout << "No books have been added yet.\n";
                cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
            } else {
                cout << "\nAll Books in Library:\n";
                cout << "---------------------------------------------------------------------------------------------\n";
                cout << left << setw(10) << "ID"
                     << setw(15) << "ISBN"
                     << setw(25) << "Title"
                     << setw(20) << "Author"
                     << setw(10) << "Edition"
                     << setw(20) << "Publication"
                     << setw(15) << "Category" << endl;
                cout << "---------------------------------------------------------------------------------------------\n";
                
                for (int i = 0; i < bookcount; i++) {
                    cout << left << setw(10) << books[i].getID()
                         << setw(15) << books[i].getISBN()
                         << setw(25) << books[i].getTitle()
                         << setw(20) << books[i].getAuthor()
                         << setw(10) << books[i].getEdition()
                         << setw(20) << books[i].getPublication()
                         << setw(15) << books[i].getCategory() << endl;
                }
                
                cout << "---------------------------------------------------------------------------------------------\n";
                cout << "Press any key to continue: ";
            string key;
            cin >> key;
            getline(cin, key);
        for (int i = 0; i < key.length(); i++) {
            key[i] = tolower(key[i]);
            (key.length() == 1);
        }
            }  
        }
          } while (choice != 7);  
        
          cout << "Exiting program\n";
          return 0; } 