#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

#include <string>

class Phone
{
public:
    string brand;
    string model;
    string form_factor;
    int year_of_issue;
    double screen_size;
    double price;

    Phone(string brand, string model, string form_factor, int year_of_issue, double screen_size, double price)
        : brand(brand), model(model), form_factor(form_factor), year_of_issue(year_of_issue), screen_size(screen_size), price(price) {}
};
void PrintPhone(const Phone &phone)
{
    cout << "Brand: " << phone.brand << endl;
    cout << "Model: " << phone.model << endl;
    cout << "Shape factor: " << phone.form_factor << endl;
    cout << "Release year: " << phone.year_of_issue << endl;
    cout << "Screen size: " << phone.screen_size << endl;
    cout << "Price: " << phone.price << endl;
}

void ShowPhonesByBrand(const vector<Phone> &phones, const string &brand)
{
    cout << "Phones of brand " << brand << ":" << endl;
    for (const Phone &phone : phones)
    {
        if (phone.brand == brand)
        {
            PrintPhone(phone);
        }
    }
}

void ShowPhonesByFormFactorAndScreenSize(const vector<Phone> &phones, const string &form_factor, double screen_size)
{
    cout << "Phones with form factor " << form_factor << " and screen size " << screen_size << ":" << endl;
    for (const Phone &phone : phones)
    {
        if (phone.form_factor == form_factor && phone.screen_size == screen_size)
        {
            PrintPhone(phone);
        }
    }
}
void ShowMaxBrand(const vector<Phone> &phones)
{
    unordered_map<string, int> brand_count;
    for (const Phone &phone : phones)
    {
        brand_count[phone.brand]++;
    }

    string max_brand;
    int max_count = 0;
    for (const auto &brand_and_count : brand_count)
    {
        if (brand_and_count.second > max_count)
        {
            max_brand = brand_and_count.first;
            max_count = brand_and_count.second;
        }
    }

    cout << "Brand with the maximum number of phones: " << max_brand << endl;
}

int main()
{

    vector<Phone> phones;

    while (true)
    {
        cout << "1. Add phone" << endl;
        cout << "2. Remove phone" << endl;
        cout << "3. Show phones" << endl;
        cout << "4. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            string brand, model, form_factor;
            int year_of_issue;
            double screen_size, price;

            cout << "Brand: ";
            cin >> brand;
            cout << "Model: ";
            cin >> model;
            cout << "Shape factor: ";
            cin >> form_factor;
            cout << "Year of issue: ";
            cin >> year_of_issue;
            cout << "Screen size: ";
            cin >> screen_size;
            cout << "Price: ";
            cin >> price;

            Phone phone(brand, model, form_factor, year_of_issue, screen_size, price);
            phones.push_back(phone);
        }
        else if (option == 2)
        {
            int phone_index;
            cout << "Enter index of phone to delete: ";
            cin >> phone_index;
            if (phone_index >= 0 && phone_index < phones.size())
            {
                phones.erase(phones.begin() + phone_index);
            }
            else
            {
                cout << "Invalid index." << endl;
            }
        }
        else if (option == 3)
        {
            for (const Phone &phone : phones)
            {
                PrintPhone(phone);
            }
        }
        else if (option == 4)
        {
            break;
        }
    }

    return 0;
}