#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Иерархия классов, определяющая разные модели принтеров, которые выполняют разные виды печати.
//лазерная и струйная типы печати pantum-p2502 canon-pixma-g1820
class Printer
{
  public:    
    virtual void print( const string & file ) = 0;
};
  
class Lazer_Printer : public Printer
{
  public:
    void print( const string & file ) {
        cout << "pantum-p2502 печатает... бррр... Готово! " << endl;
    }
};
  
class InkGet_Printer : public Printer
{
  public:
    void print( const string & file ) {
        cout << "canon-pixma-g1820 печатает... бррр... Готово! " << endl;
    }
};
  
  
// Класс для использования
class PrinterUser 
{
  public:
    PrinterUser( Printer* comp): my_printer(comp) {}
    void print( const string & file ) {
      my_printer->print( file);
    }
  private:
    Printer* my_printer;
};

//функция для проверки расширения файла //JPEG, PNG, PDF
bool file_checker(string file) {

    vector<string> filetypes = {".jpeg", ".png", ".pdf"};
    if (file.find_last_of(".") == string::npos) return 0;
    string filetype = file.substr(file.find_last_of("."), file.length());

    for (int i=0; i<filetypes.size(); i++) {
      if (filetype == filetypes[i]) {
        return 1;
      }
    } 
    return 0;

}

int main()
{
  cout << "выберете принтер для печати: pantum-p2502 (лазерный) == 0, canon-pixma-g1820 (струйный) == 1: ";
  string choise;
  cin >> choise;
  cout << "имя файла для печати: ";
  string filename;
  cin >> filename;
  if (file_checker(filename) == 0) {
    cout << "Неправильный тип файла, должен быть JPEG, PNG или PDF" << endl;
    return 0;
  }
  cout << "Файл " << filename << " печатается, подождите" << endl;
  if (choise == "0") {
    PrinterUser* my_printer = new PrinterUser( new Lazer_Printer);
    my_printer->print(filename);
  }
  else if (choise == "1") {
    PrinterUser* my_printer = new PrinterUser( new InkGet_Printer);
    my_printer->print(filename);
  }
  else {
    cout << "Некорректный выбор" << endl;
    return 0;
  }

  return 0;
}