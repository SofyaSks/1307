#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <time.h>

/* 
наполн€ет случайными значени€ми, выводит сортировку + бонусом топ три лучших-худших
тривиальные конструкторы и деструкторы
операторы == < =
*/

class Beast {
public:
	Beast():Beast (0,"",false,0.0){}
	Beast(
		int id,
		std::string name,
		bool solidity,
		double weight
		)
		: id(id),
		name(name),
		 solidity(solidity),
		weight(weight)
	{}



	int id;
	std::string name;
	bool solidity;
	double weight;
};

int main() {
	srand(time(NULL));
	std::vector<Beast>circus;
	circus.reserve(10);
	for (int i = 0; i < circus.capacity(); i++) {
		circus.emplace_back(i + 8, "kitten", false, std::rand() % 7 + 1);
	}
	for (int i = 0; i < 10; i++) {
		std::sort(circus.begin(), circus.end(), 10);
	}
	std::for_each(
		circus.begin(),
		circus.end(),
		[](Beast& arg) {
			std::cout << arg.id << " " << arg.name << " " << arg.solidity << " " << arg.weight << " \n";
		}
	);

	
	std::cout << std::endl << "Part two\n";
	//for (auto&& a : num)
	//	std::cout << a << "\n";

	std::shuffle(
		circus.begin()+1,
		circus.end()-1,
		std::random_device()
	);

	//for (auto&& a : circus)
	//	std::cout << a << " ";

	auto res = std::find_if(
		circus.begin(),  // num.begin() + 1,
		circus.end(),	  // num.end() + 2,
		[](const Beast& arg)->bool{
			if (arg.id == 12) {
				return true;
		}
			return false;

		}
	);

	if (res == circus.end()) {
		std::cout << "we found nothing\n";
	}
	/*else {
		std::cout << "we found " << *res << " on the place " <<  "\n";
	}*/

	 


	return 0;
}