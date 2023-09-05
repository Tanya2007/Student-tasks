#include <iostream>
#include <string>
#include <regex>

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

double inputValueDouble()
{
	std::regex double_regex("\\d+\\.?\\d{0,2}");
	std::string value{"0"};
	while(true)
	{
		std::cin >> value;
		
		if(std::regex_match(value, double_regex))
		{
			break;
		}
		
		std::cout << "\nInvalid input, try again: ";
	}
	
	return atof(value.c_str());
}

class CPerson
{
	protected:
		std::string m_surname;
		std::string m_name;
		std::string m_patronymic;

	public:
		CPerson(const std::string &s = "", const std::string &n = "",
		        const std::string &p = "")
			: m_surname(s), m_name(n), m_patronymic(p)
		{
		}
		
		virtual ~CPerson()
		{
		}

		virtual void showData() const = 0;

		virtual void dataEntry()
		{
			std::cout << "Surname: ";
			std::getline(std::cin, m_surname);
			std::cout << "Name: ";
			std::getline(std::cin, m_name);
			std::cout << "Patronymic: ";
			std::getline(std::cin, m_patronymic);
		}
};

void CPerson::showData() const
{
	std::cout << "FIO: " << m_surname << " " << m_name << " " << m_patronymic << "\n";
}

class CStudent : public CPerson
{
	private:
		double m_average;

	public:
		CStudent(const std::string &s = "", const std::string &n = "",
		         const std::string &p = "", double a = 0.0)
			: CPerson(s, n, p), m_average(a)
		{
		}
		
		virtual ~CStudent()
		{
		}

		virtual void showData() const override
		{
			CPerson::showData();
			std::cout << "Average score: " << m_average << "\n";
		}
		
		virtual void dataEntry() override
		{
			CPerson::dataEntry();
			std::cout << "Average score: ";
			m_average = inputValueDouble();
		}
};

class CProfessor : public CPerson
{
	public:
		enum Post
		{
			TEACHER,
			SENIOR_TEACHER,
			DOCENT,
			PROFESSOR
		};

	private:
		int m_publications;
		Post m_post;
		int m_age;

	public:
		CProfessor(const std::string &s = "", const std::string &n = "",
		           const std::string &p = "", int p_c = 0, Post post = TEACHER, int age = 0)
			: CPerson(s, n, p), m_publications(p_c), m_post(post), m_age(age)
		{
		}
		
		virtual ~CProfessor()
		{
		}

		virtual void showData() const override
		{
			CPerson::showData();
			std::string post;
			switch(m_post)
			{
				case TEACHER:
					post = "Teacher";
					break;
				case SENIOR_TEACHER:
					post = "Senior Teacher";
					break;
				case DOCENT:
					post = "Docent";
					break;
				case PROFESSOR:
					post = "Professor";
					break;
			}

			std::cout << "Post: " << post << "\n";
			std::cout << "Publications: " << m_publications << "\n";
			std::cout << "Age: " << m_age << "\n";
		}
		
		virtual void dataEntry() override
		{
			CPerson::dataEntry();
			std::cout << "Post (0 - Teacher, 1 - Senior Teacher, 2 - Docent, 3 - Professor): ";
			int post{inputValue()};
			if(post == 0)
				m_post = TEACHER;
			else if(post == 1)
				m_post = SENIOR_TEACHER;
			else if(post == 2)
				m_post = DOCENT;
			else
				post = PROFESSOR;
			std::cout << "Publications: ";
			m_publications = inputValue();
			std::cout << "Age: ";
			m_age = inputValue();
		}
};

int main()
{
	const int N {5};
	CPerson *arr[N];

	for(int i{}; i < N; ++i)
	{
		std::cout << "\nEnter the type of person (s - student, p - professor): ";
		char ch;
		std::cin >> ch;
		std::cin.ignore();
		if(ch == 's')
		{
			arr[i] = new CStudent;
		}
		else
		{
			arr[i] = new CProfessor;
		}
		arr[i]->dataEntry();
	}
	
	for(int i{}; i < N; ++i)
	{
		std::cout << "\n";
		arr[i]->showData();
	}
	
	for(int i{}; i < N; ++i)
	{
		delete arr[i];
		arr[i] = nullptr;
	}
	
	return 0;
}