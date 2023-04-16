#include <iostream>
#include <string>
/*
� ������� ��������� �������� ������� IsKPeriodic,
������� ���������, �������� �� ������ ������� ����� K.
��������� � ������������� ������ ������ K ��������(K ������ ���� ������ 0).
��������, abcabcabcabc ����� ��������� 3, ��� ��� ��� ������� �� �������� abc, ������� ����� 3.
*/

bool IsKPeriodic(const std::string& str, size_t k)
{
	int length = str.size();

	if (length % k != 0) return false;//���� ����� ������ �� ������� ��� ������� �� ����� �, �� ����.

	size_t strRepeatLength = length / k;//������� ����� ������, ������� ������ �����������, � � ����� ����������.

	for (size_t i = strRepeatLength; i < length; i += strRepeatLength)
		if (str.substr(0, strRepeatLength) != str.substr(i, strRepeatLength)) //����������� ������ ��������� ������ ������������� ������ � ���������� ����������� � �������� ������. 
			return false;
	return true;
};

int main() {
	char option;
	std::cout << "check string for Periodic?" << std::endl;
	std::cout << "enter 'y' - for check or 'n' - exit" << std::endl;
	while (!(std::cin >> option) || !(option == 'y' || option == 'n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Some mistake, enter 'y' - for check or 'n' - exit" << std::endl;
	}
	switch (option)
	{
	case('y'): {
		int k = 0; //���������
		std::cout << "Enter k (Periodic) (it must be > 0)" << std::endl;
		while (!(std::cin >> k) || (std::cin.peek() != '\n') || !(k > 0))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Some mistake, periodic (it must be > 0),try again" << std::endl;
		}
		char option2;
		std::cout << "Do you want to enter string press 'y'\n" <<
			"or to use five default string press 'n'" << std::endl;
		while (!(std::cin >> option2) || !(option2 == 'y' || option2 == 'n'))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Some mistake, enter 'y' - to enter string or 'n' - to use five default string" << std::endl;
		}
		switch (option2) {
		case('n'): {
			const size_t length = 5; //���������� ����� � �������
			std::string arrStr[length]{ "aaaaaaaaaa", "dranduletdrandulet", "falloutfalloutfallout","timetimetimetime", "avavavavav" };
			for (size_t i = 0; i < length; i++) {
				std::cout << arrStr[i] << (IsKPeriodic(arrStr[i], k) ? " IS " : " is NOT ") << "periodic to " << k << std::endl;
			}
			break;
		}
		case('y'): {
			std::cout << "enter you string" << std::endl;
			std::string str;
			std::cin >> str;
			std::cout << str << (IsKPeriodic(str, k) ? " is " : " isn't ") << "periodic to " << k << std::endl;
			break;
		}
		default: break;
		}
		break;
	}
	default: break;
	}
}