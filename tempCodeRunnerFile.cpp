
string cleaned_isbn;
for (char ch : isbn) {
    if (ch != ' ') { 
        if (ch < '0' || ch > '9') { 
            cleaned_isbn = ""; 
            break;
        }
        cleaned_isbn += ch;
    }
}