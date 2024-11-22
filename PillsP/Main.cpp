#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <iomanip>

//АККАУНТЫ
int userCount = 2;
bool isAdmin = false;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passArr = new std::string[userCount]{ "admin","user" };

//СКЛАД
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//ИНИЦИАЛИЗАЦИЯ ФУНКЦИЙ
void Start();
bool Login();
bool IsNumber(std::string string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage();

template <typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\t\tДошиРай\n\n";
	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;

}
//ФУНКЦИИ
void Start() {
	if (Login() == true)
		if (isAdmin == true) {
			std::string choose;
			while (true)
			{
				std::cout << "1 - Использовать готовый склад\n2 - Создать склад\n Ввод: ";
				std::getline(std::cin, choose, '\n');
				if (choose == "1") {
					CreateStaticStorage();
					break;
				}
				else if (choose == "2")
				{

					break;
				}
				else
				{
					std::cout << "\n\nВведи нормально...\n\n";
				}
			}
			ShowAdminMenu();
		}


		else
		{
			CreateStaticStorage();
		}
	else
	{
		std::cerr << "Ты как умудрился, лошара?..";
	}
}

bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "Логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Пароль: ";
		std::getline(std::cin, pass, '\n');

		if (login == loginArr[0] && pass == passArr[0]) {
			std::cout << "Авторизация: " << loginArr[0] << "\n\n";
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passArr[i]) {
				std::cout << "Авторизация: " << loginArr[i] << "\n\n";
				isAdmin = false;
				return true;
			}

		}

		system("cls");
		std::cout << "Неверный логин или пароль\n\n";
	}
}

bool IsNumber(std::string string)
{
	for (int  i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
		return true;
	}
}

void CreateStaticStorage() {
	const int tempSize = 10;
	int tempId[tempSize]{1,2,3,4,5,6,7,8,9,10};
	std::string tempName[tempSize]{
	"Дошик с курицей",
	"Дошик с говядиной",
	"Дошик с грибами",
	"Дошик с овощами",
	"Дошик с сыром",
	"Дошик с креветкой",
	"Дошик острый",
	"Дошик восточный",
	"Чан рамен с курицей",
	"Чан рамен с говядиной"
	};
	int tempCount[tempSize]{13, 65, 53, 62, 36, 67, 64, 23, 56, 51};
	double tempPrice[tempSize]{34.0, 34.0, 40.0, 35.0, 50.0, 60.0, 55.0, 75.0, 90.0, 90.0};
	FillStorage(tempId, idArr, tempSize);
	FillStorage(tempName, nameArr, tempSize);
	FillStorage(tempCount, countArr, tempSize);
	FillStorage(tempPrice, priceArr, tempSize);
}
void ShowStorage()
{
	system("cls");
	std::cout << "\nID\t" << "Название\t\t\t" << "Количество\t" << "Цена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
	}
	system("pause");

}
void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Изменить цену\n";
		std::cout << "6 - Изменить склад\n";
		std::cout << "7 - Изменить сотрудников\n";
		std::cout << "8 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "\nВвод:";
		std::getline(std::cin, choose, '\n');
		if (choose == "1") {

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "\nОшибка ввода\n";
			Sleep(500);
		}
	}
}

void ShowUserMenu() {
	std::string choose;

	while (true)
	{
		std::cout << "1 - Начать продажу\n";
		std::cout << "2 - Показать склад\n";
		std::cout << "3 - Пополнить склад\n";
		std::cout << "4 - Списать со склада\n";
		std::cout << "5 - Отчёт о прибыли\n";
		std::cout << "0 - Закрыть смену\n";
		std::cout << "\nВвод:";
		std::getline(std::cin, choose, '\n');
		if (choose == "1") {

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cout << "\nОшибка ввода\n";
			Sleep(500);
		}
	}
}


template<typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
