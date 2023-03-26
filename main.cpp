#include <iostream>
#include "iomanip"
#include <limits>
using namespace std;

int horizontalCoordinate;
int verticalCoordinate;

void fill_pimples(bool array[][12]) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      array[i][j] = true;
    }
  }
}

bool print_pimples(bool array[][12]) {
  int sum = 0;
  cout << "               Game Board 12 X 12 " << endl;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      sum += array[i][j];
      if (array[i][j]) {
        cout << setw(4) << 'O';
      } else
        cout << setw(4) << 'X';
    }
    cout << endl;
  }
  if (sum == 0)return false;
  else return true;
}
bool check_enter() {
  if (cin.fail() || cin.peek() != '\n') {
    cerr << "Enter Error!" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
  } else
    return true;
}
bool input_check_coordinate(bool array[][12]) {
  int count = 0;
  while (count <= 5) {
    cout << "Input horizontal coordinates: " << endl;
    cin >> horizontalCoordinate;
    if (!(check_enter())) {
      count++;
      continue;
    }
    cout << "Input vertical coordinates: " << endl;
    cin >> verticalCoordinate;
    if (!(check_enter())) {
      count++;
      continue;
    }
    if (!(array[horizontalCoordinate - 1][verticalCoordinate - 1])) {
      cout << "Incorrect coordinates!" << endl;
      count++;
      continue;
    } else return true;
  }
  return false;
}
void boom_pimples(bool array[][12]) {
  int count = 0;
  for (int i = horizontalCoordinate - 1; i >= 0; i--) {
    for (int j = verticalCoordinate - 1; j >= 0; j--) {
      if (array[i][j] == 1) {
        array[i][j] = false;
        cout << "Pop!" << " ";
        count++;
        if (count % 10 == 0)cout << endl;
      }
    }
  }
  cout << endl;
}

int main() {
  bool pimples[12][12];
  fill_pimples(pimples);
  do {
    if (!(print_pimples(pimples))) break;
    if (!(input_check_coordinate(pimples))) exit(0);
    boom_pimples(pimples);
  } while (true);
  cout << "   <<<<<<<<<<<<<<<<< GAME OVER >>>>>>>>>>>>>>>>>" << endl;
}
