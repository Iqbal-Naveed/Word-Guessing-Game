#include <iostream>
#include <string>

using namespace std;

const int rows = 6;
const int cols = 5;

void transposeColumn(string grid[][cols], string transposedGrid[][1], int columnIndex) {
    for (int i = 0; i < rows; ++i) {
        transposedGrid[i][0] = grid[i][columnIndex];
    }
}

void displayTransposedColumn(string grid[][cols], int columnIndex) {
    string transposedGrid[rows][1];

    transposeColumn(grid, transposedGrid, columnIndex);

    for (int i = 0; i < rows; ++i) {
        cout << transposedGrid[i][0] << " ";
    }
    cout << endl;
}

//calculating word based on user input after tranpose
string calculate_letter(string grid[][cols], int columnIndex, int no){
    string transposedGrid[rows][1];

    transposeColumn(grid, transposedGrid, columnIndex);

    return transposedGrid[no][0]; //
}

int main() {
    string arr[10] = {"First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eight", "Ninth", "Tenth"};
    string alphabet[6][5] = {
        {"A", "B", "C", "D", "E"},
        {"F", "G", "H", "I", "J"},
        {"K", "L", "M", "N", "O"},
        {"P", "Q", "R", "S", "T"},
        {"U", "V", "W", "X", "Y"},
        {"Z"}
    };

    // Display the original alphabet grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << alphabet[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n";

    int n;
    cout << "Think about a word and keep that in your mind\n";
    cout << "How many alphabets are there in that word :";
    cin >> n;
    int c[n];
    string Word = "";
    cout << "\n";

    // Get user input for the columns
    for (int j = 0; j < n; j++) {
        cout << "Enter column for " << arr[j] << " alphabet :\n";
        cin >> c[j];
    }

    // Display transposed columns based on user input
    for (int k = 0; k < n; k++) {
        displayTransposedColumn(alphabet, c[k] - 1);
    }

    //new array to collect column no after transpose
    int t[n];
    cout << "Again enter columns for the same words:\n";
    for (int j = 0; j < n; j++) {
        cout << "Enter column for " << arr[j] << " alphabet :\n";
        cin >> t[j]; 
        Word = Word + calculate_letter(alphabet, c[j] - 1, t[j] - 1);
	}
    cout<<"The WORD was "<<Word;
    return 0;
}