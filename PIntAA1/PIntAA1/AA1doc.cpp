#include <ctime>
#include <iostream>
#include <string>

using namespace std;

enum EnemyType {zombie, vampire, ghost, witch};
struct Enemy {
	EnemyType type;
	string name;
	int health;
};
int equalEnemies(Enemy enOne, Enemy enTwo) {
	if (enOne.type == enTwo.type) {
		int result;
		strcmp(const char *enOne.name, const char *enTwo.name);
		
	}
	else return 0;
}
int createRandomEnemy() {
	int alpha = rand() % 4;
	EnemyType beta;
	switch (alpha) {
	case 0:
		beta = zombie;
		break;
	case 1:
		beta = vampire;
		break;
	case 2:
		beta = ghost;
		break;
	default:
		beta = witch;
		break;
	}
	return beta;
}
string getEnemyTypeString(EnemyType beta) {
	string gamma;
	switch (beta) {
	case zombie:
		gamma = "is a zombie";
		break;
	case vampire:
		gamma = "is a vampire";
		break;
	case ghost:
		gamma = "is a ghost";
		break;
	case witch:
		gamma = "is a witch";
		break;
	default:
		gamma = "is an error";
		//errormessage
		break;
	}
	return gamma;
}
int main() {
	char totalEnemies[5];

}