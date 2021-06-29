#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <locale.h>
#include <cstdlib>
using namespace std;

//теперь работает
void WOOP(vector<char> &v){
	v.clear();
}
void WOOP(vector<char> &v1,vector<char> &v2,vector<char> &v3){
	WOOP(v1);
	WOOP(v2);
	WOOP(v3);
}
//слайды
void ShowGuy(int x){
	cout<< "  <o===============[x]\n";
	cout<< "   |                I\n";
	cout<< "   |                I\n";
	cout<< "   i                I\n";
	if(x==7){
		
		cout<< "  (O)               I\n";
		cout<< "                    I\n";
		cout<< "                    I\n";
		cout<< "   _                I\n";
		cout<< "  |#|              [|]\n";
		cout<< "///////////////////////\n";
	}else if(x==6){
		cout<< " (*_*)              I\n";
		cout<< "                    I\n";
		cout<< "                    I\n";
		cout<< "   _                I\n";
		cout<< "  |#|              [|]\n";
	}else if(x==5){
		cout<< " (*_*)              I\n";
		cout<< "  | |               I\n";
		cout<< "                    I\n";
		cout<< "   _                I\n";
		cout<< "  |#|              [|]\n";
		cout<< "///////////////////////.\n";
	}else if(x==4){
		cout<< " (*_*)              I\n";
		cout<< " -| |-              I\n";
		cout<< "                    I\n";
		cout<< "   _                I\n";
		cout<< "  |#|              [|]\n";
		cout<< "///////////////////////.\n";
	}else if(x==3){
		cout<< " (*-*)              I\n";
		cout<< " -| |-              I\n";
		cout<< "  |^|               I\n";
		cout<< "   _                I\n";
		cout<< "  |#|              [|]\n";
		cout<< "///////////////////////.\n";
	}else if(x==2){
		cout<< " (*o*) {plz dont}   I\n";
		cout<< " -| |-  {kill me}   I\n";
		cout<< "  |^|               I\n";
		cout<< "  !_!               I\n";
		cout<< "  |#|              [|]\n";
		cout<< "///////////////////////.\n";
	}else if(x==1){
		cout<< " (*A*) (last chanse)I\n";
		cout<< " -| |-              I\n";
		cout<< "  |^|               I\n";
		cout<< "  ! !               I\n";
		cout<< "  |#|              [|]\n";
		cout<< "///////////////////////.\n";
	}else if(x==0){
		cout<< " (X-X)   oh no      I\n";
		cout<< " -| |-              I\n";
		cout<< "  |^|               I\n";
		cout<< "  ! !               I\n";
		cout<< "                   [|]\n";
		cout<< "///////////////////////.\n";
	}else if(x==-300){
		cout<< "   _                I\n";
		cout<< " (WoW)              I\n";
		cout<< " -| |-  {thanks}    I\n";
		cout<< "  |^|               I\n";
		cout<< "  ! !              [|]\n";
		cout<< "///////////////////////.\n";
	}
}



int main() {
	system("clear");
	setlocale(LC_ALL, "Russian");
	int choise_number, lives, Len, tiker;
	char answer, again;
	srand(time(NULL));
	vector<char> Kusochki, UsedWords, SecretKUS;
	bool jake = 0, kile;
	string slovo;
	map <int, string> Slovar{ {1, "BRITAIN"},{2, "HIPERBOLA"},{3, "SOUL"},{4, "JOY"},{5, "FAIL"} };

	/////////////////////////////////////////////////////
	do{
		WOOP(Kusochki, SecretKUS, UsedWords);

		choise_number = (rand() % Slovar.size() + 1);
		slovo = Slovar[choise_number];
		Len = slovo.size();
		//cout << Len << "," << slovo << ",";

		for (char bukva : slovo) {
			Kusochki.push_back(bukva);
		}

		for (int i = 0; i < Len; i++) {
			SecretKUS.push_back('_');
		}

		//////////////////////////////////////////////////////////

		lives = 7;
		

		cout << "Загаданное слово:\n";
			for (char bukva : SecretKUS) {
				cout << bukva << " ";
			}
			cout << endl;



		while ((lives > 0) && (Len > 0)){

			tiker = -1;

			// Ввод буквы в вектор использованых
			cout << "Введите заглавной буквой выбранную букву на английском:";
			cin >> answer;
			

			for (char bukva : UsedWords) {
				if (bukva == answer) {
					jake = 1;
				}
			}
			if (jake == 1) {
				system("clear");
				cout << "Буква " << answer << " уже была использована!\n";
				jake = 0;
			}
			else if (jake == 0) {
				UsedWords.push_back(answer);
				sort(UsedWords.begin(), UsedWords.end());

			system("clear");

				// Определение качества выбора
				for (char bukva : Kusochki) {
					if (answer == bukva) {
						cout << "<[O] Буква угадана!>\n";
						Len--;
						kile = 1;
					}
				}
				if (kile == 0) {
					cout << "<[X] Такой буквы нет в слове>\n";
					lives--;
				}
				kile = 0;
			}


			// Открытие букв
			for (char bukva1 : Kusochki) {
				tiker++;
				for (char bukva2 : UsedWords) {
					if (bukva1 == bukva2) {

						SecretKUS[tiker] = bukva1;

					}
				}


			}

			cout << endl;


		
		
			ShowGuy(lives);

			cout << "\nЖизни: "<<lives << endl;
			cout << "Загаданное слово:\n";
				for (char bukva : SecretKUS) {
					cout << bukva << " ";
				}
				cout << endl;

			cout << "Использованные буквы:\n";
				for (char bukva : UsedWords) {
					cout << bukva << " ";
				}
			cout << endl;

		

		}
		

		if(lives>Len){
			ShowGuy(-300);
			cout<< "\n\n\t\t\tВЫ ПОБЕДИЛИ!";
		}else if(Len>lives){
			cout<< "\n\n\t\t\tВЫ Проиграли!";
		}

		cout<<"\n\t\t Хотите сыграть снова? (Y/N):";
		cin>> again;
		if ((again !='Y')&&(again !='N')){
			cout<<"\n\t\t\t<Неправильный ввод>";
			cout<<"\n\t\t Хотите сыграть снова? (Y/N):";
			cin>> again;
		}

	}while(again != 'N');

}
