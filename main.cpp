#include <iostream>
using namespace std;

//오신걸 환영합니다
//직업을 고르세요
//>
//던전 입장하기 나가기 선택하기
//입장하였습니다.
//몬스터 소환,스팩출력
//싸우기 도망가기 선택하기
//싸웠을때 결과값


// 구조체 struct

//struct Objection
//{
//	int type;
//	int hp;
//	int attack;
//	int defence;
//};
//
//Objection PlayertInfo;
// {
//
//
// }

int PlayerType;
int hp;
int attack;
int defence;

enum PlayerType
{
	PT_Knigt = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

int MonsterType;
int Monsterhp;
int Monsterattack;
int Monsterdefence;

enum MonsterType
{
	MT_Silme = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

//함수 선언
void EnterLobby();
void SelecPlayer();
void EnterField();
void CreatorRandomMonster();
void EnterBattle();

int main()
{
	srand(time(0));
	EnterLobby();

 return 0;
}

void SelecPlayer()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "직업을 골라주세요" << endl;
		cout << "전사 (1) , 궁수 (2) , 마법사 (3)" << endl;
		cout << ">";

		cin >> PlayerType;

		if (PlayerType == PT_Knigt)
		{
			cout << "기사 생성중.....!" << endl;
			hp = 200;
			attack = 20;
			defence = 10;
			break;
		}
		else if (PlayerType == PT_Archer)
		{
			cout << "궁수 생성중.....!" << endl;
			hp = 150;
			attack = 15;
			defence = 8;
			break;
		}
		else if (PlayerType == PT_Mage)
		{
			cout << "마법사 생성중.....!" << endl;
			hp = 100;
			attack = 30;
			defence = 5;
			break;
		}
	}

}



void EnterLobby()
{
	while (true)
	{
		cout << "----------------------------" << endl;
		cout << "TxT 알피지에 오신것을 환영합니다" << endl;
		cout << "----------------------------" << endl;
		
		//플레이어 직업 선택
		SelecPlayer();

		cout << "----------------------------" << endl;
		cout << "(1)필드입장  (2)게임 종료" << endl;
		cout << "----------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}

	}

}

void EnterField()
{
	while (true)
	{

		cout << "----------------------------" << endl;
		cout << "필드에 입장하셧습니다" << endl;
		cout << "----------------------------" << endl;

		cout << "[player hp =" << hp <<"]" << "[player attack =" << attack << "]" << "[player defence = " << defence << "]" << endl;

		CreatorRandomMonster();

		cout << "----------------------------" << endl;
		cout << "(1)전투 ,(2)도망" << endl;
		cout << ">" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (hp == 0)
				return;
		}
		else
		{
			return;
		}
	}

}

void CreatorRandomMonster()
{
	//1~3  랜덤출력

	MonsterType = 1 + (rand() % 3);

	switch (MonsterType)
	{
	case  MT_Silme:
		cout << "슬라임이 생성되고 있습니다!   (HP : 15 , ATT : 5 , DEF : 0)" << endl;

		Monsterhp = 15;
		Monsterattack = 5;
		Monsterdefence = 0;
		break;

	case  MT_Orc:
		cout << "오크가 생성되고 있습니다!   (HP : 40 , ATT : 10 , DEF : 3)" << endl;

		Monsterhp = 40;
			Monsterattack = 10;
		Monsterdefence = 3;
		break;

	case  MT_Skeleton:
		cout << "스켈레톤이 생성되고 있습니다!   (HP : 80 , ATT : 15 , DEF : 5)" << endl;

		Monsterhp = 80;
		Monsterattack = 15;
		Monsterdefence = 5;
		break;

	}

}

void EnterBattle()
{
	//  둘중하나가 죽을떄까지
	while (true)
	{
		// 플레이어 공격시
		int damage = attack - Monsterdefence;
		if (damage < 0)
			damage = 0;

		Monsterhp = Monsterhp - damage;
		if (Monsterhp < 0)
			Monsterhp = 0;

		cout << "몬스터의 남은 채력" <<  Monsterhp<< endl;

		if (Monsterhp == 0)
		{
			cout << "몬스터를 처치했습니다" << endl;
			return; 
		}

		//몬스터가 공격시
		int Monsterdamage = Monsterattack - defence;
		if (Monsterdamage < 0)
			Monsterdamage = 0;

		hp = hp - Monsterdamage;
		if (hp < 0)
			hp = 0;

		cout << "플레이어의 남은 채력 : " << hp << endl;

		if (hp == 0) 
		{
			cout << "사망하였습니다 ....game over" << endl;
			return;
		}

	}


}