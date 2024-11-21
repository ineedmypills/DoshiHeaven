#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>

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
void CreateStaticStorage();

template <typename Arr>
void FillStorage(Arr staticArr, Arr dynamicArr, int staticSize);

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
		}
		else
		{

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
		std::cout << "Логин: ";
		std::getline(std::cin, login, '\n');

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
};

template<typename Arr>
void FillStorage(Arr staticArr, Arr dynamicArr, int staticSize)
{
	for (int i = 0; i < staticSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
