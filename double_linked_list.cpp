#include<iostream>
using namespace std;


struct price {
    struct price *previous;
    struct price *next;
    double p;
};

int main() {
    price *first = NULL, *current = NULL, *price = NULL;
    double media = 0;
    int n_prices = 5;

    for (int i = 0; i < n_prices; i++) {
        price = new struct price;
        //price *price = new struct price;
        price->p = i;
        
        price->next = NULL;

        if (i == 0) {
            price->previous = NULL;
            first = price;
        } else {
            price->previous = current;
            current->next = price;
        }

        current = price;
        cout << "setting " << i+1 << "-th price to: " << current->p << endl;
        media += i;

        price = NULL;
    }
    current->next = first;
    media /= n_prices;
    cout << "current moving average: " << media << endl;

    current = first;
    for (int i = 0; i < 2*n_prices+3; i++) {
        if (current) {
            cout << "showing " << i+1 << "-th price: " << current->p << endl;
            current = current->next;
        } else {
            cout << " finished prices " << endl << endl;
            break;
        }
    }


    // serial update
    current = first;
    int start = n_prices;
    cout << endl<< "start serial update from " << start << endl;
    for (int j = start; j < start+20; j++) {
        cout << "change " << current->p << " in " << j << endl;
        media += (double )j / n_prices - current->p / n_prices;
        current->p = j;
        current = current->next;
    } 
    cout << "current moving average: " << media << endl;

    current = first;
    cout << endl<< "new print from " << start << endl;
    for (int i = 0; i < 2*n_prices+3; i++) {
        if (current) {
            cout << "showing " << i+1 << "-th price: " << current->p << endl;
            current = current->next;
        } else {
            cout << " finished prices " << endl << endl;
            break;
        }
    }

    return 0;

}
