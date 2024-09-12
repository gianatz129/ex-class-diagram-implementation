#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Function to clear the screen on Windows
void clearScreen()
{
    system("CLS");
}

// Class for displaying and managing products
class Product
{
public:
    void displayProducts()
    {
        cout << "----------PRODUCT VIEW----------" << endl;
        cout << "Product 1: Cheese Burger" << endl;
        cout << "Product ID: 123456" << endl;
        cout << "Product Price: P100" << endl;
        cout << "--------------------------------" << endl;
        cout << "Product 2: Double Cheese Burger" << endl;
        cout << "Product ID: 123457" << endl;
        cout << "Product Price: P150" << endl;
        cout << "--------------------------------" << endl;
        cout << "Product 3: Triple Cheese Burger" << endl;
        cout << "Product ID: 123458" << endl;
        cout << "Product Price: P200" << endl;
        cout << "--------------------------------" << endl;
    }
    int getProductPrice(int productID)
    {
        if (productID == 123456)
            return 100;
        else if (productID == 123457)
            return 150;
        else if (productID == 123458)
            return 200;
        else
            return 0; // Invalid ID
    }
};
// Class for handling the order details and tracking
class Order
{
private:
    int productID;
    int quantity;
    string paymentMethod;
    int pricePerItem;

public:
    Order(int pID = 0, int qty = 0, string payMethod = "", int price = 0)
        : productID(pID), quantity(qty), paymentMethod(payMethod), pricePerItem(price) {}

    void confirmOrder()
    {
        char confirm;
        while (true)
        {
            clearScreen();
            cout << "-----------ORDER CONFIRMATION-----------" << endl;
            cout << "Product ID: " << productID << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Payment Method: " << paymentMethod << endl;
            cout << "Total Amount: P" << quantity * pricePerItem << endl;
            cout << "--------------------------------" << endl;
            cout << "Do you want to confirm this order? (y/n): ";
            cin >> confirm;

            if (confirm == 'y')
            {
                cout << "Order confirmed successfully!" << endl;
                cout << "--------------------------------" << endl;
                trackOrder(); // Order confirmed, proceed to tracking
                break;
            }
            else if (confirm == 'n')
            {
                cout << "Order canceled. Starting a new order..." << endl;
                cout << "--------------------------------" << endl;
                break; // Order not confirmed, exit this order
            }
            else
            {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        }
    }

    void trackOrder()
    {
        clearScreen();
        cout << "-----------ORDER TRACKING-----------" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per item: P" << pricePerItem << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "-------------------------------------" << endl;
    }
    // Function to get order details
    void getOrderDetails() const
    {
        cout << "Product ID: " << productID << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Payment Method: " << paymentMethod << endl;
        cout << "Total Amount: P" << quantity * pricePerItem << endl;
        cout << "--------------------------------" << endl;
    }
};

// Class for storing customer information
class Customer
{
private:
    Order order;

public:
    Customer(Order custOrder = Order())
        : order(custOrder) {}

    void getCustomerDetails() const
    {
        order.getOrderDetails();
    }
};

int main()
{
    const int maxCustomers = 50;
    int currentCustomer = 0;
    char addAnother;
    Customer customers[maxCustomers]; // Array to store customer data

    do
    {
        clearScreen(); // Clear the screen before showing products

        // Display products
        Product product;
        product.displayProducts();

        int selectedProduct;
        int quantity;
        int paymentChoice;
        string paymentMethod;

        // Loop for selecting product until a valid ID is entered
        while (true)
        {
            cout << "Enter the Product ID to buy: ";
            cin >> selectedProduct;

            int price = product.getProductPrice(selectedProduct);

            if (price > 0)
            {
                cout << "Selected Product ID: " << selectedProduct << endl;
                cout << "Price per item: P" << price << endl;
                break;
            }
            else
            {
                cout << "Invalid Product ID. Please try again." << endl;
            }
        }

        // Enter quantity
        cout << "Enter quantity: ";
        cin >> quantity;

        // Payment method selection
        while (true)
        {
            clearScreen();
            cout << "-----------Payment Method:-----------" << endl;
            cout << "1. Credit Card" << endl;
            cout << "2. G-cash" << endl;
            cout << "3. Cash on Delivery" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Choose payment method: ";
            cin >> paymentChoice;

            if (paymentChoice == 1)
            {
                paymentMethod = "Credit Card";
                break;
            }
            else if (paymentChoice == 2)
            {
                paymentMethod = "G-cash";
                break;
            }
            else if (paymentChoice == 3)
            {
                paymentMethod = "Cash on Delivery";
                break;
            }
            else
            {
                cout << "Invalid payment method selected. Please try again." << endl;
            }
        }

        int pricePerItem = product.getProductPrice(selectedProduct);
        Order order(selectedProduct, quantity, paymentMethod, pricePerItem);
        Customer customer(order);

        // Confirm the order and proceed accordingly
        order.confirmOrder();

        // Store customer data
        if (currentCustomer < maxCustomers)
        {
            customers[currentCustomer] = customer;
            currentCustomer++;
        }
        else
        {
            cout << "Customer limit reached. Cannot add more customers." << endl;
            break;
        }

        // Add customer confirmation with validation
        while (true)
        {
            cout << "Do you want to add another customer? (y/n): ";
            cin >> addAnother;

            if (addAnother == 'y' || addAnother == 'n')
            {
                break; // Valid input, exit the loop
            }
            else
            {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        }

    } while (addAnother == 'y' && currentCustomer < maxCustomers);

    // Display all customers
    clearScreen();
    cout << "\n----------CUSTOMER LIST----------" << endl;
    for (int i = 0; i < currentCustomer; i++)
    {
        cout << "Customer " << (i + 1) << endl;
        customers[i].getCustomerDetails();
        cout << "--------------------------------" << endl;
    }

    return 0;
}