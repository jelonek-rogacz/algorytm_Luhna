#include <iostream>
#include <string>
#include <vector>
using namespace std;

class card_manager {
private:
    string bank_name;
    string card_owner;
    string expiration_date;
    string card_number;

public:
    void setBankName(string s_bank_name);
    string getBankName();

    void setCardOwner(string s_card_owner);
    string getCardOwner();

    void setCardNumber(string s_card_number);
    string getCardNumber();

    void setExpirationDate(string s_expiration_date);
    string getExpirationDate();

    bool Luhn_check() const;
};
/* Bank */
void card_manager::setBankName(string s_bank_name) {
    bank_name = s_bank_name;
}

string card_manager::getBankName() {
    return bank_name;
}
/* Wlasciciel */
void card_manager::setCardOwner(string s_card_owner) {
    card_owner = s_card_owner;
}

string card_manager::getCardOwner() {
    return card_owner;
}
/* datda waznosci */
void card_manager::setExpirationDate(string s_expiration_date) {
    expiration_date = s_expiration_date;
}

string card_manager::getExpirationDate() {
    return expiration_date;
}
/* numer karty */
void card_manager::setCardNumber(string s_card_number) {
    card_number = s_card_number;
}

string card_manager::getCardNumber() {
    return card_number;
}
/* Algorytm Luhna */
bool card_manager::Luhn_check() const {
    string number = card_number;

    vector<int> credit_card;
    for (int i=0; i<number.length(); i++) {
        credit_card.push_back(number[i] - '0');
    }

    for (int j = number.length()-2; j>=0; j-=2) {
        int tempValue = credit_card[j];
        tempValue *=2;
        if (tempValue > 9)
            tempValue = tempValue - 9;

        credit_card[j] = tempValue;
    }

    int sum = 0;
    for (int i=0; i < credit_card.size(); i++)
        sum +=credit_card[i];

    return (sum % 10==0);
}

int main() {
    card_manager card_a;
    card_a.setBankName("DANSKE BANK A/S");
    card_a.setCardOwner("Mirella Holst");
    card_a.setExpirationDate("09/2025");
    card_a.setCardNumber("5534551986680417");

    cout << card_a.getBankName() << " " << card_a.getCardOwner() << " " << card_a.getExpirationDate() << " " << card_a.getCardNumber() << endl;
    if (card_a.Luhn_check()){
        cout << "Numer karty jest poprawny" << endl;
    }
    else
        cout << "Numer karty jest niepoprawny" <<endl;
    /////
    card_manager card_b;
    card_b.setBankName("BANK PEKAO");
    card_b.setCardOwner("Dennis Fleischer");
    card_b.setExpirationDate("11/2025");
    card_b.setCardNumber("4210831590146383");
    cout << card_b.getBankName() << " " << card_b.getCardOwner() << " " << card_b.getExpirationDate() << " " << card_b.getCardNumber() << endl;
    if (card_b.Luhn_check()){
        cout << "Numer karty jest poprawny" << endl;
    }
    else
        cout << "Numer karty jest niepoprawny" <<endl;
    //////
    card_manager card_c;
    card_c.setBankName("SANTANDER CONSUMER FINANCE S.A.");
    card_c.setCardOwner("Merzan Bata");
    card_c.setExpirationDate("07/2024");
    card_c.setCardNumber("5268196179941226");

    cout << card_c.getBankName() << " " << card_c.getCardOwner() << " " << card_c.getExpirationDate() << " " << card_c.getCardNumber() << endl;
    if (card_c.Luhn_check()){
        cout << "Numer karty jest poprawny" << endl;
    }
    else
        cout << "Numer karty jest niepoprawny" <<endl;
    return 0;
}