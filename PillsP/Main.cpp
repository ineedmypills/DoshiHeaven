#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <iomanip>

//��������
int userCount = 2;
bool isAdmin = false;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passArr = new std::string[userCount]{ "admin","user" };

//�����
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];

//������������� �������
void Start();
bool Login();
bool IsNumber(std::string string);
void CreateStaticStorage();
void ShowAdminMenu();
void ShowUserMenu();
void ShowStorage(int mode = 0);
void RefillProducts();
void RemoveProducts();
void AddNewProduct();
void ChangePrice();
int GetID();

void Getline(std::string& stringName);

template <typename Arr>
void FillStorage(Arr staticArr[], Arr dynamicArr[], int staticSize);

//-----MAIN-----
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\t\t�������\n\n";
	Start();
	delete[]loginArr;
	delete[]passArr;
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;

}
//-----MAIN-----

//�������
void Start() {
	if (Login() == true)
		if (isAdmin == true) {
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� �����\n ����: ";
				Getline(choose);
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
					std::cout << "\n\n����� ���������...\n\n";
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
		std::cerr << "�� ��� ���������, ������?..";
	}
}
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "�����: ";
		Getline(login);
		std::cout << "������: ";
		Getline(pass);

		if (login == loginArr[0] && pass == passArr[0]) {
			std::cout << "�����������: " << loginArr[0] << "\n\n";
			isAdmin = true;
			return true;
		}

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passArr[i]) {
				std::cout << "�����������: " << loginArr[i] << "\n\n";
				isAdmin = false;
				return true;
			}

		}

		system("cls");
		std::cout << "�������� ����� ��� ������\n\n";
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
	"����� � �������",
	"����� � ���������",
	"����� � �������",
	"����� � �������",
	"����� � �����",
	"����� � ���������",
	"����� ������",
	"����� ���������",
	"��� ����� � �������",
	"��� ����� � ���������"
	};
	int tempCount[tempSize]{13, 65, 53, 62, 36, 67, 64, 23, 56, 51};
	double tempPrice[tempSize]{34.0, 34.0, 40.0, 35.0, 50.0, 60.0, 55.0, 75.0, 90.0, 90.0};
	FillStorage(tempId, idArr, tempSize);
	FillStorage(tempName, nameArr, tempSize);
	FillStorage(tempCount, countArr, tempSize);
	FillStorage(tempPrice, priceArr, tempSize);
}
void ShowStorage(int mode)
{
	system("cls");
	if (mode == 0)
	{
		std::cout << "ID\t" << "��������\t\t\t" << "����������\t" << "����\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
			system("pause");
		}
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << "��������\t\t\t" << "����������\t" << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << "��������\t\t\t" << "����\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t" << "\t" << priceArr[i] << "\n";
		}
	}
	else
	{
		std::cerr << "\nMenuModeError\n";
	}

}
void RefillProducts()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
			std::cout << "���������� ������ ��� ����������: ";
			Getline(chooseCount);
			if (IsNumber(chooseCount)) {
				count = std::stoi(chooseCount);
				if (count > 0 && count <= 1000) {
					countArr[id - 1] += count;
					std::cout << "\n\n����� ������� ��������\n\n";
					Sleep(1000);
					break;
				}
				else
				{
					std::cout << "\n������������ ID\n";
				}
			}
			else
			{
				std::cout << "������, ���";
			}
			}
			
		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void RemoveProducts()
{
	std::string choose, chooseCount;
	int id = 0, count;

	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "���������� ������ ��� ��������: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount)) {
					count = std::stoi(chooseCount);
					if (count > 0 && count <= countArr[id - 1]) {
						countArr[id - 1] -= count;
						std::cout << "\n\n����� ������� ������\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\n������������ ID\n";
					}
				}
				else
				{
					std::cout << "������, ���";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void AddNewProduct() {
	std::string choose, nameStr, priceStr, countStr;
	int id = 0, count;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[]idArr;
			delete[]nameArr;
			delete[]countArr;
			delete[]priceArr;

			size++;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempID[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			while (true)
			{
				std::cout << "������� �������� ������ ������: ";
				Getline(nameStr);
				if (nameStr.size() > 2 && nameStr.size() <= 60)
				{
					nameArr[size - 1] = nameStr;
					break;
				}
				else
				{
					std::cout << "\n������ ���! �� 3 �� 60 ��������!\n";
				}
			}

			while (true)
			{
				std::cout << "���������� ������ ������: ";
				Getline(countStr);
				if (IsNumber(countStr))
				{
					if (std::stoi(countStr) >= 0 && std::stoi(countStr) <= 1000) {
						countArr[size - 1] = std::stoi(countStr);
						break;
					}
					else {
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			while (true)
			{
				std::cout << "���� ������ ������: ";
				Getline(priceStr);
				if (IsNumber(priceStr))
				{
					if (std::stod(priceStr) >= 0 && std::stod(priceStr) <= 10000.0) {
						priceStr[size - 1] = std::stoi(priceStr);
						break;
					}
					else {
						std::cout << "\n������ �����\n";
					}
				}
				else
				{
					std::cout << "\n������ �����\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << "\t" << std::left << std::setw(30) << nameArr[size - 1] << "\t" << countArr[size - 1] << "\t" << "\t" << priceArr[size - 1] << "\n\n";
			std::cout << "����� ����� ������� �������";

			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			Sleep(3000);
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n������ ���\n";
		}
	}

}
void ChangePrice()
{
	std::string choose, choosePrice;
	int id = 0;
	double price{};

	while (true)
	{
		system("cls");
		std::cout << "1 - ������\n0 - ������\n\n����: ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStorage(1);
			id = GetID();
			while (true)
			{
				std::cout << "����� ����: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice)) {
					price = std::stod(choosePrice);
					if (price > 0 && price <= 1000.0) {
						priceArr[id - 1] = price;
						std::cout << "\n\n���� ������� ��������\n\n";
						Sleep(1000);
						break;
					}
					else
					{
						std::cout << "\n������������ ID\n";
					}
				}
				else
				{
					std::cout << "������, ���";
				}
			}

		}
		else if (choose == "0")
		{
			break;
		}


	}
}
void ChangeStorage() {
		std::string choose, chooseCount;
		int id = 0, count;

		while (true)
		{
			system("cls");
			std::cout << "1 - �������� ����� �����\n2 - ������������� ��������\n3 - ������� �����\n0 - ������\n\n����: ";
			Getline(choose);
			if (choose == "1")
			{
				AddNewProduct();
			}
			else if (choose == "2") {

			}
			else if (choose == "3") {

			}
			else if (choose == "0") {
				break;
			}
			else{
			std::cout << "\n������ ���\n"
			}
		}
	}
int GetID()
{
	std::string stringID;
	int result{};
	std::cout << "������� ID ������: ";
	Getline(stringID);
	if (IsNumber(stringID)) {
		result = std::stoi(stringID);
		if (result > 0 && result <= size) {
			return result;
		}
		else
		{
			std::cout << "\n������������ ID\n";
		}
	}
	else
	{
		std::cout << "������, ���";
	}
}
void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}
void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - �������� ����\n";
		std::cout << "6 - �������� �����\n";
		std::cout << "7 - �������� �����������\n";
		std::cout << "8 - ����� � �������\n";
		std::cout << "0 - ������� �����\n";
		std::cout << "\n����:";
		Getline(choose);
		if (choose == "1") {

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProducts();
		}
		else if (choose == "4")
		{
			RemoveProducts();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
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
			std::cout << "\n������ �����\n";
			Sleep(500);
		}
	}
}
void ShowUserMenu() {
	std::string choose;

	while (true)
	{
		std::cout << "1 - ������ �������\n";
		std::cout << "2 - �������� �����\n";
		std::cout << "3 - ��������� �����\n";
		std::cout << "4 - ������� �� ������\n";
		std::cout << "5 - ����� � �������\n";
		std::cout << "0 - ������� �����\n";
		std::cout << "\n����:";
		std::getline(std::cin, choose, '\n');
		if (choose == "1") {

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			RefillProducts();
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
			std::cout << "\n������ �����\n";
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
