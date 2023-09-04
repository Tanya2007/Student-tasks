#include <iostream>
#include <list>
#include <string>

int inputValue();

struct Textbooks
{
	std::string m_authors_surnames{};
	std::string m_title_book{};
	int year_publication{};
};

int main()
{
	std::list<Textbooks> list_books;
	char ch;
	
	do
	{
		Textbooks temp_book;
		std::cout << "Enter the authors of the book: ";
		std::getline(std::cin, temp_book.m_authors_surnames);
		
		std::cout << "Enter the name of the book: ";
		std::getline(std::cin, temp_book.m_title_book);
		
		std::cout << "Enter the year of publication of the book: ";
		temp_book.year_publication = inputValue();
		
		list_books.push_back(temp_book);
		
		std::cout << "Continue? (y/n): ";
		std::cin >> ch;
		std::cin.ignore(32767, '\n');
		
	}while(ch != 'n');
	
	std::cout << "Enter the word you are looking for: ";
	std::string looking;
	std::getline(std::cin, looking);
	
	for(const auto &elem : list_books)
	{
		if((elem.m_authors_surnames.find(looking) != std::string::npos) 
			|| (elem.m_title_book.find(looking) != std::string::npos))
		{
			std::cout << "\nBook found\n";
			std::cout << "Authors: " << elem.m_authors_surnames << "\n";
			std::cout << "Title: " << elem.m_title_book << "\n";
			std::cout << "Year: " << elem.year_publication << "\n";
		}
	}
	
	return 0;
}

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || value < 0)
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return value;
		}

		std::cout << "\nInvalid input, try again: ";
	}
}