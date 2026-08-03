// Author: Carl Anthony V. Talaboc
// Date created: June 6, 2024

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void FoodChoice(int fchoice, double &total);
void PrintReceipt(int);

int main()
{
    int choice;
    double total = 0;
    char orderMore;

    do
    {
        cout << "Welcome to C.A Restaurant" << endl;
        cout << "[1] - Order Food" << endl
             << "[2] - View Receipt" << endl
             << "[3] - Exit" << endl;
        cout << "Choose number to perform: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int fchoice;
            do
            {
                cout << "Welcome to C.A Restaurant" << endl;
                cout << "[1] - Breakfast" << endl
                     << "[2] - Lunch" << endl
                     << "[3] - Dinner" << endl
                     << "[4] - Exit" << endl;
                cout << "What menu you want to order: ";
                cin >> fchoice;

                if (fchoice >= 1 && fchoice <= 3)
                {
                    FoodChoice(fchoice, total);
                }

            } while (fchoice != 4);

            break;
        }
        case 2:
            PrintReceipt(total);
            break;
        case 3:
            cout << "Thank you for visiting our restaurant! See you again." << endl;
            break;
        default:
            cout << "Invalid number. Please try again." << endl;
            break;
        }

    } while (choice != 3);

    return 0;
}

void FoodChoice(int fchoice, double &total)
{
    int choice, qty;
    double price;
    char orderMore;

    switch (fchoice)
    {
    case 1:
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                                BREAKFAST MENU  " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "[1] - Pancakes with Maple Syrup and Butter | Price: PHP30" << endl;
        cout << "[2] - Bacon, Egg and Cheese Breakfast Sandwich | Price: PHP75" << endl;
        cout << "[3] - Omelette with Spinach, Tomato, and Cheese | Price: PHP85" << endl;
        cout << "[4] - Exit" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

        do
        {
            cout << "Enter food you want to order: ";
            cin >> choice;

            if (choice == 4)
                break;

            switch (choice)
            {
            case 1:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 30;
                total += price * qty;
                break;
            case 2:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 75;
                total += price * qty;
                break;
            case 3:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 85;
                total += price * qty;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }

            cout << "Do you want to order more? (Y/N): ";
            cin >> orderMore;

        } while (orderMore == 'Y' || orderMore == 'y');
        break;

    case 2:
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                                   LUNCH MENU  " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "[1] - Grilled Chicken Caesar Salad | Price: PHP200" << endl;
        cout << "[2] - BBQ Pulled Pork Sandwich with Coleslaw | Price: PHP170" << endl;
        cout << "[3] - Teriyaki Chicken Rice Bowl with Mixed Vegetables | Price: PHP180" << endl;
        cout << "[4] - Exit" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

        do
        {
            cout << "Enter food you want to order: ";
            cin >> choice;

            if (choice == 4)
                break;

            switch (choice)
            {
            case 1:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 200;
                total += price * qty;
                break;
            case 2:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 170;
                total += price * qty;
                break;
            case 3:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 180;
                total += price * qty;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }

            cout << "Do you want to order more? (Y/N): ";
            cin >> orderMore;

        } while (orderMore == 'Y' || orderMore == 'y');
        break;

    case 3:
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "                                   DINNER MENU  " << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "[1] - Grilled Salmon with Roasted Vegetables and Quinoa | Price: PHP300" << endl;
        cout << "[2] - Beef Stir-Fry with Broccoli, Bell Peppers, and Rice | Price: PHP250" << endl;
        cout << "[3] - Spaghetti Carbonara with Pancetta and Parmesan Cheese | Price: PHP200" << endl;
        cout << "[4] - Exit" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;

        do
        {
            cout << "Enter food you want to order: ";
            cin >> choice;

            if (choice == 4)
                break;

            switch (choice)
            {
            case 1:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 300;
                total += price * qty;
                break;
            case 2:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 250;
                total += price * qty;
                break;
            case 3:
                cout << "Enter Quantity: ";
                cin >> qty;
                price = 200;
                total += price * qty;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }

            cout << "Do you want to order more? (Y/N): ";
            cin >> orderMore;

        } while (orderMore == 'Y' || orderMore == 'y');
        break;

    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

void PrintReceipt(int b)
{
    string CusName;
    int verify;
    double cash, change = 0;
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int year = 1900 + localTime->tm_year;
    int month = 1 + localTime->tm_mon;
    int day = localTime->tm_mday;

    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;

    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, CusName);

    cout << "Hello " << CusName << ", The total of your order is: PHP " << b << endl;

    while (verify != 1){
    cout << "Enter 1 to proceed payment: ";
    cin >> verify;
    }

    if (verify == 1)
    {
        while (true)
        {
            cout << "Cash: ";
            cin >> cash;
            if (cash >= b)
            {
                double change = cash - b;
                cout << "Transaction successful. Your change is: PHP" << change << endl;
                break;
            }
            else
            {
                cout << "Insufficient balance. Try again" << endl;
            }
        }
    }
    cout << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "Date: " << year << "-" << month << "-" << day << endl;
    cout << "Time: " << hour << ":" << minute << ":" << second << endl;

    cout << "Total of your order: " << b << endl;
    cout << "You pay: " << cash << endl;
    cout << "Change: " << change << endl;

    cout << "Thank you for ordering, " << CusName << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    system ("pause");
    system ("cls");
}