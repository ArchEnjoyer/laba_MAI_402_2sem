// Создайте простой онлайн магазин, используя архитектурный шаблон MVC на языке
// C++. (Например, товар со следующими полями: название, описание, цена, количество
// на складе и т.п.)
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <filesystem>

class Product {
  private:
    std::string name_of_product;
    std::string price;
    std::string article;
    std::string count_of_product;
  public:
    Product(std::string& name_of_product, std::string& price, std::string& article, std::string& count_of_product) 
    : name_of_product(name_of_product), price(price), article(article), count_of_product(count_of_product) {}
    std::string getName() { return name_of_product; }
    std::string getPrice() { return price; }
    std::string getArticle() { return article; }
    std::string getCount() { return count_of_product; }
};

class ProductList {
  private:
    std::vector<Product> products;
  public:
    // Методы для управления списком товаров
    void addProduct(Product& newProduct) { products.push_back(newProduct); }
    void removeProduct(std::string article) {
      for (int i = 0; i < products.size(); i++) {
        if (products[i].getArticle() == article) {
          products.erase(products.begin() + i);
          break;
        }
      }
    }

    void saveProducts() {
      std::ofstream myfile ("data.txt", std::ios_base::out);
      //std::cout << myfile.is_open() << std::endl;
      for (int i = 0; i < products.size(); i++) {
        myfile << products[i].getName() << " " << products[i].getPrice() << " " 
        << products[i].getArticle() << " " << products[i].getCount() << "\n";
      }
      myfile.close();
    }

    void loadProducts() {        //считываем данные из файла
      if (std::filesystem::exists("data.txt")) {
        std::ifstream myfile ("data.txt");
        std::string input; // в этой переменной хранится строка из файла
        std::string tmp_word; // в этой переменной - слово
        while (std::getline(myfile, input)) { // пробегаемся по каждой строке в файле
          tmp_word = "";
          std::vector<std::string> stroka; // создаем массив из слов
          for (int i = 0; i < input.length(); i++) { // пробегаемся по каждой букве в строке
            if (input[i] != ' ') { // проверяем, если это пробел, то слово составлено, если нет, добавляем букву в слово
                tmp_word += input[i];
            } else { 
                stroka.push_back(tmp_word); // добавляем слово, если есть пробел
                tmp_word = "";
            }
          }
          stroka.push_back(tmp_word); // добавляем последнее слово
          std::string Name_of_product, Price, Article, Count_of_product; // 4 переменных для добавления в массив newProduct
          Count_of_product = stroka[stroka.size()-1]; //последнее слово в массиве stroka
          Article = stroka[stroka.size()-2]; //предпоследнее
          Price = stroka[stroka.size()-3]; //предпредпоследнее
          std::string another_tmp_word = ""; //составляем слово Name_of_product
          for (int i = 0; i < stroka.size()-3; i++) {
              another_tmp_word = another_tmp_word+stroka[i]+" ";
          }
          Name_of_product = another_tmp_word.substr(0,another_tmp_word.length()-1); // удаляем лишний пробел
  
          Product newProduct(Name_of_product, Price, Article, Count_of_product);
          products.push_back(newProduct);
          }
        }
      }

    void displayProducts() {
      std::cout << "Products:\n";
      for (int i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i].getName() << " " << products[i].getPrice() << " " 
        << products[i].getArticle() << " " << products[i].getCount() << "\n";
      }
    }
};

class ProductView {
  public:
    void showMenu() {
      std::cout << "\nProduct Management System\n";
      std::cout << "1. Add Product\n";
      std::cout << "2. Remove Product\n";
      std::cout << "3. Display Products\n";
      std::cout << "4. Exit\n";
    }
    int getUserChoice() {
      int choice;
      std::cout << "Enter your choice: ";
      std::cin >> choice;
      return choice;
    }
};
class OnlineMagazineController {
  private:
    ProductList model;
    ProductView view;
  public:
    void handleUserInput() {
      int choice;
      model.loadProducts();
      do {
        view.showMenu();
        choice = view.getUserChoice();
        switch (choice) {
          case 1: {
            std::string Name_of_product, Price, Article, Count_of_product;
            std::cout << "Enter name of product: ";
            std::cin.ignore();
            std::getline(std::cin, Name_of_product);
            std::cout << "Enter price: ";
            std::cin >> Price;
            std::cout << "Enter article: ";
            std::cin >> Article;
            std::cout << "Enter count of product: ";
            std::cin >> Count_of_product;
            Product newProduct(Name_of_product, Price, Article, Count_of_product);
            model.addProduct(newProduct);
            std::cout << "Product added!\n";
            break;
          }
          case 2: {
            std::string article;
            std::cout << "Enter article of product to remove: ";
            std::cin >> article;
            model.removeProduct(article);
            std::cout << "Product removed!\n";
            break;
          }
          case 3: {
            model.displayProducts();
            break;
          }
          case 4: {
            std::cout << "Exiting...\n";
            model.saveProducts();
            break;
          }
          default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
          }
        }
      } while (choice != 4);
    }
};

int main() {
  OnlineMagazineController controller;
  controller.handleUserInput();
  return 0;
}