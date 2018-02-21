#include <ctime>
#include <iostream>
#include <string>


const int CONST_ENEMY = 4;
const int ENEMY_NUMBERS = 5;
const int HP_MAX = 254;
enum class EnemyType { zombie, vampire, ghost, witch, missingNo };
struct Enemy {//variant anònima (sense el nom Enemy) pot funcionar si només cal en un punt concret del codi.
	EnemyType type;
	std::string name;
	int health;
	std::string text;
};
int equalEnemies( EnemyType typeone, EnemyType typetwo, std::string nameone, std::string nametwo) {
	if (typeone == typetwo) {
		int result = 0;
		result = nameone.compare(nametwo);
		return result;
	}
	else return 1;
}
EnemyType createRandomEnemy() {
	int alpha = rand() % CONST_ENEMY;
	EnemyType beta;
	switch (alpha) {
	case 0:
		beta = EnemyType::zombie;
		break;
	case 1:
		beta = EnemyType::vampire;
		break;
	case 2:
		beta = EnemyType::ghost;
		break;
	case 3:
		beta = EnemyType::witch;
		break;
	default:
		beta = EnemyType::missingNo;
		break;
	}
	return beta;
}
std::string getEnemyTypeString(EnemyType beta) {
	switch (beta) {
	case EnemyType::zombie:
		return " is a zombie";
		break;
	case EnemyType::vampire:
		return  " is a vampire";
		break;
	case EnemyType::ghost:
		return  " is a ghost";
		break;
	case EnemyType::witch:
		return " is a witch";
		break;
	default:
		return " is an error";
		//errormessage
		break;
	}
	//possibilitat: fotre la funció directament al struct
}

std::string giveRandomName() {
	int temp = rand() % 8;
	switch (temp) {
	case 0:
		return "Adaulasio";
		break;
	case 1:
		return "Pentonimio";
		break;
	case 2:
		return "Milterano";
		break;
	case 3:
		return "Maloparto";
		break;
	case 4:
		return "Otrojeffo";
		break;
	case 5:
		return "Sinideaso";
		break;
	case 6:
		return "Kontratako";
		break;
	case 7:
		return "Antijeffo";
		break;
	default:
		return "missingNo";
		break;
	}
}

int main() {
	srand(time(NULL));
	Enemy totalEnemies[ENEMY_NUMBERS];
	for (int i = 0; i < ENEMY_NUMBERS; i++) {
		totalEnemies[i].type = createRandomEnemy();
		totalEnemies[i].health = rand() % HP_MAX + 1;
		int flag = false;
		int compare = 0;
		while (flag == false) {
			flag = true;
			totalEnemies[i].name = giveRandomName();
			for (int j = 0; j < ENEMY_NUMBERS; j++) {
				if (i != j) {
					compare = equalEnemies(totalEnemies[i].type, totalEnemies[j].type, totalEnemies[i].name, totalEnemies[j].name);
				}
				if (compare == 0) {
					flag = false;
				}
			}
		}
	}


	for (int i = 0; i < ENEMY_NUMBERS; i++) {
		std::cout << totalEnemies[i].name << getEnemyTypeString(totalEnemies[i].type) << " whose life is " << totalEnemies[i].health << std::endl;

	}
	system("pause");
}
